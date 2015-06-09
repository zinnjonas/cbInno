#include "Setup.h"

#include <Rpc.h>

const wchar_t* compression[] =
{
  _T("zip"),
  _T("zip/1 throught zip/9"),
  _T("bzip"),
  _T("bzip"),
  _T("bzip/1 throught bzip/9"),
  _T("lzma"),
  _T("lzma/fast"),
  _T("lzma/normal"),
  _T("lzma/max"),
  _T("lzmaultra"),
  _T("lzma/ultra64"),
  _T("lzma2"),
  _T("lzma2/fast"),
  _T("lzma2/normal"),
  _T("lzma2/max"),
  _T("lzma2/ultra"),
  _T("lzma2/ultra64"),
  _T("none")
};

const wchar_t* backColor[] =
{
  _T("clBlack"),
  _T("clMaroon"),
  _T("clGreen"),
  _T("clOlive"),
  _T("clNavy"),
  _T("clPurple"),
  _T("clTeal"),
  _T("clGray"),
  _T("clSilver"),
  _T("clRed"),
  _T("clLime"),
  _T("clYellow"),
  _T("clBlue"),
  _T("clFuchsia"),
  _T("clAqua"),
  _T("clWhite")
};

const wchar_t* backColor2[] =
{
  _T("clBlack2"),
  _T("clMaroon2"),
  _T("clGreen2"),
  _T("clOlive2"),
  _T("clNavy2"),
  _T("clPurple2"),
  _T("clTeal2"),
  _T("clGray2"),
  _T("clSilver2"),
  _T("clRed2"),
  _T("clLime2"),
  _T("clYellow2"),
  _T("clBlue2"),
  _T("clFuchsia2"),
  _T("clAqua2"),
  _T("clWhite2")
};

CSetup::CSetup( void)
{
  //ctor
  Set( _T("MySetup"), _T("0.0.0.0"));
}

CSetup::CSetup( wxString AppName, wxString AppVersion)
{
  Set( AppName, AppVersion);
}

CSetup::~CSetup()
{
  //dtor
}

void CSetup::WriteInFile( wxTextFile* File)
{
  wxString Text;
  File->AddLine( _T("[Setup]"));
  File->AddLine( _T("; NOTE: The value of AppId uniquely identifies this application."));
  File->AddLine( _T("; Do not use the same AppId value in installers for other applications."));
  if( m_AppId != m_AppName)
  {
    Text.Printf( _T("AppId                          = %s"), m_AppId.c_str());
    File->AddLine( Text);
  }
  Text.Printf( _T("AppName                        = %s"), m_AppName.c_str());
  File->AddLine( Text);
  Text.Printf( _T("AppVersion                     = %s"), m_AppVersion.c_str());
  File->AddLine( Text);
  if( m_AppVerName != (m_AppName + _T("version ") + m_AppVersion))
  {
    Text.Printf( _T(";AppVerName                     = %s"), m_AppVerName.c_str());
    File->AddLine( Text);
  }
  if( m_AppPublisher != _T(""))
  {
    Text.Printf( _T("AppPublisher                   = %s"), m_AppPublisher.c_str());
    File->AddLine( Text);
  }
  if( m_AppPublisherURL != _T(""))
  {
    Text.Printf( _T("AppPublisherURL                = %s"), m_AppPublisherURL.c_str());
    File->AddLine( Text);
  }
  if( m_AppSupportURL != _T(""))
  {
    Text.Printf( _T("AppSupportURL                  = %s"), m_AppSupportURL.c_str());
    File->AddLine( Text);
  }
  if( m_AppUpdatesURL != _T(""))
  {
    Text.Printf( _T("AppUpdatesURL                  = %s"), m_AppUpdatesURL.c_str());
    File->AddLine( Text);
  }
  if( !m_DefaultDirName.IsEmpty())
  {
    Text.Printf( _T("DefaultDirName                 = %s"), m_DefaultDirName.c_str());
    File->AddLine( Text);
  }
  if( m_DefaultGroupName != _T(""))
  {
    Text.Printf( _T("DefaultGroupName               = %s"), m_DefaultGroupName.c_str());
    File->AddLine( Text);
  }
  if( m_AllowNoIcons != bool2string(false))
  {
    Text.Printf( _T("AllowNoIcons                   = %s"), m_AllowNoIcons.c_str());
    File->AddLine( Text);
  }
  if( m_LicenseFile != _T(""))
  {
    Text.Printf( _T("LicenseFile                    = %s"), m_LicenseFile.c_str());
    File->AddLine( Text);
  }
  if( m_InfoAfterFile != _T(""))
  {
    Text.Printf( _T("InfoAfterFile                  = %s"), m_InfoAfterFile.c_str());
    File->AddLine( Text);
  }
  if( m_InfoBeforeFile != _T(""))
  {
    Text.Printf( _T("InfoBeforeFile                 = %s"), m_InfoBeforeFile.c_str());
    File->AddLine( Text);
  }
  if( m_OutputDir != _T("Output"))
  {
    Text.Printf( _T("OutputDir                      = %s"), m_OutputDir.c_str());
    File->AddLine( Text);
  }
  Text.Printf( _T("OutputBaseFilename             = %s"), m_OutputBaseFilename.c_str());
  File->AddLine( Text);
  if( m_SetupIconFile != _T(""))
  {
    Text.Printf( _T("SetupIconFile                  = %s"), m_SetupIconFile.c_str());
    File->AddLine( Text);
  }
  if( m_Password != _T(""))
  {
    Text.Printf( _T("Password                       = %s"), m_Password.c_str());
    File->AddLine( Text);
  }
  if( m_Compression != _T("lzma2/max"))
  {
    Text.Printf( _T("Compression                    = %s"), m_Compression.c_str());
    File->AddLine( Text);
  }
  if( m_SolidCompression != bool2string(false))
  {
    Text.Printf( _T("SolidCompression               = %s"), m_SolidCompression.c_str());
    File->AddLine( Text);
  }

  if( m_CompressionThreads != _T("auto"))
  {
    Text.Printf( _T("CompressionThreads             = %s"), m_CompressionThreads.c_str());
    File->AddLine( Text);
  }
  if( m_DiskClusterSize != _T("512"))
  {
    Text.Printf( _T("DiskClusterSize                = %s"), m_DiskClusterSize.c_str());
    File->AddLine( Text);
  }
  if( m_DiskSliceSize != _T("max"))
  {
    Text.Printf( _T("DiskSliceSize                  = %s"), m_DiskSliceSize.c_str());
    File->AddLine( Text);
  }
  if( m_DiskSpanning != bool2string(false))
  {
    Text.Printf( _T("DiskSpanning                   = %s"), m_DiskSpanning.c_str());
    File->AddLine( Text);
  }
  if( m_Encryption != bool2string(false))
  {
    Text.Printf( _T("Encryption                     = %s"), m_Encryption.c_str());
    File->AddLine( Text);
  }
  if( m_InternalCompressLevel != _T("normal"))
  {
    Text.Printf( _T("InternalCompressLevel          = %s"), m_InternalCompressLevel.c_str());
    File->AddLine( Text);
  }
  if( m_MergeDuplicateFiles != bool2string(true))
  {
    Text.Printf( _T("MergeDuplicateFiles            = %s"), m_MergeDuplicateFiles.c_str());
    File->AddLine( Text);
  }
  if( m_OutputManifestFile != _T(""))
  {
    Text.Printf( _T("OutputManifestFile             = %s"), m_OutputManifestFile.c_str());
    File->AddLine( Text);
  }
  if( m_ReserveBytes != _T("0"))
  {
    Text.Printf( _T("ReserveBytes                   = %s"), m_ReserveBytes.c_str());
    File->AddLine( Text);
  }
  if( m_SignedUninstallerDir != _T("Output"))
  {
    Text.Printf( _T("SignedUninstallerDir           = %s"), m_SignedUninstallerDir.c_str());
    File->AddLine( Text);
  }
  if( m_SignTool != bool2string(false))
  {
    Text.Printf( _T("SignTool                       = %s"), m_SignTool.c_str());
    File->AddLine( Text);
  }
  if( m_SlicesPerDisk != _T("1"))
  {
    Text.Printf( _T("SlicesPerDisk                  = %s"), m_SlicesPerDisk.c_str());
    File->AddLine( Text);
  }
  if( m_SourceDir != _T(""))
  {
    Text.Printf( _T("SourceDir                      = %s"), m_SourceDir.c_str());
    File->AddLine( Text);
  }
  if( m_TerminalServicesAware != bool2string(true))
  {
    Text.Printf( _T("TerminalServicesAware          = %s"), m_TerminalServicesAware.c_str());
    File->AddLine( Text);
  }
  if( m_UseSetupLdr != bool2string(true))
  {
    Text.Printf( _T("UseSetupLdr                    = %s"), m_UseSetupLdr.c_str());
    File->AddLine( Text);
  }
  if( m_AllowCancelDuringInstall != bool2string(true))
  {
    Text.Printf( _T("AllowCancelDuringInstall       = %s"), m_AllowCancelDuringInstall.c_str());
    File->AddLine( Text);
  }
  if( m_AllowRootDirectory != bool2string(false))
  {
    Text.Printf( _T("AllowRootDirectory             = %s"), m_AllowRootDirectory.c_str());
    File->AddLine( Text);
  }
  if( m_AllowUNCPath != bool2string(true))
  {
    Text.Printf( _T("AllowUNCPath                   = %s"), m_AllowUNCPath.c_str());
    File->AddLine( Text);
  }
  if( m_AlwaysRestart != bool2string(false))
  {
    Text.Printf( _T("AlwaysRestart                  = %s"), m_AlwaysRestart.c_str());
    File->AddLine( Text);
  }
  if( m_AlwaysShowComponentsList != bool2string(true))
  {
    Text.Printf( _T("AlwaysShowComponentsList       = %s"), m_AlwaysShowComponentsList.c_str());
    File->AddLine( Text);
  }
  if( m_AlwaysShowDirOnReadyPage != bool2string(false))
  {
    Text.Printf( _T("AlwaysShowDirOnReadyPage       = %s"), m_AlwaysShowDirOnReadyPage.c_str());
    File->AddLine( Text);
  }
  if( m_AlwaysShowGroupOnReadyPage != bool2string(false))
  {
    Text.Printf( _T("AlwaysShowGroupOnReadyPage     = %s"), m_AlwaysShowGroupOnReadyPage.c_str());
    File->AddLine( Text);
  }
  if( m_AlwaysUsePersonalGroup != bool2string(false))
  {
    Text.Printf( _T("AlwaysUsePersonalGroup         = %s"), m_AlwaysUsePersonalGroup.c_str());
    File->AddLine( Text);
  }
  if( m_AppendDefaultDirName != bool2string(true))
  {
    Text.Printf( _T("AppendDefaultDirName           = %s"), m_AppendDefaultDirName.c_str());
    File->AddLine( Text);
  }
  if( m_AppendDefaultGroupName != bool2string(true))
  {
    Text.Printf( _T("AppendDefaultGroupName         = %s"), m_AppendDefaultGroupName.c_str());
    File->AddLine( Text);
  }
  if( m_AppComments != _T(""))
  {
    Text.Printf( _T("AppComments                    = %s"), m_AppComments.c_str());
    File->AddLine( Text);
  }
  if( m_AppContact != _T(""))
  {
    Text.Printf( _T("AppContact                     = %s"), m_AppContact.c_str());
    File->AddLine( Text);
  }
  if( m_AppModifyPath != _T(""))
  {
    Text.Printf( _T("AppModifyPath                  = %s"), m_AppModifyPath.c_str());
    File->AddLine( Text);
  }
  if( m_AppMutex != _T(""))
  {
    Text.Printf( _T("AppMutex                       = %s"), m_AppMutex.c_str());
    File->AddLine( Text);
  }
  if( m_AppReadmeFile != _T(""))
  {
    Text.Printf( _T("AppReadmeFile                  = %s"), m_AppReadmeFile.c_str());
    File->AddLine( Text);
  }
  if( m_AppSupportPhone != _T(""))
  {
    Text.Printf( _T("AppSupportPhone                = %s"), m_AppSupportPhone.c_str());
    File->AddLine( Text);
  }
  if( m_ArchitecturesAllowed != _T(""))
  {
    Text.Printf( _T("ArchitecturesAllowed           = %s"), m_ArchitecturesAllowed.c_str());
    File->AddLine( Text);
  }
  if( m_ArchitecturesInstallIn64BitMode != _T(""))
  {
    Text.Printf( _T("ArchitecturesInstallIn64BitMode= %s"), m_ArchitecturesInstallIn64BitMode.c_str());
    File->AddLine( Text);
  }
  if( m_ChangesAssociations != bool2string(false))
  {
    Text.Printf( _T("ChangesAssociations            = %s"), m_ChangesAssociations.c_str());
    File->AddLine( Text);
  }
  if( m_ChangesEnvironment != bool2string(false))
  {
    Text.Printf( _T("ChangesEnvironment             = %s"), m_ChangesEnvironment.c_str());
    File->AddLine( Text);
  }
  if( m_CreateAppDir != bool2string(true))
  {
    Text.Printf( _T("CreateAppDir                   = %s"), m_CreateAppDir.c_str());
    File->AddLine( Text);
  }
  if( m_CreateUninstallRegKey != bool2string(true))
  {
    Text.Printf( _T("CreateUninstallRegKey          = %s"), m_CreateUninstallRegKey.c_str());
    File->AddLine( Text);
  }
  if( m_DefaultDialogFontName != _T("Tahoma"))
  {
    Text.Printf( _T("DefaultDialogFontName          = %s"), m_DefaultDialogFontName.c_str());
    File->AddLine( Text);
  }
  if( m_DefaultUserInfoName != _T("{sysuserinfoname}"))
  {
    Text.Printf( _T("DefaultUserInfoName            = %s"), m_DefaultUserInfoName.c_str());
    File->AddLine( Text);
  }
  if( m_DefaultUserInfoOrg != _T("{sysuserinfoorg}"))
  {
    Text.Printf( _T("DefaultUserInfoOrg             = %s"), m_DefaultUserInfoOrg.c_str());
    File->AddLine( Text);
  }
  if( m_DefaultUserInfoSerial != _T(""))
  {
    Text.Printf( _T("DefaultUserInfoSerial          = %s"), m_DefaultUserInfoSerial.c_str());
    File->AddLine( Text);
  }
  if( m_DirExistsWarning != _T("auto"))
  {
    Text.Printf( _T("DirExistsWarning               = %s"), m_DirExistsWarning.c_str());
    File->AddLine( Text);
  }
  if( m_DisableDirPage != bool2string(false))
  {
    Text.Printf( _T("DisableDirPage                 = %s"), m_DisableDirPage.c_str());
    File->AddLine( Text);
  }
  if( m_DisableFinishedPage != bool2string(false))
  {
    Text.Printf( _T("DisableFinishedPage            = %s"), m_DisableFinishedPage.c_str());
    File->AddLine( Text);
  }
  if( m_DisableProgramGroupPage != bool2string(false))
  {
    Text.Printf( _T("DisableProgramGroupPage        = %s"), m_DisableProgramGroupPage.c_str());
    File->AddLine( Text);
  }
  if( m_DisableReadyMemo != bool2string(false))
  {
    Text.Printf( _T("DisableReadyMemo               = %s"), m_DisableReadyMemo.c_str());
    File->AddLine( Text);
  }
  if( m_DisableReadyPage != bool2string(false))
  {
    Text.Printf( _T("DisableReadyPage               = %s"), m_DisableReadyPage.c_str());
    File->AddLine( Text);
  }
  if( m_DisableStartupPrompt != bool2string(true))
  {
    Text.Printf( _T("DisableStartupPrompt           = %s"), m_DisableStartupPrompt.c_str());
    File->AddLine( Text);
  }
  if( m_DisableWelcomePage != bool2string(false))
  {
    Text.Printf( _T("DisableWelcomePage             = %s"), m_DisableWelcomePage.c_str());
    File->AddLine( Text);
  }
  if( m_EnableDirDoesntExistWarning != bool2string(false))
  {
    Text.Printf( _T("EnableDirDoesntExistWarning    = %s"), m_EnableDirDoesntExistWarning.c_str());
    File->AddLine( Text);
  }
  if( m_ExtraDiskSpaceRequired != _T("0"))
  {
    Text.Printf( _T("ExtraDiskSpaceRequired         = %s"), m_ExtraDiskSpaceRequired.c_str());
    File->AddLine( Text);
  }
  if( m_LanguageDetectionMethod != _T("uilanguage"))
  {
    Text.Printf( _T("LanguageDetectionMethod        = %s"), m_LanguageDetectionMethod.c_str());
    File->AddLine( Text);
  }
  if( m_MinVersion != _T(""))
  {
    Text.Printf( _T("MinVersion                     = %s"), m_MinVersion.c_str());
    File->AddLine( Text);
  }
  if( m_OnlyBelowVersion != _T("0,0"))
  {
    Text.Printf( _T("OnlyBelowVersion               = %s"), m_OnlyBelowVersion.c_str());
    File->AddLine( Text);
  }
  if( m_PrivilegesRequired != _T("admin"))
  {
    Text.Printf( _T("PrivilegesRequired             = %s"), m_PrivilegesRequired.c_str());
    File->AddLine( Text);
  }
  if( m_RestartIfNeededByRun != bool2string(true))
  {
    Text.Printf( _T("RestartIfNeededByRun           = %s"), m_RestartIfNeededByRun.c_str());
    File->AddLine( Text);
  }
  if( m_SetupLogging != bool2string(false))
  {
    Text.Printf( _T("SetupLogging                   = %s"), m_SetupLogging.c_str());
    File->AddLine( Text);
  }
  if( m_ShowLanguageDialog != bool2string(true))
  {
    Text.Printf( _T("ShowLanguageDialog             = %s"), m_ShowLanguageDialog.c_str());
    File->AddLine( Text);
  }
  if( m_ShowUndisplayableLanguages != bool2string(false))
  {
    Text.Printf( _T("ShowUndisplayableLanguages     = %s"), m_ShowUndisplayableLanguages.c_str());
    File->AddLine( Text);
  }
  if( m_TimeStampRounding != _T("2"))
  {
    Text.Printf( _T("TimeStampRounding              = %s"), m_TimeStampRounding.c_str());
    File->AddLine( Text);
  }
  if( m_TimeStampsInUTC != bool2string(false))
  {
    Text.Printf( _T("TimeStampsInUTC                = %s"), m_TimeStampsInUTC.c_str());
    File->AddLine( Text);
  }
  if( m_TouchDate != _T("current"))
  {
    Text.Printf( _T("TouchDate                      = %s"), m_TouchDate.c_str());
    File->AddLine( Text);
  }
  if( m_TouchTime != _T("current"))
  {
    Text.Printf( _T("TouchTime                      = %s"), m_TouchTime.c_str());
    File->AddLine( Text);
  }
  if( m_Uninstallable != bool2string(true))
  {
    Text.Printf( _T("Uninstallable                  = %s"), m_Uninstallable.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallDisplayIcon != _T(""))
  {
    Text.Printf( _T("UninstallDisplayIcon           = %s"), m_UninstallDisplayIcon.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallDisplayName != _T(""))
  {
    Text.Printf( _T("UninstallDisplayName           = %s"), m_UninstallDisplayName.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallDisplaySize != _T(""))
  {
    Text.Printf( _T("UninstallDisplaySize           = %s"), m_UninstallDisplaySize.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallFilesDir != _T("{app}"))
  {
    Text.Printf( _T("UninstallFilesDir              = %s"), m_UninstallFilesDir.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallLogMode != _T("append"))
  {
    Text.Printf( _T("UninstallLogMode               = %s"), m_UninstallLogMode.c_str());
    File->AddLine( Text);
  }
  if( m_UninstallRestartComputer != bool2string(false))
  {
    Text.Printf( _T("UninstallRestartComputer       = %s"), m_UninstallRestartComputer.c_str());
    File->AddLine( Text);
  }
  if( m_UpdateUninstallLogAppName != bool2string(true))
  {
    Text.Printf( _T("UpdateUninstallLogAppName      = %s"), m_UpdateUninstallLogAppName.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousAppDir != bool2string(true))
  {
    Text.Printf( _T("UsePreviousAppDir              = %s"), m_UsePreviousAppDir.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousGroup != bool2string(true))
  {
    Text.Printf( _T("UsePreviousGroup               = %s"), m_UsePreviousGroup.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousLanguage != bool2string(true))
  {
    Text.Printf( _T("UsePreviousLanguage            = %s"), m_UsePreviousLanguage.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousSetupType != bool2string(true))
  {
    Text.Printf( _T("UsePreviousSetupType           = %s"), m_UsePreviousSetupType.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousTasks != bool2string(true))
  {
    Text.Printf( _T("UsePreviousTasks               = %s"), m_UsePreviousTasks.c_str());
    File->AddLine( Text);
  }
  if( m_UsePreviousUserInfo != bool2string(true))
  {
    Text.Printf( _T("UsePreviousUserInfo            = %s"), m_UsePreviousUserInfo.c_str());
    File->AddLine( Text);
  }
  if( m_UserInfoPage != bool2string(false))
  {
    Text.Printf( _T("UserInfoPage                   = %s"), m_UserInfoPage.c_str());
    File->AddLine( Text);
  }
  if( m_AppCopyright != _T(""))
  {
    Text.Printf( _T("AppCopyright                   = %s"), m_AppCopyright.c_str());
    File->AddLine( Text);
  }
  if( m_BackColor != backColor[12])
  {
    Text.Printf( _T("BackColor                      = %s"), m_BackColor.c_str());
    File->AddLine( Text);
  }
  if( m_BackColor2 != backColor2[0])
  {
    Text.Printf( _T("BackColor2                     = %s"), m_BackColor2.c_str());
    File->AddLine( Text);
  }
  if( m_BackColorDirection != _T("toptobottom"))
  {
    Text.Printf( _T("BackColorDirection             = %s"), m_BackColorDirection.c_str());
    File->AddLine( Text);
  }
  if( m_BackSolid != bool2string(false))
  {
    Text.Printf( _T("BackSolid                      = %s"), m_BackSolid.c_str());
    File->AddLine( Text);
  }
  if( m_FlatComponentsList != bool2string(true))
  {
    Text.Printf( _T("FlatComponentsList             = %s"), m_FlatComponentsList.c_str());
    File->AddLine( Text);
  }
  if( m_ShowComponentSizes != bool2string(true))
  {
    Text.Printf( _T("ShowComponentSizes             = %s"), m_ShowComponentSizes.c_str());
    File->AddLine( Text);
  }
  if( m_ShowTasksTreeLines != bool2string(false))
  {
    Text.Printf( _T("ShowTasksTreeLines             = %s"), m_ShowTasksTreeLines.c_str());
    File->AddLine( Text);
  }
  if( m_WindowShowCaption != bool2string(true))
  {
    Text.Printf( _T("WindowShowCaption              = %s"), m_WindowShowCaption.c_str());
    File->AddLine( Text);
  }
  if( m_WindowStartMaximized != bool2string(true))
  {
    Text.Printf( _T("WindowStartMaximized           = %s"), m_WindowStartMaximized.c_str());
    File->AddLine( Text);
  }
  if( m_WindowResizable != bool2string(true))
  {
    Text.Printf( _T("WindowResizable                = %s"), m_WindowResizable.c_str());
    File->AddLine( Text);
  }
  if( m_WindowVisible != bool2string(false))
  {
    Text.Printf( _T("WindowVisible                  = %s"), m_WindowVisible.c_str());
    File->AddLine( Text);
  }
  if( m_WizardImageBackColor != _T("$400000"))
  {
    Text.Printf( _T("WizardImageBackColor           = %s"), m_WizardImageBackColor.c_str());
    File->AddLine( Text);
  }
  if( m_WizardImageFile != _T("compiler:WIZMODERNIMAGE.BMP"))
  {
    Text.Printf( _T("WizardImageFile                = %s"), m_WizardImageFile.c_str());
    File->AddLine( Text);
  }
  if( m_WizardImageStretch != bool2string(true))
  {
    Text.Printf( _T("WizardImageStretch             = %s"), m_WizardImageStretch.c_str());
    File->AddLine( Text);
  }
  if( m_WizardSmallImageFile != _T("compiler:WIZMODERNSMALLIMAGE.BMP "))
  {
    Text.Printf( _T("WizardSmallImageFile           = %s"), m_WizardSmallImageFile.c_str());
    File->AddLine( Text);
  }
}

void CSetup::Set( wxString AppName, wxString AppVersion)
{
  m_Compression                     = compression[14];
  m_CompressionThreads              = _T("auto");
  m_DiskClusterSize                 = _T("512");
  m_DiskSliceSize                   = _T("max");
  m_DiskSpanning                    = bool2string(false);
  m_Encryption                      = bool2string(false);
  m_InternalCompressLevel           = _T("normal");
  m_MergeDuplicateFiles             = bool2string(true);
  m_OutputBaseFilename              = _T("setup");
  m_OutputDir                       = _T("Output");
  m_OutputManifestFile              = _T("");
  m_ReserveBytes                    = _T("0");
  m_SignedUninstallerDir            =  m_OutputDir;
  m_SignTool                        = _T("no");
  m_SlicesPerDisk                   = _T("1");
  m_SolidCompression                = bool2string(false);
  m_SourceDir                       = _T("");
  m_TerminalServicesAware           = bool2string(true);
  m_UseSetupLdr                     = bool2string(true);
  m_AllowCancelDuringInstall        = bool2string(true);
  m_AllowNoIcons                    = bool2string(false);
  m_AllowRootDirectory              = bool2string(false);
  m_AllowUNCPath                    = bool2string(true);
  m_AlwaysRestart                   = bool2string(false);
  m_AlwaysShowComponentsList        = bool2string(true);
  m_AlwaysShowDirOnReadyPage        = bool2string(false);
  m_AlwaysShowGroupOnReadyPage      = bool2string(false);
  m_AlwaysUsePersonalGroup          = bool2string(false);
  m_AppendDefaultDirName            = bool2string(true);
  m_AppendDefaultGroupName          = bool2string(true);
  m_AppComments                     = _T("");
  m_AppContact                      = _T("");
  m_AppModifyPath                   = _T("");
  m_AppMutex                        = _T("");
  m_AppName                         = AppName;
  m_AppPublisher                    = _T("");
  m_AppPublisherURL                 = _T("");
  m_AppReadmeFile                   = _T("");
  m_AppSupportPhone                 = _T("");
  m_AppSupportURL                   = _T("");
  m_AppUpdatesURL                   = _T("");
  m_AppVersion                      = AppVersion;
  m_ArchitecturesAllowed            = _T("");
  m_ArchitecturesInstallIn64BitMode = _T("");
  m_ChangesAssociations             = bool2string(false);
  m_ChangesEnvironment              = bool2string(false);
  m_CreateAppDir                    = bool2string(true);
  m_CreateUninstallRegKey           = bool2string(true);
  m_DefaultDialogFontName           = _T("Tahoma");
  m_DefaultGroupName                = _T("");
  m_DefaultUserInfoName             = _T("{sysuserinfoname}");
  m_DefaultUserInfoOrg              = _T("{sysuserinfoorg}");
  m_DefaultUserInfoSerial           = _T("");
  m_DirExistsWarning                = _T("auto");
  m_DisableDirPage                  = bool2string(false);
  m_DisableFinishedPage             = bool2string(false);
  m_DisableProgramGroupPage         = bool2string(false);
  m_DisableReadyMemo                = bool2string(false);
  m_DisableReadyPage                = bool2string(false);
  m_DisableStartupPrompt            = bool2string(true);
  m_DisableWelcomePage              = bool2string(false);
  m_EnableDirDoesntExistWarning     = bool2string(false);
  m_ExtraDiskSpaceRequired          = _T("0");
  m_InfoAfterFile                   = _T("");
  m_InfoBeforeFile                  = _T("");
  m_LanguageDetectionMethod         = _T("uilanguage");
  m_LicenseFile                     = _T("");
  m_MinVersion                      = _T("");
  m_OnlyBelowVersion                = _T("0,0");
  m_Password                        = _T("");
  m_PrivilegesRequired              = _T("admin");
  m_RestartIfNeededByRun            = bool2string(true);
  m_SetupLogging                    = bool2string(false);
  m_ShowLanguageDialog              = bool2string(true);
  m_ShowUndisplayableLanguages      = bool2string(false);
  m_TimeStampRounding               = _T("2");
  m_TimeStampsInUTC                 = bool2string(false);
  m_TouchDate                       = _T("current");
  m_TouchTime                       = _T("current");
  m_Uninstallable                   = bool2string(true);
  m_UninstallDisplayIcon            = _T("");
  m_UninstallDisplayName            = _T("");
  m_UninstallDisplaySize            = _T("");
  m_UninstallFilesDir               = _T("{app}");
  m_UninstallLogMode                = _T("append");
  m_UninstallRestartComputer        = bool2string(false);
  m_UpdateUninstallLogAppName       = bool2string(true);
  m_UsePreviousAppDir               = bool2string(true);
  m_UsePreviousGroup                = bool2string(true);
  m_UsePreviousLanguage             = bool2string(true);
  m_UsePreviousSetupType            = bool2string(true);
  m_UsePreviousTasks                = bool2string(true);
  m_UsePreviousUserInfo             = bool2string(true);
  m_UserInfoPage                    = bool2string(false);
  m_AppCopyright                    = _T("");
  m_BackColor                       = backColor[12];
  m_BackColor2                      = backColor2[0];
  m_BackColorDirection              = _T("toptobottom");
  m_BackSolid                       = bool2string(false);
  m_FlatComponentsList              = bool2string(true);
  m_SetupIconFile                   = _T("");
  m_ShowComponentSizes              = bool2string(true);
  m_ShowTasksTreeLines              = bool2string(false);
  m_WindowShowCaption               = bool2string(true);
  m_WindowStartMaximized            = bool2string(true);
  m_WindowResizable                 = bool2string(true);
  m_WindowVisible                   = bool2string(false);
  m_WizardImageBackColor            = _T("$400000");
  m_WizardImageFile                 = _T("compiler:WIZMODERNIMAGE.BMP");
  m_WizardImageStretch              = bool2string(true);
  m_WizardSmallImageFile            = _T("compiler:WIZMODERNSMALLIMAGE.BMP ");
  m_AppId                           = m_AppName;
  m_AppVerName                      = m_AppName + _T(" version ") + AppVersion;
  m_DefaultDirName                  = _T("");
}

void CSetup::SetOutput( wxString outputBaseFilename, wxString outputDir)
{
  m_OutputBaseFilename = outputBaseFilename;
  m_OutputDir          = outputDir;
}

void CSetup::SetCompression( wxString compression, wxString compressionThreads)
{
  m_Compression        = compression;
  m_CompressionThreads = compressionThreads;
}

void CSetup::SetSolidCompression( bool solid)
{

  m_SolidCompression = bool2string( solid);
}

void CSetup::SetGroupName( wxString groupName)
{
  m_DefaultGroupName = groupName;
}

void CSetup::SetPrivileges( wxString privilegesRequired)
{
  m_PrivilegesRequired = privilegesRequired;
}

void CSetup::SetChangeAssociations( bool change)
{
  m_ChangesAssociations = bool2string( change);
}

void CSetup::SetAlwaysUsePersonalGroup( bool Always)
{
  m_AlwaysUsePersonalGroup = bool2string( Always);
}

void CSetup::SetPublisher( wxString publisher)
{
  m_AppPublisher = publisher;
}

void CSetup::SetWebseite( wxString webseite)
{
  m_AppPublisherURL = webseite;
  m_AppSupportURL = webseite;
  m_AppUpdatesURL = webseite;
}

void CSetup::SetDefaultDirName( wxString dirName)
{
  m_DefaultDirName = dirName;
}

void CSetup::SetDisableDirPage( bool disable)
{
  m_DisableDirPage = bool2string(disable);
}

void CSetup::SetCreateAppDir( bool create)
{
  m_CreateAppDir = bool2string( create);
}

void CSetup::SetAllowNoIcons( bool allow)
{
  m_AllowNoIcons = bool2string(allow);
}

void CSetup::SetLicenseFile( wxString license)
{
  m_LicenseFile = license;
}

void CSetup::SetInfoBefor( wxString info)
{
  m_InfoBeforeFile = info;
}

void CSetup::SetInfoAfter( wxString info)
{
  m_InfoAfterFile = info;
}

void CSetup::SetIconFile( wxString icon)
{
  m_SetupIconFile = icon;
}

void CSetup::SetPassword( wxString pass)
{
  m_Password = pass;
}

void CSetup::SetAppVerName( wxString name)
{
  m_AppVerName = name;
}

void CSetup::SetAppId( )
{
  unsigned char *pszUuid = 0;
  GUID           guid ;
  memset (&guid, '\0', sizeof (guid)) ;
  if (CoCreateGuid (&guid) == S_OK)
  {

    if (UuidToStringA(&guid, &pszUuid) == RPC_S_OK)
    {
      wchar_t GuidString[37];
      MultiByteToWideChar(CP_ACP, 0, (const char*)pszUuid, -1, GuidString, sizeof(GuidString) / sizeof(wchar_t));
      m_AppId = _T("{{");
      m_AppId += GuidString;
      m_AppId += _T("}");
      m_AppId = m_AppId.Upper();
      RpcStringFreeA(&pszUuid);
    }
  }
}

wxString CSetup::GetAppName( void)
{
  return m_AppName;
}

wxString CSetup::GetAppVersion( void)
{
  return m_AppVersion;
}

wxString CSetup::GetPublisherURL( void)
{
  return m_AppPublisherURL;
}
