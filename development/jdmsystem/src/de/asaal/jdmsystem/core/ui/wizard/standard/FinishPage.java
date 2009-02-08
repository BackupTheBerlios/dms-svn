package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

import de.asaal.jdmsystem.core.ui.wizard.DatabaseWizard;

public class FinishPage extends QWizardPage
{
  private static FinishPage finishPage = null;
  private UiFinishPage      instance   = null;

  private FinishPage()
  {
    super();
    instance = new UiFinishPage();
    instance.setupUi( this );

    finishPage = this;
  }

  public static FinishPage finishPage()
  {
    if( finishPage != null )
    {
      return finishPage;
    }
    else
    {
      finishPage = new FinishPage();
      return finishPage;
    }
  }

  @Override
  public int nextId()
  {
    return DatabaseWizard.PAGE_FINISH;
  }
}
