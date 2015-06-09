#ifndef CCOMPONENTS_H
#define CCOMPONENTS_H

#include <wx/textfile.h>

extern const char* ComponentsFlags[];

class CComponents
{
  public:
    CComponents( void);
    virtual ~CComponents();

    void WriteInFile( wxTextFile* File);

    void Set( wxString Name, wxString Description);

    void SetTypes( wxString types);
    void SetExtraDiskSpace( wxString extraDiskSpace);
    void Flags( wxString flag);

    wxString GetName( void);

  protected:

    wxString m_Name;
    wxString m_Discription;
    wxString m_Types;
    wxString m_ExtraDiskSpaceRequired;
    wxString m_Flags;
};

#endif // CCOMPONENTS_H
