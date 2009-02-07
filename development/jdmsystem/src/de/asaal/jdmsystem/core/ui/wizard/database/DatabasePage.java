package de.asaal.jdmsystem.core.ui.wizard.database;

import com.trolltech.qt.gui.*;

public class DatabasePage extends UiDatabasePage
{
  private QWizardPage databasePage = null;

  public DatabasePage()
  {
    databasePage = new QWizardPage();
    setupUi( databasePage );
  }
}
