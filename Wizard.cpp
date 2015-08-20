#include "Wizard.h"

#include <manager.h>
#include <globals.h>
#include <cbproject.h>
#include <projectmanager.h>
#include <editormanager.h>

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArraySetupFile);
WX_DEFINE_OBJARRAY(ArraySetupLanguage);
WX_DEFINE_OBJARRAY(ArraySetupTask);
WX_DEFINE_OBJARRAY(ArraySetupIcon);
WX_DEFINE_OBJARRAY(ArraySetupRun);
WX_DEFINE_OBJARRAY(ArraySetupRegistry);
WX_DEFINE_OBJARRAY(ArraySetupUninstall);
WX_DEFINE_OBJARRAY(ArraySetupComponent);
WX_DEFINE_OBJARRAY(ArraySetupCustom);
WX_DEFINE_OBJARRAY(ArraySetupType);

const long MyStandartWizard::ID_WIZARD = wxNewId();

BEGIN_EVENT_TABLE( MyStandartWizard, wxWizard)
  EVT_WIZARD_CANCEL( ID_WIZARD, MyStandartWizard::OnWizardCancel)
  EVT_WIZARD_PAGE_CHANGING( ID_WIZARD, MyStandartWizard::InWizardChanging)
  EVT_WIZARD_FINISHED( ID_WIZARD, MyStandartWizard::OnWizardFinish)
END_EVENT_TABLE()

MyStandartWizard::MyStandartWizard( wxWindow* parent) : wxWizard( parent, ID_WIZARD, _T("Inno Setup Script Wizard"), wxNullBitmap, wxDefaultPosition, wxDEFAULT_DIALOG_STYLE | wxBORDER_NONE)
{

  Page1 = new WelcomePage( this);
  Page2 = new ApplicationInformation( this, Page1);
  Page3 = new ApplicationFolder( this, Page2);
  Page4 = new ApplicationFiles( this, Page3);
  Page5 = new ApplicationIcons( this, Page4);
  Page6 = new ApplicationDocumentation( this, Page5);
  Page7 = new SetupLanguages( this, Page6, NULL);
  Page8 = new CompilerSettings( this, Page7, NULL);
  Page9 = new FinishWizard( this, Page8, NULL);
  Page8->SetNext( Page9);
  Page7->SetNext( Page8);
  Page6->SetNext( Page7);
  Page5->SetNext( Page6);
  Page4->SetNext( Page5);
  Page3->SetNext( Page4);
  Page2->SetNext( Page3);
  Page1->SetNext( Page2);
  GetPageAreaSizer()->Add(Page1);
  SetBorder( 0);
}

bool MyStandartWizard::Show( void)
{
  return RunWizard( Page1);
}

void MyStandartWizard::SetName( wxString Name)
{
  m_Name = Name;
}

void MyStandartWizard::WriteInFile( wxTextFile* File)
{

  InnoFile.Setup.WriteInFile( File);

  if( !InnoFile.Languages.IsEmpty())
  {
    File->AddLine( _T(""));
    File->AddLine( _T("[Languages]"));
    for( unsigned int i = 0; i < InnoFile.Languages.GetCount(); i++)
      InnoFile.Languages.Item( i).WriteInFile( File);
  }

  if( !InnoFile.Tasks.IsEmpty())
  {
    File->AddLine( _T(""));
    File->AddLine( _T("[Tasks]"));
    for( unsigned int i = 0; i < InnoFile.Tasks.GetCount(); i++)
      InnoFile.Tasks.Item( i).WriteInFile( File);
  }

  if( !InnoFile.Files.IsEmpty())
  {
    File->AddLine( _T(""));
    File->AddLine( _T("[Files]"));
    for( unsigned int i = 0; i < InnoFile.Files.GetCount(); i++)
      InnoFile.Files.Item( i).WriteInFile( File);
    File->AddLine(_T(";  NOTE: Don't use \"Flag: ignoreversion\" on any shared system files"));
  }

  if( !InnoFile.Icons.IsEmpty())
  {
    File->AddLine( _T(""));
    File->AddLine( _T("[Icons]"));
    for( unsigned int i = 0; i < InnoFile.Icons.GetCount(); i++)
      InnoFile.Icons.Item( i).WriteInFile( File);
  }

  if( !InnoFile.Runs.IsEmpty())
  {
    File->AddLine( _T(""));
    File->AddLine( _T("[Run]"));
    for( unsigned int i = 0; i < InnoFile.Runs.GetCount(); i++)
      InnoFile.Runs.Item( i).WriteInFile( File);
  }
}

void MyStandartWizard::OnWizardCancel(wxWizardEvent& event)
{
  if( wxMessageBox(_T("The Inno Setup Script Wizard is not complete. If you quit now, then new\nscript file will not be generated.\n\nExit the Innp Setup Wizard?"), _T("Inno Setup Script Wizard"), wxYES_NO | wxICON_QUESTION) == wxNO)
    event.Veto();
}

void MyStandartWizard::InWizardChanging( wxWizardEvent& event)
{
  if( event.GetDirection())
  {

    int index = 1;
    wxWizardPage* temp = event.GetPage();
    while( temp->GetPrev() != NULL)
    {
      temp = temp->GetPrev();
      index++;
    }

    switch( index)
    {

      case 1:
        if( !Page1->chEmpty->IsChecked())
        {
          Page2->txtAppName->SetValue( m_Name);
        }
        break;

      case 2:
        if( Page2->txtAppName->IsEmpty())
        {
          wxMessageBox( _T("Please specify the application name."), _T("Error"), wxOK | wxICON_EXCLAMATION);
          event.Veto();
          return;
        }
        if( Page2->txtAppversion->IsEmpty())
        {
          wxMessageBox( _T("Please specify the application version."), _T("Error"), wxOK | wxICON_EXCLAMATION);
          event.Veto();
          return;
        }
        if( Page2->txtAppWebseite->IsEmpty())
          Page5->cbInternetShort->Enable( false);
        else
          Page5->cbInternetShort->Enable( true);
        if( Page3->txtAppFolderName->IsEmpty())
          Page3->txtAppFolderName->SetValue( Page2->txtAppName->GetValue());
        if( Page5->txtMenuFolder->IsEmpty())
          Page5->txtMenuFolder->SetValue( Page2->txtAppName->GetValue());
        break;

      case 3:
        if( !Page3->cbDoesntFolder->IsChecked())
        {
          if( (Page3->chProgrammFolder->GetSelection() == 1) && Page3->txtCustom->IsEmpty())
          {
            wxMessageBox( _T("Please specify the application destnation base folder."), _T("Error"), wxOK | wxICON_EXCLAMATION);
            event.Veto();
            return;
          }
          if( Page3->txtAppFolderName->IsEmpty())
          {
            wxMessageBox( _T("Please specify the application folder name."), _T("Error"), wxOK | wxICON_EXCLAMATION);
            event.Veto();
            return;
          }
          Page4->cbDoesntHaveMain->Enable( true);
          if( !Page4->cbDoesntHaveMain->IsChecked())
          {
            Page4->text1->Enable( true);
            Page4->txtMainExe->Enable( true);
            Page4->cbAllowStartAfterInstall->Enable( true);
            Page4->btnMainExe->Enable( true);
          }
          Page4->SetNext( Page5);
          Page6->SetPrev( Page5);
        }
        else
        {
          Page4->text1->Enable( false);
          Page4->txtMainExe->Enable( false);
          Page4->cbAllowStartAfterInstall->Enable( false);
          Page4->btnMainExe->Enable( false);
          Page4->cbDoesntHaveMain->Enable( false);
          Page4->SetNext( Page6);
          Page6->SetPrev( Page4);
        }
        break;

      case 4:
        if( !Page3->cbDoesntFolder->IsChecked())
        {
          if( !Page4->cbDoesntHaveMain->IsChecked())
          {
            if( Page4->txtMainExe->IsEmpty())
            {
              wxMessageBox( _T("Please specify the application main executable file."), _T("Error"), wxOK | wxICON_EXCLAMATION);
              event.Veto();
              return;
            }
            Page5->text2->Enable( true);
            Page5->cbDesktopIcon->Enable( true);
            Page5->cbQuickLunchShortCut->Enable( true);
          }
          else
          {
            Page5->text2->Enable( false);
            Page5->cbDesktopIcon->Enable( false);
            Page5->cbQuickLunchShortCut->Enable( false);
          }
        }
        break;

      case 5:
        if( Page5->txtMenuFolder->IsEmpty())
        {
          wxMessageBox( _T("Please specify the application Start menu group name."), _T("Error"), wxOK | wxICON_EXCLAMATION);
          event.Veto();
          return;
        }
        break;

      case 6:

        break;

      case 7:
        if( !Page7->IsChecked())
        {
          wxMessageBox( _T("Please select at least one language."), _T("Error"), wxOK | wxICON_EXCLAMATION);
          event.Veto();
          return;
        }
        break;

      default: // TODO: Implement
        break;
    }
  }

  event.Skip();
}

void MyStandartWizard::OnWizardFinish( wxWizardEvent& event)
{
  EmptyProjekt = Page1->GetIsEmptySet();

  if( !EmptyProjekt)
  {
    InnoFile.Setup.Set( Page2->txtAppName->GetValue(), Page2->txtAppversion->GetValue());
    InnoFile.Setup.SetPublisher( Page2->txtAppPublisher->GetValue());
    InnoFile.Setup.SetWebseite( Page2->txtAppWebseite->GetValue());

    if( !Page3->cbDoesntFolder->IsChecked())
    {
      if( Page3->chProgrammFolder->GetSelection() == 0)
        InnoFile.Setup.SetDefaultDirName( _T("{pf}\\") + Page3->txtAppFolderName->GetValue());
      else
        InnoFile.Setup.SetDefaultDirName( Page3->txtCustom->GetValue() + Page3->txtAppFolderName->GetValue());

      if( !Page3->cbAppFolderName->IsChecked())
        InnoFile.Setup.SetDisableDirPage( true);

      if( !Page4->cbDoesntHaveMain->IsChecked())
      {

        CFiles Dummy;
        Dummy.Set( Page4->txtMainExe->GetValue(), _T("{app}"));
        Dummy.SetFlags( _T("ignoreversion"));
        InnoFile.Files.Add( Dummy);
        if( Page4->cbAllowStartAfterInstall->IsChecked())
        {
          CRun Temp;
          Temp.SetFilename( _T("{app}\\") + InnoFile.Files.Item(0).GetFileName());
          Temp.SetDescription( _T("{cm:LaunchProgram,") + InnoFile.Setup.GetAppName()+_T("}"));
          Temp.SetFlags( _T("nowait postinstall skipifsilent"));
          InnoFile.Runs.Add( Temp);
        }

        if( Page5->cbDesktopIcon->IsChecked())
        {
          CTasks Temp;
          Temp.SetName( _T("desktopicon"));
          Temp.SetDescription( _T("{cm:CreateDesktopIcon}"));
          Temp.SetGroupDescription( _T("{cm:AdditionalIcons}"));
          Temp.SetFlags( _T("unchecked"));
          InnoFile.Tasks.Add( Temp);
          CIcons TempIcon;
          TempIcon.Set( _T("{commondesktop}\\") + InnoFile.Setup.GetAppName(), _T("{app}\\") + InnoFile.Files.Item(0).GetFileName());
          TempIcon.SetTasks( _T("desktopicon"));
          InnoFile.Icons.Add( TempIcon);
        }

        if( Page5->cbChangeStartMenu->IsChecked())
        {
          CIcons TempIcon;
          TempIcon.Set( _T("{group}\\") + InnoFile.Setup.GetAppName(), _T("{app}\\") + InnoFile.Files.Item(0).GetFileName());
          InnoFile.Icons.Add( TempIcon);
        }

        if( Page5->cbQuickLunchShortCut->IsChecked())
        {
          CTasks TempTasks;
          TempTasks.SetName( _T("quicklaunchicon"));
          TempTasks.SetDescription( _T("{cm:CreateQuickLaunchIcon}"));
          TempTasks.SetGroupDescription( _T("{cm:AdditionalIcons}"));
          TempTasks.SetFlags( _T("unchecked"));
          TempTasks.SetOnlyBelowVersion( _T("0,6.1"));
          InnoFile.Tasks.Add( TempTasks);
          CIcons TempIcon;
          TempIcon.Set( _T("{userappdata}\\Microsoft\\Internet Explorer\\Quick Launch\\") + InnoFile.Setup.GetAppName(), _T("{app}\\") + InnoFile.Files.Item(0).GetFileName());
          TempIcon.SetTasks( _T("quicklaunchicon"));
          InnoFile.Icons.Add( TempIcon);
        }
      }

      if( Page5->cbInternetShort->IsChecked())
      {
        CIcons TempIcon;
        TempIcon.Set( _T("{group}\{cm:ProgramOnTheWeb,")+InnoFile.Setup.GetAppName() + _T("}"), InnoFile.Setup.GetPublisherURL());
        InnoFile.Icons.Add( TempIcon);
      }

      if( Page5->cbUninstallShortCut->IsChecked())
      {
        CIcons TempIcon;
        TempIcon.Set( _T("{group}\{cm:ProgramOnTheWeb,")+InnoFile.Setup.GetAppName() + _T("}"), _T("{uninstallerexe}"));
        InnoFile.Icons.Add( TempIcon);
      }

      if( Page5->cbDisableStartMenu->IsChecked())
        InnoFile.Setup.SetAllowNoIcons( true);

      InnoFile.Setup.SetGroupName( Page5->txtMenuFolder->GetValue());
    }
    else
    {
      InnoFile.Setup.SetCreateAppDir( false);
    }

    for( unsigned int i = 0; i < Page4->lbFiles->GetCount(); i++)
    {

      CFiles Dummy;
      wxString Source = Page4->Files.Item( i).Source;
      wxString destDir;
      switch( Page4->Files.Item(i).Destination)
      {
        case 0:
          destDir = _T("{app}");
          break;
        case 1:
          destDir = _T("{pf}");
          break;
        case 2:
          destDir = _T("{cf}");
          break;
        case 3:
          destDir = _T("{win}");
          break;
        case 4:
          destDir = _T("{sys}");
          break;
        case 5:
          destDir = _T("{src}");
          break;
        case 6:
          destDir = _T("{sd}");
          break;
        case 7:
          destDir = _T("{commonstartup}");
          break;
        case 8:
          destDir = _T("{userstartup}");
          break;
        case 9:
          destDir = Page4->Files.Item( i).ExternDestionation;
          break;
        default: // TODO: Implement
          break;
      }

      if( Page4->Files.Item( i).DestinationSub.Len() > 0)
        destDir += _T("\\") + Page4->Files.Item( i).DestinationSub;

      Dummy.Set( Source, destDir);
      wxString Flags = _T("ignoreversion");
      if( Page4->Files.Item( i).Recurse)
        Flags += _T(" recursesubdirs");
      if( Page4->Files.Item( i).Include)
        Flags += _T(" createallsubdirs");
      Dummy.SetFlags( Flags);

      InnoFile.Files.Add( Dummy);
    }

    if( !Page6->txtLiecens->IsEmpty())
      InnoFile.Setup.SetLicenseFile( Page6->txtLiecens->GetValue());
    if( !Page6->txtBefore->IsEmpty())
      InnoFile.Setup.SetInfoBefor( Page6->txtBefore->GetValue());
    if( !Page6->txtAfter->IsEmpty())
      InnoFile.Setup.SetInfoAfter( Page6->txtAfter->GetValue());

    for( unsigned int i = 0; i < Page7->lbLanguages->GetCount(); i++)
    {
      CLanguages Dummy;
      if( Page7->lbLanguages->IsChecked( i))
      {
        switch( i)
        {
          case 0:
            Dummy.Set( _T("english"), _T("compiler:Default.isl"));
            break;
          case 1:
            Dummy.Set( _T("basque"), _T("compiler:Languages\\Basque.isl"));
            break;
          case 2:
            Dummy.Set( _T("brazilianportuguese"), _T("compiler:Languages\\BrazilianPortuguese.isl"));
            break;
          case 3:
            Dummy.Set( _T("catalan"), _T("compiler:Languages\\Catalan.isl"));
            break;
          case 4:
            Dummy.Set( _T("czech"), _T("compiler:Languages\\Czech.isl"));
            break;
          case 5:
            Dummy.Set( _T("danish"), _T("compiler:Languages\\Danish.isl"));
            break;
          case 6:
            Dummy.Set( _T("dutch"), _T("compiler:Languages\\Dutch.isl"));
            break;
          case 7:
            Dummy.Set( _T("finnish"), _T("compiler:Languages\\Finnish.isl"));
            break;
          case 8:
            Dummy.Set( _T("french"), _T("compiler:Languages\\French.isl"));
            break;
          case 9:
            Dummy.Set( _T("german"), _T("compiler:Languages\\German.isl"));
            break;
          case 10:
            Dummy.Set( _T("hebrew"), _T("compiler:Languages\\Hebrew.isl"));
            break;
          case 11:
            Dummy.Set( _T("hungarian"), _T("compiler:Languages\\Hungarian.isl"));
            break;
          case 12:
            Dummy.Set( _T("italian"), _T("compiler:Languages\\Italian.isl"));
            break;
          case 13:
            Dummy.Set( _T("japanese"), _T("compiler:Languages\\Japanese.isl"));
            break;
          case 14:
            Dummy.Set( _T("norwegian"), _T("compiler:Languages\\Norwegian.isl"));
            break;
          case 15:
            Dummy.Set( _T("polish"), _T("compiler:Languages\\Polish.isl"));
            break;
          case 16:
            Dummy.Set( _T("portuguese"), _T("compiler:Languages\\Portuguese.isl"));
            break;
          case 17:
            Dummy.Set( _T("russian"), _T("compiler:Languages\\Russian.isl"));
            break;
          case 18:
            Dummy.Set( _T("slovak"), _T("compiler:Languages\\Slovak.isl"));
            break;
          case 19:
            Dummy.Set( _T("slovenian"), _T("compiler:Languages\\Slovenian.isl"));
            break;
          case 20:
            Dummy.Set( _T("spanish"), _T("compiler:Languages\\Spanish.isl"));
            break;
          default: // TODO: Implement
            break;
        }
        InnoFile.Languages.Add( Dummy);
      }
    }
    wxString Output = _T("Output");
    if( !Page8->txtOutputFolder->IsEmpty())
      Output = Page8->txtOutputFolder->GetValue();
    InnoFile.Setup.SetOutput( Page8->txtCompilerFileName->GetValue(), Output);
    if( !Page8->txtCustomIcon->IsEmpty())
      InnoFile.Setup.SetIconFile( Page8->txtCustomIcon->GetValue());
    if( !Page8->txtPassword->IsEmpty())
      InnoFile.Setup.SetPassword( Page8->txtPassword->GetValue());


    InnoFile.Setup.SetCompression( _T("lzma"));
    InnoFile.Setup.SetSolidCompression( true);
    InnoFile.Setup.SetAppVerName( InnoFile.Setup.GetAppName() + _T(" ") + InnoFile.Setup.GetAppVersion());
    InnoFile.Setup.SetAppId( );

  }

  event.Skip();
}

CInno::CInno()
{
  //ctor
}

CInno::~CInno()
{
  //dtor
}

void CInno::Create( wxWindow* parent)
{
  Wizard = new MyStandartWizard( parent);
}

void CInno::Set( wxString ProjectName)
{
  Wizard->SetName(ProjectName);
}

void CInno::AddToProject( bool add)
{
  m_AddToProject = add;
}

void CInno::WriteFile( wxString Name)
{

  wxTextFile QuellFile(Name + _T(".iss"));

  bool Exist = false;

  if( QuellFile.Exists())
  {
    QuellFile.Open( Name + _T(".iss"));
    Exist = true;
  }
  else
    QuellFile.Create( Name + _T(".iss"));

  QuellFile.Clear();

  QuellFile.AddLine( _T("; Script generated by the CodeBlocksInno Setup Plugin Script.\r\n; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!"));

  QuellFile.AddLine( _T(""));

  if( Wizard->EmptyProjekt)
    QuellFile.AddLine( _T("[Setup]"));
  else
    Wizard->WriteInFile( &QuellFile);

  QuellFile.Write();
  QuellFile.Close();

  Manager::Get()->GetEditorManager()->Open( Name + _T(".iss"));

  if( m_AddToProject)
  {
    cbProject* actproj = Manager::Get()->GetProjectManager()->GetActiveProject();
    ProjectFile* temp = actproj->GetFileByFilename( Name + _T(".iss"), false);

    if( !Exist || temp == NULL)
    {
      actproj->BeginAddFiles();
      actproj->AddFile( actproj->GetActiveBuildTarget(), Name + _T(".iss"), false, false);
      actproj->EndAddFiles();
      Manager::Get()->GetProjectManager()->GetUI().RebuildTree();
      //actproj->AddCommandsAfterBuild( _T("\"$(#inno)/ISCC\" \"") + Name + _T(".iss\""));
      //actproj->SetAlwaysRunPostBuildSteps( true);
    }
  }
}

void CInno::WriteEmptyFile( wxString Name)
{
  wxTextFile QuellFile(Name + _T(".iss"));

  bool Exist = false;

  if( QuellFile.Exists())
  {
    QuellFile.Open( Name + _T(".iss"));
    Exist = true;
  }
  else
    QuellFile.Create( Name + _T(".iss"));
  QuellFile.Clear();

  QuellFile.AddLine( _T("; Script generated by the CodeBlocksInno Setup Plugin Script.\r\n; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!"));

  QuellFile.AddLine( _T(""));

  QuellFile.AddLine( _T("[Setup]"));

  QuellFile.Write();
  QuellFile.Close();

  Manager::Get()->GetEditorManager()->Open( Name + _T(".iss"));

  if( m_AddToProject)
  {

    cbProject* actproj = Manager::Get()->GetProjectManager()->GetActiveProject();
    ProjectFile* temp = actproj->GetFileByFilename( Name + _T(".iss"), false);

    if( !Exist || temp == NULL)
    {
      actproj->BeginAddFiles();
      actproj->AddFile( actproj->GetActiveBuildTarget(), Name + _T(".iss"), false, false);
      actproj->EndAddFiles();
      Manager::Get()->GetProjectManager()->GetUI().RebuildTree();
      //actproj->AddCommandsAfterBuild( _T("\"$(#inno)/ISCC\" \"") + Name + _T(".iss\""));
      //actproj->SetAlwaysRunPostBuildSteps( true);
    }
  }
}

bool CInno::ShowStandartWizard( void)
{
  return Wizard->Show();
}

bool CInno::FileExist( wxString Name)
{
  wxTextFile QuellFile(Name + _T(".iss"));

  return QuellFile.Exists();
}

void CInno::Delete( void)
{
  Wizard->Destroy();
}
