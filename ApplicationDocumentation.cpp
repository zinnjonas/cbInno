#include "ApplicationDocumentation.h"

//(*InternalHeaders(ApplicationDocumentation)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include "Images/LinksOben.xpm"

//(*IdInit(ApplicationDocumentation)
const long ApplicationDocumentation::ID_STATICTEXT2 = wxNewId();
const long ApplicationDocumentation::ID_STATICTEXT1 = wxNewId();
const long ApplicationDocumentation::ID_PANEL1 = wxNewId();
const long ApplicationDocumentation::ID_STATICLINE1 = wxNewId();
const long ApplicationDocumentation::ID_STATICTEXT3 = wxNewId();
const long ApplicationDocumentation::ID_TEXTCTRL2 = wxNewId();
const long ApplicationDocumentation::ID_BUTTON2 = wxNewId();
const long ApplicationDocumentation::ID_STATICTEXT5 = wxNewId();
const long ApplicationDocumentation::ID_TEXTCTRL1 = wxNewId();
const long ApplicationDocumentation::ID_BUTTON1 = wxNewId();
const long ApplicationDocumentation::ID_STATICTEXT4 = wxNewId();
const long ApplicationDocumentation::ID_TEXTCTRL3 = wxNewId();
const long ApplicationDocumentation::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ApplicationDocumentation,wxWizardPageSimple)
	//(*EventTable(ApplicationDocumentation)
	//*)
END_EVENT_TABLE()

ApplicationDocumentation::ApplicationDocumentation(wxWizard* parent, wxWizardPageSimple* prev)
{
	//(*Initialize(ApplicationDocumentation)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxStaticText* StaticText2;
	wxStaticBitmap* StaticBitmap1;
	wxStaticText* StaticText1;
	wxBoxSizer* BoxSizer2;
	wxStaticText* StaticText3;
	wxBoxSizer* BoxSizer11;
	wxStaticText* StaticText5;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxBoxSizer* BoxSizer3;
	wxStaticText* StaticText4;

	Create(parent, prev);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour( wxColour( 255, 255, 255));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer6->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Application Documentation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	BoxSizer6->Add(StaticText2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer7->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("    Please specify which documentation files should be shown by Setup during\n    installation."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer7->Add(StaticText1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer7, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(BoxSizer5, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBitmap1 = new wxStaticBitmap(Panel1, wxID_ANY, wxBitmap(LinksOben_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer4->Add(StaticBitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer4);
	BoxSizer4->Fit(Panel1);
	BoxSizer4->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	BoxSizer1->Add(StaticLine1, 0, wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Liecense file:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	BoxSizer2->Add(StaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer8->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtLiecens = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(308,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer8->Add(txtLiecens, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnLiecense = new wxButton(this, ID_BUTTON2, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer8->Add(btnLiecense, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer8, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer10->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Information file shown before installation:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	BoxSizer10->Add(StaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer10, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtBefore = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(308,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer3->Add(txtBefore, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnBefore = new wxButton(this, ID_BUTTON1, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(btnBefore, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer9->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Information file shown after installation:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	BoxSizer9->Add(StaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer9->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer9, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer11->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtAfter = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(308,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer11->Add(txtAfter, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnAfter = new wxButton(this, ID_BUTTON3, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer11->Add(btnAfter, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer11->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer11, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	FileDialog1 = new wxFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, _("Documentation files(*.rtf,*.txt)|*.rft;*.txt"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationDocumentation::OnbtnLiecenseClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationDocumentation::OnbtnBeforeClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationDocumentation::OnbtnAfterClick);
	//*)
	SetSize( wxSize(480,320));
}

ApplicationDocumentation::~ApplicationDocumentation()
{
	//(*Destroy(ApplicationDocumentation)
	//*)
}


void ApplicationDocumentation::OnbtnLiecenseClick(wxCommandEvent& event)
{
    FileDialog1->SetPath( txtLiecens->GetValue());

    if( FileDialog1->ShowModal() == wxID_OK)
        txtLiecens->SetValue( FileDialog1->GetPath());
}

void ApplicationDocumentation::OnbtnBeforeClick(wxCommandEvent& event)
{
    FileDialog1->SetPath( txtBefore->GetValue());

    if( FileDialog1->ShowModal() == wxID_OK)
        txtBefore->SetValue( FileDialog1->GetPath());
}

void ApplicationDocumentation::OnbtnAfterClick(wxCommandEvent& event)
{
    FileDialog1->SetPath( txtAfter->GetValue());

    if( FileDialog1->ShowModal() == wxID_OK)
        txtAfter->SetValue( FileDialog1->GetPath());
}
