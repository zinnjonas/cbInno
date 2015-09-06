#include "Consume.h"

#include <manager.h>
#include <logmanager.h>

Consume::Consume(wxInputStream* out,int log) : wxThread(wxTHREAD_DETACHED)
{
  m_out = out;
  m_log = log;
  Create();
}

wxThread::ExitCode Consume::Entry()
{
  while(!TestDestroy())
  {
    wxString text;
    while( m_out->CanRead())
    {
      int c = m_out->GetC();
      if( c == '\n')
      {
        Manager::Get()->GetLogManager()->Log(text, m_log);
        text.clear();
      }
      else
        text += c;
    }
    if( !text.empty())
    {
      Manager::Get()->GetLogManager()->Log(text, m_log);
    }
  }

  return (ExitCode)0;
}
