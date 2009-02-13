package de.asaal.jdmsystem.core.dto;

public class ExceptionStackDTO
{
  protected String sqlId           = null;
  private String   sqlMessage      = null;
  private String   sqlState        = null;
  private String   sqlVendorCode   = null;

  private String   message         = null;
  private String   className       = null;
  private String   fileName        = null;
  private String   lineNumber      = null;
  private String   methodeName     = null;
  private String   hashCode        = null;
  private String   isNativeMethode = null;

  private String   created         = null;

  public ExceptionStackDTO()
  {}

  public String getSqlId()
  {
    return sqlId;
  }

  public void setSqlId( String sqlId )
  {
    this.sqlId = sqlId;
  }

  public String getSqlMessage()
  {
    return sqlMessage;
  }

  public void setSqlMessage( String sqlMessage )
  {
    this.sqlMessage = sqlMessage;
  }

  public String getSqlState()
  {
    return sqlState;
  }

  public void setSqlState( String sqlState )
  {
    this.sqlState = sqlState;
  }

  public String getSqlVendorCode()
  {
    return sqlVendorCode;
  }

  public void setSqlVendorCode( String sqlVendorCode )
  {
    this.sqlVendorCode = sqlVendorCode;
  }

  public String getMessage()
  {
    return message;
  }

  public void setMessage( String message )
  {
    this.message = message;
  }

  public String getClassName()
  {
    return className;
  }

  public void setClassName( String className )
  {
    this.className = className;
  }

  public String getFileName()
  {
    return fileName;
  }

  public void setFileName( String fileName )
  {
    this.fileName = fileName;
  }

  public String getLineNumber()
  {
    return lineNumber;
  }

  public void setLineNumber( String lineNumber )
  {
    this.lineNumber = lineNumber;
  }

  public String getMethodeName()
  {
    return methodeName;
  }

  public void setMethodeName( String methodeName )
  {
    this.methodeName = methodeName;
  }

  public String getHashCode()
  {
    return hashCode;
  }

  public void setHashCode( String hashCode )
  {
    this.hashCode = hashCode;
  }

  public String getIsNativeMethode()
  {
    return isNativeMethode;
  }

  public void setIsNativeMethode( String isNativeMethode )
  {
    this.isNativeMethode = isNativeMethode;
  }

  public String getCreated()
  {
    return created;
  }

  public void setCreated( String created )
  {
    this.created = created;
  }

}
