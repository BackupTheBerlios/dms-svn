/********************************************************************************
** Form generated from reading ui file 'ExceptionLogBase.jui'
**
** Created: Fr 6. Feb 11:53:15 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiExceptionLogBase
{
    public QGridLayout gridLayoutException;
    public QHBoxLayout horizontalLayoutGroupBy;
    public QLabel labelGroupBy;
    public QComboBox comboBoxGroupBy;
    public QHBoxLayout horizontalLayoutGroupByDate;
    public QLabel labelDate;
    public QDateEdit dateEditFirst;
    public QDateEdit dateEditSecond;
    public QTreeWidget treeWidgetExceptions;
    public QGridLayout gridLayoutSqlMessage;
    public QLabel labelSqlMessage;
    public QTextBrowser textBrowserSqlMessage;
    public QSpacerItem verticalSpacerSqlMessage;
    public QGridLayout gridLayoutMessage;
    public QLabel labelMessage;
    public QTextBrowser textBrowserMessage;
    public QSpacerItem verticalSpacerMessage;
    public QHBoxLayout horizontalLayoutExceptionButtonGroup;
    public QPushButton btnSendMail;
    public QSpacerItem horizontalSpacer;
    public QPushButton btnOk;
    public QPushButton btnCancel;

    public UiExceptionLogBase() { super(); }

    public void setupUi(QWidget ExceptionLogBase)
    {
        ExceptionLogBase.setObjectName("ExceptionLogBase");
        ExceptionLogBase.resize(new QSize(730, 480).expandedTo(ExceptionLogBase.minimumSizeHint()));
        ExceptionLogBase.setMinimumSize(new QSize(730, 480));
        gridLayoutException = new QGridLayout(ExceptionLogBase);
        gridLayoutException.setObjectName("gridLayoutException");
        horizontalLayoutGroupBy = new QHBoxLayout();
        horizontalLayoutGroupBy.setObjectName("horizontalLayoutGroupBy");
        labelGroupBy = new QLabel(ExceptionLogBase);
        labelGroupBy.setObjectName("labelGroupBy");
        labelGroupBy.setMinimumSize(new QSize(110, 0));
        labelGroupBy.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutGroupBy.addWidget(labelGroupBy);

        comboBoxGroupBy = new QComboBox(ExceptionLogBase);
        comboBoxGroupBy.setObjectName("comboBoxGroupBy");
        comboBoxGroupBy.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);

        horizontalLayoutGroupBy.addWidget(comboBoxGroupBy);


        gridLayoutException.addLayout(horizontalLayoutGroupBy, 0, 0, 1, 1);

        horizontalLayoutGroupByDate = new QHBoxLayout();
        horizontalLayoutGroupByDate.setObjectName("horizontalLayoutGroupByDate");
        labelDate = new QLabel(ExceptionLogBase);
        labelDate.setObjectName("labelDate");
        labelDate.setMinimumSize(new QSize(110, 0));
        labelDate.setMaximumSize(new QSize(110, 16777215));

        horizontalLayoutGroupByDate.addWidget(labelDate);

        dateEditFirst = new QDateEdit(ExceptionLogBase);
        dateEditFirst.setObjectName("dateEditFirst");
        dateEditFirst.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);
        dateEditFirst.setCalendarPopup(true);
        dateEditFirst.setDate(new QDate(2009, 2, 6));

        horizontalLayoutGroupByDate.addWidget(dateEditFirst);

        dateEditSecond = new QDateEdit(ExceptionLogBase);
        dateEditSecond.setObjectName("dateEditSecond");
        dateEditSecond.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);
        dateEditSecond.setCalendarPopup(true);
        dateEditSecond.setDate(new QDate(2009, 2, 6));

        horizontalLayoutGroupByDate.addWidget(dateEditSecond);


        gridLayoutException.addLayout(horizontalLayoutGroupByDate, 1, 0, 1, 1);

        treeWidgetExceptions = new QTreeWidget(ExceptionLogBase);
        treeWidgetExceptions.setObjectName("treeWidgetExceptions");
        treeWidgetExceptions.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);
        treeWidgetExceptions.setContextMenuPolicy(com.trolltech.qt.core.Qt.ContextMenuPolicy.CustomContextMenu);

        gridLayoutException.addWidget(treeWidgetExceptions, 2, 0, 1, 1);

        gridLayoutSqlMessage = new QGridLayout();
        gridLayoutSqlMessage.setObjectName("gridLayoutSqlMessage");
        labelSqlMessage = new QLabel(ExceptionLogBase);
        labelSqlMessage.setObjectName("labelSqlMessage");
        labelSqlMessage.setMinimumSize(new QSize(110, 0));
        labelSqlMessage.setMaximumSize(new QSize(110, 16777215));

        gridLayoutSqlMessage.addWidget(labelSqlMessage, 0, 0, 1, 1);

        textBrowserSqlMessage = new QTextBrowser(ExceptionLogBase);
        textBrowserSqlMessage.setObjectName("textBrowserSqlMessage");
        textBrowserSqlMessage.setProperty("cursor", new QCursor(Qt.CursorShape.ArrowCursor));
        textBrowserSqlMessage.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);
        textBrowserSqlMessage.setOpenLinks(false);

        gridLayoutSqlMessage.addWidget(textBrowserSqlMessage, 0, 1, 2, 1);

        verticalSpacerSqlMessage = new QSpacerItem(17, 37, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        gridLayoutSqlMessage.addItem(verticalSpacerSqlMessage, 1, 0, 1, 1);


        gridLayoutException.addLayout(gridLayoutSqlMessage, 3, 0, 1, 1);

        gridLayoutMessage = new QGridLayout();
        gridLayoutMessage.setObjectName("gridLayoutMessage");
        labelMessage = new QLabel(ExceptionLogBase);
        labelMessage.setObjectName("labelMessage");
        labelMessage.setMinimumSize(new QSize(110, 0));
        labelMessage.setMaximumSize(new QSize(110, 16777215));

        gridLayoutMessage.addWidget(labelMessage, 0, 0, 1, 1);

        textBrowserMessage = new QTextBrowser(ExceptionLogBase);
        textBrowserMessage.setObjectName("textBrowserMessage");
        textBrowserMessage.setProperty("cursor", new QCursor(Qt.CursorShape.ArrowCursor));
        textBrowserMessage.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.WheelFocus);
        textBrowserMessage.setOpenLinks(false);

        gridLayoutMessage.addWidget(textBrowserMessage, 0, 1, 2, 1);

        verticalSpacerMessage = new QSpacerItem(17, 37, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding);

        gridLayoutMessage.addItem(verticalSpacerMessage, 1, 0, 1, 1);


        gridLayoutException.addLayout(gridLayoutMessage, 4, 0, 1, 1);

        horizontalLayoutExceptionButtonGroup = new QHBoxLayout();
        horizontalLayoutExceptionButtonGroup.setObjectName("horizontalLayoutExceptionButtonGroup");
        btnSendMail = new QPushButton(ExceptionLogBase);
        btnSendMail.setObjectName("btnSendMail");
        btnSendMail.setMinimumSize(new QSize(75, 23));
        btnSendMail.setMaximumSize(new QSize(75, 23));
        btnSendMail.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutExceptionButtonGroup.addWidget(btnSendMail);

        horizontalSpacer = new QSpacerItem(37, 17, com.trolltech.qt.gui.QSizePolicy.Policy.Expanding, com.trolltech.qt.gui.QSizePolicy.Policy.Minimum);

        horizontalLayoutExceptionButtonGroup.addItem(horizontalSpacer);

        btnOk = new QPushButton(ExceptionLogBase);
        btnOk.setObjectName("btnOk");
        btnOk.setMinimumSize(new QSize(75, 23));
        btnOk.setMaximumSize(new QSize(75, 23));
        btnOk.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutExceptionButtonGroup.addWidget(btnOk);

        btnCancel = new QPushButton(ExceptionLogBase);
        btnCancel.setObjectName("btnCancel");
        btnCancel.setMinimumSize(new QSize(75, 23));
        btnCancel.setMaximumSize(new QSize(75, 23));
        btnCancel.setFocusPolicy(com.trolltech.qt.core.Qt.FocusPolicy.StrongFocus);

        horizontalLayoutExceptionButtonGroup.addWidget(btnCancel);


        gridLayoutException.addLayout(horizontalLayoutExceptionButtonGroup, 5, 0, 1, 1);

        QWidget.setTabOrder(comboBoxGroupBy, dateEditFirst);
        QWidget.setTabOrder(dateEditFirst, dateEditSecond);
        QWidget.setTabOrder(dateEditSecond, treeWidgetExceptions);
        QWidget.setTabOrder(treeWidgetExceptions, textBrowserSqlMessage);
        QWidget.setTabOrder(textBrowserSqlMessage, textBrowserMessage);
        QWidget.setTabOrder(textBrowserMessage, btnSendMail);
        QWidget.setTabOrder(btnSendMail, btnOk);
        QWidget.setTabOrder(btnOk, btnCancel);
        retranslateUi(ExceptionLogBase);

        comboBoxGroupBy.setCurrentIndex(2);


        ExceptionLogBase.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWidget ExceptionLogBase)
    {
        ExceptionLogBase.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Error Log"));
        labelGroupBy.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Group by:"));
        comboBoxGroupBy.clear();
        comboBoxGroupBy.addItem(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", ""));
        comboBoxGroupBy.addItem(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Name"));
        comboBoxGroupBy.addItem(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Date"));
        comboBoxGroupBy.addItem(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Exception"));
        comboBoxGroupBy.addItem(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "File"));
        labelDate.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Date:"));
        treeWidgetExceptions.headerItem().setText(0, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "SQL State"));
        treeWidgetExceptions.headerItem().setText(1, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "SQL Vendor code"));
        treeWidgetExceptions.headerItem().setText(2, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Classname"));
        treeWidgetExceptions.headerItem().setText(3, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Filename"));
        treeWidgetExceptions.headerItem().setText(4, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Line number"));
        treeWidgetExceptions.headerItem().setText(5, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Methode"));
        treeWidgetExceptions.headerItem().setText(6, com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Created"));
        labelSqlMessage.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "SQL Message:"));
        labelMessage.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "Message:"));
        btnSendMail.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "&Send eMail"));
        btnOk.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "&Ok"));
        btnCancel.setText(com.trolltech.qt.core.QCoreApplication.translate("ExceptionLogBase", "C&ancel"));
    } // retranslateUi

}

