#include "FinishWizard.h"

//(*InternalHeaders(FinishWizard)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(FinishWizard)
const long FinishWizard::ID_STATICTEXT1 = wxNewId();
//*)

#include "Images/Wizard.xpm"

BEGIN_EVENT_TABLE(FinishWizard,wxWizardPageSimple)
  //(*EventTable(FinishWizard)
  //*)
END_EVENT_TABLE()

FinishWizard::FinishWizard(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next)
{
  //(*Initialize(FinishWizard)
  wxStaticBitmap* StaticBitmap1;
  wxStaticText* StaticText1;
  wxBoxSizer* BoxSizer2;
  wxBoxSizer* BoxSizer1;

  Create(parent, prev, next);
  SetBackgroundColour( wxColour( 255, 255, 255));
  BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
  StaticBitmap1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(Wizard_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
  BoxSizer1->Add(StaticBitmap1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
  StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("\nYou have successfully completed the Inno Setup Script\nWizard.\n\nTo close wizard and generate the new script file, click\nFinish."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
  BoxSizer2->Add(StaticText1, 0, wxTOP|wxLEFT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
  BoxSizer1->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
  SetSizer(BoxSizer1);
  BoxSizer1->Fit(this);
  BoxSizer1->SetSizeHints(this);

  Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&FinishWizard::OnEraseBackground);
  //*)
  m_First = NULL;
}

FinishWizard::~FinishWizard()
{
  //(*Destroy(FinishWizard)
  //*)
}

void FinishWizard::OnEraseBackground(wxEraseEvent& event)
{
  if( m_First == NULL)
  {
    m_Normal = m_First = GetPrev();
    if( m_First != NULL)
      while( m_First->GetPrev() != NULL)
        m_First = m_First->GetPrev();
  }

  if( m_First->GetNext() == this)
    SetPrev( m_First);
  else
    SetPrev( m_Normal);

  event.Skip();
}
