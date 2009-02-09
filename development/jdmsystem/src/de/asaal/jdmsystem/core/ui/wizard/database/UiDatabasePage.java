/********************************************************************************
** Form generated from reading ui file 'DatabasePage.jui'
**
** Created: Mo 9. Feb 14:41:02 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiDatabasePage
{
    public QGridLayout gridLayout_2;
    public QLabel label;
    public QGroupBox groupBoxDatabaseOption;
    public QGridLayout gridLayoutOption;
    public QRadioButton rbtnNewDatabase;
    public QRadioButton rbtnChooseDatabase;
    public QGroupBox groupBox;
    public QGridLayout gridLayout;
    public QHBoxLayout horizontalLayoutHost;
    public QLabel labelHost;
    public QLineEdit lineEditHost;
    public QLabel label_2;
    public QHBoxLayout horizontalLayoutPort;
    public QLabel labelPort;
    public QSpinBox spinBoxPort;
    public QLabel label_5;
    public QHBoxLayout horizontalLayoutUser;
    public QLabel labelUser;
    public QLineEdit lineEditUser;
    public QLabel label_3;
    public QHBoxLayout horizontalLayoutPassword;
    public QLabel labelPassword;
    public QLineEdit lineEditPassword;
    public QHBoxLayout horizontalLayout;
    public QLabel labelDatabase;
    public QComboBox comboBoxDatabase;
    public QPushButton btnRefreshDatabases;
    public QSpacerItem verticalSpacerDatabasePage;

    public UiDatabasePage() { super(); }

    public void setupUi(QWizardPage DatabasePage)
    {
        DatabasePage.setObjectName("DatabasePage");
        DatabasePage.resize(new QSize(470, 300).expandedTo(DatabasePage.minimumSizeHint()));
        DatabasePage.setMinimumSize(new QSize(470, 300));
        DatabasePage.setMaximumSize(new QSize(470, 300));
        gridLayout_2 = new QGridLayout(DatabasePage);
        gridLayout_2.setObjectName("gridLayout_2");
        label = new QLabel(DatabasePage);
        label.setObjectName("label");
        label.setWordWrap(true);

        gridLayout_2.addWidget(label, 0, 0, 1, 1);

        groupBoxDatabaseOption = new QGroupBox(DatabasePage);
        groupBoxDatabaseOption.setObjectName("groupBoxDatabaseOption");
        gridLayoutOption = new QGridLayout(groupBoxDatabaseOption);
        gridLayoutOption.setObjectName("gridLayoutOption");
        rbtnNewDatabase = new QRadioButton(groupBoxDatabaseOption);
        rbtnNewDatabase.setObjectName("rbtnNewDatabase");
        rbtnNewDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);
        rbtnNewDatabase.setChecked(true);

        gridLayoutOption.addWidget(rbtnNewDatabase, 0, 0, 1, 1);

        rbtnChooseDatabase = new QRadioButton(groupBoxDatabaseOption);
        rbtnChooseDatabase.setObjectName("rbtnChooseDatabase");
        rbtnChooseDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        gridLayoutOption.addWidget(rbtnChooseDatabase, 1, 0, 1, 1);


        gridLayout_2.addWidget(groupBoxDatabaseOption, 1, 0, 1, 1);

        groupBox = new QGroupBox(DatabasePage);
        groupBox.setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout.setObjectName("gridLayout");
        horizontalLayoutHost = new QHBoxLayout();
        horizontalLayoutHost.setObjectName("horizontalLayoutHost");
        labelHost = new QLabel(groupBox);
        labelHost.setObjectName("labelHost");
        labelHost.setMinimumSize(new QSize(110, 0));
        labelHost.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutHost.addWidget(labelHost);

        lineEditHost = new QLineEdit(groupBox);
        lineEditHost.setObjectName("lineEditHost");

        horizontalLayoutHost.addWidget(lineEditHost);

        label_2 = new QLabel(groupBox);
        label_2.setObjectName("label_2");
        label_2.setMinimumSize(new QSize(16, 16));
        label_2.setMaximumSize(new QSize(16, 16));
        label_2.setPixmap(new QPixmap(("classpath:de/asaal/jdmsystem/resource/images/info.png")));

        horizontalLayoutHost.addWidget(label_2);


        gridLayout.addLayout(horizontalLayoutHost, 0, 0, 1, 1);

        horizontalLayoutPort = new QHBoxLayout();
        horizontalLayoutPort.setObjectName("horizontalLayoutPort");
        labelPort = new QLabel(groupBox);
        labelPort.setObjectName("labelPort");
        labelPort.setMinimumSize(new QSize(110, 0));
        labelPort.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutPort.addWidget(labelPort);

        spinBoxPort = new QSpinBox(groupBox);
        spinBoxPort.setObjectName("spinBoxPort");
        spinBoxPort.setMaximum(65536);
        spinBoxPort.setValue(3306);

        horizontalLayoutPort.addWidget(spinBoxPort);

        label_5 = new QLabel(groupBox);
        label_5.setObjectName("label_5");
        label_5.setMinimumSize(new QSize(16, 16));
        label_5.setMaximumSize(new QSize(16, 16));
        label_5.setPixmap(new QPixmap(("classpath:de/asaal/jdmsystem/resource/images/info.png")));

        horizontalLayoutPort.addWidget(label_5);


        gridLayout.addLayout(horizontalLayoutPort, 1, 0, 1, 1);

        horizontalLayoutUser = new QHBoxLayout();
        horizontalLayoutUser.setObjectName("horizontalLayoutUser");
        labelUser = new QLabel(groupBox);
        labelUser.setObjectName("labelUser");
        labelUser.setMinimumSize(new QSize(110, 0));
        labelUser.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutUser.addWidget(labelUser);

        lineEditUser = new QLineEdit(groupBox);
        lineEditUser.setObjectName("lineEditUser");

        horizontalLayoutUser.addWidget(lineEditUser);

        label_3 = new QLabel(groupBox);
        label_3.setObjectName("label_3");
        label_3.setMinimumSize(new QSize(16, 16));
        label_3.setMaximumSize(new QSize(16, 16));
        label_3.setPixmap(new QPixmap(("classpath:de/asaal/jdmsystem/resource/images/info.png")));

        horizontalLayoutUser.addWidget(label_3);


        gridLayout.addLayout(horizontalLayoutUser, 2, 0, 1, 1);

        horizontalLayoutPassword = new QHBoxLayout();
        horizontalLayoutPassword.setObjectName("horizontalLayoutPassword");
        labelPassword = new QLabel(groupBox);
        labelPassword.setObjectName("labelPassword");
        labelPassword.setMinimumSize(new QSize(110, 0));
        labelPassword.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutPassword.addWidget(labelPassword);

        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword.setObjectName("lineEditPassword");
        lineEditPassword.setEchoMode(com.trolltech.qt.gui.QLineEdit.EchoMode.Password);

        horizontalLayoutPassword.addWidget(lineEditPassword);


        gridLayout.addLayout(horizontalLayoutPassword, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout.setObjectName("horizontalLayout");
        labelDatabase = new QLabel(groupBox);
        labelDatabase.setObjectName("labelDatabase");
        labelDatabase.setEnabled(false);
        labelDatabase.setMinimumSize(new QSize(110, 0));
        labelDatabase.setMaximumSize(new QSize(110, 16777215));

        horizontalLayout.addWidget(labelDatabase);

        comboBoxDatabase = new QComboBox(groupBox);
        comboBoxDatabase.setObjectName("comboBoxDatabase");
        comboBoxDatabase.setEnabled(false);
        comboBoxDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);

        horizontalLayout.addWidget(comboBoxDatabase);

        btnRefreshDatabases = new QPushButton(groupBox);
        btnRefreshDatabases.setObjectName("btnRefreshDatabases");
        btnRefreshDatabases.setEnabled(false);
        btnRefreshDatabases.setMinimumSize(new QSize(20, 20));
        btnRefreshDatabases.setMaximumSize(new QSize(20, 20));
        btnRefreshDatabases.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayout.addWidget(btnRefreshDatabases);


        gridLayout.addLayout(horizontalLayout, 4, 0, 1, 1);


        gridLayout_2.addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacerDatabasePage = new QSpacerItem(17, 49, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        gridLayout_2.addItem(verticalSpacerDatabasePage, 3, 0, 1, 1);

        labelHost.setBuddy(lineEditHost);
        labelPort.setBuddy(spinBoxPort);
        labelUser.setBuddy(lineEditUser);
        labelPassword.setBuddy(lineEditPassword);
        labelDatabase.setBuddy(comboBoxDatabase);
        QWidget.setTabOrder(rbtnNewDatabase, rbtnChooseDatabase);
        QWidget.setTabOrder(rbtnChooseDatabase, lineEditHost);
        QWidget.setTabOrder(lineEditHost, spinBoxPort);
        QWidget.setTabOrder(spinBoxPort, lineEditUser);
        QWidget.setTabOrder(lineEditUser, lineEditPassword);
        QWidget.setTabOrder(lineEditPassword, comboBoxDatabase);
        retranslateUi(DatabasePage);

        DatabasePage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage DatabasePage)
    {
        DatabasePage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "QWizardPage"));
        label.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Select as first a option and then make your settings. You must set a host, port and a user. Password are optional."));
        groupBoxDatabaseOption.setTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Option"));
        rbtnNewDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Create ew database"));
        rbtnChooseDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Choose available database"));
        groupBox.setTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Connections"));
        labelHost.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Host:"));
        label_2.setToolTip(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"+
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"+
"p, li { white-space: pre-wrap; }\n"+
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"+
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">If <span style=\" font-weight:600;\">host</span> is blank, the default host is used. The default host are <span style=\" font-weight:600;\">localhost</span> or <span style=\" font-weight:600;\">127.0.0.1</span>.</p></body></html>"));
        labelPort.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Port:"));
        label_5.setToolTip(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"+
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"+
"p, li { white-space: pre-wrap; }\n"+
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"+
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">If <span style=\" font-weight:600;\">port</span> is blank or zerro, the default database port is used. The default database port is <span style=\" font-weight:600;\">3306</span>.</p></body></html>"));
        labelUser.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "User:"));
        label_3.setToolTip(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"+
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"+
"p, li { white-space: pre-wrap; }\n"+
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"+
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">If <span style=\" font-weight:600;\">user</span> is blank, the default database user is used. The default database user is <span style=\" font-weight:600;\">root</span>.</p></body></html>"));
        labelPassword.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Password:"));
        labelDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Database"));
        btnRefreshDatabases.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "..."));
    } // retranslateUi

}

