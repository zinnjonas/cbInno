#ifndef INNOSETTINGS_H
#define INNOSETTINGS_H

//(*Headers(InnoSettings)
#include <wx/filepicker.h>
#include <wx/panel.h>
//*)

#include <configurationpanel.h>

class InnoSettings: public cbConfigurationPanel
{
  public:

    InnoSettings(wxWindow* parent);
    virtual ~InnoSettings();

    //(*Declarations(InnoSettings)
    wxFilePickerCtrl* FilePickerCtrl1;
    //*)

    virtual wxString GetTitle() const;
    virtual wxString GetBitmapBaseName() const;
    virtual void OnApply();
    virtual void OnCancel();

  protected:

    //(*Identifiers(InnoSettings)
    //*)

  private:

    //(*Handlers(InnoSettings)
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
