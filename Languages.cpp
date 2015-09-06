#include "Languages.h"

int CLanguages::m_index_name    = 0;
int CLanguages::m_index_msg     = 0;
int CLanguages::m_index_license = 0;
int CLanguages::m_index_before  = 0;
int CLanguages::m_index_after   = 0;

CLanguages::CLanguages()
{
  //ctor
}

CLanguages::~CLanguages()
{
  //dtor
}

void CLanguages::Set(wxString name, wxString messagesFile)
{
  m_Name = name;
  m_MessagesFile = messagesFile;
}

void CLanguages::WriteInFile(wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_MessagesFile.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: \"") + m_Name +_T("\"") + _T("MessagesFile: \"") + m_MessagesFile +_T("\"");
    if( !m_LicenseFile.IsEmpty())
      Text +=_T("; LicenseFile: \"") + m_LicenseFile +_T("\"");
    if( !m_InfoBeforeFile.IsEmpty())
      Text +=_T("; InfoBeforeFile: \"") + m_InfoBeforeFile +_T("\"");
    if( !m_InfoAfterFile.IsEmpty())
      Text +=_T("; InfoAfterFile: \"") + m_InfoAfterFile +_T("\"");

    File->AddLine( Text);
  }
}

void CLanguages::Analize(const wxString& content, const wxString& line)
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

		if( part.CmpNoCase(_T("Name")) == 0)
		{
			SetName(settings);
		}
		else if( part.CmpNoCase(_T("MessagesFile")) == 0)
		{
			SetMessagesFile(settings);
		}
		else if( part.CmpNoCase(_T("LicenseFile")) == 0)
		{
			SetLicenseFile(settings);
		}
		else if( part.CmpNoCase(_T("InfoBeforeFile")) == 0)
		{
			SetInfoBeforeFile(settings);
		}
		else if( part.CmpNoCase(_T("InfoAfterFile")) == 0)
		{
			SetInfoAfterFile(settings);
		}
	}
}

void CLanguages::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name    = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_msg     = liste->InsertColumn(liste->GetColumnCount(), _T("MessagesFile"));
  m_index_license = liste->InsertColumn(liste->GetColumnCount(), _T("License"));
  m_index_before  = liste->InsertColumn(liste->GetColumnCount(), _T("InfoBeforeFile"));
  m_index_after   = liste->InsertColumn(liste->GetColumnCount(), _T("InfoAfterFile"));
}

void CLanguages::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_msg, m_MessagesFile);
  liste->SetItem(GetIndex(), m_index_license, m_LicenseFile);
  liste->SetItem(GetIndex(), m_index_before, m_InfoBeforeFile);
  liste->SetItem(GetIndex(), m_index_after, m_InfoAfterFile);
}

