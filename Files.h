#ifndef CFILES_H
#define CFILES_H

#include <wx/string.h>
#include <wx/textfile.h>

extern const char* FileFlags[];

class CFiles
{
  public:
    CFiles( void);
    virtual ~CFiles();

    void Set( wxString source, wxString destDir);

    void SetDestName( wxString destName);
    void SetExcludes( wxString excludes);
    void SetExternalSize( wxString externelSize);
    void SetAttribs( wxString Attribs);
    void SetPermission( wxString premission);
    void SetFontInstall( wxString fontInstall);
    void SetStrongAssemblyName( wxString strongAssemblyName);
    void SetFlags( wxString flag);
    void SetComponents( wxString components);
    void SetLanguages( wxString languages);

    void WriteInFile( wxTextFile* File);

    wxString GetFileName( void);

  protected:

    wxString m_Source;
    wxString m_DestDir;
    wxString m_DestName;
    wxString m_Excludes;
    wxString m_ExternalSize;
    wxString m_Attribs;
    wxString m_Permissions;
    wxString m_FontInstall;
    wxString m_StrongAssemblyName;
    wxString m_Flags;
    wxString m_Components;
    wxString m_Langauges;
};

#endif // CFILES_H
