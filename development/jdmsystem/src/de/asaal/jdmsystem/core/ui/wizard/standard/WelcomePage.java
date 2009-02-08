package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

public class WelcomePage extends UiWelcomePage
{

  private QWizardPage        welcomPage = null;
  private static WelcomePage instance   = null;

  private WelcomePage()
  {
    welcomPage = new QWizardPage();
    setupUi( welcomPage );

    instance = this;
  }

  public static WelcomePage welcomePageInstance()
  {
    if( instance != null )
    {
      return instance;
    }
    else
    {
      instance = new WelcomePage();
      return instance;
    }
  }
}
