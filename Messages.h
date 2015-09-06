#ifndef MESSAGES_H
#define MESSAGES_H

#include "Comment.h"


class CMessages : public CComment
{
  public:
    /** Default constructor */
    CMessages();
    /** Default destructor */
    virtual ~CMessages();
    /** Set m_key
     * \param val New value to set
     */
    void SetKey(wxString val) { m_Key = val; }
    /** Set m_value
     * \param val New value to set
     */
    void SetValue(wxString val) { m_Value = val; }

    void SetLanguage(wxString lang) {m_Language = lang;}

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

  protected:
  private:
    wxString m_Key; //!< Member variable "m_Key"
    wxString m_Value; //!< Member variable "m_Value"
    wxString m_Language;//!< Member variable "m_vLanguage"

    static int m_index_key; //!< Member variable "m_index_key"
    static int m_index_value; //!< Member variable "m_index_value"
    static int m_index_lang; //!< Member variable "m_index_lang"
};

#endif // MESSAGES_H
