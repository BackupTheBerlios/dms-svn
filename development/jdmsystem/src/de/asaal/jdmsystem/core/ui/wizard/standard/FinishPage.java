package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

public class FinishPage extends QWidget {

    UiFinishPage ui = new UiFinishPage();

    public static void main(String[] args) {
        QApplication.initialize(args);

        FinishPage testFinishPage = new FinishPage();
        testFinishPage.show();

        QApplication.exec();
    }

    public FinishPage() {
        ui.setupUi(this);
    }

    public FinishPage(QWidget parent) {
        super(parent);
        ui.setupUi(this);
    }
}
