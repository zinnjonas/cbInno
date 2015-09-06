#include "CustomMessages.h"

int CCustomMessages::m_index_name = 0;
int CCustomMessages::m_index_cont = 0;
int CCustomMessages::m_index_lang = 0;

CCustomMessages::CCustomMessages( void)
{
  //ctor
}

CCustomMessages::~CCustomMessages()
{
  //dtor
}

void CCustomMessages::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Content.IsEmpty())
  {
    wxString Text;

    if( !m_Language.IsEmpty())
      Text = m_Language +_T(".") + m_Name +_T("=") + m_Content;
    else
      Text = m_Name +_T("=") + m_Content;

    File->AddLine( Text);
  }
}

wxString CCustomMessages::GetName()
{
  return m_Name;
}

void CCustomMessages::SetName(wxString val)
{
  m_Name = val;
}

void CCustomMessages::SetContent(wxString val)
{
  m_Content = val;
}

void CCustomMessages::SetLanguage(wxString val)
{
  m_Language = val;
}

void CCustomMessages::Analize(const wxString& content, const wxString& line)
{
  wxString cont = content;
	wxString part;
	wxString lang;
	wxString settings;
  SetLinenumber(line);
	while( !cont.empty())
	{
	  lang = cont.BeforeFirst('.');
		part = cont.BeforeFirst('=');
		settings = cont.AfterFirst('=');
		cont = cont.AfterFirst(';');
		part = part.Trim(false);
		settings = settings.Trim(false);
		cont = cont.Trim(false);

		SetName(part);
		SetContent(settings);
		SetLanguage(lang);
	}
}

void CCustomMessages::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_lang, m_Language);
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_cont, m_Content);
}

void CCustomMessages::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_lang   = liste->InsertColumn(liste->GetColumnCount(), _T("Lang"));
  m_index_name   = liste->InsertColumn(liste->GetColumnCount(), _T("Key"));
  m_index_cont = liste->InsertColumn(liste->GetColumnCount(), _T("Value"));
}

