#include "InnoEditor.h"

//---- Icons ---------------------------------------------------------------------------------------
#include "inno.xpm"
#include "Images\components.xpm"
#include "Images\custom_msg.xpm"
#include "Images\files.xpm"
#include "Images\folder.xpm"
#include "Images\icon.xpm"
#include "Images\ini.xpm"
#include "Images\install.xpm"
#include "Images\install_del.xpm"
#include "Images\language.xpm"
#include "Images\msg.xpm"
#include "Images\registry.xpm"
#include "Images\pas.xpm"
#include "Images\script.xpm"
#include "Images\steps.xpm"
#include "Images\tasks.xpm"
#include "Images\types.xpm"
#include "Images\uninstall.xpm"
#include "Images\uninstall_del.xpm"
#include "Images\run.xpm"
//----  --------------------------------------------------------------------------------------------

#include <wx/textfile.h>
#include <logmanager.h>
#include <editormanager.h>

//(*InternalHeaders(InnoEditor)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(InnoEditor)
const long InnoEditor::ID_BUILDBUTTON = wxNewId();
const long InnoEditor::ID_TREECTRL1 = wxNewId();
const long InnoEditor::ID_BUTTON1 = wxNewId();
const long InnoEditor::ID_LISTCTRL1 = wxNewId();
const long InnoEditor::ID_PANEL1 = wxNewId();
//*)
const long ID_EDITOR_THREAD = wxNewId();

BEGIN_EVENT_TABLE(InnoEditor,cbEditor)
	//(*EventTable(InnoEditor)
	//*)
	EVT_END_PROCESS(ID_EDITOR_THREAD, InnoEditor::OnProcessEnd)
END_EVENT_TABLE()

InnoEditor::InnoEditor( wxWindow* parent, const wxString& filename, int log)
 : cbEditor( parent, Manager::Get()->GetFileManager()->Load(filename), filename,
						 Manager::Get()->GetEditorManager()->GetColourSet()),
		m_log_pos(log), inno_part(SCRIPT),m_running(false), m_consume(nullptr)
{

	wxBoxSizer* sizer = static_cast<wxBoxSizer*>(GetSizer());

	wxFileName file = wxFileName(filename);
	m_name = file.GetName();
	m_name += _T("[.");
	m_name += file.GetExt();
	m_name += _T("]");
	m_file = filename;
	Freeze();
	//(*Initialize(InnoEditor)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_build = new wxBitmapButton(this, ID_BUILDBUTTON, wxBitmap(run_xpm), wxDefaultPosition, wxSize(25,25), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BUILDBUTTON"));
	BoxSizer1->Add(m_build, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(205,460), 0, wxDefaultValidator, _T("ID_TREECTRL1"));
	wxTreeItemId TreeCtrl1_Item1 = TreeCtrl1->AddRoot(_T("root"));
	wxTreeItemId TreeCtrl1_Item2 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Script"));
	wxTreeItemId TreeCtrl1_Item3 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Files"));
	wxTreeItemId TreeCtrl1_Item4 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Folders"));
	wxTreeItemId TreeCtrl1_Item5 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Icons"));
	wxTreeItemId TreeCtrl1_Item6 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Ini"));
	wxTreeItemId TreeCtrl1_Item7 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Tasks"));
	wxTreeItemId TreeCtrl1_Item8 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Registry"));
	wxTreeItemId TreeCtrl1_Item9 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Language"));
	wxTreeItemId TreeCtrl1_Item10 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Types"));
	wxTreeItemId TreeCtrl1_Item11 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Components"));
	wxTreeItemId TreeCtrl1_Item12 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Messages"));
	wxTreeItemId TreeCtrl1_Item13 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Custom Messages"));
	wxTreeItemId TreeCtrl1_Item14 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Pascal Code"));
	wxTreeItemId TreeCtrl1_Item15 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Install Run"));
	wxTreeItemId TreeCtrl1_Item16 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Install Delete"));
	wxTreeItemId TreeCtrl1_Item17 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Uninstall Run"));
	wxTreeItemId TreeCtrl1_Item18 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Uninstall Delete"));
	TreeCtrl1->ScrollTo(TreeCtrl1_Item2);
	TreeCtrl1->SetItemText(TreeCtrl1_Item1, m_name);
	BoxSizer1->Add(TreeCtrl1, 0, wxRIGHT|wxEXPAND, 5);

	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->Hide();
	sizer->Add(Panel1, 1, wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxEXPAND, 5);
	ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES, wxDefaultValidator, _T("ID_LISTCTRL1"));
	BoxSizer2->Add(ListCtrl1, 1, wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);

	ImageList = new wxImageList(22, 22, 1);
	ImageList->Add(wxBitmap(inno_xpm));
	ImageList->Add(wxBitmap(script_xpm));
	ImageList->Add(wxBitmap(files_xpm));
	ImageList->Add(wxBitmap(folder_xpm));
	ImageList->Add(wxBitmap(icon_xpm));
	ImageList->Add(wxBitmap(ini_xpm));
	ImageList->Add(wxBitmap(tasks_xpm));
	ImageList->Add(wxBitmap(registry_xpm));
	ImageList->Add(wxBitmap(language_xpm));
	ImageList->Add(wxBitmap(types_xpm));
	ImageList->Add(wxBitmap(components_xpm));
	ImageList->Add(wxBitmap(msg_xpm));
	ImageList->Add(wxBitmap(custom_msg_xpm));
	ImageList->Add(wxBitmap(pas_xpm));
	ImageList->Add(wxBitmap(install_xpm));
	ImageList->Add(wxBitmap(install_del_xpm));
	ImageList->Add(wxBitmap(uninstall_xpm));
	ImageList->Add(wxBitmap(uninstall_del_xpm));
	ImageList->Add(wxBitmap(steps_xpm));


	Connect(ID_BUILDBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InnoEditor::OnbuildClick);
	// Set the images for TreeCtrl1.
	TreeCtrl1->SetImageList(ImageList);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item1, 0, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item2, 1, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item3, 2, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item4, 3, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item5, 4, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item6, 5, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item7, 6, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item8, 7, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item9, 8, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item10, 9, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item11, 10, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item12, 11, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item13, 12, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item14, 13, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item15, 14, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item16, 15, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item17, 16, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item18, 17, wxTreeItemIcon_Normal);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&InnoEditor::OnTreeCtrl1ItemActivated);
	//*)

	sizer->SetOrientation(wxHORIZONTAL);
	sizer->Insert(0, BoxSizer1, 0, wxRIGHT|wxEXPAND, 5);
	sizer->Layout();
	Layout();
	Thaw();
	m_script.Read(GetLeftSplitViewControl()->GetText());
}

InnoEditor::~InnoEditor()
{
	//(*Destroy(InnoEditor)
	//*)
}

void InnoEditor::OnTreeCtrl1ItemActivated(wxTreeEvent& event)
{
	wxString activated = TreeCtrl1->GetItemText(event.GetItem());
	if( activated.compare(_T("Script")) == 0
	 || activated.compare(m_name) == 0)
	{
		if( inno_part != SCRIPT)
		{
			inno_part = SCRIPT;
			Panel1->Show(false);
			GetLeftSplitViewControl()->Show(true);
			GetLeftSplitViewControl()->SetFocus();
			GetLeftSplitViewControl()->SetSCIFocus(true);
      //GetLeftSplitViewControl()->SetText(m_content);
			Activate();
			Layout();
		}
	}
	else
	{

		if( inno_part == SCRIPT)
		{
		  m_content = GetLeftSplitViewControl()->GetText();
			GetLeftSplitViewControl()->Show(false);
			Panel1->Show(true);
			Layout();
		}

		if( activated.compare(_T("Files")) == 0)
		{
			inno_part = FILES;
		}
		else if( activated.compare(_T("Folders")) == 0)
		{
			inno_part = FOLDERS;
		}
		else if( activated.compare(_T("Icons")) == 0)
		{
			inno_part = ICONS;
		}
		else if( activated.compare(_T("Ini")) == 0)
		{
			inno_part = INI;
		}
		else if( activated.compare(_T("Tasks")) == 0)
		{
			inno_part = TASKS;
		}
		else if( activated.compare(_T("Registry")) == 0)
		{
			inno_part = REGISTRY;
		}
		else if( activated.compare(_T("Language")) == 0)
		{
			inno_part = LANGUAGES;
		}
		else if( activated.compare(_T("Types")) == 0)
		{
			inno_part = TYPES;
		}
		else if( activated.compare(_T("Components")) == 0)
		{
			inno_part = COMPONENTS;
		}
		else if( activated.compare(_T("Messages")) == 0)
		{
			inno_part = MESSAGES;
		}
		else if( activated.compare(_T("Custom Messages")) == 0)
		{
			inno_part = CMESSAGES;
		}
		else if( activated.compare(_T("Pascal Code")) == 0)
		{
			inno_part = PASCALCODE;
		}
		else if( activated.compare(_T("Install Run")) == 0)
		{
			inno_part = RUN;
		}
		else if( activated.compare(_T("Install Delete")) == 0)
		{
			inno_part = INSTALLDEL;
		}
		else if( activated.compare(_T("Uninstall Run")) == 0)
		{
			inno_part = UNINSTALL;
		}
		else if( activated.compare(_T("Uninstall Delete")) == 0)
		{
			inno_part = UNINSTALLDEL;
		}
		else if( activated.compare(_T("Pre Compilation Steps")) == 0)
		{
			inno_part = PRE;
		}
		else if( activated.compare(_T("Post Compilation Steps")) == 0)
		{
			inno_part = POST;
		}
		UpdateView();
	}
}

void InnoEditor::OnbuildClick(wxCommandEvent& event)
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

  command += m_file;
  command += L"\"";

  m_running = true;
  wxProcess* compile = new wxProcess(this, ID_EDITOR_THREAD);
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

void InnoEditor::UpdateView()
{
	if( inno_part != SCRIPT)
	{
		ListCtrl1->ClearAll();
		m_script.Show(ListCtrl1, inno_part);
	}
}

bool InnoEditor::Save()
{
	bool save = cbEditor::Save();

	if( !GetModified())
	{

		m_script.Write(m_file);

		save = true;
	}

	m_script.Read(m_file);
	UpdateView();
	return save;
}

void InnoEditor::OnProcessEnd(cb_unused wxProcessEvent& evt)
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

