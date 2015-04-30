#ifndef CUNINSTALLDELTE_H
#define CUNINSTALLDELTE_H

#include <wx/textfile.h>

class CUninstallDelte
{
    public:
        CUninstallDelte( void);
        virtual ~CUninstallDelte();

        void WriteInFile( wxTextFile* File);

        void SetType(wxString val);
        void SetName(wxString val);

    private:

        wxString m_Type;
        wxString m_Name;
};

#endif // CUNINSTALLDELTE_H
