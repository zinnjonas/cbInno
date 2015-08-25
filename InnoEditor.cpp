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

//(*InternalHeaders(InnoEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(InnoEditor)
const long InnoEditor::ID_TREECTRL1 = wxNewId();
const long InnoEditor::ID_BUTTON1 = wxNewId();
const long InnoEditor::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(InnoEditor,cbEditor)
	//(*EventTable(InnoEditor)
	//*)
END_EVENT_TABLE()

InnoEditor::InnoEditor( wxWindow* parent, const wxString& filename, const wxString& fn)
 : cbEditor( parent, Manager::Get()->GetFileManager()->Load(filename), fn,
             new EditorColourSet(Manager::Get()->GetConfigManager(_T("editor"))->Read(_T("/colour_sets/active_colour_set"), COLORSET_DEFAULT))),
		m_script(true)
{

	wxBoxSizer* sizer = static_cast<wxBoxSizer*>(GetSizer());

	wxFileName file = wxFileName(fn);
	m_name = file.GetName();
	m_name += _T("[.");
	m_name += file.GetExt();
	m_name += _T("]");
	Freeze();
	//(*Initialize(InnoEditor)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

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
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->Hide();
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 0, wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	sizer->Add(Panel1, 1, wxEXPAND, 5);

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
	TreeCtrl1->SetItemText(TreeCtrl1_Item1, m_name);

	sizer->SetOrientation(wxHORIZONTAL);
	sizer->Insert(0, TreeCtrl1, 0, wxRIGHT|wxEXPAND, 5);
	sizer->Layout();
	Layout();
	Thaw();
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
		if( !m_script)
		{
			m_script = true;
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
		if( m_script)
		{
			m_script = false;
			m_line = GetLeftSplitViewControl()->GetCurrentLine();
			GetLeftSplitViewControl()->Show(false);
			Panel1->Show(true);
			Layout();
		}
	}
}
