#include "Types.h"

CTypes::CTypes( void)
{
  //ctor
}

CTypes::~CTypes()
{
  //dtor
}

void CTypes::WriteInFile( wxTextFile* File)
{
  if( !m_Name.IsEmpty() && !m_Description.IsEmpty())
  {
    wxString Text;

    Text = _T("Name: \"") + m_Name + _T("\"; Description: \"") + m_Description + _T("\"");

    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;

    File->AddLine( Text);
  }
}

void CTypes::Set( wxString name, wxString description)
{
  m_Name       = name;
  m_Description = description;
}

void CTypes::SetFlag( wxString Flags)
{
  m_Flags = Flags;
}

wxString CTypes::GetName( void)
{
  return m_Name;
}
