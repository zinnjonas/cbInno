#include "UninstallDelte.h"

CUninstallDelte::CUninstallDelte( void)
{
    //ctor
}

CUninstallDelte::~CUninstallDelte()
{
    //dtor
}

void CUninstallDelte::WriteInFile( wxTextFile* File)
{
    if( !m_Type.IsEmpty() && !m_Name.IsEmpty())
    {
        wxString Text;

        Text = _T("Type: ") + m_Type + _T("; Name: \"") + m_Name +_T("\"");

        File->AddLine( Text);
    }
}

void CUninstallDelte::SetType(wxString val)
{
    m_Type = val;
}

void CUninstallDelte::SetName(wxString val)
{
    m_Name = val;
}
