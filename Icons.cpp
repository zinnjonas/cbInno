#include "Icons.h"

const char* IconsFlag[] =
{
  "closeonexit",
  "createonlyiffileexists",
  "dontcloseonexit",
  "foldershortcut",
  "runmaximized",
  "runminimized",
  "uninsneveruninstall",
  "useapppaths"
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
    if( !m_Comment.IsEmpty())
      Text +=_T("; Comment: \"") + m_Comment +_T("\"");
    if( !m_IconFilename.IsEmpty())
      Text +=_T("; IconFilename: \"") + m_IconFilename +_T("\"");
    if( !m_IconIndex.IsEmpty())
      Text +=_T("; IconIndex: ") + m_IconIndex;
    if( !m_Flags.IsEmpty())
      Text +=_T("; Flags: ") + m_Flags;
    if( !m_Tasks.IsEmpty())
      Text +=_T("; Tasks: ") + m_Tasks;

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

void CIcons::setComment( wxString comment)
{
  m_Comment = comment;
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

void CIcons::SetTasks( wxString Task)
{
  m_Tasks = Task;
}
