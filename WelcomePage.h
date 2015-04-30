#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

//(*Headers(WelcomePage)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
//*)

#include <wx/wizard.h>

class WelcomePage: public wxWizardPageSimple
{
	public:

		WelcomePage(wxWizard* parent);
		virtual ~WelcomePage();

		//(*Declarations(WelcomePage)
		wxCheckBox* chEmpty;
		//*)

		bool GetIsEmptySet( void);

	protected:

		//(*Identifiers(WelcomePage)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		//*)

	private:

		//(*Handlers(WelcomePage)
		void OnchEmptyClick(wxCommandEvent& event);
		//*)

        bool m_Empty;

        wxWizardPage* m_Last;
        wxWizardPage* m_Normal;

		DECLARE_EVENT_TABLE()
};

#endif
