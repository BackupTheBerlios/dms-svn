/********************************************************************************
** Form generated from reading ui file 'WelcomePage.jui'
**
** Created: Mo 9. Feb 12:18:21 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiWelcomePage
{
    public QGridLayout gridLayout;
    public QLabel label;

    public UiWelcomePage() { super(); }

    public void setupUi(QWizardPage WelcomePage)
    {
        WelcomePage.setObjectName("WelcomePage");
        WelcomePage.resize(new QSize(470, 300).expandedTo(WelcomePage.minimumSizeHint()));
        WelcomePage.setMinimumSize(new QSize(470, 300));
        WelcomePage.setMaximumSize(new QSize(470, 300));
        gridLayout = new QGridLayout(WelcomePage);
        gridLayout.setObjectName("gridLayout");
        label = new QLabel(WelcomePage);
        label.setObjectName("label");
        label.setWordWrap(true);

        gridLayout.addWidget(label, 0, 0, 1, 1);

        retranslateUi(WelcomePage);

        WelcomePage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage WelcomePage)
    {
        WelcomePage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("WelcomePage", "Form"));
        label.setText(com.trolltech.qt.core.QCoreApplication.translate("WelcomePage", "Thank you for using this Database Assistant. The Database Assistant helps you to create new database or select a existing database.\n"+
"\n"+
"It is recommed you have the MySQL Server  or the MySQL Embedded Server 5.1 installed.\n"+
"\n"+
"\n"+
"\n"+
"\n"+
"\n"+
""));
    } // retranslateUi

}

