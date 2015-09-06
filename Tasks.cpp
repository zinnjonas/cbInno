#include "Tasks.h"

int CTasks::m_index_name  = 0;
int CTasks::m_index_desc  = 0;
int CTasks::m_index_group = 0;
int CTasks::m_index_comp  = 0;
int CTasks::m_index_flags = 0;

const wxString CTasks::Flags[] =
{
  wxT("checkablealone"),
  wxT("checkedonce"),
  wxT("dontinheritcheck"),
  wxT("exclusive"),
  wxT("exclusive"),
  wxT("unchecked")
};

CTasks::CTasks( void)
{
  //ctor
}

CTasks::~CTasks()
{
  //dtor
}

void CTasks::SetName(wxString val)
{
  m_Name = val;
}

void CTasks::SetDescription(wxString val)
{
  m_Description = val;
}

void CTasks::SetGroupDescription(wxString val)
{
  m_GroupDescription = val;
}

void CTasks::SetComponents( wxString val)
{
  m_Components = val;
}

void CTasks::SetFlags( wxString val)
{
  m_Flags = val;
}

void CTasks::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Description.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: ") + m_Name + _T("; Description: \"") + m_Description + _T("\"");

    if( !m_GroupDescription.IsEmpty())
      Text += _T("; GroupDescription: \"") + m_GroupDescription + _T("\"");
    if( !m_Components.IsEmpty())
      Text += _T("; Components: ") + m_Components;
    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}

void CTasks::Analize(const wxString& content, const wxString& line)
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
		else if( part.CmpNoCase(_T("GroupDescription")) == 0)
		{
			SetGroupDescription(settings);
		}
		else if( part.CmpNoCase(_T("Components")) == 0)
		{
			SetComponents(settings);
		}
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( CCommon::Analize(part, settings))
      ;
	}
}

void CTasks::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_desc, m_Description);
  liste->SetItem(GetIndex(), m_index_group, m_GroupDescription);
  liste->SetItem(GetIndex(), m_index_comp, m_Components);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCommon::FillContent(liste, GetIndex());
}

void CTasks::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name  = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_desc  = liste->InsertColumn(liste->GetColumnCount(), _T("Description"));
  m_index_group = liste->InsertColumn(liste->GetColumnCount(), _T("GroupDescription"));
  m_index_comp  = liste->InsertColumn(liste->GetColumnCount(), _T("Components"));
  m_index_flags = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCommon::AddHeader(liste);
}

