#include <sdk.h> // Code::Blocks SDK
#include <filegroupsandmasks.h>
#include <configurationpanel.h>
#include <filefilters.h>
#include "Inno.h"
#include "Wizard.h"
#include "CreateDialog.h"
#include "InnoSettings.h"

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
BEGIN_EVENT_TABLE(Inno, cbPlugin)
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
}

// destructor
Inno::~Inno()
{
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
        m_logger = new TextCtrlLogger();
        m_log_pos = Manager::Get()->GetLogManager()->SetLog(m_logger);
        Manager::Get()->GetLogManager()->Slot(m_log_pos).title = L"Inno";
        CodeBlocksLogEvent evt(cbEVT_ADD_LOG_WINDOW, m_logger, Manager::Get()->GetLogManager()->Slot(m_log_pos).title, new wxBitmap(Inno_xpm));
        Manager::Get()->ProcessEvent(evt);

        AddFileMasksToProjectManager();
    }
}

void Inno::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
    CodeBlocksLogEvent evt(cbEVT_REMOVE_LOG_WINDOW, m_logger);
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

cbConfigurationPanel* Inno::GetConfigurationPanel(wxWindow* parent)
{
    InnoSettings* dlg = new InnoSettings(parent);
    return dlg;
}

/** This method adds Filemasks, such as "*.iss" to the project manager
  * This allows the display of all images into 1 virtual folder "Images"
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
            for(i=0;i<iMax;i++) //loop over the groups managed by the project manager
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
    for(i=0;i<iMax;i++) //loop over the groups managed by the project manager
    {
        sName2 = fm->GetGroupName(i);
        if (sName == sName2) return(true);
    }

    return(false);
}

void Inno::OnEmpty(wxCommandEvent &event)
{

    CInno Inno;
    bool OverwriteFile = true;
    if( Inno.FileExist( Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.')))
        if( wxID_NO == cbMessageBox( _("Do you want to overwrite the existing File?"), _("File exist"), wxYES_NO | wxICON_QUESTION))
            OverwriteFile = false;

    if( OverwriteFile)
    {
        if(Manager::Get()->GetProjectManager()->GetActiveProject())
        {
            if(wxID_YES == cbMessageBox(_("Do you want to add the inno file to the active project?"),_("New Inno Setup"),wxYES|wxNO))
                Inno.AddToProject(true);
            else
                Inno.AddToProject(false);

            Inno.WriteEmptyFile(Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.'));
        }
        else
        {
            wxMessageBox( _T("Open your Project first"));
        }
    }
}

void Inno::OnNew(wxCommandEvent &event)
{
    CInno Inno;
    Inno.Create( Manager::Get()->GetAppWindow());

    wxString Name;

    bool OverwriteFile = true;
    if( Inno.FileExist( Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.')))
        if( wxID_NO == cbMessageBox( _("Do you want to overwrite the existing File?"), _("File exist"), wxYES_NO | wxICON_QUESTION))
            OverwriteFile = false;

    if( OverwriteFile)
    {

        if(Manager::Get()->GetProjectManager()->GetActiveProject())
        {
            Name = Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.');
            Name = Name.AfterLast( '\\');
            Inno.Set( Name);
            if(wxID_YES == cbMessageBox(_("Do you want to add the inno file to the active project?"),_("New Inno Setup"),wxYES|wxNO))
                Inno.AddToProject(true);
            else
                Inno.AddToProject(false);

            if( Inno.ShowStandartWizard())
            {
                wxString file_name = Manager::Get()->GetProjectManager()->GetActiveProject()->GetFilename().BeforeLast('.');
                Inno.WriteFile(file_name);
                iss_name = file_name + L".iss";

                cbEditor* ed = Manager::Get()->GetEditorManager()->Open(iss_name);
                ed->Reload();
                ed->Activate();

                if( wxYES == wxMessageBox( _T( "Do you want to compile the Inno Setup file?"), _T( "Inno Setup"), wxYES_NO | wxICON_QUESTION))
                {
                    wxCommandEvent event;
                    OnInnoBuild(event);
                }
            }
        }
        else
        {
            wxMessageBox( _T("Open your Project first"));
        }
    }

    Inno.Delete();
}

void Inno::OnInnoBuild(wxCommandEvent &event)
{
    ConfigManager* pCfg = Manager::Get()->GetConfigManager(_T("inno"));
    wxString path = L"\"" + pCfg->Read(_T("iscc_path"), _T("")) + L"\"";
    if( path.empty())
    {
        Manager::Get()->GetLogManager()->Log(L"please set the path to the inno compiler first!\nSettings->Environment...->Inno");
        return;
    }

    wxString command = path + L" \"";

    command += iss_name;

    command += L"\"";

    wxProcess* compile = new wxProcess(this, ID_INNO_THREAD);
    compile->Redirect();
    long pid = wxExecute(command, wxEXEC_ASYNC, compile);
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

    Manager::Get()->GetLogManager()->Log(wxString::Format(L"iscc build started with pid: %d", pid));

}

void Inno::OnProcessEnd( wxProcessEvent& evt)
{

    CodeBlocksLogEvent event(cbEVT_SWITCH_TO_LOG_WINDOW, m_logger);
    Manager::Get()->ProcessEvent(event);

    wxString text;
    while( m_out->CanRead())
    {
        text += m_out->GetC();
    }
    m_logger->Append(text);
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
        m_logger->Append(err, Logger::error);

    }
    else
    {
        Manager::Get()->GetEditorManager()->GetBuiltinActiveEditor()->Activate();
    }
}
