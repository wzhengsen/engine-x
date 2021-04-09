# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'ToolForm.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

import UI_rc

class Ui_ToolForm(object):
    def setupUi(self, ToolForm):
        if not ToolForm.objectName():
            ToolForm.setObjectName(u"ToolForm")
        ToolForm.setWindowModality(Qt.WindowModal)
        ToolForm.resize(600, 400)
        sizePolicy = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(ToolForm.sizePolicy().hasHeightForWidth())
        ToolForm.setSizePolicy(sizePolicy)
        ToolForm.setMinimumSize(QSize(600, 400))
        ToolForm.setMaximumSize(QSize(600, 400))
        icon = QIcon()
        icon.addFile(u":/res/IcoMain.ico", QSize(), QIcon.Normal, QIcon.On)
        ToolForm.setWindowIcon(icon)
        self.verticalLayout_2 = QVBoxLayout(ToolForm)
        self.verticalLayout_2.setSpacing(2)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.TabWidget = QTabWidget(ToolForm)
        self.TabWidget.setObjectName(u"TabWidget")
        self.TabHotUpdate = QWidget()
        self.TabHotUpdate.setObjectName(u"TabHotUpdate")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.TabHotUpdate.sizePolicy().hasHeightForWidth())
        self.TabHotUpdate.setSizePolicy(sizePolicy1)
        self.verticalLayout = QVBoxLayout(self.TabHotUpdate)
        self.verticalLayout.setSpacing(2)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_6 = QGridLayout()
        self.gridLayout_6.setObjectName(u"gridLayout_6")
        self.gridLayout_6.setHorizontalSpacing(2)
        self.gridLayout_6.setContentsMargins(0, 0, 0, 0)
        self.ModuleTreeWidget = QTreeWidget(self.TabHotUpdate)
        __qtreewidgetitem = QTreeWidgetItem()
        __qtreewidgetitem.setText(0, u"1");
        self.ModuleTreeWidget.setHeaderItem(__qtreewidgetitem)
        self.ModuleTreeWidget.setObjectName(u"ModuleTreeWidget")
        self.ModuleTreeWidget.setSelectionBehavior(QAbstractItemView.SelectItems)
        self.ModuleTreeWidget.header().setVisible(False)

        self.gridLayout_6.addWidget(self.ModuleTreeWidget, 0, 0, 1, 1)

        self.SettingWidget = QWidget(self.TabHotUpdate)
        self.SettingWidget.setObjectName(u"SettingWidget")
        self.gridLayout_3 = QGridLayout(self.SettingWidget)
        self.gridLayout_3.setSpacing(2)
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.gridLayout_3.setContentsMargins(0, 0, 0, 0)
        self.UploadGroupBox = QGroupBox(self.SettingWidget)
        self.UploadGroupBox.setObjectName(u"UploadGroupBox")
        self.gridLayout_2 = QGridLayout(self.UploadGroupBox)
        self.gridLayout_2.setSpacing(2)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.NoUploadCheckBox = QCheckBox(self.UploadGroupBox)
        self.NoUploadCheckBox.setObjectName(u"NoUploadCheckBox")
        sizePolicy.setHeightForWidth(self.NoUploadCheckBox.sizePolicy().hasHeightForWidth())
        self.NoUploadCheckBox.setSizePolicy(sizePolicy)

        self.gridLayout_2.addWidget(self.NoUploadCheckBox, 0, 0, 1, 1)

        self.UploadDiffHashCheckBox = QCheckBox(self.UploadGroupBox)
        self.UploadDiffHashCheckBox.setObjectName(u"UploadDiffHashCheckBox")
        self.UploadDiffHashCheckBox.setEnabled(True)
        sizePolicy.setHeightForWidth(self.UploadDiffHashCheckBox.sizePolicy().hasHeightForWidth())
        self.UploadDiffHashCheckBox.setSizePolicy(sizePolicy)
        self.UploadDiffHashCheckBox.setChecked(True)

        self.gridLayout_2.addWidget(self.UploadDiffHashCheckBox, 1, 0, 1, 1)

        self.UploadZipCheckBox = QCheckBox(self.UploadGroupBox)
        self.UploadZipCheckBox.setObjectName(u"UploadZipCheckBox")
        sizePolicy.setHeightForWidth(self.UploadZipCheckBox.sizePolicy().hasHeightForWidth())
        self.UploadZipCheckBox.setSizePolicy(sizePolicy)

        self.gridLayout_2.addWidget(self.UploadZipCheckBox, 2, 0, 1, 1)

        self.FtpAccountLineEdit = QLineEdit(self.UploadGroupBox)
        self.FtpAccountLineEdit.setObjectName(u"FtpAccountLineEdit")
        sizePolicy2 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.FtpAccountLineEdit.sizePolicy().hasHeightForWidth())
        self.FtpAccountLineEdit.setSizePolicy(sizePolicy2)
        self.FtpAccountLineEdit.setMaxLength(32)
        self.FtpAccountLineEdit.setClearButtonEnabled(True)

        self.gridLayout_2.addWidget(self.FtpAccountLineEdit, 3, 0, 1, 1)

        self.FtpPasswordLineEdit = QLineEdit(self.UploadGroupBox)
        self.FtpPasswordLineEdit.setObjectName(u"FtpPasswordLineEdit")
        sizePolicy2.setHeightForWidth(self.FtpPasswordLineEdit.sizePolicy().hasHeightForWidth())
        self.FtpPasswordLineEdit.setSizePolicy(sizePolicy2)
        self.FtpPasswordLineEdit.setMaxLength(32)
        self.FtpPasswordLineEdit.setClearButtonEnabled(True)

        self.gridLayout_2.addWidget(self.FtpPasswordLineEdit, 4, 0, 1, 1)


        self.gridLayout_3.addWidget(self.UploadGroupBox, 0, 2, 1, 1)

        self.VersionGroupBox = QGroupBox(self.SettingWidget)
        self.VersionGroupBox.setObjectName(u"VersionGroupBox")
        self.gridLayout = QGridLayout(self.VersionGroupBox)
        self.gridLayout.setSpacing(2)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.V3RadioButton = QRadioButton(self.VersionGroupBox)
        self.V3RadioButton.setObjectName(u"V3RadioButton")
        sizePolicy.setHeightForWidth(self.V3RadioButton.sizePolicy().hasHeightForWidth())
        self.V3RadioButton.setSizePolicy(sizePolicy)
        self.V3RadioButton.setChecked(True)

        self.gridLayout.addWidget(self.V3RadioButton, 0, 0, 1, 2)

        self.V2RadioButton = QRadioButton(self.VersionGroupBox)
        self.V2RadioButton.setObjectName(u"V2RadioButton")
        sizePolicy.setHeightForWidth(self.V2RadioButton.sizePolicy().hasHeightForWidth())
        self.V2RadioButton.setSizePolicy(sizePolicy)

        self.gridLayout.addWidget(self.V2RadioButton, 2, 0, 1, 3)

        self.V4RadioButton = QRadioButton(self.VersionGroupBox)
        self.V4RadioButton.setObjectName(u"V4RadioButton")
        sizePolicy.setHeightForWidth(self.V4RadioButton.sizePolicy().hasHeightForWidth())
        self.V4RadioButton.setSizePolicy(sizePolicy)

        self.gridLayout.addWidget(self.V4RadioButton, 3, 0, 1, 3)

        self.V1SpinBox = QSpinBox(self.VersionGroupBox)
        self.V1SpinBox.setObjectName(u"V1SpinBox")
        self.V1SpinBox.setEnabled(False)

        self.gridLayout.addWidget(self.V1SpinBox, 4, 0, 1, 1)

        self.V2SpinBox = QSpinBox(self.VersionGroupBox)
        self.V2SpinBox.setObjectName(u"V2SpinBox")
        self.V2SpinBox.setEnabled(False)

        self.gridLayout.addWidget(self.V2SpinBox, 4, 1, 1, 1)

        self.V3SpinBox = QSpinBox(self.VersionGroupBox)
        self.V3SpinBox.setObjectName(u"V3SpinBox")
        self.V3SpinBox.setEnabled(False)

        self.gridLayout.addWidget(self.V3SpinBox, 4, 2, 1, 1)

        self.V4SpinBox = QSpinBox(self.VersionGroupBox)
        self.V4SpinBox.setObjectName(u"V4SpinBox")
        self.V4SpinBox.setEnabled(False)

        self.gridLayout.addWidget(self.V4SpinBox, 4, 3, 1, 1)

        self.V1RadioButton = QRadioButton(self.VersionGroupBox)
        self.V1RadioButton.setObjectName(u"V1RadioButton")

        self.gridLayout.addWidget(self.V1RadioButton, 1, 0, 1, 3)


        self.gridLayout_3.addWidget(self.VersionGroupBox, 0, 1, 1, 1)

        self.DownloadGroupBox = QGroupBox(self.SettingWidget)
        self.DownloadGroupBox.setObjectName(u"DownloadGroupBox")
        self.DownloadFilterComboBox = QComboBox(self.DownloadGroupBox)
        self.DownloadFilterComboBox.addItem("")
        self.DownloadFilterComboBox.addItem("")
        self.DownloadFilterComboBox.setObjectName(u"DownloadFilterComboBox")
        self.DownloadFilterComboBox.setGeometry(QRect(2, 40, 51, 20))
        sizePolicy1.setHeightForWidth(self.DownloadFilterComboBox.sizePolicy().hasHeightForWidth())
        self.DownloadFilterComboBox.setSizePolicy(sizePolicy1)
        self.gridLayout_5 = QGridLayout(self.DownloadGroupBox)
        self.gridLayout_5.setSpacing(2)
        self.gridLayout_5.setObjectName(u"gridLayout_5")
        self.gridLayout_5.setContentsMargins(0, 0, 0, 0)
        self.label = QLabel(self.DownloadGroupBox)
        self.label.setObjectName(u"label")
        self.label.setEnabled(True)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setScaledContents(False)
        self.label.setMargin(0)
        self.label.setIndent(-1)

        self.gridLayout_5.addWidget(self.label, 0, 0, 1, 2)

        self.NumFilterCheckBox = QCheckBox(self.DownloadGroupBox)
        self.NumFilterCheckBox.setObjectName(u"NumFilterCheckBox")
        sizePolicy.setHeightForWidth(self.NumFilterCheckBox.sizePolicy().hasHeightForWidth())
        self.NumFilterCheckBox.setSizePolicy(sizePolicy)

        self.gridLayout_5.addWidget(self.NumFilterCheckBox, 1, 0, 1, 1)

        self.NumFilterSpinBox = QSpinBox(self.DownloadGroupBox)
        self.NumFilterSpinBox.setObjectName(u"NumFilterSpinBox")
        self.NumFilterSpinBox.setEnabled(False)
        sizePolicy3 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.NumFilterSpinBox.sizePolicy().hasHeightForWidth())
        self.NumFilterSpinBox.setSizePolicy(sizePolicy3)
        self.NumFilterSpinBox.setMaximum(9999)

        self.gridLayout_5.addWidget(self.NumFilterSpinBox, 1, 1, 1, 1)

        self.SizeFilterCheckBox = QCheckBox(self.DownloadGroupBox)
        self.SizeFilterCheckBox.setObjectName(u"SizeFilterCheckBox")
        sizePolicy.setHeightForWidth(self.SizeFilterCheckBox.sizePolicy().hasHeightForWidth())
        self.SizeFilterCheckBox.setSizePolicy(sizePolicy)

        self.gridLayout_5.addWidget(self.SizeFilterCheckBox, 2, 0, 1, 1)

        self.SizeFilterSpinBox = QDoubleSpinBox(self.DownloadGroupBox)
        self.SizeFilterSpinBox.setObjectName(u"SizeFilterSpinBox")
        self.SizeFilterSpinBox.setEnabled(False)
        sizePolicy3.setHeightForWidth(self.SizeFilterSpinBox.sizePolicy().hasHeightForWidth())
        self.SizeFilterSpinBox.setSizePolicy(sizePolicy3)
        self.SizeFilterSpinBox.setDecimals(2)

        self.gridLayout_5.addWidget(self.SizeFilterSpinBox, 2, 1, 1, 1)

        self.NumFilterCheckBox.raise_()
        self.NumFilterSpinBox.raise_()
        self.SizeFilterCheckBox.raise_()
        self.SizeFilterSpinBox.raise_()
        self.label.raise_()
        self.DownloadFilterComboBox.raise_()

        self.gridLayout_3.addWidget(self.DownloadGroupBox, 1, 2, 1, 1)

        self.GenerateGroupBox = QGroupBox(self.SettingWidget)
        self.GenerateGroupBox.setObjectName(u"GenerateGroupBox")
        self.gridLayout_4 = QGridLayout(self.GenerateGroupBox)
        self.gridLayout_4.setObjectName(u"gridLayout_4")
        self.gridLayout_4.setHorizontalSpacing(0)
        self.gridLayout_4.setVerticalSpacing(2)
        self.gridLayout_4.setContentsMargins(0, 0, 0, 0)
        self.UncomperssZipCheckBox = QCheckBox(self.GenerateGroupBox)
        self.UncomperssZipCheckBox.setObjectName(u"UncomperssZipCheckBox")
        sizePolicy.setHeightForWidth(self.UncomperssZipCheckBox.sizePolicy().hasHeightForWidth())
        self.UncomperssZipCheckBox.setSizePolicy(sizePolicy)

        self.gridLayout_4.addWidget(self.UncomperssZipCheckBox, 0, 0, 1, 2)

        self.EncryptResCheckBox = QCheckBox(self.GenerateGroupBox)
        self.EncryptResCheckBox.setObjectName(u"EncryptResCheckBox")
        self.EncryptResCheckBox.setChecked(True)

        self.gridLayout_4.addWidget(self.EncryptResCheckBox, 1, 0, 1, 2)

        self.EncryptResPasswordLineEdit = QLineEdit(self.GenerateGroupBox)
        self.EncryptResPasswordLineEdit.setObjectName(u"EncryptResPasswordLineEdit")
        sizePolicy.setHeightForWidth(self.EncryptResPasswordLineEdit.sizePolicy().hasHeightForWidth())
        self.EncryptResPasswordLineEdit.setSizePolicy(sizePolicy)
        self.EncryptResPasswordLineEdit.setMaxLength(16)
        self.EncryptResPasswordLineEdit.setClearButtonEnabled(True)

        self.gridLayout_4.addWidget(self.EncryptResPasswordLineEdit, 2, 0, 1, 2)

        self.CompressImgCheckBox = QCheckBox(self.GenerateGroupBox)
        self.CompressImgCheckBox.setObjectName(u"CompressImgCheckBox")
        self.CompressImgCheckBox.setChecked(True)

        self.gridLayout_4.addWidget(self.CompressImgCheckBox, 3, 0, 1, 2)

        self.MinQualitySpinBox = QSpinBox(self.GenerateGroupBox)
        self.MinQualitySpinBox.setObjectName(u"MinQualitySpinBox")
        sizePolicy.setHeightForWidth(self.MinQualitySpinBox.sizePolicy().hasHeightForWidth())
        self.MinQualitySpinBox.setSizePolicy(sizePolicy)
        self.MinQualitySpinBox.setMinimumSize(QSize(64, 20))
        self.MinQualitySpinBox.setMinimum(50)

        self.gridLayout_4.addWidget(self.MinQualitySpinBox, 4, 0, 1, 1)

        self.MaxQualitySpinBox = QSpinBox(self.GenerateGroupBox)
        self.MaxQualitySpinBox.setObjectName(u"MaxQualitySpinBox")
        sizePolicy.setHeightForWidth(self.MaxQualitySpinBox.sizePolicy().hasHeightForWidth())
        self.MaxQualitySpinBox.setSizePolicy(sizePolicy)
        self.MaxQualitySpinBox.setMinimum(85)

        self.gridLayout_4.addWidget(self.MaxQualitySpinBox, 4, 1, 1, 1, Qt.AlignLeft)

        self.CompileLuaCheckBox = QCheckBox(self.GenerateGroupBox)
        self.CompileLuaCheckBox.setObjectName(u"CompileLuaCheckBox")
        self.CompileLuaCheckBox.setChecked(True)

        self.gridLayout_4.addWidget(self.CompileLuaCheckBox, 5, 0, 1, 2)


        self.gridLayout_3.addWidget(self.GenerateGroupBox, 1, 1, 1, 1)

        self.OtherSettingGroupBox = QGroupBox(self.SettingWidget)
        self.OtherSettingGroupBox.setObjectName(u"OtherSettingGroupBox")
        sizePolicy.setHeightForWidth(self.OtherSettingGroupBox.sizePolicy().hasHeightForWidth())
        self.OtherSettingGroupBox.setSizePolicy(sizePolicy)
        self.horizontalLayout_5 = QHBoxLayout(self.OtherSettingGroupBox)
        self.horizontalLayout_5.setSpacing(2)
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.horizontalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.UniqueConfigCheckBox = QCheckBox(self.OtherSettingGroupBox)
        self.UniqueConfigCheckBox.setObjectName(u"UniqueConfigCheckBox")
        self.UniqueConfigCheckBox.setChecked(True)

        self.horizontalLayout_5.addWidget(self.UniqueConfigCheckBox)

        self.SaveOnExitCheckBox = QCheckBox(self.OtherSettingGroupBox)
        self.SaveOnExitCheckBox.setObjectName(u"SaveOnExitCheckBox")
        self.SaveOnExitCheckBox.setChecked(True)

        self.horizontalLayout_5.addWidget(self.SaveOnExitCheckBox)


        self.gridLayout_3.addWidget(self.OtherSettingGroupBox, 2, 1, 1, 2, Qt.AlignLeft)


        self.gridLayout_6.addWidget(self.SettingWidget, 0, 1, 1, 1)

        self.gridLayout_6.setColumnStretch(0, 4)
        self.gridLayout_6.setColumnStretch(1, 5)

        self.verticalLayout.addLayout(self.gridLayout_6)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setSpacing(2)
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setSpacing(2)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(2, 2, 2, 2)
        self.SelectAllButton = QPushButton(self.TabHotUpdate)
        self.SelectAllButton.setObjectName(u"SelectAllButton")
        icon1 = QIcon()
        icon1.addFile(u":/res/ImgPlus.png", QSize(), QIcon.Normal, QIcon.Off)
        self.SelectAllButton.setIcon(icon1)

        self.horizontalLayout_2.addWidget(self.SelectAllButton)

        self.SelectOtherButton = QPushButton(self.TabHotUpdate)
        self.SelectOtherButton.setObjectName(u"SelectOtherButton")
        icon2 = QIcon()
        icon2.addFile(u":/res/ImgDel.png", QSize(), QIcon.Normal, QIcon.Off)
        self.SelectOtherButton.setIcon(icon2)

        self.horizontalLayout_2.addWidget(self.SelectOtherButton)

        self.horizontalSpacer = QSpacerItem(1, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_2.addItem(self.horizontalSpacer)

        self.ManageModuleButton = QPushButton(self.TabHotUpdate)
        self.ManageModuleButton.setObjectName(u"ManageModuleButton")
        sizePolicy4 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy4.setHorizontalStretch(0)
        sizePolicy4.setVerticalStretch(0)
        sizePolicy4.setHeightForWidth(self.ManageModuleButton.sizePolicy().hasHeightForWidth())
        self.ManageModuleButton.setSizePolicy(sizePolicy4)
        icon3 = QIcon()
        icon3.addFile(u":/res/ImgGear.png", QSize(), QIcon.Normal, QIcon.Off)
        self.ManageModuleButton.setIcon(icon3)

        self.horizontalLayout_2.addWidget(self.ManageModuleButton)


        self.horizontalLayout_4.addLayout(self.horizontalLayout_2)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setSpacing(2)
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.horizontalLayout_3.setContentsMargins(2, 2, 2, 2)
        self.StartTimerCheckBox = QCheckBox(self.TabHotUpdate)
        self.StartTimerCheckBox.setObjectName(u"StartTimerCheckBox")

        self.horizontalLayout_3.addWidget(self.StartTimerCheckBox)

        self.StartTimerSpinBox = QSpinBox(self.TabHotUpdate)
        self.StartTimerSpinBox.setObjectName(u"StartTimerSpinBox")
        self.StartTimerSpinBox.setEnabled(False)
        self.StartTimerSpinBox.setWrapping(False)
        self.StartTimerSpinBox.setAlignment(Qt.AlignCenter)
        self.StartTimerSpinBox.setMaximum(100000)
        self.StartTimerSpinBox.setSingleStep(1800)

        self.horizontalLayout_3.addWidget(self.StartTimerSpinBox)

        self.horizontalSpacer_2 = QSpacerItem(1, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.horizontalLayout_3.addItem(self.horizontalSpacer_2)

        self.ClearTempButton = QPushButton(self.TabHotUpdate)
        self.ClearTempButton.setObjectName(u"ClearTempButton")
        icon4 = QIcon()
        icon4.addFile(u":/res/ImgClear.png", QSize(), QIcon.Normal, QIcon.Off)
        self.ClearTempButton.setIcon(icon4)

        self.horizontalLayout_3.addWidget(self.ClearTempButton)


        self.horizontalLayout_4.addLayout(self.horizontalLayout_3)

        self.horizontalLayout_4.setStretch(0, 4)
        self.horizontalLayout_4.setStretch(1, 5)

        self.verticalLayout.addLayout(self.horizontalLayout_4)

        self.verticalLayout.setStretch(0, 20)
        self.verticalLayout.setStretch(1, 1)
        self.TabWidget.addTab(self.TabHotUpdate, "")
        self.TabCompile = QWidget()
        self.TabCompile.setObjectName(u"TabCompile")
        self.TabWidget.addTab(self.TabCompile, "")

        self.verticalLayout_2.addWidget(self.TabWidget)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setSpacing(2)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.ProgressBar = QProgressBar(ToolForm)
        self.ProgressBar.setObjectName(u"ProgressBar")
        self.ProgressBar.setTextVisible(False)

        self.horizontalLayout.addWidget(self.ProgressBar)

        self.StartButton = QPushButton(ToolForm)
        self.StartButton.setObjectName(u"StartButton")
        self.StartButton.setEnabled(False)
        icon5 = QIcon()
        icon5.addFile(u":/res/ImgCheck.png", QSize(), QIcon.Normal, QIcon.Off)
        self.StartButton.setIcon(icon5)

        self.horizontalLayout.addWidget(self.StartButton)


        self.verticalLayout_2.addLayout(self.horizontalLayout)


        self.retranslateUi(ToolForm)

        self.TabWidget.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(ToolForm)
    # setupUi

    def retranslateUi(self, ToolForm):
        ToolForm.setWindowTitle(QCoreApplication.translate("ToolForm", u"\u5de5\u5177", None))
        self.UploadGroupBox.setTitle(QCoreApplication.translate("ToolForm", u"\u4e0a\u4f20\u914d\u7f6e", None))
        self.NoUploadCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u4e0d\u4e0a\u4f20\u6587\u4ef6", None))
        self.UploadDiffHashCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u4ec5\u4e0a\u4f20\u54c8\u5e0c\u4e0d\u540c\u7684\u6587\u4ef6", None))
        self.UploadZipCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u6587\u4ef6\u538b\u7f29\u540e\u4e0a\u4f20\uff08\u5c06\u9700\n"
"\u8981\u63a5\u6536\u7aef\u89e3\u538b\uff09", None))
        self.FtpAccountLineEdit.setPlaceholderText(QCoreApplication.translate("ToolForm", u"FTP\u8d26\u53f7", None))
        self.FtpPasswordLineEdit.setPlaceholderText(QCoreApplication.translate("ToolForm", u"FTP\u5bc6\u7801", None))
        self.VersionGroupBox.setTitle(QCoreApplication.translate("ToolForm", u"\u7248\u672c\u914d\u7f6e", None))
        self.V3RadioButton.setText(QCoreApplication.translate("ToolForm", u"\u7248\u672c\u4e0d\u53d8", None))
        self.V2RadioButton.setText(QCoreApplication.translate("ToolForm", u"\u4f7f\u7528\u672c\u5730\u7248\u672c+1", None))
        self.V4RadioButton.setText(QCoreApplication.translate("ToolForm", u"\u4f7f\u7528\u6307\u5b9a\u7248\u672c\uff1a", None))
        self.V1RadioButton.setText(QCoreApplication.translate("ToolForm", u"\u4f7f\u7528\u8fdc\u7a0b\u7248\u672c+1", None))
        self.DownloadGroupBox.setTitle(QCoreApplication.translate("ToolForm", u"\u4e0b\u8f7d\u914d\u7f6e", None))
        self.DownloadFilterComboBox.setItemText(0, QCoreApplication.translate("ToolForm", u"\u4e4b\u4e00", None))
        self.DownloadFilterComboBox.setItemText(1, QCoreApplication.translate("ToolForm", u"\u5168\u90e8", None))

        self.label.setText(QCoreApplication.translate("ToolForm", u"\u8981\u4e0b\u8f7d\u7684\u6587\u4ef6\u6ee1\u8db3\u4ee5\u4e0b\u6761\u4ef6\n"
"\n"
"         \u65f6\uff0c\u5c06\u76f4\u63a5\u4e0b\u8f7d\n"
"\n"
"\u6574\u4e2azip\u6587\u4ef6\uff1a", None))
        self.NumFilterCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u6570\u91cf\u5927\u4e8e", None))
        self.NumFilterSpinBox.setSuffix(QCoreApplication.translate("ToolForm", u"\u4e2a", None))
        self.SizeFilterCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u5bb9\u91cf\u5927\u4e8e", None))
        self.SizeFilterSpinBox.setPrefix("")
        self.SizeFilterSpinBox.setSuffix(QCoreApplication.translate("ToolForm", u"\u5146", None))
        self.GenerateGroupBox.setTitle(QCoreApplication.translate("ToolForm", u"\u751f\u6210\u914d\u7f6e", None))
        self.UncomperssZipCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u5c06zip\u6587\u4ef6\u6807\u8bc6\u4e3a\u9700\u8981\u89e3\u538b", None))
        self.EncryptResCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u5bf9\u8d44\u6e90\u52a0\u5bc6[lua/luac/png]", None))
        self.EncryptResPasswordLineEdit.setPlaceholderText(QCoreApplication.translate("ToolForm", u"\u5bc6\u7801", None))
        self.CompressImgCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u538b\u7f29\u56fe\u50cf[png]\u5e76\u6307\u5b9a\u8d28\u91cf", None))
        self.MinQualitySpinBox.setPrefix(QCoreApplication.translate("ToolForm", u"\u6700\u4f4e", None))
        self.MaxQualitySpinBox.setPrefix(QCoreApplication.translate("ToolForm", u"\u6700\u9ad8", None))
        self.CompileLuaCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u7f16\u8bd1lua\u6587\u4ef6", None))
        self.OtherSettingGroupBox.setTitle(QCoreApplication.translate("ToolForm", u"\u5176\u4ed6\u914d\u7f6e", None))
        self.UniqueConfigCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u6240\u6709\u6a21\u5757\u4f7f\u7528\u7edf\u4e00\u914d\u7f6e", None))
        self.SaveOnExitCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u9000\u51fa\u65f6\u4fdd\u5b58\u914d\u7f6e", None))
        self.SelectAllButton.setText(QCoreApplication.translate("ToolForm", u"\u5168\u9009\u6a21\u5757", None))
        self.SelectOtherButton.setText(QCoreApplication.translate("ToolForm", u"\u53cd\u9009\u6a21\u5757", None))
        self.ManageModuleButton.setText(QCoreApplication.translate("ToolForm", u"\u7ba1\u7406\u6a21\u5757", None))
        self.StartTimerCheckBox.setText(QCoreApplication.translate("ToolForm", u"\u5b9a\u65f6\uff1a", None))
        self.StartTimerSpinBox.setSuffix(QCoreApplication.translate("ToolForm", u"\u79d2", None))
        self.ClearTempButton.setText(QCoreApplication.translate("ToolForm", u"\u6e05\u7406\u7f13\u5b58", None))
        self.TabWidget.setTabText(self.TabWidget.indexOf(self.TabHotUpdate), QCoreApplication.translate("ToolForm", u"\u70ed\u66f4", None))
        self.TabWidget.setTabText(self.TabWidget.indexOf(self.TabCompile), QCoreApplication.translate("ToolForm", u"\u7f16\u8bd1", None))
        self.StartButton.setText(QCoreApplication.translate("ToolForm", u"\u5f00\u59cb", None))
    # retranslateUi

