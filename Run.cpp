#include "Run.h"

int CRun::m_index_name = 0;
int CRun::m_index_desc = 0;
int CRun::m_index_para = 0;
int CRun::m_index_work = 0;
int CRun::m_index_msg  = 0;
int CRun::m_index_run  = 0;
int CRun::m_index_verb = 0;
int CRun::m_index_flags = 0;

const wxString CRun::Flags[] =
{
  wxT("32bit"),
  wxT("64bit"),
  wxT("hidewizard"),
  wxT("nowait"),
  wxT("postinstall"),
  wxT("runascurrentuser"),
  wxT("runasoriginaluser"),
  wxT("runhidden"),
  wxT("runmaximized"),
  wxT("runminimized"),
  wxT("shellexec"),
  wxT("skipifdoesntexist"),
  wxT("skipifnotsilent"),
  wxT("skipifsilent"),
  wxT("unchecked"),
  wxT("waituntilidle"),
  wxT("waituntilterminated")
};

CRun::CRun( void)
{
  //ctor
}

CRun::~CRun()
{
  //dtor
}

void CRun::WriteInFile( wxTextFile* File)
{
  if( !m_Filename.IsEmpty())
  {
    wxString Text;

    Text = _T("Filename: \"") + m_Filename + _T("\"");
    if( !m_Description.IsEmpty())
      Text += _T("; Description: \"") + m_Description + _T("\"");
    if( !m_Parameters.IsEmpty())
      Text += _T("; Parameters: \"") + m_Parameters + _T("\"");
    if( !m_WorkingDir.IsEmpty())
      Text += _T("; WorkingDir: \"") + m_WorkingDir + _T("\"");
    if( !m_StatusMsg.IsEmpty())
      Text += _T("; StatusMsg: \"") + m_StatusMsg + _T("\"");
    if( !m_RunOnceId.IsEmpty())
      Text += _T("; RunOnceId: \"") + m_RunOnceId + _T("\"");
    if( !m_Verb.IsEmpty())
      Text += _T("; Verb: \"") + m_Verb + _T("\"");
    if( !m_Flags.IsEmpty())
      Text += _T("; Flags: ") + m_Flags;

    CCommon::AddText(Text);
    CCompTask::AddText(Text);

    File->AddLine( Text);
  }
}

void CRun::SetFilename(wxString val)
{
  m_Filename = val;
}

void CRun::SetDescription(wxString val)
{
  m_Description = val;
}

void CRun::SetParameters(wxString val)
{
  m_Parameters = val;
}

void CRun::SetWorkingDir(wxString val)
{
  m_WorkingDir = val;
}

void CRun::SetStatusMsg(wxString val)
{
  m_StatusMsg = val;
}

void CRun::SetRunOnceId(wxString val)
{
  m_RunOnceId = val;
}

void CRun::SetVerb(wxString val)
{
  m_Verb = val;
}

void CRun::SetFlags(wxString val)
{
  m_Flags = val;
}

void CRun::Analize( const wxString& content, const wxString& line)
{
  wxString cont = content;
	wxString part;
	wxString settings;
  SetLinenumber(line);
	while( !cont.empty())
	{
		part = cont.BeforeFirst(':');
		settings = cont.AfterFirst(':').BeforeFirst(';');
		cont = cont.AfterFirst(';');
		part = part.Trim(false);
		settings = settings.Trim(false);
		cont = cont.Trim(false);

		if( part.CmpNoCase(_T("Filename")) == 0)
		{
			SetFilename(settings);
		}
		else if( part.CmpNoCase(_T("Description")) == 0)
		{
			SetDescription(settings);
		}
		else if( part.CmpNoCase(_T("Parameters")) == 0)
		{
			SetParameters(settings);
		}
		else if( part.CmpNoCase(_T("WorkingDir")) == 0)
		{
			SetWorkingDir(settings);
		}
		else if( part.CmpNoCase(_T("StatusMsg")) == 0)
		{
			SetStatusMsg(settings);
		}
		else if( part.CmpNoCase(_T("RunOnceId")) == 0)
		{
			SetRunOnceId(settings);
		}
		else if( part.CmpNoCase(_T("Verb")) == 0)
		{
			SetVerb(settings);
		}
		else if( part.CmpNoCase(_T("Flags")) == 0)
		{
			SetFlags(settings);
		}
		else if( !CCompTask::Analize(part, settings))
      CCommon::Analize(part, settings);
	}
}

void CRun::FillContent(wxListCtrl* liste)
{
  liste->SetItem(GetIndex(), m_index_name, m_Filename);
  liste->SetItem(GetIndex(), m_index_desc, m_Description);
  liste->SetItem(GetIndex(), m_index_para, m_Parameters);
  liste->SetItem(GetIndex(), m_index_work, m_WorkingDir);
  liste->SetItem(GetIndex(), m_index_msg, m_StatusMsg);
  liste->SetItem(GetIndex(), m_index_run, m_RunOnceId);
  liste->SetItem(GetIndex(), m_index_verb, m_Verb);
  liste->SetItem(GetIndex(), m_index_flags, m_Flags);
  CCompTask::FillContent(liste, GetIndex());
  CCommon::FillContent(liste, GetIndex());
}

void CRun::AddHeader(wxListCtrl* liste)
{
  InsertHeader(liste);
  m_index_name  = liste->InsertColumn(liste->GetColumnCount(), _T("Filename"));
  m_index_desc  = liste->InsertColumn(liste->GetColumnCount(), _T("Description"));
  m_index_para  = liste->InsertColumn(liste->GetColumnCount(), _T("Parameters"));
  m_index_work  = liste->InsertColumn(liste->GetColumnCount(), _T("WorkingDir"));
  m_index_msg   = liste->InsertColumn(liste->GetColumnCount(), _T("StatusMsg"));
  m_index_run   = liste->InsertColumn(liste->GetColumnCount(), _T("RunOnceId"));
  m_index_verb  = liste->InsertColumn(liste->GetColumnCount(), _T("Verb"));
  m_index_flags = liste->InsertColumn(liste->GetColumnCount(), _T("Flags"));
  CCommon::AddHeader(liste);
  CCompTask::AddHeader(liste);
}
