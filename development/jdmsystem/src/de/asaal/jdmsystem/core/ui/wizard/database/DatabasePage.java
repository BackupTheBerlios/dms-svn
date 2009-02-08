package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.gui.*;

import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

public class DatabasePage extends QWizardPage
{
  private static DatabasePage instance   = null;
  private UiConnectionPage    uiInstance = null;

  private DatabasePage()
  {
    super();
    uiInstance = new UiConnectionPage();
    uiInstance.setupUi( this );
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

  @Override
  public int nextId()
  {
    return DatabaseWizard.PAGE_FINISH;
  }
}
