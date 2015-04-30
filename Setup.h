#ifndef CSETUP_H
#define CSETUP_H

#include <wx/string.h>
#include <wx/textfile.h>

extern const wchar_t* compression[];
extern const wchar_t* backColor[];
extern const wchar_t* backColor2[];

inline wxString bool2string( bool var) { return (var ? _T("yes") : _T("no"));}

class CSetup
{
    public:
        CSetup( void);
        CSetup( wxString AppName, wxString AppVersion);
        virtual ~CSetup( void);

        void WriteInFile( wxTextFile* File);

        void Set( wxString AppName, wxString AppVersion);

        void SetOutput( wxString outputBaseFilename, wxString outputDir = _T("."));

        void SetCompression( wxString compression, wxString compressionThreads = _T("auto"));
        void SetSolidCompression( bool solid);
        void SetGroupName( wxString groupName);
        void SetPrivileges( wxString privilegesRequired);
        void SetChangeAssociations( bool change);
        void SetAlwaysUsePersonalGroup( bool Always);
        void SetPublisher( wxString publisher);
        void SetWebseite( wxString webseite);
        void SetDefaultDirName( wxString dirName);
        void SetDisableDirPage( bool disable);
        void SetCreateAppDir( bool create);
        void SetAllowNoIcons( bool allow);
        void SetLicenseFile( wxString license);
        void SetInfoBefor( wxString info);
        void SetInfoAfter( wxString info);
        void SetIconFile( wxString icon);
        void SetPassword( wxString pass);
        void SetAppVerName( wxString name);
        void SetAppId( );

        wxString GetAppName( void);
        wxString GetAppVersion( void);
        wxString GetPublisherURL( void);

    protected:

        wxString m_Compression;
        wxString m_CompressionThreads;
        wxString m_DiskClusterSize;
        wxString m_DiskSliceSize;
        wxString m_DiskSpanning;
        wxString m_Encryption;
        wxString m_InternalCompressLevel;
        wxString m_MergeDuplicateFiles;
        wxString m_OutputBaseFilename;
        wxString m_OutputDir;
        wxString m_OutputManifestFile;
        wxString m_ReserveBytes;
        wxString m_SignedUninstallerDir;
        wxString m_SignTool;
        wxString m_SlicesPerDisk;
        wxString m_SolidCompression;
        wxString m_SourceDir;
        wxString m_TerminalServicesAware;
        wxString m_UseSetupLdr;
        wxString m_AllowCancelDuringInstall;
        wxString m_AllowNoIcons;
        wxString m_AllowRootDirectory;
        wxString m_AllowUNCPath;
        wxString m_AlwaysRestart;
        wxString m_AlwaysShowComponentsList;
        wxString m_AlwaysShowDirOnReadyPage;
        wxString m_AlwaysShowGroupOnReadyPage;
        wxString m_AlwaysUsePersonalGroup;
        wxString m_AppendDefaultDirName;
        wxString m_AppendDefaultGroupName;
        wxString m_AppComments;
        wxString m_AppContact;
        wxString m_AppId;
        wxString m_AppModifyPath;
        wxString m_AppMutex;
        wxString m_AppName;
        wxString m_AppPublisher;
        wxString m_AppPublisherURL;
        wxString m_AppReadmeFile;
        wxString m_AppSupportPhone;
        wxString m_AppSupportURL;
        wxString m_AppUpdatesURL;
        wxString m_AppVerName;
        wxString m_AppVersion;
        wxString m_ArchitecturesAllowed;
        wxString m_ArchitecturesInstallIn64BitMode;
        wxString m_ChangesAssociations;
        wxString m_ChangesEnvironment;
        wxString m_CreateAppDir;
        wxString m_CreateUninstallRegKey;
        wxString m_DefaultDialogFontName;
        wxString m_DefaultDirName;
        wxString m_DefaultGroupName;
        wxString m_DefaultUserInfoName;
        wxString m_DefaultUserInfoOrg;
        wxString m_DefaultUserInfoSerial;
        wxString m_DirExistsWarning;
        wxString m_DisableDirPage;
        wxString m_DisableFinishedPage;
        wxString m_DisableProgramGroupPage;
        wxString m_DisableReadyMemo;
        wxString m_DisableReadyPage;
        wxString m_DisableStartupPrompt;
        wxString m_DisableWelcomePage;
        wxString m_EnableDirDoesntExistWarning;
        wxString m_ExtraDiskSpaceRequired;
        wxString m_InfoAfterFile;
        wxString m_InfoBeforeFile;
        wxString m_LanguageDetectionMethod;
        wxString m_LicenseFile;
        wxString m_MinVersion;
        wxString m_OnlyBelowVersion;
        wxString m_Password;
        wxString m_PrivilegesRequired;
        wxString m_RestartIfNeededByRun;
        wxString m_SetupLogging;
        wxString m_ShowLanguageDialog;
        wxString m_ShowUndisplayableLanguages;
        wxString m_TimeStampRounding;
        wxString m_TimeStampsInUTC;
        wxString m_TouchDate;
        wxString m_TouchTime;
        wxString m_Uninstallable;
        wxString m_UninstallDisplayIcon;
        wxString m_UninstallDisplayName;
        wxString m_UninstallDisplaySize;
        wxString m_UninstallFilesDir;
        wxString m_UninstallLogMode;
        wxString m_UninstallRestartComputer;
        wxString m_UpdateUninstallLogAppName;
        wxString m_UsePreviousAppDir;
        wxString m_UsePreviousGroup;
        wxString m_UsePreviousLanguage;
        wxString m_UsePreviousSetupType;
        wxString m_UsePreviousTasks;
        wxString m_UsePreviousUserInfo;
        wxString m_UserInfoPage;
        wxString m_AppCopyright;
        wxString m_BackColor;
        wxString m_BackColor2;
        wxString m_BackColorDirection;
        wxString m_BackSolid;
        wxString m_FlatComponentsList;
        wxString m_SetupIconFile;
        wxString m_ShowComponentSizes;
        wxString m_ShowTasksTreeLines;
        wxString m_WindowShowCaption;
        wxString m_WindowStartMaximized;
        wxString m_WindowResizable;
        wxString m_WindowVisible;
        wxString m_WizardImageBackColor;
        wxString m_WizardImageFile;
        wxString m_WizardImageStretch;
        wxString m_WizardSmallImageFile;
};

#endif // CSETUP_H
