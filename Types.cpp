#include "Types.h"

int CTypes::m_index_name = 0;
int CTypes::m_index_desc = 0;
int CTypes::m_index_flags = 0;

const wxString CTypes::Flags[] =
{
  wxT("iscustom")
};

CTypes::CTypes( void)
{
  //ctor
}

CTypes::~CTypes()
{
  //dtor
}


void CTypes::Set( wxString name, wxString description)
{
  m_Name       = name;
  m_Description = description;
}

void CTypes::SetFlags( wxString Flags)
{
  m_Flags = Flags;
}

wxString CTypes::GetName( void)
{
  return m_Name;
}

void CTypes::SetName(wxString name)
{
  m_Name = name;
}

void CTypes::SetDescription(wxString description)
{
  m_Description = description;
}

void CTypes::Analize(const wxString& content, const wxString& line)
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
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( CCommon::Analize(part, settings))
      ;
	}
}

void CTypes::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_desc, m_Description);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCommon::FillContent(liste, GetIndex());
}

void CTypes::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name  = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_desc  = liste->InsertColumn(liste->GetColumnCount(), _T("Description"));
  m_index_flags = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCommon::AddHeader(liste);
}


void CTypes::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Description.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: \"") + m_Name + _T("\"; Description: \"") + m_Description + _T("\"");

    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}
