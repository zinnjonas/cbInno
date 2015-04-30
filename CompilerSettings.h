#ifndef COMPILERSETTINGS_H
#define COMPILERSETTINGS_H

//(*Headers(CompilerSettings)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
//*)

#include <wx/wizard.h>

class CompilerSettings: public wxWizardPageSimple
{
	public:

		CompilerSettings(wxWizard* parent, wxWizardPageSimple* prev, wxWizardPageSimple* next);
		virtual ~CompilerSettings();

		//(*Declarations(CompilerSettings)
		wxButton* btnBrowsePutputfolder;
		wxTextCtrl* txtOutputFolder;
		wxTextCtrl* txtCompilerFileName;
		wxPanel* Panel1;
		wxFileDialog* FileDialog1;
		wxDirDialog* DirDialog1;
		wxStaticLine* StaticLine1;
		wxTextCtrl* txtPassword;
		wxButton* btnBrowsIcon;
		wxTextCtrl* txtCustomIcon;
		//*)

	protected:

		//(*Identifiers(CompilerSettings)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL2;
		//*)

	private:

		//(*Handlers(CompilerSettings)
		void OnbtnBrowsePutputfolderClick(wxCommandEvent& event);
		void OnbtnBrowsIconClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
