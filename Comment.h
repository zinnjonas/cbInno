#ifndef COMMENT_H
#define COMMENT_H

#include "Section.h"
#include <wx/string.h>
#include <wx/listctrl.h>

class CComment
{
  public:
    /** Default constructor */
    CComment();
    /** Default destructor */
    virtual ~CComment();
    /** Access m_Comment
     * \return The current value of m_Comment
     */
    wxString GetComment() { return m_Comment; }
    bool IsComment() { return !m_Comment.empty(); }
    /** Set m_Comment
     * \param val New value to set
     */
    void SetComment(wxString val) { m_Comment = val; }

    void AddContent(wxListCtrl* liste, int index);

  protected:
  private:
    wxString m_Comment; //!< Member variable "m_Comment"
};

#endif // COMMENT_H
