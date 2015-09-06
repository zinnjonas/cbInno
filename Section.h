#ifndef SECTION_H
#define SECTION_H

#include <wx/string.h>
#include <wx/listctrl.h>

class CSection
{
  public:
    /** Default constructor */
    CSection();
    /** Default destructor */
    virtual ~CSection();
    /** Access m_linenumber
     * \return The current value of m_linenumber
     */
    wxString GetLinenumber() { return m_Linenumber; }
    /** Set m_linenumber
     * \param val New value to set
     */
    void SetLinenumber(wxString val) { m_Linenumber = val; }

    int GetIndex();

    void InsertContent(wxListCtrl* liste);

    static void InsertHeader(wxListCtrl* liste);

  protected:
  private:
    wxString   m_Linenumber; //!< Member variable "m_linenumber"
    int        m_index;
};

#endif // SECTION_H
