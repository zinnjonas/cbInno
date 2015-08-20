#include "SetupLanguages.h"

//(*InternalHeaders(SetupLanguages)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <prep.h>

#include "Images/LinksOben.xpm"

//(*IdInit(SetupLanguages)
const long SetupLanguages::ID_STATICTEXT2 = wxNewId();
const long SetupLanguages::ID_STATICTEXT1 = wxNewId();
const long SetupLanguages::ID_PANEL1 = wxNewId();
const long SetupLanguages::ID_STATICLINE1 = wxNewId();
const long SetupLanguages::ID_STATICTEXT3 = wxNewId();
const long SetupLanguages::ID_CHECKLISTBOX1 = wxNewId();
const long SetupLanguages::ID_BUTTON1 = wxNewId();
const long SetupLanguages::ID_BUTTON2 = wxNewId();
const long SetupLanguages::ID_STATICTEXT7 = wxNewId();
const long SetupLanguages::ID_STATICTEXT8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SetupLanguages,wxWizardPageSimple)
  //(*EventTable(SetupLanguages)
  //*)
END_EVENT_TABLE()

SetupLanguages::SetupLanguages(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next)
{
  //(*Initialize(SetupLanguages)
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer6;
  wxBoxSizer* BoxSizer19;
  wxBoxSizer* BoxSizer5;
  wxBoxSizer* BoxSizer7;
  wxBoxSizer* BoxSizer8;
  wxStaticText* StaticText2;
  wxStaticBitmap* StaticBitmap1;
  wxStaticText* StaticText8;
  wxStaticText* StaticText1;
  wxBoxSizer* BoxSizer2;
  wxStaticText* StaticText3;
  wxStaticText* StaticText7;
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer3;

  Create(parent, prev, next);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
  Panel1->SetBackgroundColour( wxColour( 255, 255, 255));
  BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer5 = new wxBoxSizer(wxVERTICAL);
  BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer6->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Setup Languages"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText2->SetFont(StaticText2Font);
  BoxSizer6->Add(StaticText2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5->Add(BoxSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer7->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("    Please specify which Setup languages should be included."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer7->Add(StaticText1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5->Add(BoxSizer7, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer4->Add(BoxSizer5, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticBitmap1 = new wxStaticBitmap(Panel1, wxID_ANY, wxBitmap( LinksOben_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
  BoxSizer4->Add(StaticBitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  Panel1->SetSizer(BoxSizer4);
  BoxSizer4->Fit(Panel1);
  BoxSizer4->SetSizeHints(Panel1);
  BoxSizer1->Add(Panel1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
  BoxSizer1->Add(StaticLine1, 0, wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer2->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Languages:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  wxFont StaticText3Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
  StaticText3->SetFont(StaticText3Font);
  BoxSizer2->Add(StaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer3->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  lbLanguages = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(261,201), 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
  lbLanguages->Check(lbLanguages->Append(_("English")));
  lbLanguages->Append(_("Basque"));
  lbLanguages->Append(_("Brazilian Portuguese"));
  lbLanguages->Append(_("Catalan"));
  lbLanguages->Append(_("Czech"));
  lbLanguages->Append(_("Danish"));
  lbLanguages->Append(_("Dutch"));
  lbLanguages->Append(_("Finnish"));
  lbLanguages->Append(_("French"));
  lbLanguages->Append(_("German"));
  lbLanguages->Append(_("Hebrew"));
  lbLanguages->Append(_("Hungarian"));
  lbLanguages->Append(_("Italian"));
  lbLanguages->Append(_("Japanese"));
  lbLanguages->Append(_("Norwegian"));
  lbLanguages->Append(_("Polish"));
  lbLanguages->Append(_("Portuguese"));
  lbLanguages->Append(_("Russian"));
  lbLanguages->Append(_("Slovak"));
  lbLanguages->Append(_("Slovenia"));
  lbLanguages->Append(_("Spanish"));
  BoxSizer3->Add(lbLanguages, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8 = new wxBoxSizer(wxVERTICAL);
  btnAll = new wxButton(this, ID_BUTTON1, _("Select all"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
  BoxSizer8->Add(btnAll, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  btnNone = new wxButton(this, ID_BUTTON2, _("Deselect all"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
  BoxSizer8->Add(btnNone, 0, wxTOP|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer3, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer19->Add(75,20,0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("bold"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  StaticText7->Disable();
  wxFont StaticText7Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
  StaticText7->SetFont(StaticText7Font);
  BoxSizer19->Add(StaticText7, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("= required"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  StaticText8->Disable();
  BoxSizer19->Add(StaticText8, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer19, 0, wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  SetSizer(BoxSizer1);
  Layout();

  Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SetupLanguages::OnbtnAllClick);
  Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SetupLanguages::OnbtnNoneClick);
  //*)
  SetSize( wxSize(480,320));
}

SetupLanguages::~SetupLanguages()
{
  //(*Destroy(SetupLanguages)
  //*)
}

bool SetupLanguages::IsChecked( void)
{
  for( unsigned int i = 0; i < lbLanguages->GetCount(); i++)
  {
    if( lbLanguages->IsChecked( i))
      return true;
  }
  return false;
}

void SetupLanguages::OnbtnAllClick(cb_unused wxCommandEvent& event)
{
  for( unsigned int i = 0; i < lbLanguages->GetCount(); i++)
  {
    lbLanguages->Check( i);
  }
}

void SetupLanguages::OnbtnNoneClick(cb_unused wxCommandEvent& event)
{
  for( unsigned int i = 0; i < lbLanguages->GetCount(); i++)
  {
    lbLanguages->Check( i, false);
  }
}
