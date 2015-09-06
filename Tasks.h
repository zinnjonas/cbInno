#ifndef CTASKS_H
#define CTASKS_H

#include "Comment.h"
#include "Common.h"

class CTasks : public CComment, public CCommon
{
  public:
    CTasks( void);
    virtual ~CTasks();

    void SetName(wxString val);
    void SetDescription(wxString val);
    void SetGroupDescription(wxString val);
    void SetComponents( wxString val);
    void SetFlags( wxString val);

    static const wxString Flags[];

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  protected:

    wxString m_Name;
    wxString m_Description;
    wxString m_GroupDescription;
    wxString m_Components;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_desc;
    static int m_index_group;
    static int m_index_comp;
    static int m_index_flags;
};

#endif // CTASKS_H
