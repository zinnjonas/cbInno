#ifndef CLANGUAGES_H
#define CLANGUAGES_H

#include <wx/textfile.h>

class CLanguages
{
    public:
        CLanguages( void);
        virtual ~CLanguages();

        void WriteInFile( wxTextFile* File);

        void Set( wxString name, wxString messagesFile);

        void SetName(wxString val);
        void SetMessagesFile(wxString val);
        void SetLicenseFile(wxString val);
        void SetInfoBeforeFile(wxString val);
        void SetInfoAfterFile(wxString val);

    protected:

        wxString m_Name;
        wxString m_MessagesFile;
        wxString m_LicenseFile;
        wxString m_InfoBeforeFile;
        wxString m_InfoAfterFile;
};

#endif // CLANGUAGES_H
