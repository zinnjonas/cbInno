#ifndef CRUN_H
#define CRUN_H

#include "Comment.h"
#include "Common.h"
#include "Comptask.h"

class CRun : public CComment, public CCommon, public CCompTask
{
  public:

    CRun( void);
    virtual ~CRun();


    void SetFilename(wxString val);
    void SetDescription(wxString val);
    void SetParameters(wxString val);
    void SetWorkingDir(wxString val);
    void SetStatusMsg(wxString val);
    void SetRunOnceId(wxString val);
    void SetVerb(wxString val);
    void SetFlags(wxString val);

    static const wxString Flags[];

    void Analize( const wxString& content, const wxString& line);

    void FillContent(wxListCtrl* liste);

    static void AddHeader(wxListCtrl* liste);

    void WriteInFile( wxTextFile* File);

  private:
    wxString m_Filename;
    wxString m_Description;
    wxString m_Parameters;
    wxString m_WorkingDir;
    wxString m_StatusMsg;
    wxString m_RunOnceId;
    wxString m_Verb;
    wxString m_Flags;

    static int m_index_name;
    static int m_index_desc;
    static int m_index_para;
    static int m_index_work;
    static int m_index_msg;
    static int m_index_run;
    static int m_index_verb;
    static int m_index_flags;
};

#endif // CRUN_H
