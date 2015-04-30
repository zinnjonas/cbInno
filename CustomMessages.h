#ifndef CCUSTOMMESSAGES_H
#define CCUSTOMMESSAGES_H

#include <wx/textfile.h>

class CCustomMessages
{
    public:
        CCustomMessages( void);
        virtual ~CCustomMessages();

        void WriteInFile( wxTextFile* File);

        wxString GetName();
        void SetName(wxString val);
        void SetContent(wxString val);
        void SetLanguage(wxString val);

    private:
        wxString m_Name;
        wxString m_Content;
        wxString m_Language;
};

#endif // CCUSTOMMESSAGES_H
