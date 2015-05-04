#include "InnoSettings.h"

//(*InternalHeaders(InnoSettings)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(InnoSettings)
//*)

#include <configmanager.h>

BEGIN_EVENT_TABLE(InnoSettings,wxPanel)
	//(*EventTable(InnoSettings)
	//*)
END_EVENT_TABLE()

InnoSettings::InnoSettings(wxWindow* parent)
{
	//(*Initialize(InnoSettings)
	wxXmlResource::Get()->LoadObject(this,parent,_T("InnoSettings"),_T("wxPanel"));
	FilePickerCtrl1 = (wxFilePickerCtrl*)FindWindow(XRCID("ID_ISCC_PICKER"));
	//*)
	ConfigManager* pCfg = Manager::Get()->GetConfigManager(_T("inno"));
    XRCCTRL(*this, "ID_ISCC_PICKER", wxFilePickerCtrl)->SetPath(pCfg->Read(_T("iscc_path"), _T("")));
}

InnoSettings::~InnoSettings()
{
	//(*Destroy(InnoSettings)
	//*)
}

wxString InnoSettings::GetTitle() const
{
    return L"Inno Settings";
}

wxString InnoSettings::GetBitmapBaseName() const
{
    return L"Inno";
}

void InnoSettings::OnApply()
{
    ConfigManager* pCfg = Manager::Get()->GetConfigManager(_T("inno"));
    pCfg->Write(_T("iscc_path"), XRCCTRL(*this, "ID_ISCC_PICKER", wxFilePickerCtrl)->GetPath());
}

void InnoSettings::OnCancel()
{

}

