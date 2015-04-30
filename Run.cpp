#include "Run.h"

CRun::CRun( void)
{
    //ctor
}

CRun::~CRun()
{
    //dtor
}

void CRun::WriteInFile( wxTextFile* File)
{
    if( !m_Filename.IsEmpty())
    {
        wxString Text;

        Text = _T("Filename: \"") + m_Filename + _T("\"");
        if( !m_Description.IsEmpty())
            Text += _T("; Description: \"") + m_Description + _T("\"");
        if( !m_Parameters.IsEmpty())
            Text += _T("; Parameters: \"") + m_Parameters + _T("\"");
        if( !m_WorkingDir.IsEmpty())
            Text += _T("; WorkingDir: \"") + m_WorkingDir + _T("\"");
        if( !m_StatusMsg.IsEmpty())
            Text += _T("; StatusMsg: \"") + m_StatusMsg + _T("\"");
        if( !m_RunOnceId.IsEmpty())
            Text += _T("; RunOnceId: \"") + m_RunOnceId + _T("\"");
        if( !m_Verb.IsEmpty())
            Text += _T("; Verb: \"") + m_Verb + _T("\"");
        if( !m_Flags.IsEmpty())
            Text += _T("; Flags: ") + m_Flags;

        File->AddLine( Text);
    }
}

void CRun::SetFilename(wxString val)
{
    m_Filename = val;
}

void CRun::SetDescription(wxString val)
{
    m_Description = val;
}

void CRun::SetParameters(wxString val)
{
    m_Parameters = val;
}

void CRun::SetWorkingDir(wxString val)
{
    m_WorkingDir = val;
}

void CRun::SetStatusMsg(wxString val)
{
    m_StatusMsg = val;
}

void CRun::SetRunOnceId(wxString val)
{
    m_RunOnceId = val;
}

void CRun::SetVerb(wxString val)
{
    m_Verb = val;
}

void CRun::SetFlags(wxString val)
{
    m_Flags = val;
}
