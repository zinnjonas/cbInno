#include "Registry.h"

int CRegistry::m_index_root = 0;
int CRegistry::m_index_sub = 0;
int CRegistry::m_index_type = 0;
int CRegistry::m_index_name = 0;
int CRegistry::m_index_data = 0;
int CRegistry::m_index_perm = 0;
int CRegistry::m_index_flag = 0;

const wxString CRegistry::Flags[] =
{
  wxT("createvalueifdoesntexist"),
  wxT("deletekey"),
  wxT("deletevalue"),
  wxT("dontcreatekey"),
  wxT("noerror"),
  wxT("preservestringtype"),
  wxT("uninsclearvalue"),
  wxT("uninsdeletekey"),
  wxT("uninsdeletekeyifempty"),
  wxT("uninsdeletevalue")
};

CRegistry::CRegistry( void)
{
  //ctor
}

CRegistry::~CRegistry()
{
  //dtor
}

void CRegistry::Set( wxString root, wxString subKey)
{
  SetRoot( root);
  SetSubkey( subKey);
}

void CRegistry::SetRoot(wxString val)
{
  m_Root = val;
}

void CRegistry::SetSubkey(wxString val)
{
  m_Subkey = val;
}

void CRegistry::SetValueType(wxString val)
{
  m_ValueType = val;
}

void CRegistry::SetValueName(wxString val)
{
  m_ValueName = val;
}

void CRegistry::SetValueData(wxString val)
{
  m_ValueData = val;
}

void CRegistry::SetPermissions(wxString val)
{
  m_Permissions = val;
}

void CRegistry::SetFlags(wxString val)
{
  m_Flags = val;
}

void CRegistry::WriteInFile( wxTextFile* File)
{
  if( !m_Root.IsEmpty() && !m_Subkey.IsEmpty())
  {
    wxString Text;

    Text = _T("Root: ") + m_Root + _T("; Subkey: \"") + m_Subkey + _T("\"");
    if( !m_ValueType.IsEmpty())
      Text += _T("; ValueType: ") + m_ValueType;
    if( !m_ValueData)
      Text += _T("; ValueData: \"") + m_ValueData + _T("\"");
    if( !m_Permissions.IsEmpty())
      Text += _T("; Permissions: ") + m_Permissions;
    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;

    CCompTask::AddText(Text);
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}
void CRegistry::Analize(const wxString& content, const wxString& line)
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

		if( part.CmpNoCase(_T("Root")) == 0)
		{
			SetRoot(settings);
		}
		else if( part.CmpNoCase(_T("Subkey")) == 0)
		{
			SetSubkey(settings);
		}
		else if( part.CmpNoCase(_T("ValueType")) == 0)
		{
			SetValueType(settings);
		}
		else if( part.CmpNoCase(_T("ValueName")) == 0)
		{
			SetValueName(settings);
		}
		else if( part.CmpNoCase(_T("ValueData")) == 0)
		{
			SetValueData(settings);
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

void CRegistry::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_root, m_Root);
  liste->SetItem(GetIndex(), m_index_sub, m_Subkey);
  liste->SetItem(GetIndex(), m_index_type, m_ValueType);
  liste->SetItem(GetIndex(), m_index_name, m_ValueName);
  liste->SetItem(GetIndex(), m_index_data, m_ValueData);
  liste->SetItem(GetIndex(), m_index_perm, m_Permissions);
  liste->SetItem(GetIndex(), m_index_flag, m_Flags);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CRegistry::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_root = liste->InsertColumn(liste->GetColumnCount(), _T("Root"));
  m_index_sub  = liste->InsertColumn(liste->GetColumnCount(), _T("Subkey"));
  m_index_type = liste->InsertColumn(liste->GetColumnCount(), _T("ValueType"));
  m_index_name = liste->InsertColumn(liste->GetColumnCount(), _T("ValueName"));
  m_index_data = liste->InsertColumn(liste->GetColumnCount(), _T("ValueData"));
  m_index_perm = liste->InsertColumn(liste->GetColumnCount(), _T("Permissions"));
  m_index_flag = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCompTask::AddHeader(liste);
  CCommon::AddHeader(liste);
}
