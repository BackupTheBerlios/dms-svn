/********************************************************************************
** Form generated from reading ui file 'UserBase.jui'
**
** Created: Mo 9. Feb 23:09:09 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiUserBase
{
    public QGridLayout gridLayoutUserWidget;
    public QGridLayout gridLayoutUser;
    public QTreeWidget treeWidgetUser;
    public QGridLayout gridLayoutUserOption;
    public QHBoxLayout horizontalLayoutUserName;
    public QLabel labelUserName;
    public QLineEdit lineEditUserName;
    public QHBoxLayout horizontalLayoutUserPassword;
    public QLabel labelUserPassword;
    public QLineEdit lineEditUserPassword;
    public QHBoxLayout horizontalLayoutUserConfirmPassword;
    public QLabel labelUserConfirmPassword;
    public QLineEdit lineEditUserPasswordConfirm;
    public QPushButton btnAddUser;
    public QPushButton btnUpdateUser;
    public QPushButton btnDeleteUser;
    public QFrame lineUser;
    public QFrame lineUserSplitWidget;
    public QHBoxLayout horizontalLayoutUserButtonGroup;
    public QPushButton btnAdvanceUser;
    public QSpacerItem horizontalSpacerUserWidgetButtonGroup;
    public QPushButton btnOk;
    public QPushButton btnCancel;

    public UiUserBase() { super(); }

    public void setupUi(QWidget UserBase)
    {
        UserBase.setObjectName("UserBase");
        UserBase.resize(new QSize(640, 415).expandedTo(UserBase.minimumSizeHint()));
        UserBase.setMinimumSize(new QSize(640, 415));
        gridLayoutUserWidget = new QGridLayout(UserBase);
        gridLayoutUserWidget.setObjectName("gridLayoutUserWidget");
        gridLayoutUser = new QGridLayout();
        gridLayoutUser.setObjectName("gridLayoutUser");
        treeWidgetUser = new QTreeWidget(UserBase);
        treeWidgetUser.setObjectName("treeWidgetUser");
        treeWidgetUser.setContextMenuPolicy(com.trolltech.qt.core.Qt.ContextMenuPolicy.CustomContextMenu);
        treeWidgetUser.setRootIsDecorated(false);
        treeWidgetUser.setSortingEnabled(true);

        gridLayoutUser.addWidget(treeWidgetUser, 0, 0, 1, 2);

        gridLayoutUserOption = new QGridLayout();
        gridLayoutUserOption.setObjectName("gridLayoutUserOption");
        horizontalLayoutUserName = new QHBoxLayout();
        horizontalLayoutUserName.setObjectName("horizontalLayoutUserName");
        labelUserName = new QLabel(UserBase);
        labelUserName.setObjectName("labelUserName");
        labelUserName.setMinimumSize(new QSize(110, 0));
        labelUserName.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutUserName.addWidget(labelUserName);

        lineEditUserName = new QLineEdit(UserBase);
        lineEditUserName.setObjectName("lineEditUserName");
        lineEditUserName.setFrame(true);

        horizontalLayoutUserName.addWidget(lineEditUserName);


        gridLayoutUserOption.addLayout(horizontalLayoutUserName, 0, 0, 1, 1);

        horizontalLayoutUserPassword = new QHBoxLayout();
        horizontalLayoutUserPassword.setObjectName("horizontalLayoutUserPassword");
        labelUserPassword = new QLabel(UserBase);
        labelUserPassword.setObjectName("labelUserPassword");
        labelUserPassword.setMinimumSize(new QSize(110, 0));
        labelUserPassword.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutUserPassword.addWidget(labelUserPassword);

        lineEditUserPassword = new QLineEdit(UserBase);
        lineEditUserPassword.setObjectName("lineEditUserPassword");
        lineEditUserPassword.setEchoMode(com.trolltech.qt.gui.QLineEdit.EchoMode.Password);

        horizontalLayoutUserPassword.addWidget(lineEditUserPassword);


        gridLayoutUserOption.addLayout(horizontalLayoutUserPassword, 1, 0, 1, 1);

        horizontalLayoutUserConfirmPassword = new QHBoxLayout();
        horizontalLayoutUserConfirmPassword.setObjectName("horizontalLayoutUserConfirmPassword");
        labelUserConfirmPassword = new QLabel(UserBase);
        labelUserConfirmPassword.setObjectName("labelUserConfirmPassword");
        labelUserConfirmPassword.setMinimumSize(new QSize(110, 0));
        labelUserConfirmPassword.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutUserConfirmPassword.addWidget(labelUserConfirmPassword);

        lineEditUserPasswordConfirm = new QLineEdit(UserBase);
        lineEditUserPasswordConfirm.setObjectName("lineEditUserPasswordConfirm");
        lineEditUserPasswordConfirm.setEchoMode(com.trolltech.qt.gui.QLineEdit.EchoMode.Password);

        horizontalLayoutUserConfirmPassword.addWidget(lineEditUserPasswordConfirm);


        gridLayoutUserOption.addLayout(horizontalLayoutUserConfirmPassword, 2, 0, 1, 1);

        btnAddUser = new QPushButton(UserBase);
        btnAddUser.setObjectName("btnAddUser");
        btnAddUser.setMinimumSize(new QSize(75, 23));
        btnAddUser.setMaximumSize(new QSize(75, 23));

        gridLayoutUserOption.addWidget(btnAddUser, 0, 2, 1, 1);

        btnUpdateUser = new QPushButton(UserBase);
        btnUpdateUser.setObjectName("btnUpdateUser");
        btnUpdateUser.setMinimumSize(new QSize(75, 23));
        btnUpdateUser.setMaximumSize(new QSize(75, 23));

        gridLayoutUserOption.addWidget(btnUpdateUser, 1, 2, 1, 1);

        btnDeleteUser = new QPushButton(UserBase);
        btnDeleteUser.setObjectName("btnDeleteUser");
        btnDeleteUser.setMinimumSize(new QSize(75, 23));
        btnDeleteUser.setMaximumSize(new QSize(75, 23));

        gridLayoutUserOption.addWidget(btnDeleteUser, 2, 2, 1, 1);

        lineUser = new QFrame(UserBase);
        lineUser.setObjectName("lineUser");
        lineUser.setFrameShape(com.trolltech.qt.gui.QFrame.Shape.VLine);
        lineUser.setFrameShadow(com.trolltech.qt.gui.QFrame.Shadow.Sunken);

        gridLayoutUserOption.addWidget(lineUser, 0, 1, 3, 1);


        gridLayoutUser.addLayout(gridLayoutUserOption, 1, 0, 1, 2);

        lineUserSplitWidget = new QFrame(UserBase);
        lineUserSplitWidget.setObjectName("lineUserSplitWidget");
        lineUserSplitWidget.setFrameShape(com.trolltech.qt.gui.QFrame.Shape.HLine);
        lineUserSplitWidget.setFrameShadow(com.trolltech.qt.gui.QFrame.Shadow.Sunken);

        gridLayoutUser.addWidget(lineUserSplitWidget, 2, 0, 1, 2);

        horizontalLayoutUserButtonGroup = new QHBoxLayout();
        horizontalLayoutUserButtonGroup.setObjectName("horizontalLayoutUserButtonGroup");
        btnAdvanceUser = new QPushButton(UserBase);
        btnAdvanceUser.setObjectName("btnAdvanceUser");
        btnAdvanceUser.setMinimumSize(new QSize(75, 23));
        btnAdvanceUser.setMaximumSize(new QSize(75, 23));
        btnAdvanceUser.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutUserButtonGroup.addWidget(btnAdvanceUser);

        horizontalSpacerUserWidgetButtonGroup = new QSpacerItem(37, 17, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum);

        horizontalLayoutUserButtonGroup.addItem(horizontalSpacerUserWidgetButtonGroup);

        btnOk = new QPushButton(UserBase);
        btnOk.setObjectName("btnOk");
        btnOk.setMinimumSize(new QSize(75, 23));
        btnOk.setMaximumSize(new QSize(75, 23));

        horizontalLayoutUserButtonGroup.addWidget(btnOk);

        btnCancel = new QPushButton(UserBase);
        btnCancel.setObjectName("btnCancel");
        btnCancel.setMinimumSize(new QSize(75, 23));
        btnCancel.setMaximumSize(new QSize(75, 23));

        horizontalLayoutUserButtonGroup.addWidget(btnCancel);


        gridLayoutUser.addLayout(horizontalLayoutUserButtonGroup, 3, 0, 1, 2);


        gridLayoutUserWidget.addLayout(gridLayoutUser, 0, 0, 1, 1);

        labelUserName.setBuddy(lineEditUserName);
        labelUserPassword.setBuddy(lineEditUserPassword);
        labelUserConfirmPassword.setBuddy(lineEditUserPasswordConfirm);
        retranslateUi(UserBase);

        UserBase.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWidget UserBase)
    {
        UserBase.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "User"));
        treeWidgetUser.headerItem().setText(0, com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Username"));
        treeWidgetUser.headerItem().setText(1, com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Firstname"));
        treeWidgetUser.headerItem().setText(2, com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Lastname"));
        treeWidgetUser.headerItem().setText(3, com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Created"));
        treeWidgetUser.headerItem().setText(4, com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Updated"));
        labelUserName.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Username:"));
        labelUserPassword.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Password:"));
        labelUserConfirmPassword.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Confirm password:"));
        btnAddUser.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "&Add"));
        btnAddUser.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+A"));
        btnUpdateUser.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "&Update"));
        btnUpdateUser.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+U"));
        btnDeleteUser.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "&Delete"));
        btnDeleteUser.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+D"));
        btnAdvanceUser.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Ad&v. User"));
        btnAdvanceUser.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+V"));
        btnOk.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "&Ok"));
        btnOk.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+O"));
        btnCancel.setText(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "&Cancel"));
        btnCancel.setShortcut(com.trolltech.qt.core.QCoreApplication.translate("UserBase", "Alt+C"));
    } // retranslateUi

}

