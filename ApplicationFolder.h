#ifndef APPLICATIONFOLDER_H
#define APPLICATIONFOLDER_H

//(*Headers(ApplicationFolder)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
//*)

#include <wx/wizard.h>

class ApplicationFolder: public wxWizardPageSimple
{
	public:

		ApplicationFolder(wxWizard* parent, wxWizardPageSimple* prev = NULL, wxWizardPageSimple* next = NULL);
		virtual ~ApplicationFolder();

		//(*Declarations(ApplicationFolder)
		wxChoice* chProgrammFolder;
		wxTextCtrl* txtAppFolderName;
		wxTextCtrl* txtCustom;
		wxStaticText* text1;
		wxPanel* Panel1;
		wxCheckBox* cbAppFolderName;
		wxCheckBox* cbDoesntFolder;
		wxStaticText* text2;
		wxStaticLine* StaticLine1;
		//*)

	protected:

		//(*Identifiers(ApplicationFolder)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_PANEL1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		//*)

	private:

		//(*Handlers(ApplicationFolder)
		void OnchProgrammFolderSelect(wxCommandEvent& event);
		void OncbDoesntFolderClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
