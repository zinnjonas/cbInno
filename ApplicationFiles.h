#ifndef APPLICATIONFILES_H
#define APPLICATIONFILES_H

//(*Headers(ApplicationFiles)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
//*)

#include <wx/wizard.h>
#include <wx/msgdlg.h>
#include <wx/dynarray.h>

#include "WizardFile.h"

WX_DECLARE_OBJARRAY(File, ArrayFile);

class ApplicationFiles: public wxWizardPageSimple
{
	public:

		ApplicationFiles(wxWizard* parent, wxWizardPageSimple* prev);
		virtual ~ApplicationFiles();

		//(*Declarations(ApplicationFiles)
		wxButton* btnFolder;
		wxButton* btnFiles;
		wxStaticText* text1;
		wxPanel* Panel1;
		wxFileDialog* FileDialog1;
		wxCheckBox* cbAllowStartAfterInstall;
		wxDirDialog* DirDialog1;
		wxTextCtrl* txtMainExe;
		wxStaticLine* StaticLine1;
		wxButton* btnRemove;
		wxFileDialog* FileDialog2;
		wxCheckBox* cbDoesntHaveMain;
		wxButton* btnEdit;
		wxListBox* lbFiles;
		wxButton* btnMainExe;
		//*)

        wxString lastPath;

        ArrayFile Files;

	protected:

		//(*Identifiers(ApplicationFiles)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT4;
		static const long ID_LISTBOX1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		//*)

		WizardFile* FileDialog;

	private:

		//(*Handlers(ApplicationFiles)
		void OncbDoesntHaveMainClick(wxCommandEvent& event);
		void OnbtnMainExeClick(wxCommandEvent& event);
		void OnbtnFilesClick(wxCommandEvent& event);
		void OnlbFilesSelect(wxCommandEvent& event);
		void OnbtnFolderClick(wxCommandEvent& event);
		void OnbtnEditClick(wxCommandEvent& event);
		void OnbtnRemoveClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
