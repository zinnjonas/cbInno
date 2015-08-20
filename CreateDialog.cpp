#include "CreateDialog.h"

//(*InternalHeaders(CCreateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CCreateDialog)
const long CCreateDialog::ID_STATICTEXT1 = wxNewId();
const long CCreateDialog::ID_TEXTCTRL1 = wxNewId();
const long CCreateDialog::ID_BUTTON1 = wxNewId();
//*)

#include <prep.h>

BEGIN_EVENT_TABLE(CCreateDialog,wxDialog)
  //(*EventTable(CCreateDialog)
  //*)
END_EVENT_TABLE()

CCreateDialog::CCreateDialog(wxWindow* parent,wxWindowID id,cb_unused const wxPoint& pos,cb_unused const wxSize& size)
{
  //(*Initialize(CCreateDialog)
  wxBoxSizer* BoxSizer1;

  Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
  SetClientSize(wxDefaultSize);
  Move(wxDefaultPosition);
  BoxSizer1 = new wxBoxSizer(wxVERTICAL);
  StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Create Dialog"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(325,159), wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
  BoxSizer1->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  btnOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
  BoxSizer1->Add(btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  BoxSizer1->Fit(this);
  BoxSizer1->SetSizeHints(this);
  //*)

  Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CCreateDialog::OnbtnOKClick));
}

CCreateDialog::~CCreateDialog()
{
  //(*Destroy(CCreateDialog)
  //*)
}

void CCreateDialog::SetName( wxString Name)
{

  wxExecute(Name,m_output);
  for( unsigned int i = 0; i < m_output.GetCount(); i++)
    TextCtrl1->AppendText(_T("\n") + m_output[i]);
  TextCtrl1->ShowPosition(TextCtrl1->GetLastPosition());
}

void CCreateDialog::OnbtnOKClick(cb_unused wxCommandEvent& event)
{
  EndModal( 1);
}
