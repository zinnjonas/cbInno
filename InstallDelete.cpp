#include "InstallDelete.h"

int CInstallDelete::m_index_type = 0;
int CInstallDelete::m_index_name = 0;

CInstallDelete::CInstallDelete()
{
  //ctor
}

CInstallDelete::~CInstallDelete()
{
  //dtor
}

void CInstallDelete::Analize(const wxString& content, const wxString& line)
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

		if( part.CmpNoCase(_T("Type")) == 0)
		{
			SetType(settings);
		}
		else if( part.CmpNoCase(_T("Name")) == 0)
		{
			SetName(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CInstallDelete::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_type, m_Type);
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CInstallDelete::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_type = liste->InsertColumn(liste->GetColumnCount(), _T("Type"));
  m_index_name = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  CCommon::AddHeader(liste);
  CCompTask::AddHeader(liste);
}

void CInstallDelete::WriteInFile(wxTextFile* File)
{
  if( !m_Type.IsEmpty() && !m_Name.IsEmpty())
  {
    wxString Text;
    Text.Printf(_T("Type: %s; Name: \"%s\""), m_Type.c_str(), m_Name.c_str());
    CCompTask::AddText(Text);
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}

