/********************************************************************************
** Form generated from reading ui file 'WelcomePage.jui'
**
** Created: So 8. Feb 17:09:09 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiWelcomePage
{

    public UiWelcomePage() { super(); }

    public void setupUi(QWizardPage WelcomePage)
    {
        WelcomePage.setObjectName("WelcomePage");
        WelcomePage.resize(new QSize(470, 300).expandedTo(WelcomePage.minimumSizeHint()));
        WelcomePage.setMinimumSize(new QSize(470, 300));
        WelcomePage.setMaximumSize(new QSize(470, 300));
        retranslateUi(WelcomePage);

        WelcomePage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage WelcomePage)
    {
        WelcomePage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("WelcomePage", "Form"));
        WelcomePage.setTitle(com.trolltech.qt.core.QCoreApplication.translate("WelcomePage", "Welcome to Database wizard"));
    } // retranslateUi

}

