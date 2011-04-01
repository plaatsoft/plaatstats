;
; PlaatStats windows installer configurationm file.
;
; The file can be processed with "Inno Setup Compiler v5.3.8"
;
; All Copyrights Reserved (c) PlaatSoft 2008-2011

[Setup]
AppPublisher=PlaatSoft
AppPublisherURL=http://www.plaatsoft.nl
AppName=PlaatStats
AppVerName=PlaatSoft Statistics v0.93
AppVersion=0.93
AppCopyright=Copyright (C) 2008-2011 PlaatSoft


DefaultDirName={pf}\PlaatStats
DefaultGroupName=PlaatSoft
UninstallDisplayIcon={app}\Statistics.exe
Compression=lzma
SolidCompression=yes
OutputDir=release\

[Files]
Source: "src\release\Statistics.exe"; DestDir: "{app}"
Source: "src\release\libgcc_s_dw2-1.dll"; DestDir: "{app}"
Source: "src\release\mingwm10.dll"; DestDir: "{app}"
Source: "src\release\QtCore4.dll"; DestDir: "{app}"
Source: "src\release\QtGui4.dll"; DestDir: "{app}"
Source: "src\release\QtNetwork4.dll"; DestDir: "{app}"
Source: "src\release\QtXml4.dll"; DestDir: "{app}"
Source: "src\release\license.txt"; DestDir: "{app}"; Flags: isreadme

[Icons]
Name: "{group}\PlaatStats\PlaatStats"; Filename: "{app}\Statistics.exe"
Name: "{commondesktop}\PlaatSoft Statistics"; Filename: "{app}\Statistics.exe"
Name: "{group}\PlaatStats\Uninstaller"; Filename: "{uninstallexe}"

[Registry]
Root: HKCU; Subkey: "Software\PlaatSoft\RedSquare"; ValueName: "target"; ValueData: {app}; ValueType: string;  Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\PlaatSoft\RedSquare"; ValueName: "username"; ValueData: {username}; ValueType: string;  Flags: uninsdeletekeyifempty

