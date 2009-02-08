/********************************************************************************
** Form generated from reading ui file 'DatabasePage.jui'
**
** Created: So 8. Feb 16:28:45 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiDatabasePage
{
    public QGridLayout gridLayoutDatabasePage;
    public QGroupBox groupBoxDatabaseOption;
    public QGridLayout gridLayout_2;
    public QRadioButton rbtnNewDatabase;
    public QRadioButton rbtnChooseDatabase;
    public QGroupBox groupBox;
    public QGridLayout gridLayoutConnection;
    public QGridLayout gridLayoutDatabaseConnection;
    public QHBoxLayout horizontalLayoutHost;
    public QLabel labelHost;
    public QLineEdit lineEditoHost;
    public QVBoxLayout verticalLayoutPort;
    public QHBoxLayout horizontalLayoutPort;
    public QLabel labelPort;
    public QSpinBox spinBoxPort;
    public QSpacerItem verticalSpacerPort;
    public QHBoxLayout horizontalLayoutUser;
    public QLabel labelUser;
    public QLineEdit lineEditUser;
    public QHBoxLayout horizontalLayoutPassword;
    public QLabel labelPassword;
    public QLineEdit lineEditPassword;
    public QHBoxLayout horizontalLayoutDatabase;
    public QLabel labelDatabase;
    public QComboBox comboBoxDatabase;
    public QSpacerItem verticalSpacerDatabasePage;

    public UiDatabasePage() { super(); }

    public void setupUi(QWizardPage DatabasePage)
    {
        DatabasePage.setObjectName("DatabasePage");
        DatabasePage.resize(new QSize(470, 300).expandedTo(DatabasePage.minimumSizeHint()));
        DatabasePage.setMinimumSize(new QSize(470, 300));
        DatabasePage.setMaximumSize(new QSize(470, 300));
        gridLayoutDatabasePage = new QGridLayout(DatabasePage);
        gridLayoutDatabasePage.setObjectName("gridLayoutDatabasePage");
        groupBoxDatabaseOption = new QGroupBox(DatabasePage);
        groupBoxDatabaseOption.setObjectName("groupBoxDatabaseOption");
        gridLayout_2 = new QGridLayout(groupBoxDatabaseOption);
        gridLayout_2.setObjectName("gridLayout_2");
        rbtnNewDatabase = new QRadioButton(groupBoxDatabaseOption);
        rbtnNewDatabase.setObjectName("rbtnNewDatabase");
        rbtnNewDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);
        rbtnNewDatabase.setChecked(true);

        gridLayout_2.addWidget(rbtnNewDatabase, 0, 0, 1, 1);

        rbtnChooseDatabase = new QRadioButton(groupBoxDatabaseOption);
        rbtnChooseDatabase.setObjectName("rbtnChooseDatabase");
        rbtnChooseDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        gridLayout_2.addWidget(rbtnChooseDatabase, 1, 0, 1, 1);


        gridLayoutDatabasePage.addWidget(groupBoxDatabaseOption, 0, 0, 1, 1);

        groupBox = new QGroupBox(DatabasePage);
        groupBox.setObjectName("groupBox");
        gridLayoutConnection = new QGridLayout(groupBox);
        gridLayoutConnection.setObjectName("gridLayoutConnection");
        gridLayoutDatabaseConnection = new QGridLayout();
        gridLayoutDatabaseConnection.setObjectName("gridLayoutDatabaseConnection");
        horizontalLayoutHost = new QHBoxLayout();
        horizontalLayoutHost.setObjectName("horizontalLayoutHost");
        labelHost = new QLabel(groupBox);
        labelHost.setObjectName("labelHost");
        labelHost.setMinimumSize(new QSize(110, 0));
        labelHost.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutHost.addWidget(labelHost);

        lineEditoHost = new QLineEdit(groupBox);
        lineEditoHost.setObjectName("lineEditoHost");

        horizontalLayoutHost.addWidget(lineEditoHost);


        gridLayoutDatabaseConnection.addLayout(horizontalLayoutHost, 0, 0, 1, 1);

        verticalLayoutPort = new QVBoxLayout();
        verticalLayoutPort.setObjectName("verticalLayoutPort");
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


        verticalLayoutPort.addLayout(horizontalLayoutPort);

        verticalSpacerPort = new QSpacerItem(17, 37, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        verticalLayoutPort.addItem(verticalSpacerPort);


        gridLayoutDatabaseConnection.addLayout(verticalLayoutPort, 0, 1, 4, 1);

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


        gridLayoutDatabaseConnection.addLayout(horizontalLayoutUser, 1, 0, 1, 1);

        horizontalLayoutPassword = new QHBoxLayout();
        horizontalLayoutPassword.setObjectName("horizontalLayoutPassword");
        labelPassword = new QLabel(groupBox);
        labelPassword.setObjectName("labelPassword");
        labelPassword.setMinimumSize(new QSize(110, 0));
        labelPassword.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutPassword.addWidget(labelPassword);

        lineEditPassword = new QLineEdit(groupBox);
        lineEditPassword.setObjectName("lineEditPassword");
        lineEditPassword.setEchoMode(com.trolltech.qt.gui.QLineEdit.EchoMode.Normal);

        horizontalLayoutPassword.addWidget(lineEditPassword);


        gridLayoutDatabaseConnection.addLayout(horizontalLayoutPassword, 2, 0, 1, 1);

        horizontalLayoutDatabase = new QHBoxLayout();
        horizontalLayoutDatabase.setObjectName("horizontalLayoutDatabase");
        labelDatabase = new QLabel(groupBox);
        labelDatabase.setObjectName("labelDatabase");
        labelDatabase.setMinimumSize(new QSize(110, 0));
        labelDatabase.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDatabase.addWidget(labelDatabase);

        comboBoxDatabase = new QComboBox(groupBox);
        comboBoxDatabase.setObjectName("comboBoxDatabase");
        comboBoxDatabase.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);

        horizontalLayoutDatabase.addWidget(comboBoxDatabase);


        gridLayoutDatabaseConnection.addLayout(horizontalLayoutDatabase, 3, 0, 1, 1);


        gridLayoutConnection.addLayout(gridLayoutDatabaseConnection, 0, 0, 1, 1);


        gridLayoutDatabasePage.addWidget(groupBox, 1, 0, 1, 1);

        verticalSpacerDatabasePage = new QSpacerItem(17, 49, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        gridLayoutDatabasePage.addItem(verticalSpacerDatabasePage, 2, 0, 1, 1);

        labelHost.setBuddy(lineEditoHost);
        labelPort.setBuddy(spinBoxPort);
        labelUser.setBuddy(lineEditUser);
        labelPassword.setBuddy(lineEditPassword);
        labelDatabase.setBuddy(comboBoxDatabase);
        QWidget.setTabOrder(rbtnNewDatabase, rbtnChooseDatabase);
        QWidget.setTabOrder(rbtnChooseDatabase, lineEditoHost);
        QWidget.setTabOrder(lineEditoHost, spinBoxPort);
        QWidget.setTabOrder(spinBoxPort, lineEditUser);
        QWidget.setTabOrder(lineEditUser, lineEditPassword);
        QWidget.setTabOrder(lineEditPassword, comboBoxDatabase);
        retranslateUi(DatabasePage);
        rbtnNewDatabase.toggled.connect(labelDatabase, "setEnabled(boolean)");
        rbtnNewDatabase.toggled.connect(comboBoxDatabase, "setEnabled(boolean)");

        DatabasePage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage DatabasePage)
    {
        DatabasePage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "QWizardPage"));
        groupBoxDatabaseOption.setTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Option"));
        rbtnNewDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Create ew database"));
        rbtnChooseDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Choose available database"));
        groupBox.setTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Connections"));
        labelHost.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Host:"));
        labelPort.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Port:"));
        labelUser.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "User:"));
        labelPassword.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Password:"));
        labelDatabase.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Database"));
    } // retranslateUi

}

