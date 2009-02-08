package de.asaal.jdmsystem.core.ui.wizard.standard;

import com.trolltech.qt.gui.*;

public class FinishPage extends UiFinishPage
{
  private QWizardPage       finishPage = null;
  private static FinishPage instance   = null;

  private FinishPage()
  {
    finishPage = new QWizardPage();
    setupUi( finishPage );

    instance = this;
  }

  public static FinishPage finishPageInstance()
  {
    if( instance != null )
    {
      return instance;
    }
    else
    {
      instance = new FinishPage();
      return instance;
    }
  }
}
