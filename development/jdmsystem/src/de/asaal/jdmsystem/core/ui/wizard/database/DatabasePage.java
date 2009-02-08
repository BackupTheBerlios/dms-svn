package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.gui.*;

public class DatabasePage extends UiDatabasePage
{
  private QWizardPage         databasePage = null;
  private static DatabasePage instance     = null;

  public DatabasePage()
  {
    databasePage = new QWizardPage();
    setupUi( databasePage );
    instance = this;
  }

  public static DatabasePage databasePage()
  {
    if( instance != null )
    {
      return instance;
    }
    else
    {
      instance = new DatabasePage();
      return instance;
    }
  }
}
