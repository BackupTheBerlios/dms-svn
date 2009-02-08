/********************************************************************************
** Form generated from reading ui file 'ConnectionPage.jui'
**
** Created: So 8. Feb 13:27:42 2009
**      by: Qt User Interface Compiler version 4.4.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.core.*;
import com.trolltech.qt.gui.*;

public class UiConnectionPage
{

    public UiConnectionPage() { super(); }

    public void setupUi(QWizardPage ConnectionPage)
    {
        ConnectionPage.setObjectName("ConnectionPage");
        ConnectionPage.resize(new QSize(400, 300).expandedTo(ConnectionPage.minimumSizeHint()));
        retranslateUi(ConnectionPage);

        ConnectionPage.connectSlotsByName();
    } // setupUi

    void retranslateUi(QWizardPage ConnectionPage)
    {
        ConnectionPage.setWindowTitle(com.trolltech.qt.core.QCoreApplication.translate("ConnectionPage", "Form"));
    } // retranslateUi

}

