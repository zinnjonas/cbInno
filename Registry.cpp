#include "Registry.h"

const char* RegistryFlags[] =
{
    "createvalueifdoesntexist",
    "deletekey",
    "deletevalue",
    "dontcreatekey",
    "noerror",
    "preservestringtype",
    "uninsclearvalue",
    "uninsdeletekey",
    "uninsdeletekeyifempty",
    "uninsdeletevalue"
};

CRegistry::CRegistry( void)
{
    //ctor
}

CRegistry::~CRegistry()
{
    //dtor
}

void CRegistry::WriteInFile( wxTextFile* File)
{
    if( !m_Root.IsEmpty() && !m_Subkey.IsEmpty())
    {
        wxString Text;

        Text = _T("Root: ") + m_Root + _T("; Subkey: \"") + m_Subkey + _T("\"");
        if( !m_ValueType.IsEmpty())
            Text += _T("; ValueType: ") + m_ValueType;
        if( !m_ValueData)
            Text += _T("; ValueData: \"") + m_ValueData + _T("\"");
        if( !m_Permissions.IsEmpty())
            Text += _T("; Permissions: ") + m_Permissions;
        if( !m_Flags.IsEmpty())
            Text += _T("; Flags: ") + m_Flags;

        File->AddLine( Text);
    }
}

void CRegistry::Set( wxString root, wxString subKey)
{
    SetRoot( root);
    SetSubkey( subKey);
}

void CRegistry::SetRoot(wxString val)
{
    m_Root = val;
}

void CRegistry::SetSubkey(wxString val)
{
    m_Subkey = val;
}

void CRegistry::SetValueType(wxString val)
{
    m_ValueType = val;
}

void CRegistry::SetValueName(wxString val)
{
    m_ValueName = val;
}

void CRegistry::SetValueData(wxString val)
{
    m_ValueData = val;
}

void CRegistry::SetPermissions(wxString val)
{
    m_Permissions = val;
}

void CRegistry::SetFlags(wxString val)
{
    m_Flags = val;
}
