#ifndef CONSUME_H_
#define CONSUME_H_

#include <wx/thread.h>
#include <wx/stream.h>
#include <loggers.h>

class Consume : public wxThread
{
  public:
    Consume(wxInputStream* out, int log);

  protected:

    virtual ExitCode Entry();
    wxInputStream* m_out;
    int m_log;
};

#endif // header guard

