#include "ApplicationFiles.h"

//(*InternalHeaders(ApplicationFiles)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <cbproject.h>

#include "Images/LinksOben.xpm"

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayFile);

//(*IdInit(ApplicationFiles)
const long ApplicationFiles::ID_STATICTEXT2 = wxNewId();
const long ApplicationFiles::ID_STATICTEXT1 = wxNewId();
const long ApplicationFiles::ID_PANEL1 = wxNewId();
const long ApplicationFiles::ID_STATICLINE1 = wxNewId();
const long ApplicationFiles::ID_STATICTEXT3 = wxNewId();
const long ApplicationFiles::ID_TEXTCTRL1 = wxNewId();
const long ApplicationFiles::ID_BUTTON1 = wxNewId();
const long ApplicationFiles::ID_CHECKBOX1 = wxNewId();
const long ApplicationFiles::ID_CHECKBOX2 = wxNewId();
const long ApplicationFiles::ID_STATICTEXT4 = wxNewId();
const long ApplicationFiles::ID_LISTBOX1 = wxNewId();
const long ApplicationFiles::ID_BUTTON2 = wxNewId();
const long ApplicationFiles::ID_BUTTON3 = wxNewId();
const long ApplicationFiles::ID_BUTTON4 = wxNewId();
const long ApplicationFiles::ID_BUTTON5 = wxNewId();
const long ApplicationFiles::ID_STATICTEXT7 = wxNewId();
const long ApplicationFiles::ID_STATICTEXT8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ApplicationFiles,wxWizardPageSimple)
  //(*EventTable(ApplicationFiles)
  //*)
END_EVENT_TABLE()

ApplicationFiles::ApplicationFiles(wxWizard* parent, wxWizardPageSimple* prev)
{
  //(*Initialize(ApplicationFiles)
  wxBoxSizer* BoxSizer4;
  wxBoxSizer* BoxSizer6;
  wxBoxSizer* BoxSizer19;
  wxBoxSizer* BoxSizer5;
  wxBoxSizer* BoxSizer10;
  wxBoxSizer* BoxSizer7;
  wxBoxSizer* BoxSizer8;
  wxStaticText* StaticText2;
  wxStaticBitmap* StaticBitmap1;
  wxStaticText* StaticText8;
  wxStaticText* StaticText1;
  wxBoxSizer* BoxSizer2;
  wxBoxSizer* BoxSizer11;
  wxBoxSizer* BoxSizer12;
  wxStaticText* StaticText7;
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
  BoxSizer6->Add(35,20,0, wxALIGN_CENTER_VERTICAL, 5);
  StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Application Files"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
  wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  StaticText2->SetFont(StaticText2Font);
  BoxSizer6->Add(StaticText2, 1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5->Add(BoxSizer6, 0, wxEXPAND, 5);
  BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer7->Add(35,20,0, wxALIGN_CENTER_VERTICAL, 5);
  StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("    Please specify the files that are part of your application."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer7->Add(StaticText1, 1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer5->Add(BoxSizer7, 0, wxEXPAND, 5);
  BoxSizer4->Add(BoxSizer5, 0, wxEXPAND, 5);
  BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
  StaticBitmap1 = new wxStaticBitmap(Panel1, wxID_ANY, wxBitmap(LinksOben_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
  BoxSizer4->Add(StaticBitmap1, 0, wxALIGN_CENTER_VERTICAL, 5);
  Panel1->SetSizer(BoxSizer4);
  BoxSizer4->Fit(Panel1);
  BoxSizer4->SetSizeHints(Panel1);
  BoxSizer1->Add(Panel1, 0, wxEXPAND, 5);
  StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
  BoxSizer1->Add(StaticLine1, 0, wxBOTTOM|wxEXPAND, 5);
  BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer2->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  text1 = new wxStaticText(this, ID_STATICTEXT3, _("Application main executable file:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
  wxFont text1Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
  text1->SetFont(text1Font);
  BoxSizer2->Add(text1, 0, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxLEFT|wxEXPAND, 5);
  BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer3->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  txtMainExe = new wxTextCtrl(this, ID_TEXTCTRL1, _("C:\\Program Files (x86)\\Inno setup 5\\Examples\\MyProg.exe"), wxDefaultPosition, wxSize(308,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  BoxSizer3->Add(txtMainExe, 0, wxALIGN_CENTER_VERTICAL, 5);
  btnMainExe = new wxButton(this, ID_BUTTON1, _("Browse..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
  BoxSizer3->Add(btnMainExe, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer3->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer3, 0, wxTOP|wxLEFT|wxEXPAND, 5);
  BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer8->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  cbAllowStartAfterInstall = new wxCheckBox(this, ID_CHECKBOX1, _("Allow user to start the application after Setup has finished"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
  cbAllowStartAfterInstall->SetValue(true);
  BoxSizer8->Add(cbAllowStartAfterInstall, 0, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer8->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer8, 0, wxTOP|wxLEFT|wxEXPAND, 5);
  BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer9->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  cbDoesntHaveMain = new wxCheckBox(this, ID_CHECKBOX2, _("The application doesn\'t have a main executable file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
  cbDoesntHaveMain->SetValue(false);
  BoxSizer9->Add(cbDoesntHaveMain, 0, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer9->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer9, 0, wxTOP|wxLEFT|wxEXPAND, 5);
  BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer10->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Other application files:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
  BoxSizer10->Add(StaticText4, 0, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer10->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer10, 0, wxTOP|wxLEFT|wxEXPAND, 5);
  BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer11->Add(75,20,0, wxALIGN_CENTER_VERTICAL, 5);
  lbFiles = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(309,124), 0, 0, wxLB_HSCROLL, wxDefaultValidator, _T("ID_LISTBOX1"));
  BoxSizer11->Add(lbFiles, 0, wxEXPAND, 5);
  BoxSizer12 = new wxBoxSizer(wxVERTICAL);
  btnFiles = new wxButton(this, ID_BUTTON2, _("Add file(s) ..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
  BoxSizer12->Add(btnFiles, 0, wxBOTTOM|wxEXPAND, 5);
  btnFolder = new wxButton(this, ID_BUTTON3, _("Add folder ..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
  BoxSizer12->Add(btnFolder, 0, wxEXPAND, 5);
  btnEdit = new wxButton(this, ID_BUTTON4, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
  btnEdit->Disable();
  BoxSizer12->Add(btnEdit, 0, wxTOP|wxEXPAND, 5);
  btnRemove = new wxButton(this, ID_BUTTON5, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
  btnRemove->Disable();
  BoxSizer12->Add(btnRemove, 1, wxTOP|wxEXPAND, 5);
  BoxSizer11->Add(BoxSizer12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer11->Add(-1,-1,1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer11, 0, wxTOP|wxLEFT|wxEXPAND, 5);
  BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
  BoxSizer19->Add(75,20,0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5);
  StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("bold"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
  StaticText7->Disable();
  wxFont StaticText7Font(8,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
  StaticText7->SetFont(StaticText7Font);
  BoxSizer19->Add(StaticText7, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5);
  StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("= required"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
  StaticText8->Disable();
  BoxSizer19->Add(StaticText8, 1, wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer1->Add(BoxSizer19, 0, wxLEFT|wxEXPAND, 5);
  SetSizer(BoxSizer1);
  DirDialog1 = new wxDirDialog(this, _("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
  FileDialog1 = new wxFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, _("Application files (*.exe)|*.exe"), wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  FileDialog2 = new wxFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, _("All Files|*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
  SetSizer(BoxSizer1);
  Layout();

  Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnMainExeClick);
  Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OncbDoesntHaveMainClick);
  Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&ApplicationFiles::OnlbFilesSelect);
  Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnEditClick);
  Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnFilesClick);
  Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnFolderClick);
  Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnEditClick);
  Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ApplicationFiles::OnbtnRemoveClick);
  //*)
  SetSize( wxSize(480,320));
  txtMainExe->SetValue(Manager::Get()->GetProjectManager()->GetActiveProject()->GetOutputFilename());
}

ApplicationFiles::~ApplicationFiles()
{
  //(*Destroy(ApplicationFiles)
  //*)
}


void ApplicationFiles::OncbDoesntHaveMainClick(cb_unused wxCommandEvent& event)
{
  if( cbDoesntHaveMain->IsChecked())
  {
    text1->Enable( false);
    txtMainExe->Enable( false);
    btnMainExe->Enable( false);
    cbAllowStartAfterInstall->Enable( false);
  }
  else
  {
    text1->Enable( true);
    txtMainExe->Enable( true);
    btnMainExe->Enable( true);
    cbAllowStartAfterInstall->Enable( true);
  }
}

void ApplicationFiles::OnbtnMainExeClick(cb_unused wxCommandEvent& event)
{
  if( txtMainExe->GetValue().Len() > 0)
    FileDialog1->SetPath( txtMainExe->GetValue());

  if( FileDialog1->ShowModal() == wxID_OK)
    txtMainExe->SetValue(FileDialog1->GetPath());
}

void ApplicationFiles::OnbtnFilesClick(cb_unused wxCommandEvent& event)
{
  if( lastPath.Len() == 0)
    if( txtMainExe->GetValue().Len() > 0)
      lastPath = txtMainExe->GetValue().BeforeLast('\\') + _("\\");
  FileDialog2->SetPath( lastPath);

  if( FileDialog2->ShowModal() == wxID_OK)
  {
    wxArrayString filenames;
    lastPath = FileDialog2->GetPath();
    FileDialog2->GetPaths(filenames);
    for( unsigned int i = 0; i < filenames.GetCount(); i++)
    {
      lbFiles->Append( filenames.Item( i));
      File Dummy;
      Dummy.Source             = filenames.Item( i);
      Dummy.Recurse            = false;
      Dummy.Include            = false;
      Dummy.Destination        = 0;
      Dummy.ExternDestionation = _("");
      Dummy.DestinationSub     = _("");
      Files.Add( Dummy);
    }
  }
}

void ApplicationFiles::OnlbFilesSelect(cb_unused wxCommandEvent& event)
{
  btnEdit->Enable( true);
  btnRemove->Enable( true);
}

void ApplicationFiles::OnbtnFolderClick(cb_unused wxCommandEvent& event)
{
  if( DirDialog1->ShowModal() == wxID_OK)
  {
    int antwort = wxMessageBox( _("Should files in subfolders of \"") + DirDialog1->GetPath() + _("\" also be\nincluded?"), _("Confirm"), wxYES_NO | wxCANCEL | wxICON_QUESTION);
    if( antwort == wxYES)
    {
      lbFiles->Append( DirDialog1->GetPath()+_("\\*"));
      File Dummy;
      Dummy.Source             = DirDialog1->GetPath()+_("\\*");
      Dummy.Recurse            = true;
      Dummy.Include            = true;
      Dummy.Destination        = 0;
      Dummy.ExternDestionation = _("");
      Dummy.DestinationSub     = _("");
      Files.Add( Dummy);
    }
    else
      if( antwort == wxNO)
      {
        lbFiles->Append( DirDialog1->GetPath()+_("\\*"));
        File Dummy;
        Dummy.Source             = DirDialog1->GetPath()+_("\\*");
        Dummy.Recurse            = false;
        Dummy.Include            = false;
        Dummy.Destination        = 0;
        Dummy.ExternDestionation = _("");
        Dummy.DestinationSub     = _("");
        Files.Add( Dummy);
      }
  }
}

void ApplicationFiles::OnbtnEditClick(cb_unused wxCommandEvent& event)
{

  if( lbFiles->GetSelection() != wxNOT_FOUND)
  {
    FileDialog = new WizardFile( this, Files.Item( lbFiles->GetSelection()));
    if( FileDialog->ShowModal())
    {
      Files[lbFiles->GetSelection()] = FileDialog->FileData;
    }
  }
}

void ApplicationFiles::OnbtnRemoveClick(cb_unused wxCommandEvent& event)
{
  if( lbFiles->GetSelection() == wxNOT_FOUND)
  {

    btnEdit->Enable( false);
    btnRemove->Enable( false);
  }
  Files.Detach( lbFiles->GetSelection());
  lbFiles->Delete( lbFiles->GetSelection());
}
