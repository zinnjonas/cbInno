#ifndef LANGUAGES_H
#define LANGUAGES_H

#include "Comment.h"


class CLanguages : public CComment
{
  public:
    /** Default constructor */
    CLanguages();
    /** Default destructor */
    virtual ~CLanguages();

    void Set(wxString name, wxString messagesFile);

    /** Set m_Name
     * \param val New value to set
     */
    void SetName(wxString val) { m_Name = val; }
    /** Set m_MessagesFile
     * \param val New value to set
     */
    void SetMessagesFile(wxString val) { m_MessagesFile = val; }
    /** Set m_LicenseFile
     * \param val New value to set
     */
    void SetLicenseFile(wxString val) { m_LicenseFile = val; }
    /** Set m_InfoBeforeFile
     * \param val New value to set
     */
    void SetInfoBeforeFile(wxString val) { m_InfoBeforeFile = val; }
    /** Set m_InfoAfterFile
     * \param val New value to set
     */
    void SetInfoAfterFile(wxString val) { m_InfoAfterFile = val; }

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    static void AddHeader(wxListCtrl* liste);

    void FillContent(wxListCtrl* liste);

  protected:
  private:
    wxString m_Name; //!< Member variable "m_Name"
    wxString m_MessagesFile; //!< Member variable "m_MessagesFile"
    wxString m_LicenseFile; //!< Member variable "m_LicenseFile"
    wxString m_InfoBeforeFile; //!< Member variable "m_InfoBeforeFile"
    wxString m_InfoAfterFile; //!< Member variable "m_InfoAfterFile"

    static int m_index_name; //!< Member variable "m_index_name"
    static int m_index_msg; //!< Member variable "m_index_msg"
    static int m_index_license; //!< Member variable "m_index_licence"
    static int m_index_before; //!< Member variable "m_index_before"
    static int m_index_after; //!< Member variable "m_index_after"
};

#endif // LANGUAGES_H
