/********************************************************************************
** Form generated from reading ui file 'DatabasePage.jui'
**
** Created: So 8. Feb 16:12:51 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiDatabasePage
{
    public QWidget layoutWidget;
    public QGridLayout gridLayout;
    public QHBoxLayout horizontalLayout_3;
    public QLabel labelHost;
    public QLineEdit lineEditoHost;
    public QVBoxLayout verticalLayout;
    public QHBoxLayout horizontalLayout_4;
    public QLabel labelPort;
    public QSpinBox spinBoxPort;
    public QSpacerItem verticalSpacer;
    public QHBoxLayout horizontalLayout_2;
    public QLabel labelUser;
    public QLineEdit lineEditUser;
    public QHBoxLayout horizontalLayout;
    public QLabel labelPassword;
    public QLineEdit lineEditPassword;

    public UiDatabasePage() { super(); }

    public void setupUi(QWizardPage DatabasePage)
    {
        DatabasePage.setObjectName("DatabasePage");
        DatabasePage.resize(new QSize(639, 300).expandedTo(DatabasePage.minimumSizeHint()));
        layoutWidget = new QWidget(DatabasePage);
        layoutWidget.setObjectName("layoutWidget");
        layoutWidget.setGeometry(new QRect(10, 80, 430, 80));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout.setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3.setObjectName("horizontalLayout_3");
        labelHost = new QLabel(layoutWidget);
        labelHost.setObjectName("labelHost");
        labelHost.setMinimumSize(new QSize(110, 0));
        labelHost.setMaximumSize(new QSize(110, 16777215));

        horizontalLayout_3.addWidget(labelHost);

        lineEditoHost = new QLineEdit(layoutWidget);
        lineEditoHost.setObjectName("lineEditoHost");

        horizontalLayout_3.addWidget(lineEditoHost);


        gridLayout.addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout.setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4.setObjectName("horizontalLayout_4");
        labelPort = new QLabel(layoutWidget);
        labelPort.setObjectName("labelPort");
        labelPort.setMinimumSize(new QSize(110, 0));
        labelPort.setMaximumSize(new QSize(110, 16777215));

        horizontalLayout_4.addWidget(labelPort);

        spinBoxPort = new QSpinBox(layoutWidget);
        spinBoxPort.setObjectName("spinBoxPort");
        spinBoxPort.setMaximum(65536);
        spinBoxPort.setValue(3306);

        horizontalLayout_4.addWidget(spinBoxPort);


        verticalLayout.addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(17, 37, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        verticalLayout.addItem(verticalSpacer);


        gridLayout.addLayout(verticalLayout, 0, 1, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2.setObjectName("horizontalLayout_2");
        labelUser = new QLabel(layoutWidget);
        labelUser.setObjectName("labelUser");
        labelUser.setMinimumSize(new QSize(110, 0));
        labelUser.setMaximumSize(new QSize(110, 16777215));

        horizontalLayout_2.addWidget(labelUser);

        lineEditUser = new QLineEdit(layoutWidget);
        lineEditUser.setObjectName("lineEditUser");

        horizontalLayout_2.addWidget(lineEditUser);


        gridLayout.addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout.setObjectName("horizontalLayout");
        labelPassword = new QLabel(layoutWidget);
        labelPassword.setObjectName("labelPassword");
        labelPassword.setMinimumSize(new QSize(110, 0));
        labelPassword.setMaximumSize(new QSize(110, 16777215));

        horizontalLayout.addWidget(labelPassword);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword.setObjectName("lineEditPassword");
        lineEditPassword.setEchoMode(com.trolltech.qt.gui.QLineEdit.EchoMode.Normal);

        horizontalLayout.addWidget(lineEditPassword);


        gridLayout.addLayout(horizontalLayout, 2, 0, 1, 1);

        retranslateUi(DatabasePage);

        DatabasePage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage DatabasePage)
    {
        DatabasePage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "QWizardPage"));
        labelHost.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Host:"));
        labelPort.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Port:"));
        labelUser.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "User:"));
        labelPassword.setText(com.trolltech.qt.core.QCoreApplication.translate("DatabasePage", "Password:"));
    } // retranslateUi

}

