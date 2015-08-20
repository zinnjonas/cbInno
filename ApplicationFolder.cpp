#include "ApplicationFolder.h"

//(*InternalHeaders(ApplicationFolder)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include <prep.h>

#include "Images/LinksOben.xpm"

//(*IdInit(ApplicationFolder)
const long ApplicationFolder::ID_STATICTEXT2 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT1 = wxNewId();
const long ApplicationFolder::ID_PANEL1 = wxNewId();
const long ApplicationFolder::ID_STATICLINE1 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT3 = wxNewId();
const long ApplicationFolder::ID_CHOICE1 = wxNewId();
const long ApplicationFolder::ID_TEXTCTRL1 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT4 = wxNewId();
const long ApplicationFolder::ID_TEXTCTRL2 = wxNewId();
const long ApplicationFolder::ID_CHECKBOX1 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT5 = wxNewId();
const long ApplicationFolder::ID_CHECKBOX2 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT7 = wxNewId();
const long ApplicationFolder::ID_STATICTEXT8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ApplicationFolder,wxPanel)
  //(*EventTable(ApplicationFolder)
  //*)
END_EVENT_TABLE()

ApplicationFolder::ApplicationFolder(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next)
{
  //(*Initialize(ApplicationFolder)
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer6;
  wxBoxSizer* BoxSizer19;
  wxBoxSizer* BoxSizer5;
  wxBoxSizer* BoxSizer10;
  wxBoxSizer* BoxSizer7;
  wxBoxSizer* BoxSizer8;
  wxStaticText* StaticText2;
  wxBoxSizer* BoxSizer13;
  wxStaticBitmap* StaticBitmap1;
  wxStaticText* StaticText8;
  wxStaticText* StaticText1;
  wxBoxSizer* BoxSizer2;
  wxBoxSizer* BoxSizer11;
  wxBoxSizer* BoxSizer12;
  wxBoxSizer* BoxSizer14;
  wxStaticText* StaticText5;
  wxStaticText* StaticText7;
  wxBoxSizer* BoxSizer1;
  wxBoxSizer* BoxSizer9;
  wxBoxSizer* BoxSizer3;

  Create(parent, prev, next);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
  Panel1->SetBackgroundColour( wxColour( 255, 255, 255));
  BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer5 = new wxBoxSizer(wxVERTICAL);
  BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer6->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Application Folder"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText2->SetFont(StaticText2Font);
  BoxSizer6->Add(StaticText2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5->Add(BoxSizer6, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer7->Add(35,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("    Please specify folder information about your application."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
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
  BoxSizer2 = new wxBoxSizer(wxVERTICAL);
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer3->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  text1 = new wxStaticText(this, ID_STATICTEXT3, _("Application destination base folder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  wxFont text1Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  text1->SetFont(text1Font);
  BoxSizer3->Add(text1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer3, 0, wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer8->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  chProgrammFolder = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(214,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
  chProgrammFolder->SetSelection( chProgrammFolder->Append(_("program Files folder")) );
  chProgrammFolder->Append(_("(custom)"));
  BoxSizer8->Add(chProgrammFolder, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer8, 0, wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer9->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtCustom = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(217,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  txtCustom->Disable();
  BoxSizer9->Add(txtCustom, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer9, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer10->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  text2 = new wxStaticText(this, ID_STATICTEXT4, _("Application folder name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  wxFont text2Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  text2->SetFont(text2Font);
  BoxSizer10->Add(text2, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer10, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer11->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  txtAppFolderName = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(221,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
  BoxSizer11->Add(txtAppFolderName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer11->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer11, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer12->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  cbAppFolderName = new wxCheckBox(this, ID_CHECKBOX1, _("Allow user to change the application folder"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
  cbAppFolderName->SetValue(true);
  BoxSizer12->Add(cbAppFolderName, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer12->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer12, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer13->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Otehr:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
  BoxSizer13->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer13->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer13, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer14->Add(75,20,0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  cbDoesntFolder = new wxCheckBox(this, ID_CHECKBOX2, _("The application doesn\'t need a folder"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
  cbDoesntFolder->SetValue(false);
  BoxSizer14->Add(cbDoesntFolder, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer14->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(BoxSizer14, 0, wxTOP|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

  Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ApplicationFolder::OnchProgrammFolderSelect);
  Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ApplicationFolder::OncbDoesntFolderClick);
  //*)
  SetSize( wxSize(480,320));
}

ApplicationFolder::~ApplicationFolder()
{
  //(*Destroy(ApplicationFolder)
  //*)
}


void ApplicationFolder::OnchProgrammFolderSelect(cb_unused wxCommandEvent& event)
{

  if( chProgrammFolder->GetSelection() == 0)
    txtCustom->Enable( false);
  else
    txtCustom->Enable( true);
}

void ApplicationFolder::OncbDoesntFolderClick(cb_unused wxCommandEvent& event)
{
  if( cbDoesntFolder->IsChecked())
  {
    text1->Enable( false);
    text2->Enable( false);
    chProgrammFolder->Enable( false);
    txtCustom->Enable( false);
    txtAppFolderName->Enable( false);
    cbAppFolderName->Enable( false);
  }
  else
  {
    cbAppFolderName->Enable( true);
    text1->Enable( true);
    text2->Enable( true);
    txtAppFolderName->Enable( true);
    chProgrammFolder->Enable( true);
    if( chProgrammFolder->GetSelection() == 0)
      txtCustom->Enable( false);
    else
      txtCustom->Enable( true);
  }
}
