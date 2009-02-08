package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

public class WelcomePage extends QWidget {

    UiWelcomePage ui = new UiWelcomePage();

    public static void main(String[] args) {
        QApplication.initialize(args);

        WelcomePage testWelcomePage = new WelcomePage();
        testWelcomePage.show();

        QApplication.exec();
    }

    public WelcomePage() {
        ui.setupUi(this);
    }

    public WelcomePage(QWidget parent) {
        super(parent);
        ui.setupUi(this);
    }
}
