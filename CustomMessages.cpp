#include "CustomMessages.h"

CCustomMessages::CCustomMessages( void)
{
    //ctor
}

CCustomMessages::~CCustomMessages()
{
    //dtor
}

void CCustomMessages::WriteInFile( wxTextFile* File)
{
    if( !m_Name.IsEmpty() && !m_Content.IsEmpty())
    {
        wxString Text;

        if( !m_Language.IsEmpty())
            Text = m_Language +_T(".") + m_Name +_T("=") + m_Content;
        else
            Text = m_Name +_T("=") + m_Content;

        File->AddLine( Text);
    }
}

wxString CCustomMessages::GetName()
{
    return m_Name;
}

void CCustomMessages::SetName(wxString val)
{
    m_Name = val;
}

void CCustomMessages::SetContent(wxString val)
{
    m_Content = val;
}

void CCustomMessages::SetLanguage(wxString val)
{
    m_Language = val;
}
