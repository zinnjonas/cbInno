#ifndef CICONS_H
#define CICONS_H

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"

class CIcons : public CComment, public CCommon, public CCompTask
{
  public:
    CIcons( void);
    virtual ~CIcons();

    void Set( wxString name, wxString filename);

    void SetName( wxString name);
    void SetFilename( wxString filename);
    void SetParameters( wxString parameters);
    void SetWorkingDir( wxString workingDir);
    void SetHotKey( wxString hotKey);
    void SetCommentar( wxString comment);
    void SetIconFilename( wxString iconFilename);
    void SetIconIndex( wxString iconIndex);
    void SetAppUserModelID( wxString app);
    void SetFlags( wxString flags);

    static const wxString Flags[];

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  protected:

    wxString m_Name;
    wxString m_Filename;
    wxString m_Parameters;
    wxString m_WorkingDir;
    wxString m_HotKey;
    wxString m_Commentar;
    wxString m_IconFilename;
    wxString m_IconIndex;
    wxString m_AppUserModelId;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_filename;
    static int m_index_parameters;
    static int m_index_workingdir;
    static int m_index_hotkey;
    static int m_index_commentar;
    static int m_index_iconfilename;
    static int m_index_iconindex;
    static int m_index_appuser;
    static int m_index_flags;
};

#endif // CICONS_H
