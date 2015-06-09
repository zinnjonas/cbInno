#ifndef APPLICATIONDOCUMENTATION_H
#define APPLICATIONDOCUMENTATION_H

//(*Headers(ApplicationDocumentation)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
//*)

#include <wx/wizard.h>

class ApplicationDocumentation: public wxWizardPageSimple
{
  public:

    ApplicationDocumentation(wxWizard* parent, wxWizardPageSimple* prev);
    virtual ~ApplicationDocumentation();

    //(*Declarations(ApplicationDocumentation)
    wxButton* btnAfter;
    wxPanel* Panel1;
    wxFileDialog* FileDialog1;
    wxTextCtrl* txtBefore;
    wxTextCtrl* txtLiecens;
    wxButton* btnLiecense;
    wxStaticLine* StaticLine1;
    wxButton* btnBefore;
    wxTextCtrl* txtAfter;
    //*)

  protected:

    //(*Identifiers(ApplicationDocumentation)
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT1;
    static const long ID_PANEL1;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON2;
    static const long ID_STATICTEXT5;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    static const long ID_STATICTEXT4;
    static const long ID_TEXTCTRL3;
    static const long ID_BUTTON3;
    //*)

  private:

    //(*Handlers(ApplicationDocumentation)
    void OnbtnLiecenseClick(wxCommandEvent& event);
    void OnbtnBeforeClick(wxCommandEvent& event);
    void OnbtnAfterClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
