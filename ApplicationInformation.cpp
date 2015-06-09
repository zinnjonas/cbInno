#include "ApplicationInformation.h"

//(*InternalHeaders(ApplicationInformation)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include "Images/LinksOben.xpm"

//(*IdInit(ApplicationInformation)
const long ApplicationInformation::ID_STATICTEXT2 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT1 = wxNewId();
const long ApplicationInformation::ID_PANEL1 = wxNewId();
const long ApplicationInformation::ID_STATICLINE1 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT6 = wxNewId();
const long ApplicationInformation::ID_TEXTCTRL4 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT5 = wxNewId();
const long ApplicationInformation::ID_TEXTCTRL3 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT4 = wxNewId();
const long ApplicationInformation::ID_TEXTCTRL2 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT3 = wxNewId();
const long ApplicationInformation::ID_TEXTCTRL1 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT7 = wxNewId();
const long ApplicationInformation::ID_STATICTEXT8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ApplicationInformation,wxPanel)
  //(*EventTable(ApplicationInformation)
  //*)
END_EVENT_TABLE()

ApplicationInformation::ApplicationInformation(wxWizard* parent, wxWizardPageSimple* prev)
{
  //(*Initialize(ApplicationInformation)
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer6;
  wxBoxSizer* BoxSizer19;
  wxBoxSizer* BoxSizer15;
  wxBoxSizer* BoxSizer5;
  wxBoxSizer* BoxSizer10;
  wxBoxSizer* BoxSizer7;
  wxBoxSizer* BoxSizer8;
  wxStaticText* StaticText2;
  wxBoxSizer* BoxSizer13;
  wxStaticText* StaticText6;
  wxStaticBitmap* StaticBitmap1;
  wxStaticText* StaticText8;
  wxStaticText* StaticText1;
  wxBoxSizer* BoxSizer2;
  wxStaticText* StaticText3;
  wxBoxSizer* BoxSizer11;
  wxBoxSizer* BoxSizer16;
  wxBoxSizer* BoxSizer12;
  wxBoxSizer* BoxSizer18;
  wxBoxSizer* BoxSizer14;
  wxStaticText* StaticText5;
  wxStaticText* StaticText7;
  wxBoxSizer* BoxSizer17;
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer9;
  wxBoxSizer* BoxSizer3;
  wxStaticText* StaticText4;

  Create(parent, prev);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
  Panel1->SetBackgroundColour( wxColour( 255, 255, 255));
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer4 = new wxBoxSizer(wxVERTICAL);
  BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer6->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Application Information"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText2->SetFont(StaticText2Font);
  BoxSizer6->Add(StaticText2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer4->Add(BoxSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer5->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("    Please specify some basic information about your application."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer5->Add(StaticText1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer4->Add(BoxSizer5, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(BoxSizer4, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticBitmap1 = new wxStaticBitmap(Panel1, wxID_ANY, wxBitmap(LinksOben_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
  BoxSizer3->Add(StaticBitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Panel1->SetSizer(BoxSizer3);
  BoxSizer3->Fit(Panel1);
  BoxSizer3->SetSizeHints(Panel1);
  BoxSizer1->Add(Panel1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
  BoxSizer1->Add(StaticLine1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2 = new wxBoxSizer(wxVERTICAL);
  BoxSizer16 = new wxBoxSizer(wxVERTICAL);
  BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer17->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Application name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
  wxFont StaticText6Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText6->SetFont(StaticText6Font);
  BoxSizer17->Add(StaticText6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer17->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer16->Add(BoxSizer17, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer18->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtAppName = new wxTextCtrl(this, ID_TEXTCTRL4, _("My Program"), wxDefaultPosition, wxSize(237,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
  BoxSizer18->Add(txtAppName, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer18->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer16->Add(BoxSizer18, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer16, 0, wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13 = new wxBoxSizer(wxVERTICAL);
  BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer14->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Application version:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
  wxFont StaticText5Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText5->SetFont(StaticText5Font);
  BoxSizer14->Add(StaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer14->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13->Add(BoxSizer14, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer15->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtAppversion = new wxTextCtrl(this, ID_TEXTCTRL3, _("1.5"), wxDefaultPosition, wxSize(237,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
  BoxSizer15->Add(txtAppversion, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer15->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13->Add(BoxSizer15, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer13, 0, wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10 = new wxBoxSizer(wxVERTICAL);
  BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer11->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Application publisher:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  BoxSizer11->Add(StaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer11->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(BoxSizer11, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer12->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtAppPublisher = new wxTextCtrl(this, ID_TEXTCTRL2, _("MyCompany, Inc."), wxDefaultPosition, wxSize(237,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  BoxSizer12->Add(txtAppPublisher, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer12->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(BoxSizer12, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer10, 0, wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7 = new wxBoxSizer(wxVERTICAL);
  BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer8->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Application webseite:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  BoxSizer8->Add(StaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7->Add(BoxSizer8, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer9->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtAppWebseite = new wxTextCtrl(this, ID_TEXTCTRL1, _("http://www.example.com/"), wxDefaultPosition, wxSize(237,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  BoxSizer9->Add(txtAppWebseite, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7->Add(BoxSizer9, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer7, 0, wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer19->Add(75,20,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("bold"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  StaticText7->Disable();
  wxFont StaticText7Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
  StaticText7->SetFont(StaticText7Font);
  BoxSizer19->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("= required"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  StaticText8->Disable();
  BoxSizer19->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer19, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  SetSizer(BoxSizer1);
  Layout();
  //*)
  //Weiter = true;
  SetSize( wxSize(480,320));
}

ApplicationInformation::~ApplicationInformation()
{
  //(*Destroy(ApplicationInformation)
  //*)
}

