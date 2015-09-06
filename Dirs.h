#ifndef DIRS_H_
#define DIRS_H_

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"

class CDirs : public CComment, public CCommon, public CCompTask
{
  public:
    CDirs();
    virtual ~CDirs();

    void SetName(const wxString& Name);
    void SetAttribs(const wxString& Attribs);
    void SetPermissions(const wxString& Permissions);
    void SetFlags(const wxString& Flags);

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

    static const wxString Flags[];

  protected:

    wxString m_Name;
    wxString m_Attribs;
    wxString m_Permissions;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_attribs;
    static int m_index_permissions;
    static int m_index_flags;
};


#endif // header guard

