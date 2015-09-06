#ifndef CCOMPONENTS_H
#define CCOMPONENTS_H

#include "Comment.h"
#include "Common.h"

class CComponents : public CComment, public CCommon
{
  public:
    CComponents( void);
    virtual ~CComponents();


    void Set( wxString Name, wxString Description);

    void SetName(wxString name);
    void SetDescription( wxString description);
    void SetTypes( wxString types);
    void SetExtraDiskSpace( wxString extraDiskSpace);
    void SetFlags( wxString flag);

    wxString GetName( void);

    static const wxString Flags[];

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);


  protected:

    wxString m_Name;
    wxString m_Description;
    wxString m_Types;
    wxString m_ExtraDiskSpaceRequired;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_desc;
    static int m_index_type;
    static int m_index_requ;
    static int m_index_flag;
};

#endif // CCOMPONENTS_H
