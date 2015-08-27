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

void CComment::AddContent(wxListCtrl* liste, int index)
{
  liste->SetItem(index, 1, m_Comment);
  wxListItem comment;
  comment.m_itemId = index;
  EditorColourSet* cset = Manager::Get()->GetEditorManager()->GetColourSet();
  HighlightLanguage ln = cset->GetHighlightLanguage(wxSCI_LEX_INNOSETUP);
  comment.SetTextColour(cset->GetOptionByIndex(ln, 1)->fore);
  comment.SetBackgroundColour(cset->GetOptionByIndex(ln, 1)->back);
  liste->SetItem(comment);
}
