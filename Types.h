#ifndef CTYPES_H
#define CTYPES_H

#include <wx/textfile.h>

class CTypes
{
    public:
        CTypes( void);
        virtual ~CTypes();

        void WriteInFile( wxTextFile* File);

        void Set( wxString name, wxString description);

        void SetFlag( wxString Flags);

        wxString GetName( void);

    protected:

        wxString m_Name;
        wxString m_Description;
        wxString m_Flags;
};

#endif // CTYPES_H
