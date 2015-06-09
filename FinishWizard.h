#ifndef FINISHWIZARD_H
#define FINISHWIZARD_H

//(*Headers(FinishWizard)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
//*)

#include <wx/wizard.h>

class FinishWizard: public wxWizardPageSimple
{
  public:

    FinishWizard(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next);
    virtual ~FinishWizard();

    //(*Declarations(FinishWizard)
    //*)

  protected:

    //(*Identifiers(FinishWizard)
    static const long ID_STATICTEXT1;
    //*)

  private:

    //(*Handlers(FinishWizard)
    void OnEraseBackground(wxEraseEvent& event);
    //*)

    wxWizardPage* m_First;
    wxWizardPage* m_Normal;

    DECLARE_EVENT_TABLE()
};

#endif
