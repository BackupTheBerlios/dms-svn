package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.QWizardPage;

import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

public class WelcomePage extends QWizardPage
{
  private static WelcomePage welcomPage = null;
  private UiWelcomePage      instance   = null;

  private WelcomePage()
  {
    instance = new UiWelcomePage();
    instance.setupUi( this );

    welcomPage = this;
  }

  public static WelcomePage welcomePage()
  {
    if( welcomPage != null )
    {
      return welcomPage;
    }
    else
    {
      welcomPage = new WelcomePage();
      return welcomPage;
    }
  }

  @Override
  public int nextId()
  {
    return DatabaseWizard.PAGE_CONNECTION;
  }
}
