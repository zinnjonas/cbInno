#include "Icons.h"

int CIcons::m_index_name         = 0;
int CIcons::m_index_filename     = 0;
int CIcons::m_index_parameters   = 0;
int CIcons::m_index_workingdir   = 0;
int CIcons::m_index_hotkey       = 0;
int CIcons::m_index_commentar    = 0;
int CIcons::m_index_iconfilename = 0;
int CIcons::m_index_iconindex    = 0;
int CIcons::m_index_appuser      = 0;
int CIcons::m_index_flags        = 0;

const wxString CIcons::Flags[] =
{
  wxT("closeonexit"),
  wxT("createonlyiffileexists"),
  wxT("dontcloseonexit"),
  wxT("foldershortcut"),
  wxT("runmaximized"),
  wxT("runminimized"),
  wxT("uninsneveruninstall"),
  wxT("useapppaths")
};

CIcons::CIcons( void)
{
  //ctor
}

CIcons::~CIcons()
{
  //dtor
}

void CIcons::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Filename.IsEmpty())
  {
    wxString Text;

    Text =_T("Name: \"") + m_Name +_T("\"; Filename: \"") + m_Filename +_T("\"");
    if( !m_Parameters.IsEmpty())
      Text +=_T("; Parameters; \"") + m_Parameters +_T("\"");
    if( !m_WorkingDir.IsEmpty())
      Text +=_T("; WorkingDir: \"") + m_WorkingDir +_T("\"");
    if( !m_HotKey.IsEmpty())
      Text +=_T("; HotKey: \"") + m_HotKey +_T("\"");
    if( !m_Commentar.IsEmpty())
      Text +=_T("; Comment: \"") + m_Commentar +_T("\"");
    if( !m_IconFilename.IsEmpty())
      Text +=_T("; IconFilename: \"") + m_IconFilename +_T("\"");
    if( !m_IconIndex.IsEmpty())
      Text +=_T("; IconIndex: ") + m_IconIndex;
    if( !m_Flags.IsEmpty())
      Text +=_T("; Flags: ") + m_Flags;

    CCompTask::AddText(Text);
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
}

void CIcons::Set( wxString name, wxString filename)
{
  m_Name = name;
  m_Filename = filename;
}

void CIcons::SetParameters( wxString parameters)
{
  m_Parameters = parameters;
}

void CIcons::SetWorkingDir( wxString workingDir)
{
  m_WorkingDir = workingDir;
}

void CIcons::SetHotKey( wxString hotKey)
{
  m_HotKey = hotKey;
}

void CIcons::SetCommentar( wxString commentar)
{
  m_Commentar = commentar;
}

void CIcons::SetIconFilename( wxString iconFilename)
{
  m_IconFilename = iconFilename;
}

void CIcons::SetAppUserModelID( wxString app)
{
  m_AppUserModelId = app;
}

void CIcons::SetFlags( wxString flags)
{
  m_Flags = flags;
}

void CIcons::SetName(wxString name)
{
  m_Name = name;
}

void CIcons::SetFilename(wxString filename)
{
  m_Filename = filename;
}

void CIcons::SetIconIndex(wxString iconIndex)
{
  m_IconIndex = iconIndex;
}

void CIcons::Analize(const wxString& content, const wxString& line)
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

		if( part.CmpNoCase(_T("name")) == 0)
		{
			SetName(settings);
		}
		else if( part.CmpNoCase(_T("Filename")) == 0)
		{
			SetFilename(settings);
		}
		else if( part.CmpNoCase(_T("parameters")) == 0)
		{
			SetParameters(settings);
		}
		else if( part.CmpNoCase(_T("workingdir")) == 0)
		{
			SetWorkingDir(settings);
		}
		else if( part.CmpNoCase(_T("hotkey")) == 0)
		{
			SetHotKey(settings);
		}
		else if( part.CmpNoCase(_T("comment")) == 0)
		{
			SetCommentar(settings);
		}
		else if( part.CmpNoCase(_T("iconfilename")) == 0)
		{
			SetIconFilename(settings);
		}
		else if( part.CmpNoCase(_T("iconindex")) == 0)
		{
			SetIconIndex(settings);
		}
		else if( part.CmpNoCase(_T("appusermodelid")) == 0)
		{
      SetAppUserModelID(settings);
		}
		else if( part.CmpNoCase(_T("flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CIcons::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Name);
  liste->SetItem(GetIndex(), m_index_filename, m_Filename);
  liste->SetItem(GetIndex(), m_index_parameters, m_Parameters);
  liste->SetItem(GetIndex(), m_index_workingdir, m_WorkingDir);
  liste->SetItem(GetIndex(), m_index_hotkey, m_HotKey);
  liste->SetItem(GetIndex(), m_index_commentar, m_Commentar);
  liste->SetItem(GetIndex(), m_index_iconfilename, m_IconFilename);
  liste->SetItem(GetIndex(), m_index_iconindex, m_IconIndex);
  liste->SetItem(GetIndex(), m_index_appuser, m_AppUserModelId);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CIcons::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name              = liste->InsertColumn(liste->GetColumnCount(), _T("Name"));
  m_index_filename          = liste->InsertColumn(liste->GetColumnCount(), _T("Filename"));
  m_index_parameters        = liste->InsertColumn(liste->GetColumnCount(), _T("Parameters"));
  m_index_workingdir        = liste->InsertColumn(liste->GetColumnCount(), _T("WorkingDir"));
  m_index_hotkey            = liste->InsertColumn(liste->GetColumnCount(), _T("HotKey"));
  m_index_commentar         = liste->InsertColumn(liste->GetColumnCount(), _T("Comment"));
  m_index_iconfilename      = liste->InsertColumn(liste->GetColumnCount(), _T("IconFilename"));
  m_index_iconindex         = liste->InsertColumn(liste->GetColumnCount(), _T("IconIndex"));
  m_index_appuser           = liste->InsertColumn(liste->GetColumnCount(), _T("AppUserModelID"));
  m_index_flags             = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCompTask::AddHeader(liste);
  CCommon::AddHeader(liste);
}

