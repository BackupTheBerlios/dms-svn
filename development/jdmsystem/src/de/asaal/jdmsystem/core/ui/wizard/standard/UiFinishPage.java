/********************************************************************************
** Form generated from reading ui file 'FinishPage.jui'
**
** Created: Di 10. Feb 13:03:58 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiFinishPage
{
    public QGridLayout gridLayout;
    public QLabel label;

    public UiFinishPage() { super(); }

    public void setupUi(QWizardPage FinishPage)
    {
        FinishPage.setObjectName("FinishPage");
        FinishPage.resize(new QSize(470, 300).expandedTo(FinishPage.minimumSizeHint()));
        FinishPage.setMinimumSize(new QSize(470, 300));
        FinishPage.setMaximumSize(new QSize(470, 300));
        gridLayout = new QGridLayout(FinishPage);
        gridLayout.setObjectName("gridLayout");
        label = new QLabel(FinishPage);
        label.setObjectName("label");
        label.setWordWrap(true);

        gridLayout.addWidget(label, 0, 0, 1, 1);

        retranslateUi(FinishPage);

        FinishPage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage FinishPage)
    {
        FinishPage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("FinishPage", "Form"));
        label.setText(com.trolltech.qt.core.QCoreApplication.translate("FinishPage", "Database connection is now configured.\n"+
"\n"+
"\n"+
"If you make configure the database connection again, call this assistant from menu Option -> Database -> Database Assistant.\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
""));
    } // retranslateUi

}

