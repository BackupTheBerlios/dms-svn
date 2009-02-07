package de.asaal.jdmsystem.core.ui.wizard;

import com.trolltech.qt.gui.QApplication;
import com.trolltech.qt.gui.QDialog;
import com.trolltech.qt.gui.QWidget;

public class MySqlConnection extends QDialog
{

  UiMySqlConnection ui = new UiMySqlConnection();

  public static void main( String[] args )
  {
    QApplication.initialize( args );

    MySqlConnection testMySqlConnection = new MySqlConnection();
    testMySqlConnection.show();

    QApplication.exec();
  }

  public MySqlConnection()
  {
    ui.setupUi( this );
  }

  public MySqlConnection( QWidget parent )
  {
    super( parent );
    ui.setupUi( this );
  }
}
