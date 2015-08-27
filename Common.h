#ifndef COMMON_H_
#define COMMON_H_

#include <wx/string.h>
#include <wx/listctrl.h>

class CCommon
{
  public:

    CCommon();
    virtual ~CCommon();

    void SetLanguages(wxString lang);
    void SetMinVersion(wxString version);
    void SetOnlyBelowVersion(wxString version);

    bool HasLanguages();
    bool HasMinVersion();
    bool HasOnlyBelowVersion();

    wxString GetLanguages();
    wxString GetMinVersion();
    wxString GetOnlyBelowVersion();

    void AddText( wxString& text);

    bool Analize(const wxString& part, const wxString& settings);

    void AddContent(wxListCtrl* liste, int index);

    static void AddHeader(wxListCtrl* liste);

  protected:

  private:

    wxString m_Languages;
    wxString m_MinVersion;
    wxString m_OnlyBelow;

    static int m_index_lang;
    static int m_index_min;
    static int m_index_only;
};

#endif // header guard

