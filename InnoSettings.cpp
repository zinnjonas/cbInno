#include "InnoSettings.h"

//(*InternalHeaders(InnoSettings)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(InnoSettings)
//*)

BEGIN_EVENT_TABLE(InnoSettings,wxPanel)
	//(*EventTable(InnoSettings)
	//*)
END_EVENT_TABLE()

InnoSettings::InnoSettings(wxWindow* parent)
{
	//(*Initialize(InnoSettings)
	wxXmlResource::Get()->LoadObject(this,parent,_T("InnoSettings"),_T("wxPanel"));
	//*)
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

}

void InnoSettings::OnCancel()
{

}
