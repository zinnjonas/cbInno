#include "Comment.h"

#include <manager.h>
#include <configmanager.h>
#include <editormanager.h>
#include <editorcolourset.h>

CComment::CComment()
{
  //ctor
}

CComment::~CComment()
{
  //dtor
}

void CComment::AddContent(wxListCtrl* liste)
{
  InsertContent(liste);
  if( IsComment())
  {
    liste->SetItem(GetIndex(), 1, m_Comment);
    wxListItem comment;
    comment.m_itemId = GetIndex();
    EditorColourSet* cset = Manager::Get()->GetEditorManager()->GetColourSet();
    HighlightLanguage ln = cset->GetHighlightLanguage(wxSCI_LEX_INNOSETUP);
    comment.SetTextColour(cset->GetOptionByIndex(ln, 1)->fore);
    comment.SetBackgroundColour(cset->GetOptionByIndex(ln, 1)->back);
    liste->SetItem(comment);
  }
  else
    FillContent(liste);
}

void CComment::Write(wxTextFile* File)
{
  if( IsComment())
  {
    File->AddLine(m_Comment);
  }
  else
    WriteInFile(File);
}
