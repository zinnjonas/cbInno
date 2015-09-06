#include <sdk.h> // Code::Blocks SDK

#include <cbeditor.h>
#include <cbproject.h>
#include <configmanager.h>
#include <configurationpanel.h>
#include <editormanager.h>
#include <filefilters.h>
#include <filegroupsandmasks.h>
#include <logmanager.h>

#include "Inno.h"
#include "Wizard.h"
#include "CreateDialog.h"
#include "InnoSettings.h"

std::set<CEditor*> Inno::m_editors;

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
  PluginRegistrant<Inno> reg(_T("Inno"));
  const int ID_INNO_EMPTY = wxNewId();
  const int ID_INNO_NEW = wxNewId();
  const int ID_INNO_BUILD = wxNewId();
  const int ID_INNO_THREAD = wxNewId();
}


// events handling
BEGIN_EVENT_TABLE(Inno, cbMimePlugin)
  // add any events you want to handle here
  EVT_MENU( ID_INNO_EMPTY, Inno::OnEmpty)
  EVT_MENU(ID_INNO_NEW, Inno::OnNew)
  EVT_MENU( ID_INNO_BUILD, Inno::OnInnoBuild)
  EVT_END_PROCESS(ID_INNO_THREAD, Inno::OnProcessEnd)
END_EVENT_TABLE()

// constructor
Inno::Inno()
{
  // Make sure our resources are available.
  // In the generated boilerplate code we have no resources but when
  // we add some, it will be nice that this code is in place already ;)
  if(!Manager::LoadResource(_T("Inno.zip")))
  {
    NotifyMissingFile(_T("Inno.zip"));
  }
  m_consume = nullptr;
}

// destructor
Inno::~Inno()
{
  if( m_consume != nullptr)
  {
    m_consume->Delete();
    delete m_consume;
  }
  m_consume = nullptr;
}

#include "Images/Inno.xpm"

void Inno::OnAttach()
{
  // do whatever initialization you need for your plugin
  // NOTE: after this function, the inherited member variable
  // m_IsAttached will be TRUE...
  // You should check for it in other functions, because if it
  // is FALSE, it means that the application did *not* "load"
  // (see: does not need) this plugin...
  if( m_IsAttached)
  {
    m_log_pos = Manager::Get()->GetLogManager()->SetLog(new TextCtrlLogger());
    Manager::Get()->GetLogManager()->Slot(m_log_pos).title = L"Inno";
    CodeBlocksLogEvent evt(cbEVT_ADD_LOG_WINDOW, m_log_pos, Manager::Get()->GetLogManager()->Slot(m_log_pos).title, new wxBitmap(Inno_xpm));
    Manager::Get()->ProcessEvent(evt);

    AddFileMasksToProjectManager();
  }
}

void Inno::OnRelease(cb_unused bool appShutDown)
{
  // do de-initialization for your plugin
  // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
  // which means you must not use any of the SDK Managers
  // NOTE: after this function, the inherited member variable
  // m_IsAttached will be FALSE...
  CodeBlocksLogEvent evt(cbEVT_REMOVE_LOG_WINDOW, m_log_pos);
  Manager::Get()->ProcessEvent(evt);
}

void Inno::BuildMenu(wxMenuBar* menuBar)
{
  //The application is offering its menubar for your plugin,
  //to add any menu items you want...
  //Append any items you need in the menu...
  //NOTE: Be careful in here... The application's menubar is at your disposal.
  int pos = menuBar->FindMenu(_("&File"));
  wxMenu* FileMenu = menuBar->GetMenu(pos);
  pos = FileMenu->FindItem(_("New"));
  wxMenu* WizardMenu = new wxMenu;
  WizardMenu->Append( ID_INNO_EMPTY, _("Empty File"));
  WizardMenu->Append( ID_INNO_NEW, _("standard Wizard"));
  FileMenu->Insert(1, wxID_ANY, _("Inno"), WizardMenu);
}

void Inno::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
  if( type == mtProjectManager)
  {
    if( data && data->GetKind() == FileTreeData::ftdkFile)
    {
      if( data->GetProjectFile()->relativeFilename.AfterLast('.').compare(L"iss") == 0)
      {
        iss_name = data->GetProjectFile()->file.GetFullPath() ;
        menu->Append(ID_INNO_BUILD, L"Build");
      }
    }
  }
}

bool Inno::CanHandleFile(const wxString& filename) const
{
  wxString fn;

  fn = filename;
  fn.MakeUpper();

  if( fn.Right(4) == _T(".ISS"))
    return true;

  return false;
}

int Inno::OpenFile(const wxString& filename)
{

  new CEditor(filename, m_log_pos);
  return 0;
}

bool Inno::HandlesEverything() const
{
  return false;
}

cbConfigurationPanel* Inno::GetConfigurationPanel(wxWindow* parent)
{
  InnoSettings* dlg = new InnoSettings(parent);
  return dlg;
}

/** This method adds Filemasks, such as "*.iss" to the project manager
  * This allows the display of all inno setup into 1 virtual folder "Inno"
  */
void Inno::AddFileMasksToProjectManager(void)
{
  ProjectManager *pm = Manager::Get()->GetProjectManager();

  wxString sFileMasks = _("*.iss");

  //add these file masks to the project manager
  if (pm)
  {
    FilesGroupsAndMasks *fm;
    fm = (FilesGroupsAndMasks *) pm->GetFilesGroupsAndMasks();
    if (fm)
    {
      //test if the filemasks are already associated
      unsigned int i, iMax;
      unsigned int iMatch;
      bool bMatch = false;
      iMax = fm->GetGroupsCount();
      for(i=0; i<iMax; i++) //loop over the groups managed by the project manager
      {
        if (fm->MatchesMask(sFileMasks, i))
        {
          bMatch= true;
          break;
        }
      }

      if (!bMatch)
      {
        //create a new group
        wxString sName;
        sName = _("Inno");
        while (IsGroupNameExisting(sName, fm)) sName = sName + _("_");
        fm->AddGroup(sName);
        iMatch = fm->GetGroupsCount() - 1;
      }

      //add all the filemasks to the group
      wxString sMask = fm->GetFileMasks(iMatch);
      if (!(fm->MatchesMask(sFileMasks, i))) //to avoid having twice the same mask
      {
        if (sMask.Len() > 0) sMask = sMask  + _(";");
        sMask = sMask  + sFileMasks;
      }
      fm->SetFileMasks(iMatch, sMask);

      fm->Save();
      pm->GetUI().RebuildTree();
    }
  }

  FileFilters::Add(_("Inno Setup Files"), sFileMasks);
}

/** Test if a group name is already existing in the Project Manager
  * \param sName : the group name to test. Example: _("Images")
  * \param fm : the FilesGroupAndMasks to search
  * \return true if the Name already exist, false otherwise
  */
bool Inno::IsGroupNameExisting(wxString sName, const FilesGroupsAndMasks *fm)
{
  if (!fm) return(false);
  unsigned int i, iMax;

  wxString sName2;

  iMax = fm->GetGroupsCount();
  for(i=0; i<iMax; i++) //loop over the groups managed by the project manager
  {
    sName2 = fm->GetGroupName(i);
    if (sName == sName2) return(true);
  }

  return(false);
}

void Inno::OnEmpty(cb_unused wxCommandEvent& event)
{

  CInno inno;
  bool OverwriteFile = true;
  if( inno.FileExist( Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.')))
    if( wxID_NO == cbMessageBox( _("Do you want to overwrite the existing File?"), _("File exist"), wxYES_NO | wxICON_QUESTION))
      OverwriteFile = false;

  if( OverwriteFile)
  {
    if(Manager::Get()->GetProjectManager()->GetActiveProject())
    {
      if(wxID_YES == cbMessageBox(_("Do you want to add the inno file to the active project?"),_("New Inno Setup"),wxYES|wxNO))
        inno.AddToProject(true);
      else
        inno.AddToProject(false);

      inno.WriteEmptyFile(Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.'));
    }
    else
    {
      wxMessageBox( _T("Open your Project first"));
    }
  }
}

void Inno::OnNew(cb_unused wxCommandEvent& event)
{
  CInno inno;
  inno.Create( Manager::Get()->GetAppWindow());

  wxString Name;

  bool OverwriteFile = true;
  if( inno.FileExist( Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.')))
    if( wxID_NO == cbMessageBox( _("Do you want to overwrite the existing File?"), _("File exist"), wxYES_NO | wxICON_QUESTION))
      OverwriteFile = false;

  if( OverwriteFile)
  {

    if(Manager::Get()->GetProjectManager()->GetActiveProject())
    {
      Name = Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.');
      Name = Name.AfterLast( '\\');
      inno.Set( Name);
      if(wxID_YES == cbMessageBox(_("Do you want to add the inno file to the active project?"),_("New Inno Setup"),wxYES|wxNO))
        inno.AddToProject(true);
      else
        inno.AddToProject(false);

      if( inno.ShowStandartWizard())
      {
        wxString file_name = Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.');
        inno.WriteFile(file_name);
        iss_name = file_name + L".iss";

        cbEditor* ed = Manager::Get()->GetEditorManager()->Open(iss_name);
        ed->Reload();
        ed->Activate();

        if( wxYES == wxMessageBox( _T( "Do you want to compile the Inno Setup file?"), _T( "Inno Setup"), wxYES_NO | wxICON_QUESTION))
        {
          wxCommandEvent e;
          OnInnoBuild(e);
        }
      }
    }
    else
    {
      wxMessageBox( _T("Open your Project first"));
    }
  }

  inno.Delete();
}

void Inno::OnInnoBuild(cb_unused wxCommandEvent& event)
{
  ConfigManager* pCfg = Manager::Get()->GetConfigManager(_T("inno"));
  wxString path = pCfg->Read(_T("iscc_path"), _T(""));
  if( path.empty())
  {
    Manager::Get()->GetLogManager()->Log(L"please set the path to the inno compiler first!\nSettings->Environment...->Inno");
    return;
  }

  path = L"\"" + path + L"\"";

  wxString command = path + L" \"";

  command += iss_name;

  command += L"\"";
  m_running = true;
  wxProcess* compile = new wxProcess(this, ID_INNO_THREAD);
  compile->Redirect();
  wxExecute(command, wxEXEC_ASYNC, compile);
  if( !compile)
  {
    cbMessageBox(L"can't open a process to the iscc");
    return;
  }

  m_out = compile->GetInputStream();
  m_err = compile->GetErrorStream();
  if( !m_out || !m_err)
  {
    cbMessageBox(L"can't read from stdout of iscc");
    return;
  }

  CodeBlocksLogEvent evt(cbEVT_SWITCH_TO_LOG_WINDOW, m_log_pos);
  Manager::Get()->ProcessEvent(evt);

  if( m_consume == nullptr)
  {
    m_consume = new Consume(m_out, m_log_pos);
    wxThreadError er = m_consume->Run();
    if( er != wxTHREAD_NO_ERROR)
    {
      Manager::Get()->GetLogManager()->Log(wxString::Format(L"Can't create the thread!%d", er), m_log_pos);
      delete m_consume;
      m_consume = nullptr;
    }
  }
}

void Inno::OnProcessEnd(cb_unused wxProcessEvent& evt)
{
  if( m_running)
  {
    m_running = false;

    if(m_consume != nullptr)
    {
      if( m_consume->IsRunning())
        if( m_consume->Delete() != wxTHREAD_NO_ERROR)
          Manager::Get()->GetLogManager()->Log(L"Error at deleting", m_log_pos);
    }
    m_consume = nullptr;

    CodeBlocksLogEvent event(cbEVT_SWITCH_TO_LOG_WINDOW, m_log_pos);
    Manager::Get()->ProcessEvent(event);
    wxString text;
    while( m_out->CanRead())
    {
      text += m_out->GetC();
    }
    Manager::Get()->GetLogManager()->Log(text, m_log_pos);
    wxString err;
    while( m_err->CanRead())
    {
      err += m_err->GetC();
    }
    if( !err.empty())
    {

      size_t pos = err.find(L": ");
      size_t spos = err.find(L"in ");
      wxString file = err.substr(spos+3, pos-spos-3);
      wxString msg = err.substr(pos+2, err.find(L"Compile aborted.")-pos-2);
      spos = err.find(L"on line");
      int linenr = -1;
      if( spos != wxString::npos)
      {
        wxString line = err.substr(spos+8, err.find(' ', spos+8)-spos-8);
        linenr = wxAtoi(line);
      }

      pos = msg.find('[');
      if( pos != wxString::npos)
      {
        pos++;
        wxString section = msg.substr(pos, msg.find(']') - pos);
      }


      cbEditor* ed = Manager::Get()->GetEditorManager()->Open(file);
      ed->Reload();
      ed->Activate();
      if( linenr != -1)
      {
        ed->GotoLine(linenr-1);
        ed->SetErrorLine(linenr-1);
      }
      Manager::Get()->GetLogManager()->Log(err, m_log_pos, Logger::error);

    }
    else
    {
      Manager::Get()->GetEditorManager()->GetBuiltinActiveEditor()->Activate();
    }
  }
}
