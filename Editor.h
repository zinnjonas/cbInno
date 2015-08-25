#ifndef EDITOR_H_
#define EDITOR_H_

#include <manager.h>
#include <cbeditor.h>
#include <editormanager.h>
#include <cbauibook.h>

#include <wx/string.h>
#include "InnoEditor.h"

class CEditor
{
  public:

    CEditor();
    CEditor(const wxString& file);
    virtual ~CEditor();

  protected:

    InnoEditor* m_editor;

};

#endif // EDITOR_H_

