#include "Components.h"

int CComponents::m_index_name = 0;
int CComponents::m_index_desc = 0;
int CComponents::m_index_type = 0;
int CComponents::m_index_requ = 0;
int CComponents::m_index_flag = 0;

const wxString CComponents::Flags[] =
{
  wxT("checkablealone"),
  wxT("dontinheritcheck"),
  wxT("exclusive"),
  wxT("fixed"),
  wxT("restart"),
  wxT("disablenouninstallwarning")
};

CComponents::CComponents( void)
{
  //ctor
}

CComponents::~CComponents()
{
  //dtor
}

void CComponents::Set( wxString Name, wxString Description)
{
  m_Name         = Name;
  m_Description  = Description;
}

void CComponents::SetName(wxString name)
{
  m_Name = name;
}

void CComponents::SetDescription(wxString description)
{
  m_Description = description;
}

void CComponents::SetTypes( wxString types)
{
  m_Types = types;
}

void CComponents::SetExtraDiskSpace( wxString extraDiskSpace)
{
  m_ExtraDiskSpaceRequired = extraDiskSpace;
}

void CComponents::SetFlags( wxString flag)
{
  m_Flags = flag;
}

wxString CComponents::GetName( void)
{
  return m_Name;
}

void CComponents::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Description.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: \"") + m_Name + _T("\"; Description: \"") + m_Description + _T("\"");

    if( !m_Types.IsEmpty())
      Text += _T("; Types: ") + m_Types;
    if( !m_ExtraDiskSpaceRequired.IsEmpty())
      Text += _T("; ExtraDiskSpaceRequired: ") + m_ExtraDiskSpaceRequired;
    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}

void CComponents::Analize(const wxString& content, const wxString& line)
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
		else if( part.CmpNoCase(_T("Description")) == 0)
		{
			SetDescription(settings);
		}
		else if( part.CmpNoCase(_T("Types")) == 0)
		{
			SetTypes(settings);
		}
		else if( part.CmpNoCase(_T("ExtraDiskSpaceRequired")) == 0)
		{
			SetExtraDiskSpace(settings);
		}
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( CCommon::Analize(part, settings))
      ;
	}
}

void CComponents::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_desc, m_Description);
  liste->SetItem(GetIndex(), m_index_type, m_Types);
  liste->SetItem(GetIndex(), m_index_requ, m_ExtraDiskSpaceRequired);
  liste->SetItem(GetIndex(), m_index_flag, m_Flags);
  CCommon::FillContent(liste, GetIndex());
}

void CComponents::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name  = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_desc  = liste->InsertColumn(liste->GetColumnCount(), _T("Description"));
  m_index_type  = liste->InsertColumn(liste->GetColumnCount(), _T("Types"));
  m_index_requ  = liste->InsertColumn(liste->GetColumnCount(), _T("ExtraDiskSpaceRequired"));
  m_index_flag = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCommon::AddHeader(liste);
}

