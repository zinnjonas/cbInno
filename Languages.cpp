#include "Languages.h"

CLanguages::CLanguages( void)
{
    //ctor
}

CLanguages::~CLanguages()
{
    //dtor
}

void CLanguages::WriteInFile( wxTextFile* File)
{

    if( !m_Name.IsEmpty() && !m_MessagesFile.IsEmpty())
    {
        wxString Text;

        Text = _T("Name: \"") + m_Name + _T("\"; MessagesFile: \"") + m_MessagesFile + _T("\"");
        if( !m_LicenseFile.IsEmpty())
            Text += _T("; LicenseFile: \"") + m_LicenseFile + _T("\"");
        if( !m_InfoBeforeFile.IsEmpty())
            Text += _T("; InfoBeforeFile: \"") + m_InfoBeforeFile + _T("\"");
        if( !m_InfoAfterFile.IsEmpty())
            Text += _T("; InfoAfterFile: \"") + m_InfoAfterFile + _T("\"");

        File->AddLine( Text);
    }
}

void CLanguages::Set( wxString name, wxString messagesFile)
{
    m_Name          = name;
    m_MessagesFile  = messagesFile;
}

void CLanguages::SetName(wxString val)
{
    m_Name = val;
}

void CLanguages::SetMessagesFile(wxString val)
{
    m_MessagesFile = val;
}

void CLanguages::SetLicenseFile(wxString val)
{
    m_LicenseFile = val;
}

void CLanguages::SetInfoBeforeFile(wxString val)
{
    m_InfoBeforeFile = val;
}

void CLanguages::SetInfoAfterFile(wxString val)
{
    m_InfoAfterFile = val;
}
