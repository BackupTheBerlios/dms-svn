package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

public class WelcomePage extends UiWelcomePage
{

  private QWizardPage welcomPage = null;

  public WelcomePage()
  {
    welcomPage = new QWizardPage();
    setupUi( welcomPage );
  }
}
