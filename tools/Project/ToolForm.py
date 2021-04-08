
#!/usr/bin/env python3
# Copyright (c) 2021 - wzhengsen

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import typing
from Scripts.Assistant import Assistant
import os
import sys
from enum import Enum, auto
from typing import Dict, List
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import QFileInfo, QObject, QThread, QTimer, QUrl, Qt, pyqtSignal
from PyQt5.QtWidgets import QComboBox, QDialog, QDoubleSpinBox, QFileIconProvider, QLabel, QLineEdit, QListWidgetItem, QProgressBar, QRadioButton, QSpinBox, QTableWidget, QTableWidgetItem, QTreeWidgetItem, QTreeWidget, QWidget, QFileDialog, QMessageBox, QTextBrowser
from PyQt5.QtMultimedia import QMediaContent, QMediaPlayer, QMediaPlaylist
from PyQt5.QtMultimediaWidgets import QVideoWidget
from UI_ToolForm import Ui_ToolForm
from UI_ModuleMgrDlg import Ui_ModuleMgrDlg
from Scripts import Functions, Template


class ToolForm(QWidget, Ui_ToolForm):

    class TreeItemType(Enum):
        Dir = auto(),
        File = auto(),
        Image = auto(),
        Text = auto(),
        Module = auto(),
        Media = auto(),
        Error = auto()

    class WorkType(Enum):
        Idle = auto()
        Timer = auto()
        HotUpdate = auto()
        Complie = auto()

    ModuleFileName = "Module.json"

    def __init__(self, cwd=None) -> None:
        super().__init__()
        self.setupUi(self)
        if cwd and os.path.isdir(cwd):
            os.chdir(cwd)
        self.__modulePath = ""
        self.__moduleConfig = None

        if not self.__ReadConfig():
            sys.exit()

        self.__verRBtn: List[QRadioButton] = []
        self.__verSBox: List[QSpinBox] = []

        self.__assistant = Assistant(self.__modulePath, self.__moduleConfig)
        self.__workType = ToolForm.WorkType.Idle

        self.__fip = QFileIconProvider()

        self.__hotUpdateTimer = QTimer(self)
        self.__hotUpdateTimer.timeout.connect(self.__HotUpdateTimerElapsed)
        self.__hotUpdateWorker = HotUpdateWorkThread(self, self.__assistant)

        self.__SetupUiByManual()
        self.show()
        self.UpdateTreeView()

    def __ReadConfig(self) -> bool:
        if not os.path.isfile(ToolForm.ModuleFileName):
            fName, _ = QFileDialog.getOpenFileName(
                self, "选择模块配置文件",
                os.getcwd(), "模块配置文件 ({})".format(ToolForm.ModuleFileName)
            )
            if fName:
                ToolForm.ModuleFileName = fName
            else:
                if QMessageBox.Yes == QMessageBox.information(
                    self,
                    "提示",
                    "没有找到指定的Module.json文件，是否选择一个文件夹以创建一个默认的Module.json文件？",
                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No
                ):
                    fPath = QFileDialog.getExistingDirectory(
                        self, "选择一个工作目录，以创建新的Module.json配置文件：",
                        os.getcwd())
                    if fPath:
                        ToolForm.ModuleFileName = os.path.join(fPath, ToolForm.ModuleFileName)
                        self.__moduleConfig = Template.ConfigTemplate()
                        if not Functions.SaveJson(ToolForm.ModuleFileName, self.__moduleConfig):
                            return False

        if not self.__moduleConfig:
            self.__moduleConfig: Template.ConfigTemplate = Functions.LoadJson(
                ToolForm.ModuleFileName, object_hook=Template.ConfigTemplate.FromJson
            )

        if self.__moduleConfig != None:
            configRoot = os.path.join(os.path.dirname(ToolForm.ModuleFileName), self.__moduleConfig.configRoot)
            if not os.path.isdir(configRoot):
                os.makedirs(configRoot)
            os.chdir(configRoot)
            self.__modulePath = os.path.abspath("..")
            return True
        return False

    def __OnSettingWidgetGeometryChangedEvent(self, _):
        geometry = self.SettingWidget.geometry()
        self.TextBrowser.setGeometry(geometry)
        self.ImageLabel.setGeometry(geometry)
        self.VideoWidget.setGeometry(geometry)
        self.ZipTreeView.setGeometry(geometry)

    def __OnModuleTreeExpandedEvent(self, item: QTreeWidgetItem):
        if item.expanded:
            return
        else:
            item.expanded = True
            # 清理占位节点。
            item.removeChild(item.child(0))
        if item.itemType == ToolForm.TreeItemType.Error:
            return
        elif item.itemType == ToolForm.TreeItemType.Module:
            for path in item.module.dirs + item.module.files:
                self.__CreateSubTreeItem(item, path, True)
        elif item.itemType == ToolForm.TreeItemType.Dir:
            itemPath = ToolForm.__GetTreeItemPath(item)
            for path in os.listdir(itemPath):
                self.__CreateSubTreeItem(item, os.path.join(itemPath, path))

    def __OnModuleTreeItemSelectedEvent(self, item: QTreeWidgetItem, _):
        if item == None:
            self.__HideInfoView()
        elif item.itemType == ToolForm.TreeItemType.Module:
            self.__StopPreview()
            self.__UpdateModuleView()
            self.SettingWidget.show()
        else:
            itemPath = ToolForm.__GetTreeItemPath(item)
            self.__HideInfoView()
            if not os.path.isfile(itemPath):
                return
            if item.itemType == ToolForm.TreeItemType.Text:
                try:
                    with open(itemPath, "rb") as file:
                        self.TextBrowser.setText(file.read().decode("utf8"))
                except:
                    return
                self.TextBrowser.show()
            elif item.itemType == ToolForm.TreeItemType.Image:
                pix = QPixmap(itemPath)
                iWidth = self.ImageLabel.width()
                iHeight = self.ImageLabel.height()
                if pix.width() > iWidth or pix.height() > iHeight:
                    pix = pix.scaled(iWidth, iHeight, Qt.AspectRatioMode.KeepAspectRatio)
                self.ImageLabel.setPixmap(pix)
                self.ImageLabel.show()
            elif item.itemType == ToolForm.TreeItemType.Media:
                self.MediaPlayList.clear()
                self.MediaPlayList.addMedia(QMediaContent(QUrl.fromLocalFile(itemPath)))
                self.MediaPlayList.setCurrentIndex(0)
                self.MediaPlayList.setPlaybackMode(QMediaPlaylist.CurrentItemOnce)
                # 如果播放失败，尝试安装lavfilter。
                self.MediaPlayer.play()
                self.VideoWidget.show()

    def __OnModuleTreeItemCheckedEvent(self, item: QTreeWidgetItem = None, _=None):
        if not item or not item.parent():
            for col in range(0, self.ModuleTreeWidget.topLevelItemCount()):
                idxItem: QTreeWidgetItem = self.ModuleTreeWidget.topLevelItem(col)
                if idxItem.checkState(0) == Qt.Checked:
                    self.StartButton.setEnabled(True)
                    return
            self.StartButton.setEnabled(False)

    def __OnStartTimerCheckBoxCheckedEvent(self, state: int):
        self.StartTimerSpinBox.setEnabled(state == 2)

    def __OnSelectAllButtonClickedEvent(self, _):
        for col in range(0, self.ModuleTreeWidget.topLevelItemCount()):
            idxItem: QTreeWidgetItem = self.ModuleTreeWidget.topLevelItem(col)
            idxItem.setCheckState(0, Qt.Checked)
        else:
            self.StartButton.setEnabled(True)

    def __OnSelectOtherButtonClickedEvent(self, _):
        for col in range(0, self.ModuleTreeWidget.topLevelItemCount()):
            idxItem: QTreeWidgetItem = self.ModuleTreeWidget.topLevelItem(col)
            checkState = idxItem.checkState(0)
            if checkState == Qt.Unchecked or checkState == Qt.PartiallyChecked:
                checkState = Qt.Checked
            else:
                checkState = Qt.Unchecked
            idxItem.setCheckState(0, checkState)
        else:
            self.__OnModuleTreeItemCheckedEvent()

    def __OnManageModuleButtonClickedEvent(self, _):
        ModuleMgrDlg(self).show()

    def __OnVersionRadioButtonToggledEvent(self, checked):
        if checked:
            module = self.__GetModule()
            if not module:
                return
            for idx, rb in enumerate(self.__verRBtn):
                if rb.isChecked():
                    module.versionType = idx
                    break
            v3Checked = self.__verRBtn[3].isChecked()
            for sb in self.__verSBox:
                sb.setEnabled(v3Checked)

    def __OnVersionSpinBoxChangedEvent(self, _):
        module = self.__GetModule()
        if module:
            vList = [str(sb.value()) for sb in self.__verSBox]
            module.useVersion = ".".join(vList)

    def __OnNoUploadCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if not module:
            return
        enable = state == 2
        self.UploadDiffHashCheckBox.setEnabled(not enable)
        self.UploadZipCheckBox.setEnabled(not enable)
        self.FtpAccountLineEdit.setEnabled(not enable)
        self.FtpPasswordLineEdit.setEnabled(not enable)
        if enable:
            self.UploadDiffHashCheckBox.setChecked(False)
            self.UploadZipCheckBox.setChecked(False)
        module.noUpload = enable

    def __OnUploadDiffHashCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            module.onlyHashDiff = state == 2

    def __OnUploadZipCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            module.compressUpload = state == 2

    def __OnFtpAccountLineEditEditedEvent(self, text: str):
        module = self.__GetModule()
        if module:
            module.ftpAccount = text

    def __OnFtpPasswordLineEditEditedEvent(self, text: str):
        module = self.__GetModule()
        if module:
            module.ftpPassword = text

    def __OnUncomperssZipCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            module.zipUncompress = state == 2

    def __OnEncryptResCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            enable = state == 2
            self.EncryptResPasswordLineEdit.setEnabled(enable)
            module.encryptRes = enable

    def __OnEncryptResPasswordLineEditEditedEvent(self, text: str):
        module = self.__GetModule()
        if module:
            module.encryptPassword = text

    def __OnCompressImgCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            enable = state == 2
            self.MinQualitySpinBox.setEnabled(enable)
            self.MaxQualitySpinBox.setEnabled(enable)
            module.compressPic = enable

    def __OnMinQualitySpinBoxChangedEvent(self, val: int):
        module = self.__GetModule()
        if module:
            module.compressQualityMin = val

    def __OnMaxQualitySpinBoxChangedEvent(self, val: int):
        module = self.__GetModule()
        if module:
            module.compressQualityMax = val

    def __OnCompileLuaCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            module.compileLua = state == 2

    def __OnDownloadFilterComboBoxChangedEvent(self, idx: int):
        module = self.__GetModule()
        if module:
            module.filterType = idx

    def __OnNumFilterCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            enable = state == 2
            self.NumFilterSpinBox.setEnabled(enable)
            module.openFilterNum = enable

    def __OnSizeFilterCheckBoxCheckedEvent(self, state: int):
        module = self.__GetModule()
        if module:
            enable = state == 2
            self.SizeFilterSpinBox.setEnabled(enable)
            module.openFilterSize = enable

    def __OnNumFilterSpinBoxChangedEvent(self, val: int):
        module = self.__GetModule()
        if module:
            module.filterNum = val

    def __OnSizeFilterSpinBoxChangedEvent(self, val: float):
        module = self.__GetModule()
        if module:
            module.filterSize = int(val * 1024 * 1024)

    def __OnUniqueConfigCheckBoxCheckedEvent(self, state: int):
        self.__moduleConfig.useUniConfig = state == 2
        self.__UpdateModuleView()

    def __OnSaveOnExitCheckBoxCheckedEvent(self, state: int):
        self.__moduleConfig.exitSave = state == 2

    def __OnStartButtonClickedEvent(self, _):
        if self.__workType == ToolForm.WorkType.Idle:
            self.__StartHotUpdate()
        elif self.__workType == ToolForm.WorkType.Timer or self.__workType == ToolForm.WorkType.HotUpdate:
            self.__StopHotUpdate()
        elif self.__workType == ToolForm.WorkType.Compile:
            pass

    def __HotUpdateTimerElapsed(self):
        time = self.StartTimerSpinBox.value()
        if time <= 0:
            self.StartTimerCheckBox.setChecked(False)
            self.__hotUpdateTimer.stop()
            self.__StartHotUpdateWorkThread()
            return
        self.StartTimerSpinBox.setValue(time-1)

    def __StartHotUpdate(self):
        self.TabWidget.setEnabled(False)
        self.StartButton.setText("停止")
        if self.StartTimerCheckBox.isChecked():
            self.__workType = ToolForm.WorkType.Timer
            self.__hotUpdateTimer.start(1000)
        else:
            self.__workType = ToolForm.WorkType.HotUpdate
            self.__StartHotUpdateWorkThread()

    def __StopHotUpdate(self):
        if self.__workType == ToolForm.WorkType.Timer:
            self.OnHotUpdateFinished()
        elif self.__workType == ToolForm.WorkType.HotUpdate:
            if QMessageBox.Yes == QMessageBox.warning(
                self, "警告", "除非你明确知道你在做什么，否则不建议停止当前的操作，仍然要停止吗？",
                QMessageBox.Yes | QMessageBox.No, QMessageBox.No
            ):
                if self.__hotUpdateWorker.isRunning():
                    self.__hotUpdateWorker.exit(1)

    def __StartHotUpdateWorkThread(self):
        self.__hotUpdateWorker.ModuleNames = self.__GetModuleNames()
        self.__hotUpdateWorker.start()

    def OnHotUpdateFinished(self):
        self.StartTimerCheckBox.setChecked(False)
        self.__hotUpdateTimer.stop()
        self.TabWidget.setEnabled(True)
        self.StartButton.setText("开始")
        self.ProgressBar.setValue(0)
        self.__workType = ToolForm.WorkType.Idle

    @staticmethod
    def __GetTreeItemPath(item: QTreeWidgetItem) -> str:
        path = ""
        while True:
            parent = item.parent()
            if not parent:
                break
            if path:
                path = os.path.join(item.text(0), path)
            else:
                path = item.text(0)
            item = parent
        return path

    def __SetupUiByManual(self):
        self.__verRBtn.append(self.V1RadioButton)
        self.__verRBtn.append(self.V2RadioButton)
        self.__verRBtn.append(self.V3RadioButton)
        self.__verRBtn.append(self.V4RadioButton)
        self.__verSBox.append(self.V1SpinBox)
        self.__verSBox.append(self.V2SpinBox)
        self.__verSBox.append(self.V3SpinBox)
        self.__verSBox.append(self.V4SpinBox)

        # 一些预览文本、图像、压缩文件的控件。
        self.TextBrowser = QTextBrowser(self.TabHotUpdate)
        self.TextBrowser.hide()
        self.ImageLabel = QLabel(self.TabHotUpdate)
        self.ImageLabel.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.ImageLabel.hide()
        self.VideoWidget = QVideoWidget(self.TabHotUpdate)
        self.VideoWidget.hide()
        self.MediaPlayList = QMediaPlaylist(self.TabHotUpdate)
        self.MediaPlayer = QMediaPlayer(self.TabHotUpdate)
        self.MediaPlayer.setVideoOutput(self.VideoWidget)
        self.MediaPlayer.setPlaylist(self.MediaPlayList)
        self.ZipTreeView = QTreeWidget(self.TabHotUpdate)
        self.ZipTreeView.hide()

        self.SettingWidget.resizeEvent = self.__OnSettingWidgetGeometryChangedEvent
        self.SettingWidget.moveEvent = self.__OnSettingWidgetGeometryChangedEvent
        self.ModuleTreeWidget.itemExpanded.connect(self.__OnModuleTreeExpandedEvent)
        self.ModuleTreeWidget.currentItemChanged.connect(self.__OnModuleTreeItemSelectedEvent)
        self.ModuleTreeWidget.itemChanged.connect(self.__OnModuleTreeItemCheckedEvent)
        self.StartTimerCheckBox.stateChanged.connect(self.__OnStartTimerCheckBoxCheckedEvent)
        self.SelectAllButton.clicked.connect(self.__OnSelectAllButtonClickedEvent)
        self.SelectOtherButton.clicked.connect(self.__OnSelectOtherButtonClickedEvent)
        self.ManageModuleButton.clicked.connect(self.__OnManageModuleButtonClickedEvent)

        for rb in self.__verRBtn:
            rb.toggled.connect(self.__OnVersionRadioButtonToggledEvent)
        for sb in self.__verSBox:
            sb.valueChanged.connect(self.__OnVersionSpinBoxChangedEvent)

        self.NoUploadCheckBox.stateChanged.connect(self.__OnNoUploadCheckBoxCheckedEvent)
        self.UploadDiffHashCheckBox.stateChanged.connect(self.__OnUploadDiffHashCheckBoxCheckedEvent)
        self.UploadZipCheckBox.stateChanged.connect(self.__OnUploadZipCheckBoxCheckedEvent)
        self.FtpAccountLineEdit.textEdited.connect(self.__OnFtpAccountLineEditEditedEvent)
        self.FtpPasswordLineEdit.textEdited.connect(self.__OnFtpPasswordLineEditEditedEvent)

        self.UncomperssZipCheckBox.stateChanged.connect(self.__OnUncomperssZipCheckBoxCheckedEvent)
        self.EncryptResCheckBox.stateChanged.connect(self.__OnEncryptResCheckBoxCheckedEvent)
        self.EncryptResPasswordLineEdit.textEdited.connect(self.__OnEncryptResPasswordLineEditEditedEvent)
        self.CompressImgCheckBox.stateChanged.connect(self.__OnCompressImgCheckBoxCheckedEvent)
        self.MinQualitySpinBox.valueChanged.connect(self.__OnMinQualitySpinBoxChangedEvent)
        self.MaxQualitySpinBox.valueChanged.connect(self.__OnMaxQualitySpinBoxChangedEvent)
        self.CompileLuaCheckBox.stateChanged.connect(self.__OnCompileLuaCheckBoxCheckedEvent)

        self.DownloadFilterComboBox.currentIndexChanged.connect(self.__OnDownloadFilterComboBoxChangedEvent)
        self.NumFilterCheckBox.stateChanged.connect(self.__OnNumFilterCheckBoxCheckedEvent)
        self.SizeFilterCheckBox.stateChanged.connect(self.__OnSizeFilterCheckBoxCheckedEvent)
        self.NumFilterSpinBox.valueChanged.connect(self.__OnNumFilterSpinBoxChangedEvent)
        self.SizeFilterSpinBox.valueChanged.connect(self.__OnSizeFilterSpinBoxChangedEvent)

        self.UniqueConfigCheckBox.stateChanged.connect(self.__OnUniqueConfigCheckBoxCheckedEvent)
        self.SaveOnExitCheckBox.stateChanged.connect(self.__OnSaveOnExitCheckBoxCheckedEvent)

        self.StartButton.clicked.connect(self.__OnStartButtonClickedEvent)

    def UpdateTreeView(self):
        self.ModuleTreeWidget.clear()
        for name, module in self.__moduleConfig.modules.items():
            self.__CreateModuleTreeItem(name, module)
        self.__HideInfoView()

    def __UpdateModuleView(self):
        module = self.__GetModule()
        if not module:
            return
        self.__UpdateModuleVersionInfo(module)
        self.__UpdateModuleUploadInfo(module)
        self.__UpdateModuleResourceInfo(module)
        self.__UpdateModuleDownloadInfo(module)
        self.__UpdateModuleOtherInfo()

    def __UpdateModuleVersionInfo(self, module: Template.Module):
        versionType = module.versionType
        versionStr = module.useVersion
        if isinstance(versionType, int) and versionType >= 0 and versionType < len(self.__verRBtn):
            self.__verRBtn[versionType].setChecked(True)

        vList = versionStr.split(".")
        for idx in range(0, 4):
            ver = 0
            if idx < len(vList):
                ver = vList[idx]
                try:
                    ver = int(ver)
                except:
                    ver = 0
            self.__verSBox[idx].setValue(ver)

    def __UpdateModuleUploadInfo(self, module: Template.Module):
        self.UploadDiffHashCheckBox.setChecked(module.onlyHashDiff)
        self.UploadZipCheckBox.setChecked(module.compressUpload)
        self.NoUploadCheckBox.setChecked(module.noUpload)
        self.FtpAccountLineEdit.setText(module.ftpAccount)
        self.FtpPasswordLineEdit.setText(module.ftpPassword)

    def __UpdateModuleResourceInfo(self, module: Template.Module):
        self.UncomperssZipCheckBox.setChecked(module.zipUncompress)
        self.EncryptResCheckBox.setChecked(module.encryptRes)
        self.EncryptResPasswordLineEdit.setText(module.encryptPassword)
        self.CompressImgCheckBox.setChecked(module.compressPic)
        self.MinQualitySpinBox.setValue(module.compressQualityMin)
        self.MaxQualitySpinBox.setValue(module.compressQualityMax)
        self.CompileLuaCheckBox.setChecked(module.compileLua)

    def __UpdateModuleDownloadInfo(self, module: Template.Module):
        self.DownloadFilterComboBox.setCurrentIndex(module.filterType)
        self.NumFilterCheckBox.setChecked(module.openFilterNum)
        self.SizeFilterCheckBox.setChecked(module.openFilterSize)
        self.NumFilterSpinBox.setValue(module.filterNum)
        self.SizeFilterSpinBox.setValue(module.filterSize / 1024 / 1024)

    def __UpdateModuleOtherInfo(self):
        self.UniqueConfigCheckBox.setChecked(self.__moduleConfig.useUniConfig)
        self.SaveOnExitCheckBox.setChecked(self.__moduleConfig.exitSave)

    def __StopPreview(self):
        self.TextBrowser.setText("")
        self.ImageLabel.clear()
        self.MediaPlayer.stop()
        self.MediaPlayList.clear()
        self.ZipTreeView.clear()

        self.TextBrowser.hide()
        self.ImageLabel.hide()
        self.VideoWidget.hide()
        self.ZipTreeView.hide()

    def __HideInfoView(self):
        self.SettingWidget.hide()
        self.__StopPreview()

    def __CreateModuleTreeItem(self, name, module: Template.Module):
        icon = QIcon()
        icon.addPixmap(QPixmap(":/res/IcoModule.ico"), QIcon.Normal, QIcon.On)
        tItem = QTreeWidgetItem(self.ModuleTreeWidget, [name])
        tItem.setCheckState(0, Qt.Unchecked)
        tItem.setIcon(0, icon)

        tItem.name = name
        tItem.itemType = ToolForm.TreeItemType.Module
        tItem.module = module

        # 并不将子节点一次性全部添加，暂时添加一个空的占位节点。
        # 在首次展开时，才添加真正的节点。
        if len(module.dirs) > 0 or len(module.files) > 0:
            tItem.expanded = False
            tItem.addChild(QTreeWidgetItem())
        else:
            tItem.expanded = True

    def __CreateSubTreeItem(self, parent, path: str, absPath=False):
        if not os.path.exists(path):
            return
        tItem = QTreeWidgetItem(parent, [path if absPath else os.path.basename(path)])

        if os.path.isdir(path):
            tItem.itemType = ToolForm.TreeItemType.Dir
            tItem.setFlags(QtCore.Qt.ItemIsEnabled)
            tItem.setIcon(0, self.__fip.icon(QFileIconProvider.Folder))
            # 并不将子节点一次性全部添加，暂时添加一个空的占位节点。
            # 在首次展开时，才添加真正的节点。
            if len(os.listdir(path)) > 0:
                tItem.expanded = False
                tItem.addChild(QTreeWidgetItem())
            else:
                tItem.expanded = True
        else:
            tItem.setIcon(0, self.__fip.icon(QFileInfo(path)))
            if path.endswith(".lua") or path.endswith(".json") or path.endswith(".txt"):
                tItem.itemType = ToolForm.TreeItemType.Text
            elif path.endswith(".ogg") or path.endswith(".wav") or path.endswith(".mp3") or path.endswith(".mp4"):
                tItem.itemType = ToolForm.TreeItemType.Media
            elif path.endswith(".png") or path.endswith(".jpg") or path.endswith(".jpeg") or path.endswith(".ico") or path.endswith(".bmp"):
                tItem.itemType = ToolForm.TreeItemType.Image
            else:
                tItem.itemType = ToolForm.TreeItemType.File

    def __GetModule(self):
        if self.__moduleConfig.useUniConfig:
            return self.__moduleConfig.uniModule

        item: QTreeWidget = self.ModuleTreeWidget.currentItem()
        if item:
            return item.module
        return None

    def __GetModuleNames(self):
        moduleNames: List[str] = []
        for col in range(0, self.ModuleTreeWidget.topLevelItemCount()):
            idxItem: QTreeWidgetItem = self.ModuleTreeWidget.topLevelItem(col)
            if idxItem.checkState(0) == Qt.Checked:
                moduleNames.append(idxItem.text(0))
        return moduleNames

    @property
    def ModuleConfig(self):
        return self.__moduleConfig


class HotUpdateWorkThread(QThread):
    progressSignal = pyqtSignal(int)

    def __init__(self, parent: typing.Optional[QObject], assistant: Assistant) -> None:
        super().__init__(parent=parent)
        self.__assistant = assistant
        self.__moduleNames: List[str] = []
        self.finished.connect(parent.OnHotUpdateFinished)

    def run(self):
        pass

    @property
    def ModuleNames(self):
        return self.__moduleNames

    @ModuleNames.setter
    def ModuleNames(self, mn: List[str]):
        self.__moduleNames = mn


class ModuleMgrDlg(QDialog, Ui_ModuleMgrDlg):
    def __init__(self, parent: ToolForm) -> None:
        super().__init__(parent, Qt.WindowType.Window)
        self.setupUi(self)

        self.__modules = parent.ModuleConfig.modules
        self.__SetupUiByManual()

    def __SetupUiByManual(self):
        self.ModuleListWidget.currentItemChanged.connect(self.__OnModuleListItemSelectedEvent)
        self.__InitWithModules()
        self.ModuleListWidget.itemChanged.connect(self.__OnModuleListItemChangedEvent)

        self.NewModuleButton.clicked.connect(self.__OnNewModuleButtonClickedEvent)
        self.DelModuleButton.clicked.connect(self.__OnDelModuleButtonClickedEvent)

        self.InfoTableWidget.itemChanged.connect(self.__OnInfoTableItemChangedEvent)

        self.DirsListWidget.currentItemChanged.connect(self.__OnDirsListItemSelectedEvent)
        self.FilesListWidget.currentItemChanged.connect(self.__OnFilesListItemSelectedEvent)

        self.DelDirButton.clicked.connect(self.__OnDelDirButtonClickedEvent)
        self.DelFileButton.clicked.connect(self.__OnDelFileButtonClickedEvent)

        self.NewDirButton.clicked.connect(self.__OnNewDirButtonClickedEvent)
        self.NewFileButton.clicked.connect(self.__OnNewFileButtonClickedEvent)

    def closeEvent(self, a0: QtGui.QCloseEvent) -> None:
        super().closeEvent(a0)
        self.parent().UpdateTreeView()

    def __OnModuleListItemChangedEvent(self, item: QListWidgetItem):
        for idx in range(0, self.ModuleListWidget.count()):
            lItem = self.ModuleListWidget.item(idx)
            if lItem != item and item.text() == lItem.text():
                item.setText(item.name)
                break
        else:
            oldName = item.name
            newName = item.text()
            item.name = newName
            self.__modules[newName] = self.__modules[oldName]
            del self.__modules[oldName]

    def __OnInfoTableItemChangedEvent(self, item: QTableWidgetItem):
        modules = self.__GetModule()
        if not modules:
            return
        row: int = item.row()
        header: QTableWidgetItem = self.InfoTableWidget.verticalHeaderItem(row)
        modules.__dict__[header.text()] = item.text()

    def __OnModuleListItemSelectedEvent(self, cur: QListWidgetItem, _):
        self.DelModuleButton.setEnabled(cur != None)
        self.ModuleInfoTabWidget.setEnabled(cur != None)
        if cur:
            self.__ShowInfo()
        else:
            self.__ClearInfo()

    def __OnDirsListItemSelectedEvent(self, cur: QListWidgetItem, _):
        self.DelDirButton.setEnabled(cur != None)

    def __OnFilesListItemSelectedEvent(self, cur: QListWidgetItem, _):
        self.DelFileButton.setEnabled(cur != None)

    def __OnNewModuleButtonClickedEvent(self, _):
        self.__PushNewModule()

    def __OnDelModuleButtonClickedEvent(self, _):
        self.__DelModule()

    def __OnDelDirButtonClickedEvent(self, _):
        self.__DelDir()

    def __OnDelFileButtonClickedEvent(self, _):
        self.__DelFile()

    def __OnNewDirButtonClickedEvent(self, _):
        self.__PushNewDir()

    def __OnNewFileButtonClickedEvent(self, _):
        self.__PushNewFile()

    def __InitWithModules(self):
        self.ModuleListWidget.clear()
        for name, module in self.__modules.items():
            self.__PushModule(name, module)
        else:
            self.ModuleListWidget.setCurrentItem(self.ModuleListWidget.item(0))

    def __PushModule(self, name: str, module: Template.Module):
        listItem = QListWidgetItem(name, self.ModuleListWidget)
        listItem.setFlags(listItem.flags() | QtCore.Qt.ItemIsEditable)
        listItem.name = name
        listItem.module = module

    def __PushNewModule(self):
        listItem = QListWidgetItem(self.ModuleListWidget)
        listItem.setFlags(listItem.flags() | QtCore.Qt.ItemIsEditable)
        name = "新建模块"
        idx = 1
        while True:
            if name not in self.__modules.keys():
                break
            else:
                name = "新建模块" + str(idx)
                idx += 1

        self.__modules[name] = Template.Module()
        listItem.setText(name)
        listItem.name = name
        listItem.module = self.__modules[name]
        self.ModuleListWidget.setCurrentItem(listItem)

    def __DelModule(self):
        item = self.ModuleListWidget.currentItem()
        if item:
            if item.name in self.__modules.keys():
                del self.__modules[item.name]
                self.ModuleListWidget.takeItem(self.ModuleListWidget.row(item))

    def __DelDir(self):
        item: QListWidgetItem = self.DirsListWidget.currentItem()
        if not item:
            return
        row = self.DirsListWidget.row(item)
        self.DirsListWidget.takeItem(row)

        module = self.__GetModule()
        if not module:
            return
        module.dirs.pop(row)

    def __DelFile(self):
        item: QListWidgetItem = self.FilesListWidget.currentItem()
        if not item:
            return
        row = self.FilesListWidget.row(item)
        self.FilesListWidget.takeItem(row)

        module = self.__GetModule()
        if not module:
            return
        module.files.pop(row)

    def __PushNewDir(self):
        dName = QFileDialog.getExistingDirectory(
            self, "选择一个新的目录加入到当前模块：",
            os.getcwd()
        )
        error: str = self.__CheckItemLegality(dName)
        if error != ModuleMgrDlg.LegalityError.Ok:
            QMessageBox.warning(
                self, "警告", error.format("目录"),
                QMessageBox.Ok, QMessageBox.Ok
            )
            return
        rel = os.path.relpath(dName)
        module = self.__GetModule()
        module.dirs.append(rel)
        QListWidgetItem(rel, self.DirsListWidget)

        excludeFiles = []
        for dir in module.dirs:
            for file in module.files:
                if ModuleMgrDlg.__CheckDirContain(dir, file):
                    excludeFiles.append(file)
        module.files = [file for file in module.files if file not in excludeFiles]
        self.FilesListWidget.clear()
        for file in module.files:
            QListWidgetItem(file, self.FilesListWidget)

    def __PushNewFile(self):
        fName, _ = QFileDialog.getOpenFileName(
            self, "选择一个新的文件加入到当前模块：",
            os.getcwd(), "所有文件 (*)"
        )

        error: str = self.__CheckItemLegality(fName)
        if error != ModuleMgrDlg.LegalityError.Ok:
            QMessageBox.warning(
                self, "警告", error.format("文件"),
                QMessageBox.Ok, QMessageBox.Ok
            )
            return

        rel = os.path.relpath(fName)
        module = self.__GetModule()
        module.files.append(rel)
        QListWidgetItem(rel, self.FilesListWidget)

    @staticmethod
    def __CheckDirContain(dir, file):
        absDir: str = os.path.abspath(dir)
        absFile: str = os.path.abspath(file)
        return absFile.startswith(absDir)

    class LegalityError():
        Same = "该{}已重复。"
        Outside = "选取的{}必须位于当前目录下。"
        Contained = "该{}已包含于其它目录中。"
        Unknow = "{}未知错误。"
        Ok = ""

    def __CheckItemLegality(self, item):
        iRel = os.path.relpath(item)
        if iRel.startswith(".."):
            return ModuleMgrDlg.LegalityError.Outside
        module = self.__GetModule()
        if not module:
            return ModuleMgrDlg.LegalityError.Unknow
        for mItem in module.files + module.dirs:
            rel = os.path.relpath(mItem, item)
            if rel == ".":
                return ModuleMgrDlg.LegalityError.Same
        for dir in module.dirs:
            if ModuleMgrDlg.__CheckDirContain(dir, item):
                return ModuleMgrDlg.LegalityError.Contained

        return ModuleMgrDlg.LegalityError.Ok

    def __GetModule(self) -> Template.Module:
        item = self.ModuleListWidget.currentItem()
        if item:
            return item.module
        return None

    def __ClearInfo(self):
        for idx in range(0, self.InfoTableWidget.rowCount()):
            item: QTableWidgetItem = self.InfoTableWidget.item(idx, 0)
            item.setText("")
        self.DirsListWidget.clear()
        self.FilesListWidget.clear()

    def __ShowInfo(self):
        self.__ClearInfo()
        module = self.__GetModule()
        for idx in range(0, self.InfoTableWidget.rowCount()):
            vItem: QTableWidgetItem = self.InfoTableWidget.verticalHeaderItem(idx)
            item: QTableWidgetItem = self.InfoTableWidget.item(idx, 0)
            item.setText(module.__dict__.get(vItem.text(), ""))
        for dir in module.dirs:
            QListWidgetItem(dir, self.DirsListWidget)
        for file in module.files:
            QListWidgetItem(file, self.FilesListWidget)
