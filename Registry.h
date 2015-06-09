#ifndef CREGISTRY_H
#define CREGISTRY_H

#include <wx/textfile.h>

extern const char* RegistryFlags[];

class CRegistry
{
  public:
    CRegistry( void);
    virtual ~CRegistry();

    void WriteInFile( wxTextFile* File);

    void Set( wxString root, wxString Subkey);

    void SetRoot(wxString val);
    void SetSubkey(wxString val);
    void SetValueType(wxString val);
    void SetValueName(wxString val);
    void SetValueData(wxString val);
    void SetPermissions(wxString val);
    void SetFlags(wxString val);

  private:
    wxString m_Root;
    wxString m_Subkey;
    wxString m_ValueType;
    wxString m_ValueName;
    wxString m_ValueData;
    wxString m_Permissions;
    wxString m_Flags;
};

#endif // CREGISTRY_H
