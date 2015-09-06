#ifndef INNOSCRIPT_H
#define INNOSCRIPT_H

#include "Files.h"
#include "Dirs.h"
#include "Comment.h"
#include "Icons.h"
#include "Ini.h"
#include "Tasks.h"
#include "Registry.h"
#include "Languages.h"
#include "Types.h"
#include "Components.h"
#include "Messages.h"
#include "CustomMessages.h"
#include "Run.h"
#include "InstallDelete.h"
#include "UninstallDelete.h"
#include <list>
#include <string>
#include <wx/string.h>
#include <wx/listctrl.h>
#include <wx/textfile.h>

using namespace std;

enum InnoPart
{
	SCRIPT,
	SETUP,
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
	INSTALLDEL,
	UNINSTALL,
	UNINSTALLDEL,
	PRE,
	POST
};

class InnoScript
{
  public:
    /** Default constructor */
    InnoScript();
    /** Default destructor */
    virtual ~InnoScript();

    void Read(const wxString& filename);

    void Analize(const wxString& content, const wxString& line);
    void AnalizePreprocessor(const wxString& content);
    void AnalizeSection(const wxString& content, const wxString& line);

    void Write(wxString filename);

    void Show(wxListCtrl* liste, const InnoPart& part);

  protected:
  private:

    InnoPart m_part;
    list<CFiles>           m_files;
    list<CDirs>            m_dirs;
    list<CIcons>           m_icons;
    list<CIni>             m_ini;
    list<CTasks>           m_tasks;
    list<CRegistry>        m_registry;
    list<CLanguages>       m_languages;
    list<CTypes>           m_types;
    list<CComponents>      m_components;
    list<CMessages>        m_messages;
    list<CCustomMessages>  m_cmessages;
    list<CRun>             m_runs;
    list<CInstallDelete>   m_instal_del;
    list<CUninstallDelete> m_uninstal_del;
    list<CRun>             m_uninstal_run;
};

#endif // INNOSCRIPT_H
