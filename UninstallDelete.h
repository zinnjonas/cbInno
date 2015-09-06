#ifndef UNINSTALLDELETE_H
#define UNINSTALLDELETE_H

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"


class CUninstallDelete : public CComment, public CCommon, public CCompTask
{
  public:
    /** Default constructor */
    CUninstallDelete();
    /** Default destructor */
    virtual ~CUninstallDelete();
    /** Set m_Type
     * \param val New value to set
     */
    void SetType(wxString val) { m_Type = val; }
    /** Set m_Name
     * \param val New value to set
     */
    void SetName(wxString val) { m_Name = val; }

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

    void WriteInFile( wxTextFile* File);

  protected:
  private:
    wxString m_Type; //!< Member variable "m_Type"
    wxString m_Name; //!< Member variable "m_Name"

    static int m_index_type; //!< Member variable "m_index_type"
    static int m_index_name; //!< Member variable "m_index_name"
};

#endif // UNINSTALLDELETE_H
