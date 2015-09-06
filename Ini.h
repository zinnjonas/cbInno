#ifndef INI_H
#define INI_H

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"

class CIni : public CComment, public CCommon, public CCompTask
{
  public:
    /** Default constructor */
    CIni();
    /** Default destructor */
    virtual ~CIni();
    /** Set m_Filename
     * \param val New value to set
     */
    void SetFilename(wxString val) { m_Filename = val; }
    /** Set m_Section
     * \param val New value to set
     */
    void SetSection(wxString val) { m_Section = val; }
    /** Set m_Key
     * \param val New value to set
     */
    void SetKey(wxString val) { m_Key = val; }
    /** Set m_String
     * \param val New value to set
     */
    void SetString(wxString val) { m_String = val; }
    /** Set m_Flags
     * \param val New value to set
     */
    void SetFlags(wxString val) { m_Flags = val; }

    void WriteInFile( wxTextFile* File);

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

    static const wxString Flags[];

  protected:
  private:
    wxString m_Filename; //!< Member variable "m_Filename"
    wxString m_Section; //!< Member variable "m_Section"
    wxString m_Key; //!< Member variable "m_Key"
    wxString m_String; //!< Member variable "m_String"
    wxString m_Flags; //!< Member variable "m_Flags"

    static int m_index_filename;
    static int m_index_section;
    static int m_index_key;
    static int m_index_string;
    static int m_index_flags;
};

#endif // INI_H
