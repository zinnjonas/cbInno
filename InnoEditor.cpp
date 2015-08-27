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
//----  --------------------------------------------------------------------------------------------

#include <wx/textfile.h>
#include <logmanager.h>
#include <editormanager.h>

//(*InternalHeaders(InnoEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(InnoEditor)
const long InnoEditor::ID_BUILD = wxNewId();
const long InnoEditor::ID_TREECTRL1 = wxNewId();
const long InnoEditor::ID_BUTTON1 = wxNewId();
const long InnoEditor::ID_LISTCTRL1 = wxNewId();
const long InnoEditor::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(InnoEditor,cbEditor)
	//(*EventTable(InnoEditor)
	//*)
END_EVENT_TABLE()

InnoEditor::InnoEditor( wxWindow* parent, const wxString& filename)
 : cbEditor( parent, Manager::Get()->GetFileManager()->Load(filename), filename,
						 Manager::Get()->GetEditorManager()->GetColourSet()),
		inno_part(SCRIPT)
{

	wxBoxSizer* sizer = static_cast<wxBoxSizer*>(GetSizer());

	wxFileName file = wxFileName(filename);
	m_name = file.GetName();
	m_name += _T("[.");
	m_name += file.GetExt();
	m_name += _T("]");
	Freeze();
	//(*Initialize(InnoEditor)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer3;

	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_build = new wxButton(this, ID_BUILD, _("Build"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUILD"));
	BoxSizer1->Add(m_build, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
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
	wxTreeItemId TreeCtrl1_Item19 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Pre Compilation Steps"));
	wxTreeItemId TreeCtrl1_Item20 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("Post Compilation Steps"));
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


	Connect(ID_BUILD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&InnoEditor::OnbuildClick);
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
	TreeCtrl1->SetItemImage(TreeCtrl1_Item19, 18, wxTreeItemIcon_Normal);
	TreeCtrl1->SetItemImage(TreeCtrl1_Item20, 18, wxTreeItemIcon_Normal);
	Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&InnoEditor::OnTreeCtrl1ItemActivated);
	//*)

	sizer->SetOrientation(wxHORIZONTAL);
	sizer->Insert(0, BoxSizer1, 0, wxRIGHT|wxEXPAND, 5);
	sizer->Layout();
	Layout();
	Thaw();
	readfile(filename);
}

InnoEditor::~InnoEditor()
{
	//(*Destroy(InnoEditor)
	//*)
}

void InnoEditor::readfile(const wxString& filename)
{

	wxTextFile file;
	file.Open(filename);

	wxString content = file.GetFirstLine();
	int line = 0;
	analize(content, wxString::Format(_T("%d"), ++line));
	while( !file.Eof())
	{
		content = file.GetNextLine();
		analize(content, wxString::Format(_T("%d"), ++line));
	}
	file.Close();

	inno_part = SCRIPT;
}

void InnoEditor::analize(const wxString& content, const wxString& line)
{
	wxString cont = content.BeforeFirst(';');
  cont = cont.Trim();
  if( !content.empty() && !cont.empty())
  {
    if( content.StartsWith(_T("#"), &cont))
    {
      analize_preprocessor(cont);
    }
    else if(content.StartsWith(_T("["), &cont))
    {
      cont = cont.BeforeLast(']');
      analize_section(cont, line);
    }
    else
    {
      if( inno_part == FILES)
      {
        CFiles file;
				file.Analize(content, line);
				m_Files.push_back(file);
      }
    }
  }
  else if( !content.empty())
  {
  	if( inno_part == FILES)
		{
			CFiles comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_Files.push_back(comment);
		}
  }
}

void InnoEditor::analize_preprocessor(const wxString& content)
{
	wxString con;
	if( content.StartsWith(_T("include"), &con))
	{
	}
	else if( content.StartsWith(_T("define"), &con))
	{
	}
	else if( content.StartsWith(_T("undef"), &con))
	{
	}
	else if( content.StartsWith(_T("file"), &con))
	{
	}
	else if( content.StartsWith(_T("emit"), &con))
	{
	}
	else if( content.StartsWith(_T("expr"), &con))
	{
	}
	else if( content.StartsWith(_T("insert"), &con))
	{
	}
	else if( content.StartsWith(_T("append"), &con))
	{
	}
	else if( content.StartsWith(_T("for"), &con))
	{
	}
	else if( content.StartsWith(_T("pragma"), &con))
	{
	}
	else if( content.StartsWith(_T("error"), &con))
	{
	}
}

void InnoEditor::analize_section(const wxString& content, const wxString& line)
{
	if( content.CmpNoCase(_T("setup")) == 0)
		inno_part = SETUP;
	else if( content.CmpNoCase(_T("types")) == 0)
		inno_part = TYPES;
	else if( content.CmpNoCase(_T("components")) == 0)
		inno_part = COMPONENTS;
	else if( content.CmpNoCase(_T("tasks")) == 0)
		inno_part = TASKS;
	else if( content.CmpNoCase(_T("dirs")) == 0)
		inno_part = FOLDERS;
	else if( content.CmpNoCase(_T("files")) == 0)
		inno_part = FILES;
	else if( content.CmpNoCase(_T("icons")) == 0)
		inno_part = ICONS;
	else if( content.CmpNoCase(_T("ini")) == 0)
		inno_part = INI;
	else if( content.CmpNoCase(_T("installdelete")) == 0)
		inno_part = INSTALLDEL;
	else if( content.CmpNoCase(_T("languages")) == 0)
		inno_part = LANGUAGES;
	else if( content.CmpNoCase(_T("messages")) == 0)
		inno_part = MESSAGES;
	else if( content.CmpNoCase(_T("custommessages")) == 0)
		inno_part = CMESSAGES;
	else if( content.CmpNoCase(_T("langoptions")) == 0)
		inno_part = LANGOPT;
	else if( content.CmpNoCase(_T("registry")) == 0)
		inno_part = REGISTRY;
	else if( content.CmpNoCase(_T("run")) == 0)
		inno_part = RUN;
	else if( content.CmpNoCase(_T("uninstalldelete")) == 0)
		inno_part = UNINSTALLDEL;
	else if( content.CmpNoCase(_T("uninstallrun")) == 0)
		inno_part = UNINSTALL;
	else if( content.CmpNoCase(_T("code")) == 0)
		inno_part = PASCALCODE;
	else
		inno_part = SCRIPT;
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
			Reload();
			Activate();
			GotoLine(m_line);
			Layout();
		}
	}
	else
	{
		ListCtrl1->ClearAll();

		if( inno_part == SCRIPT)
		{
			m_line = GetLeftSplitViewControl()->GetCurrentLine();
			GetLeftSplitViewControl()->Show(false);
			Panel1->Show(true);
			Layout();
		}

		if( activated.compare(_T("Files")) == 0)
		{
			inno_part = FILES;
			CFiles::AddHeader(ListCtrl1);
			for( CFiles file : m_Files)
			{
				file.AddContent(ListCtrl1);
			}
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
			inno_part = INSTALL;
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
	}
}

void InnoEditor::OnbuildClick(wxCommandEvent& event)
{
}
