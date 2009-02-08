package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.gui.QWizardPage;

public class ConnectionPage extends UiConnectionPage
{

  private QWizardPage           connectionPage = null;
  private static ConnectionPage instance       = null;

  private ConnectionPage()
  {
    super();

    connectionPage = new QWizardPage();
    setupUi( connectionPage );
    instance = this;
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
}
