#include "WelcomePage.h"

//(*InternalHeaders(WelcomePage)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(WelcomePage)
const long WelcomePage::ID_STATICTEXT1 = wxNewId();
const long WelcomePage::ID_STATICTEXT2 = wxNewId();
const long WelcomePage::ID_CHECKBOX1 = wxNewId();
//*)

#include "Images/Wizard.xpm"

BEGIN_EVENT_TABLE(WelcomePage,wxWizardPageSimple)
	//(*EventTable(WelcomePage)
	//*)
END_EVENT_TABLE()

WelcomePage::WelcomePage(wxWizard* parent)
{
	//(*Initialize(WelcomePage)
	wxStaticText* StaticText2;
	wxStaticBitmap* StaticBitmap1;
	wxStaticText* StaticText1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap( Wizard_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	BoxSizer1->Add(StaticBitmap1, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to the Inno Script\nWizard"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(20,4,0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("This wizard will guide you through the process of creatubg a\nnew Inno Setup script file. The results will be used to generate\na new script file which can be compiled directly or saved on \ndisk for later use.\n\nNot all features of Inno Setup are coverd by this wizard. See\nthe documentation for details on creating Inno Setup script\nfiles.\n\nClick Next to continue, or Cancel to exit this wizard."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(20,63,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	chEmpty = new wxCheckBox(this, ID_CHECKBOX1, _("Create a new empty script file"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	chEmpty->SetValue(false);
	BoxSizer2->Add(chEmpty, 0, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&WelcomePage::OnchEmptyClick);
	//*)
	SetSize( wxSize(480,320));
	SetBackgroundColour( wxColour( 255, 255, 255));
	m_Empty = false;
	m_Last = NULL;
	m_Normal = NULL;
}

WelcomePage::~WelcomePage()
{
	//(*Destroy(WelcomePage)
	//*)
}

bool WelcomePage::GetIsEmptySet( void)
{
    return m_Empty;
}

void WelcomePage::OnchEmptyClick(wxCommandEvent& event)
{
    m_Empty = !m_Empty;

    if( m_Last == NULL)
    {
        m_Normal = m_Last = this->GetNext();
        if( m_Last != NULL)
            while( m_Last->GetNext() != NULL)
                m_Last = m_Last->GetNext();
    }
    if( m_Last != NULL)
    {
        if( m_Empty)
            SetNext( m_Last);
        else
            SetNext( m_Normal);
    }
}
