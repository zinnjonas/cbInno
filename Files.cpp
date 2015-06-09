#include "Files.h"

const char* FileFlags[] =
{
  "32bit",
  "64bit",
  "allowunsafefiles",
  "comparetimestamp",
  "confirmoverwrite",
  "createallsubdirs",
  "deleteafterinstall",
  "dontcopy",
  "dontverifychecksum",
  "external",
  "fontisnttruetype",
  "gacinstall",
  "ignoreversion",
  "isreadme",
  "nocompression",
  "noencryption",
  "noregerror",
  "onlyifdestfileexist",
  "overwritereadonly",
  "promptifolder",
  "recursesubdirs",
  "regserver",
  "regtypelib",
  "replacesameversion",
  "restartreplace",
  "setntfscompression",
  "sharedfile",
  "skipifsourcedoesntexist",
  "solidbreak",
  "sortfilesbyextension",
  "sortfilesbyname",
  "touch",
  "uninsonsharedfileprompt",
  "uninsremovereadonly",
  "uninsneveruninstall",
  "unsetntfscompression"
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

void CFiles::SetExcludes( wxString excludes)
{
  m_Excludes = excludes;
}

void CFiles::SetExternalSize( wxString externelSize)
{
  m_Excludes = externelSize;
}

void CFiles::SetAttribs( wxString Attribs)
{

  m_Attribs = Attribs;
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

void CFiles::SetComponents( wxString components)
{
  m_Components = components;
}

void CFiles::SetLanguages( wxString languages)
{
  m_Langauges = languages;
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
    if( !m_Components.IsEmpty())
      Text +=_T("; Components: ") + m_Components;
    if( !m_Langauges.IsEmpty())
      Text +=_T("; Languages: ") + m_Langauges;
    File->AddLine( Text);
  }
}

wxString CFiles::GetFileName( void)
{
  return m_Source.AfterLast('\\');
}
