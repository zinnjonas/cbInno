#include "Files.h"

int CFiles::m_index_src = 0;
int CFiles::m_index_dest_dir = 0;
int CFiles::m_index_dest_name = 0;
int CFiles::m_index_exc = 0;
int CFiles::m_index_extern = 0;
int CFiles::m_index_copy = 0;
int CFiles::m_index_attr = 0;
int CFiles::m_index_perm = 0;
int CFiles::m_index_font = 0;
int CFiles::m_index_strong = 0;
int CFiles::m_index_flags = 0;

const wxString CFiles::FileFlags[] =
{
  _T("32bit"),
  _T("64bit"),
  _T("allowunsafefiles"),
  _T("comparetimestamp"),
  _T("confirmoverwrite"),
  _T("createallsubdirs"),
  _T("deleteafterinstall"),
  _T("dontcopy"),
  _T("dontverifychecksum"),
  _T("external"),
  _T("fontisnttruetype"),
  _T("gacinstall"),
  _T("ignoreversion"),
  _T("isreadme"),
  _T("nocompression"),
  _T("noencryption"),
  _T("noregerror"),
  _T("onlyifdestfileexist"),
  _T("overwritereadonly"),
  _T("promptifolder"),
  _T("recursesubdirs"),
  _T("regserver"),
  _T("regtypelib"),
  _T("replacesameversion"),
  _T("restartreplace"),
  _T("setntfscompression"),
  _T("sharedfile"),
  _T("skipifsourcedoesntexist"),
  _T("solidbreak"),
  _T("sortfilesbyextension"),
  _T("sortfilesbyname"),
  _T("touch"),
  _T("uninsonsharedfileprompt"),
  _T("uninsremovereadonly"),
  _T("uninsneveruninstall"),
  _T("unsetntfscompression")
};

CFiles::CFiles( void)
{
  //ctor
}

CFiles::~CFiles()
{
  //dtor
}

void CFiles::Set( wxString source, wxString destDir)
{
  m_Source    = source;
  m_DestDir   = destDir;
}

void CFiles::SetSource( wxString source)
{
  m_Source = source;
}

void CFiles::SetDestDir( wxString destDir)
{
  m_DestDir = destDir;
}

void CFiles::SetDestName( wxString destName)
{
  m_DestName  = destName;
}

void CFiles::SetExcludes( wxString excludes)
{
  m_Excludes = excludes;
}

void CFiles::SetExternalSize( wxString externelSize)
{
  m_ExternalSize = externelSize;
}

void CFiles::SetCopyMode( wxString copyMode)
{
  m_CopyMode = copyMode;
}

void CFiles::SetAttribs( wxString Attribs)
{
  m_Attribs = Attribs;
}

void CFiles::SetPermission( wxString permission)
{
  m_Permissions = permission;
}

void CFiles::SetFontInstall( wxString fontInstall)
{
  m_FontInstall = fontInstall;
}

void CFiles::SetStrongAssemblyName( wxString strongAssemblyName)
{

  m_StrongAssemblyName = strongAssemblyName;
}

void CFiles::SetFlags( wxString flag)
{

  m_Flags = flag;
}

void CFiles::WriteInFile( wxTextFile* File)
{
  if( !m_Source.IsEmpty() && !m_DestDir.IsEmpty())
  {
    wxString Text;
    Text.Printf(_T("Source: \"%s\"; DestDir: \"%s\""), m_Source.c_str(), m_DestDir.c_str());
    if( !m_DestName.IsEmpty())
      Text+=_T("; DestDir: \"") + m_DestName +_T("\"");
    if( !m_Excludes.IsEmpty())
      Text+=_T("; Excludes: \"") + m_Excludes +_T("\"");
    if( !m_ExternalSize.IsEmpty())
      Text+=_T("; ExternalSize: ") + m_ExternalSize;
    if( !m_CopyMode.IsEmpty())
      Text+=_T("; CopyMode: ") + m_CopyMode;
    if( !m_Attribs.IsEmpty())
      Text+=_T("; Attribs: ") + m_Attribs;
    if( !m_Permissions.IsEmpty())
      Text+=_T("; Permissions: ") + m_Permissions;
    if( !m_FontInstall.IsEmpty())
      Text+=_T("; FontInstall: \"") + m_FontInstall +_T("\"");
    if( !m_StrongAssemblyName.IsEmpty())
      Text+=_T("; StrongAssemblyName: \"") + m_StrongAssemblyName +_T("\"");
    if( !m_Flags.IsEmpty())
      Text+=_T("; Flags: ") + m_Flags;
    CCompTask::AddText(Text);
    CCommon::AddText(Text);
    File->AddLine( Text);
  }
  else if( IsComment())
  {
    File->AddLine(GetComment());
  }
}

wxString CFiles::GetFileName( void)
{
  return m_Source.AfterLast('\\');
}

void CFiles::Analize(const wxString& content, const wxString& line)
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

		if( part.CmpNoCase(_T("source")) == 0)
		{
			SetSource(settings);
		}
		else if( part.CmpNoCase(_T("DestDir")) == 0)
		{
			SetDestDir(settings);
		}
		else if( part.CmpNoCase(_T("destname")) == 0)
		{
			SetDestName(settings);
		}
		else if( part.CmpNoCase(_T("excludes")) == 0)
		{
			SetExcludes(settings);
		}
		else if( part.CmpNoCase(_T("ExternalSize")) == 0)
		{
			SetExternalSize(settings);
		}
		else if( part.CmpNoCase(_T("CopyMode")) == 0)
		{
			SetCopyMode(settings);
		}
		else if( part.CmpNoCase(_T("Attribs")) == 0)
		{
			SetAttribs(settings);
		}
		else if( part.CmpNoCase(_T("Permissions")) == 0)
		{
			SetPermission(settings);
		}
		else if( part.CmpNoCase(_T("FontInstall")) == 0)
		{
      SetFontInstall(settings);
		}
		else if( part.CmpNoCase(_T("StrongAssemblyName")) == 0)
		{
			SetStrongAssemblyName(settings);
		}
		else if( part.CmpNoCase(_T("Flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CFiles::AddContent(wxListCtrl* liste)
{
  CSection::AddContent(liste);
  if( IsComment())
  {
    CComment::AddContent(liste, GetIndex());
  }
  else
  {
    liste->SetItem(GetIndex(), m_index_src, m_Source);
    liste->SetItem(GetIndex(), m_index_dest_dir, m_DestDir);
    liste->SetItem(GetIndex(), m_index_dest_name, m_DestName);
    liste->SetItem(GetIndex(), m_index_exc, m_Excludes);
    liste->SetItem(GetIndex(), m_index_extern, m_ExternalSize);
    liste->SetItem(GetIndex(), m_index_copy, m_CopyMode);
    liste->SetItem(GetIndex(), m_index_attr, m_Attribs);
    liste->SetItem(GetIndex(), m_index_perm, m_Permissions);
    liste->SetItem(GetIndex(), m_index_font, m_FontInstall);
    liste->SetItem(GetIndex(), m_index_strong, m_StrongAssemblyName);
    liste->SetItem(GetIndex(), m_index_flags, m_Flags);
    CCompTask::AddContent(liste, GetIndex());
    CCommon::AddContent(liste, GetIndex());
  }
}

void CFiles::AddHeader(wxListCtrl* liste)
{
  CSection::AddHeader(liste);
  m_index_src       = liste->InsertColumn(liste->GetColumnCount(), _T("Source"));
  m_index_dest_dir  = liste->InsertColumn(liste->GetColumnCount(), _T("DestDir"));
  m_index_dest_name = liste->InsertColumn(liste->GetColumnCount(), _T("DestName"));
  m_index_exc       = liste->InsertColumn(liste->GetColumnCount(), _T("Excludes"));
  m_index_extern    = liste->InsertColumn(liste->GetColumnCount(), _T("ExternalSize"));
  m_index_copy      = liste->InsertColumn(liste->GetColumnCount(), _T("CopyMode"));
  m_index_attr      = liste->InsertColumn(liste->GetColumnCount(), _T("Attribs"));
  m_index_perm      = liste->InsertColumn(liste->GetColumnCount(), _T("Permissions"));
  m_index_font      = liste->InsertColumn(liste->GetColumnCount(), _T("FontInstall"));
  m_index_strong    = liste->InsertColumn(liste->GetColumnCount(), _T("StrongAssemblyName"));
  m_index_flags     = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCompTask::AddHeader(liste);
  CCommon::AddHeader(liste);
}
