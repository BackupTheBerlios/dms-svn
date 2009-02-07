package de.asaal.jdmsystem.core.ui;

import com.trolltech.qt.gui.QWidget;

import de.asaal.jdmsystem.JDMSystemBase;
import de.asaal.jdmsystem.core.JDMSystemLibrary;
import de.asaal.jdmsystem.core.iface.IWidget;

public class ExceptionLogBase extends UiExceptionLogBase implements IWidget
{

  private QWidget                 exceptionLogBase = null;
  private JDMSystemLibrary        systemLibrary    = null;

  private static ExceptionLogBase instance         = null;

  public ExceptionLogBase()
  {
    super();

    systemLibrary = JDMSystemBase.systemLibraryInstance();
    instance = this;

    exceptionLogBase = new QWidget();
    setupUi( exceptionLogBase );

    initialConnections();
    realoadExceptions();
  }

  @Override
  public void initialConnections()
  {
    try
    {
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void close()
  {
    try
    {
      exceptionLogBase.close();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  @Override
  public void show()
  {
    try
    {
      exceptionLogBase.show();
    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  /**
   * Returns a instance {@link ExceptionLogBase}
   */
  public static ExceptionLogBase exceptionLogBaseInstance()
  {
    return instance;
  }

  protected void search()
  {
    try
    {

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  protected void sendMail()
  {
    try
    {

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

  private void realoadExceptions()
  {
    try
    {

    }
    catch( Exception ex )
    {
      systemLibrary.createExceptions( ex, null );
    }
  }

}
