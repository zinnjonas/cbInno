#ifndef CFILES_H
#define CFILES_H

#include <wx/string.h>
#include <wx/textfile.h>
#include <wx/listctrl.h>

#include "Common.h"
#include "Comptask.h"
#include "Section.h"
#include "Comment.h"

class CFiles : public CCommon, public CCompTask, public CComment
{
  public:
    CFiles( void);
    virtual ~CFiles();

    void Set( wxString source, wxString destDir);

    void SetSource( wxString source);
    void SetDestDir( wxString destDir);
    void SetDestName( wxString destName);
    void SetExcludes( wxString excludes);
    void SetExternalSize( wxString externelSize);
    void SetCopyMode( wxString copyMode);
    void SetAttribs( wxString Attribs);
    void SetPermission( wxString premission);
    void SetFontInstall( wxString fontInstall);
    void SetStrongAssemblyName( wxString strongAssemblyName);
    void SetFlags( wxString flag);

    void WriteInFile( wxTextFile* File);

    wxString GetFileName( void);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

    static const wxString Flags[];

  protected:

    wxString m_Source;
    wxString m_DestDir;
    wxString m_DestName;
    wxString m_Excludes;
    wxString m_ExternalSize;
    wxString m_CopyMode;
    wxString m_Attribs;
    wxString m_Permissions;
    wxString m_FontInstall;
    wxString m_StrongAssemblyName;
    wxString m_Flags;

    static int m_index_src;
    static int m_index_dest_dir;
    static int m_index_dest_name;
    static int m_index_exc;
    static int m_index_extern;
    static int m_index_copy;
    static int m_index_attr;
    static int m_index_perm;
    static int m_index_font;
    static int m_index_strong;
    static int m_index_flags;
};

#endif // CFILES_H
