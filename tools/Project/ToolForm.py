
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

from Scripts.Assistant import Assistant
import os
import sys
from enum import Enum, auto
from typing import Dict
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import QFileInfo, QUrl, Qt
from PyQt5.QtWidgets import QDialog, QFileIconProvider, QLabel, QListWidgetItem, QTreeWidgetItem, QTreeWidget, QWidget, QFileDialog, QMessageBox, QTextBrowser
from PyQt5.QtMultimedia import QMediaContent, QMediaPlayer, QMediaPlaylist
from PyQt5.QtMultimediaWidgets import QVideoWidget
from UI_ToolForm import Ui_ToolForm
from UI_ModuleMgrDlg import Ui_ModuleMgrDlg
from Scripts import Functions, Template


class TreeItemType(Enum):
    Dir = auto(),
    File = auto(),
    Image = auto(),
    Text = auto(),
    Module = auto(),
    Media = auto(),
    Error = auto()


class ToolForm(QWidget, Ui_ToolForm):
    ModuleFileName = "Module.json"

    def __init__(self) -> None:
        super().__init__()
        self.setupUi(self)
        self.__modulePath = ""
        self.__moduleConfig = None
        if not self.__ReadConfig():
            sys.exit()
        self.__fip = QFileIconProvider()
        self.__Assistant = Assistant(self.__modulePath, self.__moduleConfig)
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
                os.chdir(os.path.dirname(fName))
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
                        os.chdir(fPath)
                        if Functions.SaveJson(ToolForm.ModuleFileName, self.__moduleConfig):
                            self.__modulePath = os.path.dirname(ToolForm.ModuleFileName)
                            return True
                return False

        self.__moduleConfig: Template.ConfigTemplate = Functions.LoadJson(
            ToolForm.ModuleFileName, object_hook=Template.ConfigTemplate.FromJson)

        if self.__moduleConfig != None:
            self.__modulePath = os.path.dirname(ToolForm.ModuleFileName)
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
        if item.itemType == TreeItemType.Error:
            return
        elif item.itemType == TreeItemType.Module:
            for path in item.module.dirs + item.module.files:
                self.__CreateSubTreeItem(item, path, True)
        elif item.itemType == TreeItemType.Dir:
            itemPath = ToolForm.GetTreeItemPath(item)
            for path in os.listdir(itemPath):
                self.__CreateSubTreeItem(item, os.path.join(itemPath, path))

    def __OnModuleTreeItemSelectedEvent(self, item: QTreeWidgetItem, _):
        if item == None:
            self.__HideInfoView()
        elif item.itemType == TreeItemType.Module:
            self.__StopPreview()
            self.SettingWidget.show()
        else:
            itemPath = ToolForm.GetTreeItemPath(item)
            self.__HideInfoView()
            if not os.path.isfile(itemPath):
                return
            if item.itemType == TreeItemType.Text:
                try:
                    with open(itemPath, "rb") as file:
                        self.TextBrowser.setText(file.read().decode("utf8"))
                except:
                    return
                self.TextBrowser.show()
            elif item.itemType == TreeItemType.Image:
                pix = QPixmap(itemPath)
                iWidth = self.ImageLabel.width()
                iHeight = self.ImageLabel.height()
                if pix.width() > iWidth or pix.height() > iHeight:
                    pix = pix.scaled(iWidth, iHeight, Qt.AspectRatioMode.KeepAspectRatio)
                self.ImageLabel.setPixmap(pix)
                self.ImageLabel.show()
            elif item.itemType == TreeItemType.Media:
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

    def __OnStartTimerCheckedEvent(self, state: int):
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

    @staticmethod
    def GetTreeItemPath(item: QTreeWidgetItem) -> str:
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
        self.StartTimerCheckBox.stateChanged.connect(self.__OnStartTimerCheckedEvent)
        self.SelectAllButton.clicked.connect(self.__OnSelectAllButtonClickedEvent)
        self.SelectOtherButton.clicked.connect(self.__OnSelectOtherButtonClickedEvent)
        self.ManageModuleButton.clicked.connect(self.__OnManageModuleButtonClickedEvent)

    def UpdateTreeView(self):
        self.ModuleTreeWidget.clear()
        for name, module in self.__moduleConfig.modules.items():
            self.__CreateModuleTreeItem(name, module)
        self.__HideInfoView()

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
        tItem = QTreeWidgetItem(self.ModuleTreeWidget)
        tItem.setText(0, "<" + name + ">")
        tItem.setCheckState(0, Qt.Unchecked)
        tItem.setIcon(0, icon)

        tItem.name = name
        tItem.itemType = TreeItemType.Module
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
        tItem = QTreeWidgetItem(parent)
        tItem.setText(0, path if absPath else os.path.basename(path))

        if os.path.isdir(path):
            tItem.itemType = TreeItemType.Dir
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
                tItem.itemType = TreeItemType.Text
            elif path.endswith(".ogg") or path.endswith(".wav") or path.endswith(".mp3") or path.endswith(".mp4"):
                tItem.itemType = TreeItemType.Media
            elif path.endswith(".png") or path.endswith(".jpg") or path.endswith(".jpeg") or path.endswith(".ico") or path.endswith(".bmp"):
                tItem.itemType = TreeItemType.Image
            else:
                tItem.itemType = TreeItemType.File

    @property
    def ModuleConfig(self):
        return self.__moduleConfig


class ModuleMgrDlg(QDialog, Ui_ModuleMgrDlg):
    def __init__(self, parent: ToolForm) -> None:
        super().__init__(parent, Qt.WindowType.Window)
        self.setupUi(self)

        self.__modules = parent.ModuleConfig.modules
        self.__SetupUiByManual()
        self.__InitWithModules()

    def __SetupUiByManual(self):
        self.ModuleListWidget.__editingItem = None
        self.ModuleListWidget.itemDoubleClicked.connect(self.__OnModuleListItemDoubleClickedEvent)
        self.ModuleListWidget.currentItemChanged.connect(self.__OnModuleListItemSelectedEvent)
        self.ModuleListWidget.focusInEvent = self.__OnModuleListFocusInEvent

        self.NewModuleButton.clicked.connect(self.__OnNewModuleButtonClickedEvent)
        self.DelModuleButton.clicked.connect(self.__OnDelModuleButtonClickedEvent)

    def closeEvent(self, a0: QtGui.QCloseEvent) -> None:
        super().closeEvent(a0)
        self.parent().UpdateTreeView()

    def __OnModuleListItemSelectedEvent(self, cur: QListWidgetItem, _):
        self.DelModuleButton.setEnabled(cur != None)

    def __OnModuleListFocusInEvent(self, _):
        self.__CloseModuleEdit()

    def __OnModuleListItemDoubleClickedEvent(self, item: QListWidgetItem):
        self.__EnterModuleEdit(item)

    def __OnNewModuleButtonClickedEvent(self, _):
        self.__CloseModuleEdit()
        self.__PushNewModule()

    def __OnDelModuleButtonClickedEvent(self, _):
        self.__CloseModuleEdit()
        self.__DelModule()

    def __EnterModuleEdit(self, item: QListWidgetItem):
        self.__CloseModuleEdit()
        self.ModuleListWidget.__editingItem = item
        self.ModuleListWidget.openPersistentEditor(item)
        self.ModuleListWidget.editItem(item)

    def __CloseModuleEdit(self):
        if self.ModuleListWidget.__editingItem and self.ModuleListWidget.isPersistentEditorOpen(self.ModuleListWidget.__editingItem):
            self.ModuleListWidget.closePersistentEditor(self.ModuleListWidget.__editingItem)
            preText = self.ModuleListWidget.__editingItem.name
            curText = self.ModuleListWidget.__editingItem.text()
            if curText and (curText not in self.__modules.keys()):
                self.__modules[curText] = self.__modules[preText]
                del self.__modules[preText]
                self.ModuleListWidget.__editingItem.name = curText
            else:
                self.ModuleListWidget.__editingItem.setText(preText)

            self.ModuleListWidget.__editingItem = None

    def __InitWithModules(self):
        self.ModuleListWidget.clear()
        for name, module in self.__modules.items():
            self.__PushModule(name, module)
        else:
            self.ModuleListWidget.setCurrentItem(self.ModuleListWidget.item(0))

    def __PushModule(self, name: str, module: Template.Module):
        listItem = QListWidgetItem(self.ModuleListWidget)
        listItem.setText(name)
        listItem.name = name
        listItem.module = module

    def __PushNewModule(self):
        listItem = QListWidgetItem(self.ModuleListWidget)
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

    def __DelModule(self):
        item = self.ModuleListWidget.currentItem()
        if item:
            self.__CloseModuleEdit()
            if item.name in self.__modules.keys():
                del self.__modules[item.name]
                self.ModuleListWidget.takeItem(self.ModuleListWidget.row(item))
