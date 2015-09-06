#ifndef CREGISTRY_H
#define CREGISTRY_H

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"

class CRegistry : public CComment, public CCommon,public CCompTask
{
  public:
    CRegistry( void);
    virtual ~CRegistry();


    void Set( wxString root, wxString Subkey);

    void SetRoot(wxString val);
    void SetSubkey(wxString val);
    void SetValueType(wxString val);
    void SetValueName(wxString val);
    void SetValueData(wxString val);
    void SetPermissions(wxString val);
    void SetFlags(wxString val);

    static const wxString Flags[];

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  private:
    wxString m_Root;
    wxString m_Subkey;
    wxString m_ValueType;
    wxString m_ValueName;
    wxString m_ValueData;
    wxString m_Permissions;
    wxString m_Flags;

    static int m_index_root;
    static int m_index_sub;
    static int m_index_type;
    static int m_index_name;
    static int m_index_data;
    static int m_index_perm;
    static int m_index_flag;
};

#endif // CREGISTRY_H
