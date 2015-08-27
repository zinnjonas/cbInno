#include "Section.h"

CSection::CSection()
{
  //ctor
}

CSection::~CSection()
{
  //dtor
}

int CSection::GetIndex()
{
  return m_index;
}

void CSection::AddContent(wxListCtrl* liste)
{
  m_index = liste->InsertItem(liste->GetItemCount(), m_Linenumber);
}

void CSection::AddHeader(wxListCtrl* liste)
{
  liste->InsertColumn(liste->GetColumnCount(), _T("Line"));
}
