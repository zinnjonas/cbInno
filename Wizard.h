#ifndef WIZARD_H
#define WIZARD_H

#include <wx/textfile.h>

#include <wx/msgdlg.h>

#include <wx/wizard.h>
#include "WelcomePage.h"
#include "ApplicationInformation.h"
#include "ApplicationFolder.h"
#include "ApplicationFiles.h"
#include "ApplicationIcons.h"
#include "ApplicationDocumentation.h"
#include "SetupLanguages.h"
#include "CompilerSettings.h"
#include "FinishWizard.h"

#include "Components.h"
#include "CustomMessages.h"
#include "Files.h"
#include "Icons.h"
#include "Languages.h"
#include "Registry.h"
#include "Run.h"
#include "Setup.h"
#include "Types.h"
#include "UninstallDelte.h"
#include "Tasks.h"

#include <wx/dynarray.h>

WX_DECLARE_OBJARRAY(CFiles,         ArraySetupFile);
WX_DECLARE_OBJARRAY(CLanguages,     ArraySetupLanguage);
WX_DECLARE_OBJARRAY(CTasks,         ArraySetupTask);
WX_DECLARE_OBJARRAY(CIcons,         ArraySetupIcon);
WX_DECLARE_OBJARRAY(CRun,           ArraySetupRun);
WX_DECLARE_OBJARRAY(CRegistry,      ArraySetupRegistry);
WX_DECLARE_OBJARRAY(CUninstallDelte,ArraySetupUninstall);
WX_DECLARE_OBJARRAY(CComponents,    ArraySetupComponent);
WX_DECLARE_OBJARRAY(CCustomMessages,ArraySetupCustom);
WX_DECLARE_OBJARRAY(CTypes,         ArraySetupType);

struct CInnoFile
{
    CSetup              Setup;
    ArraySetupFile      Files;
    ArraySetupLanguage  Languages;
    ArraySetupTask      Tasks;
    ArraySetupIcon      Icons;
    ArraySetupRun       Runs;
    ArraySetupRegistry  Registrys;
    ArraySetupUninstall UninstallDeletes;
    ArraySetupComponent Components;
    ArraySetupCustom    CustomMessages;
    ArraySetupType      Types;
};

class MyStandartWizard : public wxWizard
{

    public:

        MyStandartWizard( wxWindow* parent);

        void SetName( wxString Name);

        bool Show( void);

        void WriteInFile( wxTextFile* File);

        CInnoFile InnoFile;

        bool EmptyProjekt;

    protected:

        static const long ID_WIZARD;

        void OnWizardCancel(wxWizardEvent& event);
        void InWizardChanging( wxWizardEvent& event);
        void OnWizardFinish( wxWizardEvent& event);

    private:


        WelcomePage             *Page1;
        ApplicationInformation  *Page2;
        ApplicationFolder       *Page3;
        ApplicationFiles        *Page4;
        ApplicationIcons        *Page5;
        ApplicationDocumentation*Page6;
        SetupLanguages          *Page7;
        CompilerSettings        *Page8;
        FinishWizard            *Page9;

        wxString                m_Name;

        DECLARE_EVENT_TABLE()
};


class CInno
{
    public:
        CInno( void);
        virtual ~CInno();

        void Create( wxWindow* parent);
        void Set( wxString ProjectName);
        void AddToProject( bool add);

        void WriteFile( wxString Name = _("Test"));
        void WriteEmptyFile( wxString Name = _("Test"));

        bool ShowStandartWizard( void);
        bool FileExist( wxString Name);

        void Delete( void);

    private:

        bool     m_AddToProject;

        MyStandartWizard *Wizard;

};

#endif // WIZARD_H
