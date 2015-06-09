#ifndef SETUPLANGUAGES_H
#define SETUPLANGUAGES_H

//(*Headers(SetupLanguages)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/checklst.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
//*)

#include <wx/wizard.h>

class SetupLanguages: public wxWizardPageSimple
{
  public:

    SetupLanguages(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next);
    virtual ~SetupLanguages();

    bool IsChecked( void);

    //(*Declarations(SetupLanguages)
    wxCheckListBox* lbLanguages;
    wxPanel* Panel1;
    wxButton* btnNone;
    wxStaticLine* StaticLine1;
    wxButton* btnAll;
    //*)

  protected:

    //(*Identifiers(SetupLanguages)
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT1;
    static const long ID_PANEL1;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT3;
    static const long ID_CHECKLISTBOX1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT8;
    //*)

  private:

    //(*Handlers(SetupLanguages)
    void OnbtnAllClick(wxCommandEvent& event);
    void OnbtnNoneClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
