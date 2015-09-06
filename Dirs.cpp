#include "Dirs.h"

int CDirs::m_index_name = 0;
int CDirs::m_index_attribs = 0;
int CDirs::m_index_permissions = 0;
int CDirs::m_index_flags = 0;

const wxString CDirs::Flags[] =
{
  wxT("deleteafterinstall"),
  wxT("setntfscompression"),
  wxT("uninstalwaysuninstall"),
  wxT("uninsneveruninstall"),
  wxT("unsetntfscompression")
};

CDirs::CDirs()
{

}

CDirs::~CDirs()
{

}

void CDirs::SetName(const wxString& Name)
{
  m_Name = Name;
}

void CDirs::SetAttribs(const wxString& Attribs)
{
  m_Attribs = Attribs;
}

void CDirs::SetPermissions(const wxString& Permissions)
{
  m_Permissions = Permissions;
}

void CDirs::SetFlags(const wxString& Flags)
{
  m_Flags = Flags;
}

void CDirs::WriteInFile(wxTextFile* File)
{

}
#include <manager.h>
#include <logmanager.h>

void CDirs::Analize(const wxString& content, const wxString& line)
{
  Manager::Get()->GetLogManager()->Log(content);
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

		if( part.CmpNoCase(_T("name")) == 0)
		{
			SetName(settings);
		}
		else if( part.CmpNoCase(_T("attribs")) == 0)
		{
			SetAttribs(settings);
		}
		else if( part.CmpNoCase(_T("permissions")) == 0)
		{
			SetPermissions(settings);
		}
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CDirs::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_attribs, m_Attribs);
  liste->SetItem(GetIndex(), m_index_permissions, m_Permissions);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CDirs::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name        = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_attribs     = liste->InsertColumn(liste->GetColumnCount(), _T("Attribs"));
  m_index_permissions = liste->InsertColumn(liste->GetColumnCount(), _T("Permissions"));
  m_index_flags       = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCompTask::AddHeader(liste);
  CCommon::AddHeader(liste);
}

