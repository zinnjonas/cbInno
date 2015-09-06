#include "Editor.h"

CEditor::CEditor()
{
  m_editor = new InnoEditor(Manager::Get()->GetEditorManager()->GetNotebook(), _T("test.iss"), -1);
  Manager::Get()->GetEditorManager()->SetActiveEditor(m_editor);
}

CEditor::CEditor( const wxString& file, int log)
{
  wxFileName fn(realpath(file));
  wxString fname = UnixFilename(fn.GetFullPath());

  m_editor = new InnoEditor(Manager::Get()->GetEditorManager()->GetNotebook(), file, log);
  Manager::Get()->GetEditorManager()->SetActiveEditor(m_editor);
}

CEditor::~CEditor()
{

}
