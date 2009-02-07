/********************************************************************************
** Form generated from reading ui file 'DocumentBase.jui'
**
** Created: Mi 4. Feb 15:18:05 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiDocumentBase
{
    public QGridLayout gridLayoutDocumentWidget;
    public QGridLayout gridLayoutDocumentBase;
    public QTreeWidget treeWidgetDocument;
    public QGridLayout gridLayoutDocumentSettings;
    public QHBoxLayout horizontalLayoutDocumentId;
    public QLabel labelDocumentId;
    public QLineEdit lineEditDocumentId;
    public QPushButton btnDocId;
    public QHBoxLayout horizontalLayoutDocumentGroup;
    public QLabel labelGroup;
    public QComboBox comboBoxGroup;
    public QPushButton btnGroup;
    public QVBoxLayout verticalLayoutDocumentButtonGroup;
    public QPushButton btnAddDocument;
    public QPushButton btnUpdateDocument;
    public QPushButton btnDeleteDocument;
    public QSpacerItem verticalSpacer;
    public QHBoxLayout horizontalLayoutDocumentUser;
    public QLabel labelUser;
    public QComboBox comboBoxUser;
    public QPushButton btnUser;
    public QHBoxLayout horizontalLayoutDocumentName;
    public QLabel labelDocumentName;
    public QLineEdit lineEditDocumentName;
    public QHBoxLayout horizontalLayoutDocumentPath;
    public QLabel labelDocument;
    public QLineEdit lineEditDocumentPath;
    public QPushButton btnSelectDocument;
    public QFrame lineDocumentSplit;
    public QHBoxLayout horizontalLayoutDocumentWidgetButtonGroup;
    public QSpacerItem horizontalSpacerDocumentWidget;
    public QPushButton btnOk;
    public QPushButton btnCancel;

    public UiDocumentBase() { super(); }

    public void setupUi(QWidget DocumentBase)
    {
        DocumentBase.setObjectName("DocumentBase");
        DocumentBase.resize(new QSize(640, 415).expandedTo(DocumentBase.minimumSizeHint()));
        DocumentBase.setMinimumSize(new QSize(640, 415));
        gridLayoutDocumentWidget = new QGridLayout(DocumentBase);
        gridLayoutDocumentWidget.setObjectName("gridLayoutDocumentWidget");
        gridLayoutDocumentBase = new QGridLayout();
        gridLayoutDocumentBase.setObjectName("gridLayoutDocumentBase");
        treeWidgetDocument = new QTreeWidget(DocumentBase);
        treeWidgetDocument.setObjectName("treeWidgetDocument");
        treeWidgetDocument.setRootIsDecorated(false);
        treeWidgetDocument.setSortingEnabled(true);

        gridLayoutDocumentBase.addWidget(treeWidgetDocument, 0, 0, 1, 1);

        gridLayoutDocumentSettings = new QGridLayout();
        gridLayoutDocumentSettings.setObjectName("gridLayoutDocumentSettings");
        horizontalLayoutDocumentId = new QHBoxLayout();
        horizontalLayoutDocumentId.setObjectName("horizontalLayoutDocumentId");
        labelDocumentId = new QLabel(DocumentBase);
        labelDocumentId.setObjectName("labelDocumentId");
        labelDocumentId.setMinimumSize(new QSize(110, 0));
        labelDocumentId.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDocumentId.addWidget(labelDocumentId);

        lineEditDocumentId = new QLineEdit(DocumentBase);
        lineEditDocumentId.setObjectName("lineEditDocumentId");
        lineEditDocumentId.setEnabled(false);
        lineEditDocumentId.setFrame(true);
        lineEditDocumentId.setReadOnly(true);

        horizontalLayoutDocumentId.addWidget(lineEditDocumentId);

        btnDocId = new QPushButton(DocumentBase);
        btnDocId.setObjectName("btnDocId");
        btnDocId.setMinimumSize(new QSize(23, 23));
        btnDocId.setMaximumSize(new QSize(23, 23));

        horizontalLayoutDocumentId.addWidget(btnDocId);


        gridLayoutDocumentSettings.addLayout(horizontalLayoutDocumentId, 0, 0, 1, 2);

        horizontalLayoutDocumentGroup = new QHBoxLayout();
        horizontalLayoutDocumentGroup.setObjectName("horizontalLayoutDocumentGroup");
        labelGroup = new QLabel(DocumentBase);
        labelGroup.setObjectName("labelGroup");
        labelGroup.setMinimumSize(new QSize(110, 0));
        labelGroup.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDocumentGroup.addWidget(labelGroup);

        comboBoxGroup = new QComboBox(DocumentBase);
        comboBoxGroup.setObjectName("comboBoxGroup");

        horizontalLayoutDocumentGroup.addWidget(comboBoxGroup);

        btnGroup = new QPushButton(DocumentBase);
        btnGroup.setObjectName("btnGroup");
        btnGroup.setMinimumSize(new QSize(23, 23));
        btnGroup.setMaximumSize(new QSize(23, 23));

        horizontalLayoutDocumentGroup.addWidget(btnGroup);


        gridLayoutDocumentSettings.addLayout(horizontalLayoutDocumentGroup, 1, 0, 1, 1);

        verticalLayoutDocumentButtonGroup = new QVBoxLayout();
        verticalLayoutDocumentButtonGroup.setObjectName("verticalLayoutDocumentButtonGroup");
        btnAddDocument = new QPushButton(DocumentBase);
        btnAddDocument.setObjectName("btnAddDocument");
        btnAddDocument.setMinimumSize(new QSize(75, 23));
        btnAddDocument.setMaximumSize(new QSize(75, 23));

        verticalLayoutDocumentButtonGroup.addWidget(btnAddDocument);

        btnUpdateDocument = new QPushButton(DocumentBase);
        btnUpdateDocument.setObjectName("btnUpdateDocument");
        btnUpdateDocument.setMinimumSize(new QSize(75, 23));
        btnUpdateDocument.setMaximumSize(new QSize(75, 23));

        verticalLayoutDocumentButtonGroup.addWidget(btnUpdateDocument);

        btnDeleteDocument = new QPushButton(DocumentBase);
        btnDeleteDocument.setObjectName("btnDeleteDocument");
        btnDeleteDocument.setMinimumSize(new QSize(75, 23));
        btnDeleteDocument.setMaximumSize(new QSize(75, 23));

        verticalLayoutDocumentButtonGroup.addWidget(btnDeleteDocument);

        verticalSpacer = new QSpacerItem(0, 0, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        verticalLayoutDocumentButtonGroup.addItem(verticalSpacer);


        gridLayoutDocumentSettings.addLayout(verticalLayoutDocumentButtonGroup, 1, 1, 3, 1);

        horizontalLayoutDocumentUser = new QHBoxLayout();
        horizontalLayoutDocumentUser.setObjectName("horizontalLayoutDocumentUser");
        labelUser = new QLabel(DocumentBase);
        labelUser.setObjectName("labelUser");
        labelUser.setMinimumSize(new QSize(110, 0));
        labelUser.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDocumentUser.addWidget(labelUser);

        comboBoxUser = new QComboBox(DocumentBase);
        comboBoxUser.setObjectName("comboBoxUser");

        horizontalLayoutDocumentUser.addWidget(comboBoxUser);

        btnUser = new QPushButton(DocumentBase);
        btnUser.setObjectName("btnUser");
        btnUser.setMinimumSize(new QSize(23, 23));
        btnUser.setMaximumSize(new QSize(23, 23));

        horizontalLayoutDocumentUser.addWidget(btnUser);


        gridLayoutDocumentSettings.addLayout(horizontalLayoutDocumentUser, 2, 0, 1, 1);

        horizontalLayoutDocumentName = new QHBoxLayout();
        horizontalLayoutDocumentName.setObjectName("horizontalLayoutDocumentName");
        labelDocumentName = new QLabel(DocumentBase);
        labelDocumentName.setObjectName("labelDocumentName");
        labelDocumentName.setMinimumSize(new QSize(110, 0));
        labelDocumentName.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDocumentName.addWidget(labelDocumentName);

        lineEditDocumentName = new QLineEdit(DocumentBase);
        lineEditDocumentName.setObjectName("lineEditDocumentName");
        lineEditDocumentName.setFrame(true);

        horizontalLayoutDocumentName.addWidget(lineEditDocumentName);


        gridLayoutDocumentSettings.addLayout(horizontalLayoutDocumentName, 3, 0, 1, 1);

        horizontalLayoutDocumentPath = new QHBoxLayout();
        horizontalLayoutDocumentPath.setObjectName("horizontalLayoutDocumentPath");
        labelDocument = new QLabel(DocumentBase);
        labelDocument.setObjectName("labelDocument");
        labelDocument.setMinimumSize(new QSize(110, 0));
        labelDocument.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutDocumentPath.addWidget(labelDocument);

        lineEditDocumentPath = new QLineEdit(DocumentBase);
        lineEditDocumentPath.setObjectName("lineEditDocumentPath");
        lineEditDocumentPath.setFrame(true);

        horizontalLayoutDocumentPath.addWidget(lineEditDocumentPath);

        btnSelectDocument = new QPushButton(DocumentBase);
        btnSelectDocument.setObjectName("btnSelectDocument");
        btnSelectDocument.setMinimumSize(new QSize(23, 23));
        btnSelectDocument.setMaximumSize(new QSize(23, 23));

        horizontalLayoutDocumentPath.addWidget(btnSelectDocument);


        gridLayoutDocumentSettings.addLayout(horizontalLayoutDocumentPath, 4, 0, 1, 2);


        gridLayoutDocumentBase.addLayout(gridLayoutDocumentSettings, 1, 0, 1, 1);

        lineDocumentSplit = new QFrame(DocumentBase);
        lineDocumentSplit.setObjectName("lineDocumentSplit");
        lineDocumentSplit.setFrameShape(com.trolltech.qt.gui.QFrame.Shape.HLine);
        lineDocumentSplit.setFrameShadow(com.trolltech.qt.gui.QFrame.Shadow.Sunken);

        gridLayoutDocumentBase.addWidget(lineDocumentSplit, 2, 0, 1, 1);

        horizontalLayoutDocumentWidgetButtonGroup = new QHBoxLayout();
        horizontalLayoutDocumentWidgetButtonGroup.setObjectName("horizontalLayoutDocumentWidgetButtonGroup");
        horizontalSpacerDocumentWidget = new QSpacerItem(37, 17, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum);

        horizontalLayoutDocumentWidgetButtonGroup.addItem(horizontalSpacerDocumentWidget);

        btnOk = new QPushButton(DocumentBase);
        btnOk.setObjectName("btnOk");
        btnOk.setMinimumSize(new QSize(75, 23));
        btnOk.setMaximumSize(new QSize(75, 23));

        horizontalLayoutDocumentWidgetButtonGroup.addWidget(btnOk);

        btnCancel = new QPushButton(DocumentBase);
        btnCancel.setObjectName("btnCancel");
        btnCancel.setMinimumSize(new QSize(75, 23));
        btnCancel.setMaximumSize(new QSize(75, 23));

        horizontalLayoutDocumentWidgetButtonGroup.addWidget(btnCancel);


        gridLayoutDocumentBase.addLayout(horizontalLayoutDocumentWidgetButtonGroup, 3, 0, 1, 1);


        gridLayoutDocumentWidget.addLayout(gridLayoutDocumentBase, 0, 0, 1, 1);

        labelDocumentId.setBuddy(lineEditDocumentId);
        labelGroup.setBuddy(comboBoxGroup);
        labelUser.setBuddy(comboBoxUser);
        labelDocumentName.setBuddy(lineEditDocumentName);
        labelDocument.setBuddy(lineEditDocumentPath);
        retranslateUi(DocumentBase);

        DocumentBase.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWidget DocumentBase)
    {
        DocumentBase.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Form"));
        treeWidgetDocument.headerItem().setText(0, com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "User"));
        treeWidgetDocument.headerItem().setText(1, com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Document"));
        treeWidgetDocument.headerItem().setText(2, com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Group"));
        treeWidgetDocument.headerItem().setText(3, com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Documentpath"));
        labelDocumentId.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Document ID:"));
        btnDocId.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", ""));
        labelGroup.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Group:"));
        btnGroup.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "..."));
        btnAddDocument.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "&Add"));
        btnUpdateDocument.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "&Update"));
        btnDeleteDocument.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "&Delete"));
        labelUser.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "User:"));
        btnUser.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "..."));
        labelDocumentName.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Document name:"));
        labelDocument.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "Document:"));
        btnSelectDocument.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "..."));
        btnOk.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "&Ok"));
        btnCancel.setText(com.trolltech.qt.core.QCoreApplication.translate("DocumentBase", "&Cancel"));
    } // retranslateUi

}

