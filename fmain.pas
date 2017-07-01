
unit fmain;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, Menus, ComCtrls, StdCtrls;

type

  { TfrmMain }

  TfrmMain = class(TForm)
    CoolBar1: TCoolBar;
    mnuGlobalMidiInput: TMenuItem;
    mnuFileExit: TMenuItem;
    mnuFileSave: TMenuItem;
    mnuMain: TMainMenu;
    mnuHelpAbout: TMenuItem;
    mnuHelp: TMenuItem;
    mnuFileLoad: TMenuItem;
    mnuFile: TMenuItem;
    pgctrlMain: TPageControl;
    tabMidiChannel1: TTabSheet;
    TabSheet2: TTabSheet;
    procedure mnuFileExitClick(Sender: TObject);
    procedure mnuFileLoadClick(Sender: TObject);
    procedure mnuFileSaveClick(Sender: TObject);
    procedure mnuHelpAboutClick(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  frmMain: TfrmMain;

implementation

{$R *.lfm}

{ TfrmMain }

procedure TfrmMain.mnuFileLoadClick(Sender: TObject);
begin
  ShowMessage('TODO !');
end;

procedure TfrmMain.mnuFileSaveClick(Sender: TObject);
begin
  ShowMessage('TODO !');
end;

procedure TfrmMain.mnuFileExitClick(Sender: TObject);
begin
  self.Close();
end;

procedure TfrmMain.mnuHelpAboutClick(Sender: TObject);
begin
  ShowMessage('Ultimate Synth V0.01' + LineEnding + 'Codding started by' + LineEnding + 'Sam TFL/TDV in 2017');
end;

end.

