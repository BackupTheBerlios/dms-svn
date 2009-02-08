package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.gui.QWizardPage;

import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

public class ConnectionPage extends QWizardPage
{
  private static ConnectionPage instance   = null;
  private UiConnectionPage      uiInstance = null;

  private ConnectionPage()
  {
    super();

    uiInstance = new UiConnectionPage();
    uiInstance.setupUi( this );
  }

  public static ConnectionPage connectionPage()
  {
    if( instance != null )
    {
      return instance;
    }
    else
    {
      instance = new ConnectionPage();
      return instance;
    }
  }

  @Override
  public int nextId()
  {
    return DatabaseWizard.PAGE_DATABASE;
  }
}
