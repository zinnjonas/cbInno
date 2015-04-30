#ifndef APPLICATIONINFORMATION_H
#define APPLICATIONINFORMATION_H

//(*Headers(ApplicationInformation)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
//*)

#include <wx/wizard.h>

class ApplicationInformation: public wxWizardPageSimple
{
	public:

		ApplicationInformation(wxWizard* parent, wxWizardPageSimple* prev);
		virtual ~ApplicationInformation();

		bool Weiter;

		//(*Declarations(ApplicationInformation)
		wxTextCtrl* txtAppversion;
		wxTextCtrl* txtAppName;
		wxTextCtrl* txtAppWebseite;
		wxPanel* Panel1;
		wxTextCtrl* txtAppPublisher;
		wxStaticLine* StaticLine1;
		//*)

	protected:

		//(*Identifiers(ApplicationInformation)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		//*)

	private:

		//(*Handlers(ApplicationInformation)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
