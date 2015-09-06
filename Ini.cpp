#include "Ini.h"

int CIni::m_index_filename = 0;
int CIni::m_index_section  = 0;
int CIni::m_index_key      = 0;
int CIni::m_index_string   = 0;
int CIni::m_index_flags    = 0;

const wxString CIni::Flags[] =
{
  wxT("createkeyifdoesntexist"),
  wxT("uninsdeleteentry"),
  wxT("uninsdeletesection"),
  wxT("uninsdeletesection")
};

CIni::CIni()
{
  //ctor
}

CIni::~CIni()
{
  //dtor
}

void CIni::WriteInFile(wxTextFile* File)
{
  if( !m_Filename.IsEmpty())
  {
    wxString Text;

    Text =_T("Filename: \"") + m_Filename +_T("\"");
    if( !m_Section.IsEmpty())
      Text +=_T("; Section; \"") + m_Section +_T("\"");
    if( !m_Key.IsEmpty())
      Text +=_T("; Key: \"") + m_Key +_T("\"");
    if( !m_String.IsEmpty())
      Text +=_T("; String: \"") + m_String +_T("\"");
    if( !m_Flags.IsEmpty())
      Text +=_T("; Flags: ") + m_Flags;

    CCompTask::AddText(Text);
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}

void CIni::Analize(const wxString& content, const wxString& line)
{
  wxString cont = content;
	wxString part;
	wxString settings;
  SetLinenumber(line);
	while( !cont.empty())
	{
		part = cont.BeforeFirst(':');
		settings = cont.AfterFirst(':').BeforeFirst(';');
		cont = cont.AfterFirst(';');
		part = part.Trim(false);
		settings = settings.Trim(false);
		cont = cont.Trim(false);

		if( part.CmpNoCase(_T("Filename")) == 0)
		{
			SetFilename(settings);
		}
		else if( part.CmpNoCase(_T("Section")) == 0)
		{
			SetSection(settings);
		}
		else if( part.CmpNoCase(_T("Key")) == 0)
		{
			SetKey(settings);
		}
		else if( part.CmpNoCase(_T("String")) == 0)
		{
			SetString(settings);
		}
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CIni::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_filename, m_Filename);
  liste->SetItem(GetIndex(), m_index_section, m_Section);
  liste->SetItem(GetIndex(), m_index_key, m_Key);
  liste->SetItem(GetIndex(), m_index_string, m_String);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CIni::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_filename = liste->InsertColumn(liste->GetColumnCount(), _T("Filename"));
  m_index_section  = liste->InsertColumn(liste->GetColumnCount(), _T("Parameters"));
  m_index_key      = liste->InsertColumn(liste->GetColumnCount(), _T("WorkingDir"));
  m_index_string   = liste->InsertColumn(liste->GetColumnCount(), _T("HotKey"));
  m_index_flags    = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCompTask::AddHeader(liste);
  CCommon::AddHeader(liste);
}

