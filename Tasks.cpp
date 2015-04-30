#include "Tasks.h"

CTasks::CTasks( void)
{
    //ctor
}

CTasks::~CTasks()
{
    //dtor
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
        if( !m_OnlyBelowVersion.IsEmpty())
            Text += _T("; OnlyBelowVersion: ") + m_OnlyBelowVersion;

        File->AddLine( Text);
    }
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

void CTasks::SetOnlyBelowVersion( wxString val)
{
    m_OnlyBelowVersion = val;
}
