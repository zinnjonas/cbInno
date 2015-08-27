#ifndef COMPTASK_H
#define COMPTASK_H

#include <wx/string.h>
#include <wx/listctrl.h>

class CCompTask
{
  public:
    /** Default constructor */
    CCompTask();
    /** Default destructor */
    virtual ~CCompTask();
    /** Access m_Tasks
     * \return The current value of m_Tasks
     */
    wxString GetTasks() { return m_Tasks; }
    /** Checks existens of m_Tasks
     * \return true if some tasks are added
     */
    bool HasTasks() {return !m_Tasks.empty(); }
    /** Set m_Tasks
     * \param val New value to set
     */
    void SetTasks(wxString val) { m_Tasks = val; }
    /** Access m_Components
     * \return The current value of m_Components
     */
    wxString GetComponents() { return m_Components; }
    /** Checks existens of m_Components
     * \return true if some components are added
     */
    bool HasComponents() {return !m_Components.empty(); }
    /** Set m_Components
     * \param val New value to set
     */
    void SetComponents(wxString val) { m_Components = val; }

    void AddText(wxString& text);

    bool Analize( const wxString& part, const wxString& settings);

    void AddContent(wxListCtrl* liste, int index);

    static void AddHeader(wxListCtrl* liste);

  protected:
  private:
    wxString m_Tasks; //!< Member variable "m_Tasks"
    wxString m_Components; //!< Member variable "m_Components"

    static int m_index_tasks;
    static int m_index_comp;
};

#endif // COMPTASK_H
