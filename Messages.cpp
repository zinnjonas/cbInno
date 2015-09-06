#include "Messages.h"

int CMessages::m_index_key   = 0;
int CMessages::m_index_value = 0;
int CMessages::m_index_lang  = 0;

CMessages::CMessages()
{
  //ctor
}

CMessages::~CMessages()
{
  //dtor
}

void CMessages::WriteInFile(wxTextFile* File)
{
  wxString Text = wxT("");
  if(!m_Language.empty())
    Text += m_Language + wxT(".");
  Text += m_Key + _T(" = ") + m_Value;

  File->AddLine( Text);
}

void CMessages::Analize(const wxString& content, const wxString& line)
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

		SetKey(part);
		SetValue(settings);
		SetLanguage(lang);
	}
}

void CMessages::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_lang, m_Language);
  liste->SetItem(GetIndex(), m_index_key, m_Key);
  liste->SetItem(GetIndex(), m_index_value, m_Value);
}

void CMessages::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_lang  = liste->InsertColumn(liste->GetColumnCount(), _T("Lang"));
  m_index_key   = liste->InsertColumn(liste->GetColumnCount(), _T("Key"));
  m_index_value = liste->InsertColumn(liste->GetColumnCount(), _T("Value"));
}

