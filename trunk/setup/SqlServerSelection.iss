[CustomMessages]
SqlServerSelection_Caption=SQL Server Option
SqlServerSelection_Description=Select a SQL Server for your system.
SqlServerSelection_lblInformation_Caption0=Whish SQL Server would you like use on your system?
SqlServerSelection_rbtnMySql50_Caption0=My SQL 5.0.45 Generally Available (GA) Release
SqlServerSelection_rbtnMySql51_Caption0=MySQL 5.1.22 Development Release
SqlServerSelection_rbznMsSql2005_Caption0=Microsoft SQL Server 2005
SqlServerSelection_rbtnMsAccess2003_Caption0=Microsoft Access 2003

[Code]
var
  lblInformation: TLabel;
  rbtnMySql50: TRadioButton;
  rbtnMySql51: TRadioButton;
  rbznMsSql2005: TRadioButton;
  rbtnMsAccess2003: TRadioButton;
  selectedMySql: String;
  mysqlFile: String;
  sqlPageId: Integer;

procedure SqlServerSelection_Activate(Page: TWizardPage);
begin
  // enter code here...
end;

function SqlServerSelection_ShouldSkipPage(Page: TWizardPage): Boolean;
begin
  Result := False;
end;

function SqlServerSelection_BackButtonClick(Page: TWizardPage): Boolean;
begin
  Result := True;
end;

function SqlServerSelection_NextButtonClick(Page: TWizardPage): Boolean;
var
  res: Boolean;

begin
	if( rbtnMySql50.Checked = True ) then
	begin
		selectedMySql := 'http://dev.mysql.com/get/Downloads/MySQL-5.0/mysql-essential-5.0.45-win32.msi/from/http://ftp.gwdg.de/pub/misc/mysql/';
		mysqlFile := 'mysql-essential-5.0.45-win32.msi';
		res := True;
	end
	else if( rbtnMySql51.Checked = True ) then
	begin
		selectedMySql := 'http://dev.mysql.com/get/Downloads/MySQL-5.1/mysql-essential-5.1.22-rc-win32.msi/from/http://ftp.gwdg.de/pub/misc/mysql/';
		mysqlFile :=  'mysql-essential-5.1.22-rc-win32.msi';
		res := True;
	end
	else if( rbznMsSql2005.Checked = True ) then
	begin
		mysqlFile := '';
		if( RegKeyExists( HKEY_LOCAL_MACHINE, 'SOFTWARE\Microsoft\Microsoft SQL Server' ) )then
		begin
			res := True;
		end
		else
		begin
			if MsgBox('No Microsoft SQL Server 2005 was found on your system. Are you sure to continue?', mbCriticalError, MB_YESNO or MB_DEFBUTTON2) = IDYES then
			begin
				res := True;
			end;

			res := False;
		end
	end
	else if( rbtnMsAccess2003.Checked = True ) then
	begin
		mysqlFile := '';
		if( RegKeyExists( HKEY_CURRENT_USER, 'Software\Microsoft\Office\11.0\Access' ) )then
		begin
			res := True;
		end
		else
		begin
			if MsgBox('No Microsoft Access was found on your system. Are you sure to continue?', mbCriticalError, MB_YESNO or MB_DEFBUTTON2) = IDYES then
			begin
				res := True;
			end;

			res := False;
		end
	end

	Result := res;
end;

procedure SqlServerSelection_CancelButtonClick(Page: TWizardPage; var Cancel, Confirm: Boolean);
begin
  // enter code here...
end;

function SqlServerSelection_CreatePage(PreviousPageId: Integer): Integer;
var
  Page: TWizardPage;
begin
  Page := CreateCustomPage(
    PreviousPageId,
    ExpandConstant('{cm:SqlServerSelection_Caption}'),
    ExpandConstant('{cm:SqlServerSelection_Description}')
  );

  lblInformation := TLabel.Create(Page);
  with lblInformation do
  begin
    Parent := Page.Surface;
    Caption := ExpandConstant('{cm:SqlServerSelection_lblInformation_Caption0}');
    Left := ScaleX(0);
    Top := ScaleY(0);
    Width := ScaleX(255);
    Height := ScaleY(13);
  end;

  rbtnMySql50 := TRadioButton.Create(Page);
  with rbtnMySql50 do
  begin
    Parent := Page.Surface;
    Caption := ExpandConstant('{cm:SqlServerSelection_rbtnMySql50_Caption0}');
    Left := ScaleX(0);
    Top := ScaleY(24);
    Width := ScaleX(413);
    Height := ScaleY(17);
    Checked := True;
    Font.Height := ScaleY(-15);
    Font.Name := 'Tahoma';
    TabOrder := 0;
    TabStop := True;
  end;

  rbtnMySql51 := TRadioButton.Create(Page);
  with rbtnMySql51 do
  begin
    Parent := Page.Surface;
    Caption := ExpandConstant('{cm:SqlServerSelection_rbtnMySql51_Caption0}');
    Left := ScaleX(0);
    Top := ScaleY(48);
    Width := ScaleX(413);
    Height := ScaleY(17);
    Font.Height := ScaleY(-15);
    Font.Name := 'Tahoma';
    TabOrder := 1;
  end;

  rbznMsSql2005 := TRadioButton.Create(Page);
  with rbznMsSql2005 do
  begin
    Parent := Page.Surface;
    Caption := ExpandConstant('{cm:SqlServerSelection_rbznMsSql2005_Caption0}');
    Left := ScaleX(0);
    Top := ScaleY(72);
    Width := ScaleX(413);
    Height := ScaleY(17);
    Font.Height := ScaleY(-15);
    Font.Name := 'Tahoma';
    TabOrder := 2;
  end;

  rbtnMsAccess2003 := TRadioButton.Create(Page);
  with rbtnMsAccess2003 do
  begin
    Parent := Page.Surface;
    Caption := ExpandConstant('{cm:SqlServerSelection_rbtnMsAccess2003_Caption0}');
    Left := ScaleX(0);
    Top := ScaleY(96);
    Width := ScaleX(413);
    Height := ScaleY(17);
    Font.Height := ScaleY(-15);
    Font.Name := 'Tahoma';
    TabOrder := 3;
  end;

  with Page do
  begin
    OnActivate := @SqlServerSelection_Activate;
    OnShouldSkipPage := @SqlServerSelection_ShouldSkipPage;
    OnBackButtonClick := @SqlServerSelection_BackButtonClick;
    OnNextButtonClick := @SqlServerSelection_NextButtonClick;
    OnCancelButtonClick := @SqlServerSelection_CancelButtonClick;
  end;

  Result := Page.ID;
end;

function IsMySqlInstalled(): Boolean;
var
	installed: Boolean;
begin
	if( RegKeyExists( HKEY_LOCAL_MACHINE, 'SOFTWARE\MySQL AB\MySQL Server 5.1' ) )then
	begin
		installed := True;
	end;

	Result := installed;
end;

function NextButtonClick(CurPageID: Integer): Boolean;
var
	ErrorCode: Integer;

begin
	if( not IsMySqlInstalled() ) then
	begin
		if( mysqlFile <> '' ) then
		begin
			if( CurPageID = sqlPageId ) then
			begin
				itd_init;
				itd_addfile( selectedMySql, ExpandConstant( '{tmp}\' + mysqlFile ) );
				itd_downloadafter(sqlPageId);
			end;

			if( CurPageID = wpReady ) then
			begin
				ShellExec('', ExpandConstant( '{tmp}\' + mysqlFile ), '', '', SW_SHOW, ewWaitUntilTerminated, ErrorCode );
			end;
		end;
	end;

	Result := True;
end;