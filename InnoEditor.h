#ifndef INNOEDITOR_H
#define INNOEDITOR_H

#include <cbeditor.h>
#include <manager.h>
#include <filemanager.h>
#include <configmanager.h>
#include <editorcolourset.h>

//(*Headers(InnoEditor)
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/imaglist.h>
#include <wx/button.h>
//*)
#include <wx/imaglist.h>
#include <wx/icon.h>
#include <list>
#include <cbstyledtextctrl.h>
#include <wx/process.h>

#include "InnoScript.h"
#include "Consume.h"

class InnoEditor: public cbEditor
{
	public:

		InnoEditor( wxWindow* parent, const wxString& filename, int log);
		virtual ~InnoEditor();

		void UpdateView();

		//(*Declarations(InnoEditor)
		wxListCtrl* ListCtrl1;
		wxButton* Button1;
		wxImageList* ImageList;
		wxPanel* Panel1;
		wxBitmapButton* m_build;
		wxTreeCtrl* TreeCtrl1;
		//*)

		bool Save();

		void OnProcessEnd(cb_unused wxProcessEvent& evt);

	protected:

		//(*Identifiers(InnoEditor)
		static const long ID_BUILDBUTTON;
		static const long ID_TREECTRL1;
		static const long ID_BUTTON1;
		static const long ID_LISTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(InnoEditor)
		void OnTreeCtrl1ItemActivated(wxTreeEvent& event);
		void OnbuildClick(wxCommandEvent& event);
		//*)

		int m_log_pos;

		wxString m_name;

    wxString m_file;
    InnoPart inno_part;
    InnoScript m_script;
    bool m_running;
    wxInputStream* m_out;
    wxInputStream* m_err;
    Consume* m_consume;

    wxString m_content;

		DECLARE_EVENT_TABLE()
};

#endif
