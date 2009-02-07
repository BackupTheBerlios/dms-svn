/********************************************************************************
** Form generated from reading ui file 'AdvancedUserBase.jui'
**
** Created: Mi 4. Feb 22:08:11 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiAdvancedUserBase
{
    public QGridLayout gridLayoutAdvUserDialog;
    public QGridLayout gridLayoutAdvUserSettings;
    public QGridLayout gridLayoutAdvUser;
    public QHBoxLayout horizontalLayoutFirstName;
    public QLabel labelFirstName;
    public QLineEdit lineEditFirstName;
    public QHBoxLayout horizontalLayoutLastName;
    public QLabel labelLastName;
    public QLineEdit lineEditLastName;
    public QHBoxLayout horizontalLayoutStreetName;
    public QLabel labelStreetName;
    public QLineEdit lineEditStreetName;
    public QHBoxLayout horizontalLayoutStreetNr;
    public QLabel labelStreetNumber;
    public QLineEdit lineEditStreetNumber;
    public QHBoxLayout horizontalLayoutCity;
    public QLabel labelCity;
    public QLineEdit lineEditCity;
    public QHBoxLayout horizontalLayoutPostalCode;
    public QLabel labelPostalCode;
    public QLineEdit lineEditPostalCode;
    public QHBoxLayout horizontalLayoutCountry;
    public QLabel labelCountry;
    public QLineEdit lineEditCountry;
    public QSpacerItem verticalSpacer;
    public QFrame lineSplitAdvUser;
    public QHBoxLayout horizontalLayoutAdvUserButtonGroup;
    public QSpacerItem horizontalSpacerAdvUserButtonGroup;
    public QPushButton btnOk;
    public QPushButton btnCancel;

    public UiAdvancedUserBase() { super(); }

    public void setupUi(QDialog AdvancedUserBase)
    {
        AdvancedUserBase.setObjectName("AdvancedUserBase");
        AdvancedUserBase.resize(new QSize(415, 258).expandedTo(AdvancedUserBase.minimumSizeHint()));
        gridLayoutAdvUserDialog = new QGridLayout(AdvancedUserBase);
        gridLayoutAdvUserDialog.setObjectName("gridLayoutAdvUserDialog");
        gridLayoutAdvUserSettings = new QGridLayout();
        gridLayoutAdvUserSettings.setObjectName("gridLayoutAdvUserSettings");
        gridLayoutAdvUser = new QGridLayout();
        gridLayoutAdvUser.setObjectName("gridLayoutAdvUser");
        horizontalLayoutFirstName = new QHBoxLayout();
        horizontalLayoutFirstName.setObjectName("horizontalLayoutFirstName");
        labelFirstName = new QLabel(AdvancedUserBase);
        labelFirstName.setObjectName("labelFirstName");
        labelFirstName.setMinimumSize(new QSize(110, 0));
        labelFirstName.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutFirstName.addWidget(labelFirstName);

        lineEditFirstName = new QLineEdit(AdvancedUserBase);
        lineEditFirstName.setObjectName("lineEditFirstName");
        lineEditFirstName.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutFirstName.addWidget(lineEditFirstName);


        gridLayoutAdvUser.addLayout(horizontalLayoutFirstName, 0, 0, 1, 1);

        horizontalLayoutLastName = new QHBoxLayout();
        horizontalLayoutLastName.setObjectName("horizontalLayoutLastName");
        labelLastName = new QLabel(AdvancedUserBase);
        labelLastName.setObjectName("labelLastName");
        labelLastName.setMinimumSize(new QSize(110, 0));
        labelLastName.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutLastName.addWidget(labelLastName);

        lineEditLastName = new QLineEdit(AdvancedUserBase);
        lineEditLastName.setObjectName("lineEditLastName");
        lineEditLastName.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutLastName.addWidget(lineEditLastName);


        gridLayoutAdvUser.addLayout(horizontalLayoutLastName, 1, 0, 1, 1);

        horizontalLayoutStreetName = new QHBoxLayout();
        horizontalLayoutStreetName.setObjectName("horizontalLayoutStreetName");
        labelStreetName = new QLabel(AdvancedUserBase);
        labelStreetName.setObjectName("labelStreetName");
        labelStreetName.setMinimumSize(new QSize(110, 0));
        labelStreetName.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutStreetName.addWidget(labelStreetName);

        lineEditStreetName = new QLineEdit(AdvancedUserBase);
        lineEditStreetName.setObjectName("lineEditStreetName");
        lineEditStreetName.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutStreetName.addWidget(lineEditStreetName);


        gridLayoutAdvUser.addLayout(horizontalLayoutStreetName, 2, 0, 1, 1);

        horizontalLayoutStreetNr = new QHBoxLayout();
        horizontalLayoutStreetNr.setObjectName("horizontalLayoutStreetNr");
        labelStreetNumber = new QLabel(AdvancedUserBase);
        labelStreetNumber.setObjectName("labelStreetNumber");
        labelStreetNumber.setMinimumSize(new QSize(110, 0));
        labelStreetNumber.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutStreetNr.addWidget(labelStreetNumber);

        lineEditStreetNumber = new QLineEdit(AdvancedUserBase);
        lineEditStreetNumber.setObjectName("lineEditStreetNumber");
        lineEditStreetNumber.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutStreetNr.addWidget(lineEditStreetNumber);


        gridLayoutAdvUser.addLayout(horizontalLayoutStreetNr, 3, 0, 1, 1);

        horizontalLayoutCity = new QHBoxLayout();
        horizontalLayoutCity.setObjectName("horizontalLayoutCity");
        labelCity = new QLabel(AdvancedUserBase);
        labelCity.setObjectName("labelCity");
        labelCity.setMinimumSize(new QSize(110, 0));
        labelCity.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutCity.addWidget(labelCity);

        lineEditCity = new QLineEdit(AdvancedUserBase);
        lineEditCity.setObjectName("lineEditCity");
        lineEditCity.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutCity.addWidget(lineEditCity);


        gridLayoutAdvUser.addLayout(horizontalLayoutCity, 4, 0, 1, 1);

        horizontalLayoutPostalCode = new QHBoxLayout();
        horizontalLayoutPostalCode.setObjectName("horizontalLayoutPostalCode");
        labelPostalCode = new QLabel(AdvancedUserBase);
        labelPostalCode.setObjectName("labelPostalCode");
        labelPostalCode.setMinimumSize(new QSize(110, 0));
        labelPostalCode.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutPostalCode.addWidget(labelPostalCode);

        lineEditPostalCode = new QLineEdit(AdvancedUserBase);
        lineEditPostalCode.setObjectName("lineEditPostalCode");
        lineEditPostalCode.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutPostalCode.addWidget(lineEditPostalCode);


        gridLayoutAdvUser.addLayout(horizontalLayoutPostalCode, 5, 0, 1, 1);

        horizontalLayoutCountry = new QHBoxLayout();
        horizontalLayoutCountry.setObjectName("horizontalLayoutCountry");
        labelCountry = new QLabel(AdvancedUserBase);
        labelCountry.setObjectName("labelCountry");
        labelCountry.setMinimumSize(new QSize(110, 0));
        labelCountry.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutCountry.addWidget(labelCountry);

        lineEditCountry = new QLineEdit(AdvancedUserBase);
        lineEditCountry.setObjectName("lineEditCountry");
        lineEditCountry.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutCountry.addWidget(lineEditCountry);


        gridLayoutAdvUser.addLayout(horizontalLayoutCountry, 6, 0, 1, 1);


        gridLayoutAdvUserSettings.addLayout(gridLayoutAdvUser, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(17, 37, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        gridLayoutAdvUserSettings.addItem(verticalSpacer, 1, 0, 1, 1);

        lineSplitAdvUser = new QFrame(AdvancedUserBase);
        lineSplitAdvUser.setObjectName("lineSplitAdvUser");
        lineSplitAdvUser.setFrameShape(com.trolltech.qt.gui.QFrame.Shape.HLine);
        lineSplitAdvUser.setFrameShadow(com.trolltech.qt.gui.QFrame.Shadow.Sunken);

        gridLayoutAdvUserSettings.addWidget(lineSplitAdvUser, 2, 0, 1, 1);

        horizontalLayoutAdvUserButtonGroup = new QHBoxLayout();
        horizontalLayoutAdvUserButtonGroup.setObjectName("horizontalLayoutAdvUserButtonGroup");
        horizontalSpacerAdvUserButtonGroup = new QSpacerItem(37, 17, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum);

        horizontalLayoutAdvUserButtonGroup.addItem(horizontalSpacerAdvUserButtonGroup);

        btnOk = new QPushButton(AdvancedUserBase);
        btnOk.setObjectName("btnOk");
        btnOk.setMinimumSize(new QSize(75, 23));
        btnOk.setMaximumSize(new QSize(75, 23));
        btnOk.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutAdvUserButtonGroup.addWidget(btnOk);

        btnCancel = new QPushButton(AdvancedUserBase);
        btnCancel.setObjectName("btnCancel");
        btnCancel.setMinimumSize(new QSize(75, 23));
        btnCancel.setMaximumSize(new QSize(75, 23));
        btnCancel.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutAdvUserButtonGroup.addWidget(btnCancel);


        gridLayoutAdvUserSettings.addLayout(horizontalLayoutAdvUserButtonGroup, 3, 0, 1, 1);


        gridLayoutAdvUserDialog.addLayout(gridLayoutAdvUserSettings, 0, 0, 1, 1);

        labelFirstName.setBuddy(lineEditFirstName);
        labelLastName.setBuddy(lineEditLastName);
        labelStreetName.setBuddy(lineEditStreetName);
        labelStreetNumber.setBuddy(lineEditStreetNumber);
        labelCity.setBuddy(lineEditCity);
        labelPostalCode.setBuddy(lineEditPostalCode);
        labelCountry.setBuddy(lineEditCountry);
        QWidget.setTabOrder(lineEditFirstName, lineEditLastName);
        QWidget.setTabOrder(lineEditLastName, lineEditStreetName);
        QWidget.setTabOrder(lineEditStreetName, lineEditStreetNumber);
        QWidget.setTabOrder(lineEditStreetNumber, lineEditCity);
        QWidget.setTabOrder(lineEditCity, lineEditPostalCode);
        QWidget.setTabOrder(lineEditPostalCode, lineEditCountry);
        QWidget.setTabOrder(lineEditCountry, btnOk);
        QWidget.setTabOrder(btnOk, btnCancel);
        retranslateUi(AdvancedUserBase);

        AdvancedUserBase.connectSlotsByName();
    } // setupUi

    void retranslateUi(QDialog AdvancedUserBase)
    {
        AdvancedUserBase.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Dialog"));
        labelFirstName.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Firstname:"));
        labelLastName.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Lastname:"));
        labelStreetName.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Street:"));
        labelStreetNumber.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Street Nr.:"));
        labelCity.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "City (Town):"));
        labelPostalCode.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Postalcode (ZipCode):"));
        labelCountry.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "Country:"));
        btnOk.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "&Ok"));
        btnCancel.setText(com.trolltech.qt.core.QCoreApplication.translate("AdvancedUserBase", "&Cancel"));
    } // retranslateUi

}

