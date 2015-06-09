#include "Components.h"

const char* ComponentsFlags[] =
{
  "checkablealone",
  "dontinheritcheck",
  "exclusive",
  "fixed",
  "restart",
  "disablenouninstallwarning"
};

CComponents::CComponents( void)
{
  //ctor
}

CComponents::~CComponents()
{
  //dtor
}

void CComponents::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Discription.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: \"") + m_Name + _T("\"; Description: \"") + m_Discription + _T("\"");

    if( !m_Types.IsEmpty())
      Text += _T("; Types: ") + m_Types;
    if( !m_ExtraDiskSpaceRequired.IsEmpty())
      Text += _T("; ExtraDiskSpaceRequired: ") + m_ExtraDiskSpaceRequired;
    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;

    File->AddLine( Text);
  }
}

void CComponents::Set( wxString Name, wxString Description)
{
  m_Name         = Name;
  m_Discription  = Description;
}

void CComponents::SetTypes( wxString types)
{
  m_Types = types;
}

void CComponents::SetExtraDiskSpace( wxString extraDiskSpace)
{
  m_ExtraDiskSpaceRequired = extraDiskSpace;
}

void CComponents::Flags( wxString flag)
{
  m_Flags = flag;
}

wxString CComponents::GetName( void)
{
  return m_Name;
}
