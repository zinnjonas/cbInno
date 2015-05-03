#include "WizardFile.h"

//(*InternalHeaders(WizardFile)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(WizardFile)
const long WizardFile::ID_STATICTEXT1 = wxNewId();
const long WizardFile::ID_TEXTCTRL1 = wxNewId();
const long WizardFile::ID_CHECKBOX1 = wxNewId();
const long WizardFile::ID_CHECKBOX2 = wxNewId();
const long WizardFile::ID_STATICTEXT2 = wxNewId();
const long WizardFile::ID_CHOICE1 = wxNewId();
const long WizardFile::ID_TEXTCTRL2 = wxNewId();
const long WizardFile::ID_STATICTEXT3 = wxNewId();
const long WizardFile::ID_TEXTCTRL3 = wxNewId();
const long WizardFile::ID_STATICTEXT4 = wxNewId();
const long WizardFile::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(WizardFile,wxDialog)
	//(*EventTable(WizardFile)
	//*)
END_EVENT_TABLE()

WizardFile::WizardFile(wxWindow* parent, File Data,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(WizardFile)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticText* StaticText2;
	wxStaticText* text1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticText* StaticText4;

	Create(parent, id, _T("Inno Wizard"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Source"));
	text1 = new wxStaticText(this, ID_STATICTEXT1, _("Source file or folder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	text1->Disable();
	wxFont text1Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	text1->SetFont(text1Font);
	StaticBoxSizer1->Add(text1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtFile = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	txtFile->Disable();
	StaticBoxSizer1->Add(txtFile, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	cbRecurse = new wxCheckBox(this, ID_CHECKBOX1, _("Recurse subfolders"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	cbRecurse->SetValue(false);
	BoxSizer2->Add(cbRecurse, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	cbInclude = new wxCheckBox(this, ID_CHECKBOX2, _("Include empty subfolders"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	cbInclude->SetValue(false);
	cbInclude->Disable();
	BoxSizer2->Add(cbInclude, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Destination"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Destination base folder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticBoxSizer2->Add(StaticText2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chDestination = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	chDestination->SetSelection( chDestination->Append(_("Application directory")) );
	chDestination->Append(_("Program Files directory"));
	chDestination->Append(_("Common Files directory"));
	chDestination->Append(_("Windows directory"));
	chDestination->Append(_("Windows system directory"));
	chDestination->Append(_("Setup source directroy"));
	chDestination->Append(_("System drive root directory"));
	chDestination->Append(_("Common Startup folder"));
	chDestination->Append(_("User Startup folder"));
	chDestination->Append(_("(Custiom)"));
	StaticBoxSizer2->Add(chDestination, 0, wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDestination = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	txtDestination->Disable();
	StaticBoxSizer2->Add(txtDestination, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Destination subfolder:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticBoxSizer2->Add(StaticText3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	txtDestSub = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer2->Add(txtDestSub, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("bold"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->Disable();
	wxFont StaticText4Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	BoxSizer3->Add(StaticText4, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _(" = required"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText5->Disable();
	BoxSizer3->Add(StaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnOK = new wxButton(this, wxID_YES, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_YES"));
	btnOK->SetDefault();
	BoxSizer3->Add(btnOK, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer3->Add(btnCancel, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&WizardFile::OncbRecurseClick);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&WizardFile::OnchDestinationSelect);
	Connect(wxID_YES,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WizardFile::OnbtnOKClick);
	Connect(wxID_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&WizardFile::OnbtnCancelClick);
	//*)
	FileData = Data;

	txtFile->SetValue( FileData.Source);
	cbRecurse->SetValue( FileData.Recurse);
	cbInclude->Enable( FileData.Recurse);
	cbInclude->SetValue( FileData.Include);
	chDestination->SetSelection( FileData.Destination);
	if( FileData.Destination == 9)
        txtDestination->Enable( true);
    txtDestination->SetValue( FileData.ExternDestionation);
    txtDestSub->SetValue(FileData.DestinationSub);
}

WizardFile::~WizardFile()
{
	//(*Destroy(WizardFile)
	//*)
}


void WizardFile::OnchDestinationSelect(wxCommandEvent& event)
{
    if( chDestination->GetSelection() == 9)
        txtDestination->Enable( true);
    else
        txtDestination->Enable( false);
}

void WizardFile::OncbRecurseClick(wxCommandEvent& event)
{
    cbInclude->Enable( cbRecurse->IsChecked());
}

void WizardFile::OnbtnOKClick(wxCommandEvent& event)
{
    if( (chDestination->GetSelection() != 9) || ( !txtDestination->IsEmpty()))
    {
        FileData.Recurse            = cbRecurse->IsChecked();
        FileData.Include            = cbInclude->IsChecked();
        FileData.Destination        = chDestination->GetSelection();
        FileData.ExternDestionation = txtDestination->GetValue();
        FileData.DestinationSub     = txtDestSub->GetValue();

        EndModal( true);
    }
    else
    {
        wxMessageBox( _T("Please specify the destination base folder."), _T("Error"), wxOK | wxICON_EXCLAMATION);
    }
}

void WizardFile::OnbtnCancelClick(wxCommandEvent& event)
{
    EndModal( false);
}
