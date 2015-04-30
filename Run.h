#ifndef CRUN_H
#define CRUN_H

#include <wx/textfile.h>

class CRun
{
    public:
        CRun( void);
        virtual ~CRun();

        void WriteInFile( wxTextFile* File);

        void SetFilename(wxString val);
        void SetDescription(wxString val);
        void SetParameters(wxString val);
        void SetWorkingDir(wxString val);
        void SetStatusMsg(wxString val);
        void SetRunOnceId(wxString val);
        void SetVerb(wxString val);
        void SetFlags(wxString val);

    private:
        wxString m_Filename;
        wxString m_Description;
        wxString m_Parameters;
        wxString m_WorkingDir;
        wxString m_StatusMsg;
        wxString m_RunOnceId;
        wxString m_Verb;
        wxString m_Flags;
};

#endif // CRUN_H
