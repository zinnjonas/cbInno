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
#include <wx/imaglist.h>
#include <wx/button.h>
//*)
#include <wx/imaglist.h>
#include <wx/icon.h>
#include <list>
#include <cbstyledtextctrl.h>

#include "Files.h"
#include "Comment.h"

enum InnoPart
{
	SETUP,
	SCRIPT,
	FILES,
	FOLDERS,
	ICONS,
	INI,
	TASKS,
	REGISTRY,
	LANGUAGES,
	LANGOPT,
	TYPES,
	COMPONENTS,
	MESSAGES,
	CMESSAGES,
	RUN,
	PASCALCODE,
	INSTALL,
	INSTALLDEL,
	UNINSTALL,
	UNINSTALLDEL,
	PRE,
	POST
};

class InnoEditor: public cbEditor
{
	public:

		InnoEditor( wxWindow* parent, const wxString& filename);
		virtual ~InnoEditor();

		void readfile(const wxString& filename);
		void analize(const wxString& content, const wxString& line);

		void analize_preprocessor( const wxString& content);
		void analize_section( const wxString& content, const wxString& line);

		//(*Declarations(InnoEditor)
		wxListCtrl* ListCtrl1;
		wxButton* Button1;
		wxImageList* ImageList;
		wxPanel* Panel1;
		wxButton* m_build;
		wxTreeCtrl* TreeCtrl1;
		//*)

	protected:

		//(*Identifiers(InnoEditor)
		static const long ID_BUILD;
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

		wxString m_name;

    int  m_line;
    InnoPart inno_part;
    std::list<CFiles> m_Files;

		DECLARE_EVENT_TABLE()
};

#endif
