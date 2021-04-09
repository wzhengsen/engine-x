# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'ModuleMgrDlg.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

import UI_rc

class Ui_ModuleMgrDlg(object):
    def setupUi(self, ModuleMgrDlg):
        if not ModuleMgrDlg.objectName():
            ModuleMgrDlg.setObjectName(u"ModuleMgrDlg")
        ModuleMgrDlg.setWindowModality(Qt.WindowModal)
        ModuleMgrDlg.resize(600, 300)
        ModuleMgrDlg.setMinimumSize(QSize(300, 150))
        ModuleMgrDlg.setMaximumSize(QSize(600, 300))
        icon = QIcon()
        icon.addFile(u":/res/IcoModule.ico", QSize(), QIcon.Normal, QIcon.Off)
        ModuleMgrDlg.setWindowIcon(icon)
        ModuleMgrDlg.setModal(True)
        self.horizontalLayout = QHBoxLayout(ModuleMgrDlg)
        self.horizontalLayout.setSpacing(2)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout = QGridLayout()
        self.gridLayout.setSpacing(2)
        self.gridLayout.setObjectName(u"gridLayout")
        self.NewModuleButton = QPushButton(ModuleMgrDlg)
        self.NewModuleButton.setObjectName(u"NewModuleButton")
        icon1 = QIcon()
        icon1.addFile(u":/res/ImgPlus.png", QSize(), QIcon.Normal, QIcon.Off)
        self.NewModuleButton.setIcon(icon1)
        self.NewModuleButton.setAutoDefault(False)

        self.gridLayout.addWidget(self.NewModuleButton, 1, 0, 1, 1)

        self.DelModuleButton = QPushButton(ModuleMgrDlg)
        self.DelModuleButton.setObjectName(u"DelModuleButton")
        self.DelModuleButton.setEnabled(False)
        icon2 = QIcon()
        icon2.addFile(u":/res/ImgDel.png", QSize(), QIcon.Normal, QIcon.Off)
        self.DelModuleButton.setIcon(icon2)
        self.DelModuleButton.setAutoDefault(False)

        self.gridLayout.addWidget(self.DelModuleButton, 1, 1, 1, 1)

        self.ModuleListWidget = QListWidget(ModuleMgrDlg)
        self.ModuleListWidget.setObjectName(u"ModuleListWidget")

        self.gridLayout.addWidget(self.ModuleListWidget, 0, 0, 1, 2)


        self.horizontalLayout.addLayout(self.gridLayout)

        self.ModuleInfoTabWidget = QTabWidget(ModuleMgrDlg)
        self.ModuleInfoTabWidget.setObjectName(u"ModuleInfoTabWidget")
        self.ModuleInfoTabWidget.setEnabled(False)
        self.tab = QWidget()
        self.tab.setObjectName(u"tab")
        self.gridLayout_2 = QGridLayout(self.tab)
        self.gridLayout_2.setSpacing(0)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.InfoTableWidget = QTableWidget(self.tab)
        if (self.InfoTableWidget.columnCount() < 1):
            self.InfoTableWidget.setColumnCount(1)
        __qtablewidgetitem = QTableWidgetItem()
        self.InfoTableWidget.setHorizontalHeaderItem(0, __qtablewidgetitem)
        if (self.InfoTableWidget.rowCount() < 4):
            self.InfoTableWidget.setRowCount(4)
        __qtablewidgetitem1 = QTableWidgetItem()
        self.InfoTableWidget.setVerticalHeaderItem(0, __qtablewidgetitem1)
        __qtablewidgetitem2 = QTableWidgetItem()
        self.InfoTableWidget.setVerticalHeaderItem(1, __qtablewidgetitem2)
        __qtablewidgetitem3 = QTableWidgetItem()
        self.InfoTableWidget.setVerticalHeaderItem(2, __qtablewidgetitem3)
        __qtablewidgetitem4 = QTableWidgetItem()
        self.InfoTableWidget.setVerticalHeaderItem(3, __qtablewidgetitem4)
        __qtablewidgetitem5 = QTableWidgetItem()
        self.InfoTableWidget.setItem(0, 0, __qtablewidgetitem5)
        __qtablewidgetitem6 = QTableWidgetItem()
        self.InfoTableWidget.setItem(1, 0, __qtablewidgetitem6)
        __qtablewidgetitem7 = QTableWidgetItem()
        self.InfoTableWidget.setItem(2, 0, __qtablewidgetitem7)
        __qtablewidgetitem8 = QTableWidgetItem()
        self.InfoTableWidget.setItem(3, 0, __qtablewidgetitem8)
        self.InfoTableWidget.setObjectName(u"InfoTableWidget")
        self.InfoTableWidget.setSelectionMode(QAbstractItemView.SingleSelection)
        self.InfoTableWidget.setGridStyle(Qt.SolidLine)
        self.InfoTableWidget.horizontalHeader().setVisible(False)
        self.InfoTableWidget.horizontalHeader().setStretchLastSection(True)
        self.InfoTableWidget.verticalHeader().setDefaultSectionSize(20)
        self.InfoTableWidget.verticalHeader().setHighlightSections(False)

        self.gridLayout_2.addWidget(self.InfoTableWidget, 0, 0, 1, 1)

        self.ModuleInfoTabWidget.addTab(self.tab, "")
        self.tab_2 = QWidget()
        self.tab_2.setObjectName(u"tab_2")
        self.gridLayout_3 = QGridLayout(self.tab_2)
        self.gridLayout_3.setSpacing(0)
        self.gridLayout_3.setObjectName(u"gridLayout_3")
        self.gridLayout_3.setContentsMargins(0, 0, 0, 0)
        self.DelDirButton = QPushButton(self.tab_2)
        self.DelDirButton.setObjectName(u"DelDirButton")
        self.DelDirButton.setEnabled(False)
        self.DelDirButton.setIcon(icon2)

        self.gridLayout_3.addWidget(self.DelDirButton, 1, 2, 1, 1)

        self.NewDirButton = QPushButton(self.tab_2)
        self.NewDirButton.setObjectName(u"NewDirButton")
        self.NewDirButton.setIcon(icon1)

        self.gridLayout_3.addWidget(self.NewDirButton, 1, 1, 1, 1)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.gridLayout_3.addItem(self.horizontalSpacer, 1, 0, 1, 1)

        self.DirsListWidget = QListWidget(self.tab_2)
        self.DirsListWidget.setObjectName(u"DirsListWidget")

        self.gridLayout_3.addWidget(self.DirsListWidget, 0, 0, 1, 3)

        self.ModuleInfoTabWidget.addTab(self.tab_2, "")
        self.tab_3 = QWidget()
        self.tab_3.setObjectName(u"tab_3")
        self.gridLayout_4 = QGridLayout(self.tab_3)
        self.gridLayout_4.setSpacing(0)
        self.gridLayout_4.setObjectName(u"gridLayout_4")
        self.gridLayout_4.setContentsMargins(0, 0, 0, 0)
        self.DelFileButton = QPushButton(self.tab_3)
        self.DelFileButton.setObjectName(u"DelFileButton")
        self.DelFileButton.setEnabled(False)
        self.DelFileButton.setIcon(icon2)

        self.gridLayout_4.addWidget(self.DelFileButton, 1, 2, 1, 1)

        self.NewFileButton = QPushButton(self.tab_3)
        self.NewFileButton.setObjectName(u"NewFileButton")
        self.NewFileButton.setIcon(icon1)

        self.gridLayout_4.addWidget(self.NewFileButton, 1, 1, 1, 1)

        self.horizontalSpacer_2 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.gridLayout_4.addItem(self.horizontalSpacer_2, 1, 0, 1, 1)

        self.FilesListWidget = QListWidget(self.tab_3)
        self.FilesListWidget.setObjectName(u"FilesListWidget")

        self.gridLayout_4.addWidget(self.FilesListWidget, 0, 0, 1, 3)

        self.ModuleInfoTabWidget.addTab(self.tab_3, "")

        self.horizontalLayout.addWidget(self.ModuleInfoTabWidget)

        self.horizontalLayout.setStretch(0, 4)
        self.horizontalLayout.setStretch(1, 12)

        self.retranslateUi(ModuleMgrDlg)

        self.ModuleInfoTabWidget.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(ModuleMgrDlg)
    # setupUi

    def retranslateUi(self, ModuleMgrDlg):
        ModuleMgrDlg.setWindowTitle(QCoreApplication.translate("ModuleMgrDlg", u"\u6a21\u5757\u7ba1\u7406", None))
        self.NewModuleButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u65b0\u589e\u6a21\u5757", None))
        self.DelModuleButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u5220\u9664\u6a21\u5757", None))
        ___qtablewidgetitem = self.InfoTableWidget.horizontalHeaderItem(0)
        ___qtablewidgetitem.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u503c", None));
        ___qtablewidgetitem1 = self.InfoTableWidget.verticalHeaderItem(0)
        ___qtablewidgetitem1.setText(QCoreApplication.translate("ModuleMgrDlg", u"downloadUrl", None));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem1.setToolTip(QCoreApplication.translate("ModuleMgrDlg", u"\u8fdc\u7a0b\u6587\u4ef6\u6839\u76ee\u5f55", None));
#endif // QT_CONFIG(tooltip)
        ___qtablewidgetitem2 = self.InfoTableWidget.verticalHeaderItem(1)
        ___qtablewidgetitem2.setText(QCoreApplication.translate("ModuleMgrDlg", u"uploadUrl", None));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem2.setToolTip(QCoreApplication.translate("ModuleMgrDlg", u"\u4e0a\u4f20\u6839\u8def\u5f84", None));
#endif // QT_CONFIG(tooltip)
        ___qtablewidgetitem3 = self.InfoTableWidget.verticalHeaderItem(2)
        ___qtablewidgetitem3.setText(QCoreApplication.translate("ModuleMgrDlg", u"remoteVersionUrl", None));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem3.setToolTip(QCoreApplication.translate("ModuleMgrDlg", u"\u8fdc\u7a0b\u7248\u672c\u6587\u4ef6", None));
#endif // QT_CONFIG(tooltip)
        ___qtablewidgetitem4 = self.InfoTableWidget.verticalHeaderItem(3)
        ___qtablewidgetitem4.setText(QCoreApplication.translate("ModuleMgrDlg", u"remoteManifestUrl", None));
#if QT_CONFIG(tooltip)
        ___qtablewidgetitem4.setToolTip(QCoreApplication.translate("ModuleMgrDlg", u"\u8fdc\u7a0b\u6e05\u5355\u6587\u4ef6", None));
#endif // QT_CONFIG(tooltip)

        __sortingEnabled = self.InfoTableWidget.isSortingEnabled()
        self.InfoTableWidget.setSortingEnabled(False)
        self.InfoTableWidget.setSortingEnabled(__sortingEnabled)

        self.ModuleInfoTabWidget.setTabText(self.ModuleInfoTabWidget.indexOf(self.tab), QCoreApplication.translate("ModuleMgrDlg", u"\u5e38\u89c4", None))
        self.DelDirButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u5220\u9664\u76ee\u5f55", None))
        self.NewDirButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u65b0\u589e\u76ee\u5f55", None))
        self.ModuleInfoTabWidget.setTabText(self.ModuleInfoTabWidget.indexOf(self.tab_2), QCoreApplication.translate("ModuleMgrDlg", u"\u76ee\u5f55", None))
        self.DelFileButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u5220\u9664\u6587\u4ef6", None))
        self.NewFileButton.setText(QCoreApplication.translate("ModuleMgrDlg", u"\u65b0\u589e\u6587\u4ef6", None))
        self.ModuleInfoTabWidget.setTabText(self.ModuleInfoTabWidget.indexOf(self.tab_3), QCoreApplication.translate("ModuleMgrDlg", u"\u6587\u4ef6", None))
    # retranslateUi

