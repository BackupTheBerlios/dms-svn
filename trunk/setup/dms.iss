;/*
; *   Copyright (C) ©'2007 by Alexander Saal <alex.saal@gmx.de>
; *
; *   This program is free software; you can redistribute it and/or modify
; *   it under the terms of the GNU General Public License as published by
; *   the Free Software Foundation; either version 2 of the License, or (at
; *   your option) any later version.
; *
; *   This program is distributed in the hope that it will be useful, but
; *   WITHOUT ANY WARRANTY; without even the implied warranty of
; *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; *   GNU General Public License for more details.
; *
; *   You should have received a copy of the GNU General Public License
; *   along with this program; if not, write to the Free Software Foundation,
; *   Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
; */

#define MyAppName "DMS"
#define MyAppVerName "Document Managemnt System 0.1.0.0"
#define MyAppVersion "0.1.0.0"
#define MyAppPublisher "Privat - Alexander Saal"
#define MyAppURL "http://chmaster.freeforge.net"
#define MyAppCopyright "(C)opyright ©'2007 by Alexander Saal"
#define MyAppExeName "dms.exe"
#define MyAppUrlName "dms.url"

#include ReadReg(HKEY_LOCAL_MACHINE,'Software\Sherlock Software\InnoTools\Downloader','ScriptPath','')
#include "SqlServerSelection.iss"

[Setup]
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}

DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}

VersionInfoVersion={#MyAppVersion}
VersionInfoCopyright={#MyAppCopyright}
VersionInfoCompany={#MyAppPublisher}

AllowNoIcons=true
LicenseFile=..\resource\misc\COPYING
OutputDir=.
OutputBaseFilename=dms-{#MyAppVersion}-setup-win32
SetupIconFile=..\dms\dms.ico
Compression=lzma
SolidCompression=true
InternalCompressLevel=max
MinVersion=4.1.2222,5.0.2195sp3
AppID={{0F40AF50-E524-4B61-9772-CFAA42C0672A}
UninstallDisplayIcon={app}\dms.exe
DisableFinishedPage=false
UninstallDisplayName={#MyAppVersion}-{#MyAppName}
AllowRootDirectory=true
UninstallLogMode=new
DisableStartupPrompt=true
;WizardImageFile=..\..\..\WizardImages\Modern\SetupModern16.bmp
;WizardSmallImageFile=..\..\..\WizardImages\Modern\Small\SetupModernSmall16.bmp
ShowLanguageDialog=yes

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}; GroupDescription: {cm:AdditionalIcons}; MinVersion: 4.1.2222,4.0.1381sp6
Name: quicklaunchicon; Description: {cm:CreateQuickLaunchIcon}; GroupDescription: {cm:AdditionalIcons}; MinVersion: 4.1.2222,4.0.1381sp6

[Files]
Source: ..\bin\dms.exe; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: ..\bin\libdms.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: ..\resource\misc\COPYING; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6

; Needed library (Qt4 Release):
;Source: D:\qt434\bin\QtGui4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: D:\qt434\bin\QtCore4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: D:\qt434\bin\QtSql4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: D:\qt434\bin\QtXml4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: D:\qt434\plugins\sqldrivers\qsqlmysql4.dll; DestDir: {app}\sqldrivers; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6

; Needed library (Qt4 Debug):
Source: D:\qt434\bin\QtGuid4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: D:\qt434\bin\QtCored4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: D:\qt434\bin\QtSqld4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: D:\qt434\bin\QtXmld4.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
Source: D:\qt434\plugins\sqldrivers\qsqlmysqld4.dll; DestDir: {app}\sqldrivers; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6

; Needed library (MS VC++ 2008 Release)
;Source: msvcm90.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: msvcr90.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: msvcp90.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: Microsoft.VC90.DebugCRT.manifest; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6

; Needed library (MS VC++ 2008 Debug)
;Source: msvcm90d.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: msvcr90d.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: msvcp90d.dll; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6
;Source: Microsoft.VC90.DebugCRT.manifest; DestDir: {app}; Flags: ignoreversion uninsremovereadonly 32bit overwritereadonly replacesameversion; MinVersion: 4.1.2222,4.0.1381sp6

[INI]
Filename: {app}\{#MyAppUrlName}; Section: InternetShortcut; Key: URL; String: {#MyAppURL}; Flags: createkeyifdoesntexist; MinVersion: 4.1.2222,4.0.1381sp6

[Icons]
Name: {group}\{#MyAppName}; Filename: {app}\{#MyAppExeName}
Name: {group}\{cm:ProgramOnTheWeb,{#MyAppName}}; Filename: {app}\{#MyAppUrlName}
Name: {group}\{cm:UninstallProgram,{#MyAppName}}; Filename: {uninstallexe}
Name: {userdesktop}\{#MyAppName}; Filename: {app}\{#MyAppExeName}; Tasks: desktopicon
Name: {userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}; Filename: {app}\{#MyAppExeName}; Tasks: quicklaunchicon

[Run]
Filename: {app}\{#MyAppExeName}; Description: {cm:LaunchProgram,{#MyAppName}}; Flags: postinstall skipifsilent; MinVersion: 4.1.2222,4.0.1381sp6; WorkingDir: {app}

[UninstallDelete]
Type: files; Name: {app}\{#MyAppUrlName}

[Messages]
BeveledLabel={#MyAppCopyright}

[Code]
procedure InitializeWizard();
begin
	sqlPageId := SqlServerSelection_CreatePage(wpSelectComponents);
end;

