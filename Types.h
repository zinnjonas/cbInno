#ifndef CTYPES_H
#define CTYPES_H

#include "Comment.h"
#include "Common.h"

class CTypes : public CComment, public CCommon
{
  public:
    CTypes( void);
    virtual ~CTypes();

    void Set( wxString name, wxString description);

    void SetName( wxString name);
    void SetDescription( wxString description);
    void SetFlags( wxString Flags);

    wxString GetName( void);

    static const wxString Flags[];

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  protected:

    wxString m_Name;
    wxString m_Description;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_desc;
    static int m_index_flags;

};

#endif // CTYPES_H
