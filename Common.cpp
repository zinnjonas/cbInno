#include "Common.h"

int CCommon::m_index_lang = 0;
int CCommon::m_index_min = 0;
int CCommon::m_index_only = 0;

CCommon::CCommon()
{
}

CCommon::~CCommon()
{
}

void CCommon::SetLanguages(wxString lang)
{
  m_Languages = lang;
}

void CCommon::SetMinVersion(wxString version)
{
  m_MinVersion = version;
}

void CCommon::SetOnlyBelowVersion(wxString version)
{
  m_OnlyBelow = version;
}

bool CCommon::HasLanguages()
{
  return !m_Languages.empty();
}

bool CCommon::HasMinVersion()
{
  return !m_MinVersion.empty();
}

bool CCommon::HasOnlyBelowVersion()
{
  return !m_OnlyBelow;
}

wxString CCommon::GetLanguages()
{
  return m_Languages;
}

wxString CCommon::GetMinVersion()
{
  return m_MinVersion;
}

wxString CCommon::GetOnlyBelowVersion()
{
  return m_OnlyBelow;
}

void CCommon::AddText(wxString& text)
{
  if( HasLanguages())
    text += _T("; Languages: ") + m_Languages;
  if( HasMinVersion())
    text += _T("; MinVersoin: ") + m_MinVersion;
  if( HasOnlyBelowVersion())
    text += _T("; OnlyBelowVersion: ") + m_OnlyBelow;
}

bool CCommon::Analize(const wxString& part, const wxString& settings)
{
  if( part.CmpNoCase(_T("Languages")) == 0)
  {
    SetLanguages(settings);
    return true;
  }
  if( part.CmpNoCase(_T("MinVersion")) == 0)
  {
    SetMinVersion(settings);
    return true;
  }
  if( part.CmpNoCase(_T("OnlyBelowVersion")) == 0)
  {
    SetOnlyBelowVersion(settings);
    return true;
  }
  return false;
}

void CCommon::FillContent(wxListCtrl* liste, int index)
{
  liste->SetItem(index, m_index_lang, m_Languages);
  liste->SetItem(index, m_index_min, m_MinVersion);
  liste->SetItem(index, m_index_only, m_OnlyBelow);
}

void CCommon::AddHeader(wxListCtrl* liste)
{
  m_index_lang = liste->InsertColumn(liste->GetColumnCount(), _T("Languages"));
  m_index_min  = liste->InsertColumn(liste->GetColumnCount(), _T("MinVersion"));
  m_index_only = liste->InsertColumn(liste->GetColumnCount(), _T("OnlyBelowVersion"));
}
