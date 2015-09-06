#include "Comptask.h"

int CCompTask::m_index_tasks = 0;
int CCompTask::m_index_comp = 0;

CCompTask::CCompTask()
{
  //ctor
}

CCompTask::~CCompTask()
{
  //dtor
}

void CCompTask::AddText(wxString& text)
{
  if(HasComponents())
    text += _T("; Components; ") + m_Components;
  if(HasTasks())
    text += _T("; Tasks: ") + m_Tasks;
}

bool CCompTask::Analize(const wxString& part, const wxString& settings)
{
  if( part.CmpNoCase(_T("Tasks")) == 0)
  {
    SetTasks(settings);
    return true;
  }
  else if( part.CmpNoCase(_T("Components")) == 0)
  {
    SetComponents(settings);
    return true;
  }
  return false;
}

void CCompTask::FillContent(wxListCtrl* liste, int index)
{
  liste->SetItem(index, m_index_tasks, m_Tasks);
  liste->SetItem(index, m_index_comp, m_Components);
}

void CCompTask::AddHeader(wxListCtrl* liste)
{
  m_index_tasks = liste->InsertColumn(liste->GetColumnCount(), _T("Tasks"));
  m_index_comp = liste->InsertColumn(liste->GetColumnCount(), _T("Components"));
}
