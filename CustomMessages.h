#ifndef CCUSTOMMESSAGES_H
#define CCUSTOMMESSAGES_H

#include "Comment.h"
#include "Common.h"

class CCustomMessages : public CComment, public CCommon
{
  public:
    CCustomMessages( void);
    virtual ~CCustomMessages();

    void WriteInFile( wxTextFile* File);

    wxString GetName();
    void SetName(wxString val);
    void SetContent(wxString val);
    void SetLanguage(wxString val);


    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  private:
    wxString m_Name;
    wxString m_Content;
    wxString m_Language;

    static int m_index_name;
    static int m_index_cont;
    static int m_index_lang;
};

#endif // CCUSTOMMESSAGES_H
