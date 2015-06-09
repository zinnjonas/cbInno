#ifndef CICONS_H
#define CICONS_H

#include <wx/textfile.h>

extern const char* IconsFlag[];

class CIcons
{
  public:
    CIcons( void);
    virtual ~CIcons();

    void WriteInFile( wxTextFile* File);

    void Set( wxString name, wxString filename);

    void SetParameters( wxString parameters);
    void SetWorkingDir( wxString workingDir);
    void SetHotKey( wxString hotKey);
    void setComment( wxString comment);
    void SetIconFilename( wxString iconFilename);
    void SetAppUserModelID( wxString app);
    void SetFlags( wxString flags);

    void SetTasks( wxString Task);

  protected:

    wxString m_Name;
    wxString m_Filename;
    wxString m_Parameters;
    wxString m_WorkingDir;
    wxString m_HotKey;
    wxString m_Comment;
    wxString m_IconFilename;
    wxString m_IconIndex;
    wxString m_AppUserModelId;
    wxString m_Flags;
    wxString m_Tasks;
};

#endif // CICONS_H
