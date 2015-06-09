#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

//(*Headers(CreateDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class CCreateDialog: public wxDialog
{
  public:

    CCreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~CCreateDialog();

    void SetName( wxString Name);

    //(*Declarations(CreateDialog)
    wxStaticText* StaticText1;
    wxButton* btnOK;
    wxTextCtrl* TextCtrl1;
    //*)

  protected:

    //(*Identifiers(CreateDialog)
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    //*)

  private:

    //(*Handlers(CreateDialog)
    void OnbtnOKClick(wxCommandEvent& event);
    //*)
    wxArrayString m_output;

    DECLARE_EVENT_TABLE()
};

#endif
