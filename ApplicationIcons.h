#ifndef APPLICATIONICONS_H
#define APPLICATIONICONS_H

//(*Headers(ApplicationIcons)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
//*)

#include <wx/wizard.h>

class ApplicationIcons: public wxWizardPageSimple
{
	public:

		ApplicationIcons(wxWizard* parent, wxWizardPageSimple* prev);
		virtual ~ApplicationIcons();

		//(*Declarations(ApplicationIcons)
		wxCheckBox* cbChangeStartMenu;
		wxTextCtrl* txtMenuFolder;
		wxPanel* Panel1;
		wxCheckBox* cbInternetShort;
		wxCheckBox* cbUninstallShortCut;
		wxStaticText* text2;
		wxCheckBox* cbDesktopIcon;
		wxStaticLine* StaticLine1;
		wxCheckBox* cbDisableStartMenu;
		wxCheckBox* cbQuickLunchShortCut;
		//*)

	protected:

		//(*Identifiers(ApplicationIcons)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT4;
		static const long ID_CHECKBOX6;
		static const long ID_CHECKBOX5;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		//*)

	private:

		//(*Handlers(ApplicationIcons)
		void OncbChangeStartMenuClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
