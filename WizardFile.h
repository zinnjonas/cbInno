#ifndef WIZARDFILE_H
#define WIZARDFILE_H

//(*Headers(WizardFile)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
//*)

#include <wx/msgdlg.h>

struct File
{
    wxString    Source;
    bool        Recurse;
    bool        Include;
    int         Destination;
    wxString    ExternDestionation;
    wxString    DestinationSub;
};

class WizardFile: public wxDialog
{
	public:

		WizardFile(wxWindow* parent, File Data,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~WizardFile();

		//(*Declarations(WizardFile)
		wxTextCtrl* txtDestSub;
		wxButton* btnCancel;
		wxTextCtrl* txtFile;
		wxStaticText* StaticText3;
		wxButton* btnOK;
		wxChoice* chDestination;
		wxStaticText* StaticText5;
		wxCheckBox* cbRecurse;
		wxCheckBox* cbInclude;
		wxTextCtrl* txtDestination;
		//*)

		File FileData;

	protected:

		//(*Identifiers(WizardFile)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		//*)

	private:

		//(*Handlers(WizardFile)
		void OnchDestinationSelect(wxCommandEvent& event);
		void OncbRecurseClick(wxCommandEvent& event);
		void OnbtnOKClick(wxCommandEvent& event);
		void OnbtnCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
