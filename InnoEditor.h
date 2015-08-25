#ifndef INNOEDITOR_H
#define INNOEDITOR_H

#include <cbeditor.h>
#include <manager.h>
#include <filemanager.h>
#include <configmanager.h>
#include <editorcolourset.h>

//(*Headers(InnoEditor)
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/button.h>
//*)
#include <wx/imaglist.h>
#include <wx/icon.h>
#include <cbstyledtextctrl.h>

class InnoEditor: public cbEditor
{
	public:

		InnoEditor( wxWindow* parent, const wxString& filename, const wxString& fn);
		virtual ~InnoEditor();

		//(*Declarations(InnoEditor)
		wxButton* Button1;
		wxImageList* ImageList;
		wxPanel* Panel1;
		wxTreeCtrl* TreeCtrl1;
		//*)

	protected:

		//(*Identifiers(InnoEditor)
		static const long ID_TREECTRL1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(InnoEditor)
		void OnTreeCtrl1ItemActivated(wxTreeEvent& event);
		//*)

		wxString m_name;

    bool m_script;
    int  m_line;

		DECLARE_EVENT_TABLE()
};

#endif
