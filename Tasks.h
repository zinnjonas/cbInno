#ifndef CTASKS_H
#define CTASKS_H

#include <wx/textfile.h>

class CTasks
{
    public:
        CTasks( void);
        virtual ~CTasks();

        void WriteInFile( wxTextFile* File);

        void SetName(wxString val);
        void SetDescription(wxString val);
        void SetGroupDescription(wxString val);
        void SetComponents( wxString val);
        void SetFlags( wxString val);
        void SetOnlyBelowVersion( wxString val);

    protected:

        wxString m_Name;
        wxString m_Description;
        wxString m_GroupDescription;
        wxString m_Components;
        wxString m_Flags;
        wxString m_OnlyBelowVersion;
};

#endif // CTASKS_H
