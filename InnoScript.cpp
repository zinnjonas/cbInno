#include "InnoScript.h"

#include <wx/sstream.h>
#include <wx/txtstrm.h>

InnoScript::InnoScript()
{
  //ctor
  m_part = SCRIPT;
}

InnoScript::~InnoScript()
{
  //dtor
}

void InnoScript::Read(const wxString& content)
{

  m_files.clear();

  wxStringInputStream stream(content);
  wxTextInputStream input(stream);

	int line = 0;
	while( !stream.Eof())
	{
		Analize(input.ReadLine(), wxString::Format(_T("%d"), ++line));
	}

	m_part = SCRIPT;
}

void InnoScript::Analize(const wxString& content, const wxString& line)
{
  wxString cont = content.BeforeFirst(';');
  cont = cont.Trim();
  if( !content.empty() && !cont.empty())
  {
    if( content.StartsWith(_T("#"), &cont))
    {
      AnalizePreprocessor(cont);
    }
    else if(content.StartsWith(_T("["), &cont))
    {
      cont = cont.BeforeLast(']');
      AnalizeSection(cont, line);
    }
    else
    {
      if( m_part == FILES)
      {
        CFiles file;
				file.Analize(content, line);
				m_files.push_back(file);
      }
      else if( m_part == FOLDERS)
      {
        CDirs dir;
        dir.Analize(content, line);
        m_dirs.push_back(dir);
      }
      else if( m_part == ICONS)
      {
        CIcons icon;
        icon.Analize(content, line);
        m_icons.push_back(icon);
      }
      else if( m_part == INI)
      {
        CIni ini;
        ini.Analize(content, line);
        m_ini.push_back(ini);
      }
      else if( m_part == TASKS)
      {
        CTasks task;
        task.Analize(content, line);
        m_tasks.push_back(task);
      }
      else if( m_part == REGISTRY)
      {
        CRegistry reg;
        reg.Analize(content, line);
        m_registry.push_back(reg);
      }
      else if( m_part == LANGUAGES)
      {
        CLanguages lang;
        lang.Analize(content, line);
        m_languages.push_back(lang);
      }
      else if( m_part == TYPES)
      {
        CTypes types;
        types.Analize(content, line);
        m_types.push_back(types);
      }
      else if( m_part == COMPONENTS)
      {
        CComponents comp;
        comp.Analize(content, line);
        m_components.push_back(comp);
      }
      else if( m_part == MESSAGES)
      {
        CMessages msg;
        msg.Analize(content, line);
        m_messages.push_back(msg);
      }
      else if( m_part == CMESSAGES)
      {
        CCustomMessages msg;
        msg.Analize(content, line);
        m_cmessages.push_back(msg);
      }
      else if( m_part == RUN)
      {
        CRun run;
        run.Analize(content, line);
        m_runs.push_back(run);
      }
      else if( m_part == INSTALLDEL)
      {
        CInstallDelete inst;
        inst.Analize(content, line);
        m_instal_del.push_back(inst);
      }
      else if( m_part == UNINSTALLDEL)
      {
        CUninstallDelete inst;
        inst.Analize(content, line);
        m_uninstal_del.push_back(inst);
      }
      else if( m_part == UNINSTALL)
      {
        CRun inst;
        inst.Analize(content, line);
        m_uninstal_run.push_back(inst);
      }
    }
  }
  else if( !content.empty())
  {
  	if( m_part == FILES)
		{
			CFiles comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_files.push_back(comment);
		}
		else if( m_part == FOLDERS)
		{
			CDirs comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_dirs.push_back(comment);
		}
		else if( m_part == ICONS)
		{
			CIcons comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_icons.push_back(comment);
		}
		else if( m_part == INI)
		{
			CIni comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_ini.push_back(comment);
		}
		else if( m_part == TASKS)
		{
			CTasks comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_tasks.push_back(comment);
		}
		else if( m_part == REGISTRY)
		{
			CRegistry comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_registry.push_back(comment);
		}
		else if( m_part == LANGUAGES)
		{
			CLanguages comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_languages.push_back(comment);
		}
		else if( m_part == TYPES)
		{
			CTypes comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_types.push_back(comment);
		}
		else if( m_part == COMPONENTS)
		{
			CComponents comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_components.push_back(comment);
		}
		else if( m_part == MESSAGES)
		{
			CMessages comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_messages.push_back(comment);
		}
		else if( m_part == CMESSAGES)
		{
			CCustomMessages comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_cmessages.push_back(comment);
		}
		else if( m_part == RUN)
		{
			CRun comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_runs.push_back(comment);
		}
		else if( m_part == UNINSTALL)
		{
			CRun comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_uninstal_run.push_back(comment);
		}
		else if( m_part == INSTALLDEL)
		{
			CInstallDelete comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_instal_del.push_back(comment);
		}
		else if( m_part == UNINSTALLDEL)
		{
			CUninstallDelete comment;
			comment.SetLinenumber(line);
			comment.SetComment(content);
			m_uninstal_del.push_back(comment);
		}
  }
}

void InnoScript::AnalizePreprocessor(const wxString& content)
{
	wxString con;
	if( content.StartsWith(_T("include"), &con))
	{
	}
	else if( content.StartsWith(_T("define"), &con))
	{
	}
	else if( content.StartsWith(_T("undef"), &con))
	{
	}
	else if( content.StartsWith(_T("file"), &con))
	{
	}
	else if( content.StartsWith(_T("emit"), &con))
	{
	}
	else if( content.StartsWith(_T("expr"), &con))
	{
	}
	else if( content.StartsWith(_T("insert"), &con))
	{
	}
	else if( content.StartsWith(_T("append"), &con))
	{
	}
	else if( content.StartsWith(_T("for"), &con))
	{
	}
	else if( content.StartsWith(_T("pragma"), &con))
	{
	}
	else if( content.StartsWith(_T("error"), &con))
	{
	}
}

void InnoScript::AnalizeSection(const wxString& content, const wxString& line)
{
	if( content.CmpNoCase(_T("setup")) == 0)
		m_part = SETUP;
	else if( content.CmpNoCase(_T("types")) == 0)
		m_part = TYPES;
	else if( content.CmpNoCase(_T("components")) == 0)
		m_part = COMPONENTS;
	else if( content.CmpNoCase(_T("tasks")) == 0)
		m_part = TASKS;
	else if( content.CmpNoCase(_T("dirs")) == 0)
		m_part = FOLDERS;
	else if( content.CmpNoCase(_T("files")) == 0)
		m_part = FILES;
	else if( content.CmpNoCase(_T("icons")) == 0)
		m_part = ICONS;
	else if( content.CmpNoCase(_T("ini")) == 0)
		m_part = INI;
	else if( content.CmpNoCase(_T("installdelete")) == 0)
		m_part = INSTALLDEL;
	else if( content.CmpNoCase(_T("languages")) == 0)
		m_part = LANGUAGES;
	else if( content.CmpNoCase(_T("messages")) == 0)
		m_part = MESSAGES;
	else if( content.CmpNoCase(_T("custommessages")) == 0)
		m_part = CMESSAGES;
	else if( content.CmpNoCase(_T("langoptions")) == 0)
		m_part = LANGOPT;
	else if( content.CmpNoCase(_T("registry")) == 0)
		m_part = REGISTRY;
	else if( content.CmpNoCase(_T("run")) == 0)
		m_part = RUN;
	else if( content.CmpNoCase(_T("uninstalldelete")) == 0)
		m_part = UNINSTALLDEL;
	else if( content.CmpNoCase(_T("uninstallrun")) == 0)
		m_part = UNINSTALL;
	else if( content.CmpNoCase(_T("code")) == 0)
		m_part = PASCALCODE;
	else
		m_part = SCRIPT;
}

void InnoScript::Write(wxString filename)
{
  wxTextFile* textFile = new wxTextFile();
  textFile->Create(filename);

  if( m_files.size())
  {
    textFile->AddLine(wxT("[Files]"));
    for(CFiles file : m_files)
      file.Write(textFile);
    textFile->AddLine(wxT(""));
  }

  textFile->Close();
}

void InnoScript::Show(wxListCtrl* liste, const InnoPart& part)
{
  switch(part)
  {
    case SCRIPT:
    default:
    break;

    case FILES:
      CFiles::AddHeader(liste);
      for(CFiles file : m_files)
        file.AddContent(liste);
    break;

    case FOLDERS:
      CDirs::AddHeader(liste);
      for(CDirs folder : m_dirs)
        folder.AddContent(liste);
    break;

    case ICONS:
      CIcons::AddHeader(liste);
      for(CIcons icon : m_icons)
        icon.AddContent(liste);
    break;

    case INI:
      CIni::AddHeader(liste);
      for(CIni ini : m_ini)
        ini.AddContent(liste);
    break;

    case TASKS:
      CTasks::AddHeader(liste);
      for(CTasks task : m_tasks)
        task.AddContent(liste);
    break;

    case REGISTRY:
      CRegistry::AddHeader(liste);
      for(CRegistry reg : m_registry)
        reg.AddContent(liste);
    break;

    case LANGUAGES:
      CLanguages::AddHeader(liste);
      for(CLanguages lang : m_languages)
        lang.AddContent(liste);
    break;

    case TYPES:
      CTypes::AddHeader(liste);
      for(CTypes type : m_types)
        type.AddContent(liste);
    break;

    case COMPONENTS:
      CComponents::AddHeader(liste);
      for(CComponents comp : m_components)
        comp.AddContent(liste);
    break;

    case MESSAGES:
      CMessages::AddHeader(liste);
      for(CMessages msg : m_messages)
        msg.AddContent(liste);
    break;

    case CMESSAGES:
      CCustomMessages::AddHeader(liste);
      for(CCustomMessages msg : m_cmessages)
        msg.AddContent(liste);
    break;

    case RUN:
      CRun::AddHeader(liste);
      for(CRun run : m_runs)
        run.AddContent(liste);
    break;

    case UNINSTALL:
      CRun::AddHeader(liste);
      for(CRun run : m_uninstal_run)
        run.AddContent(liste);
    break;

    case INSTALLDEL:
      CInstallDelete::AddHeader(liste);
      for(CInstallDelete inst : m_instal_del)
        inst.AddContent(liste);
    break;

    case UNINSTALLDEL:
      CUninstallDelete::AddHeader(liste);
      for(CUninstallDelete inst : m_uninstal_del)
        inst.AddContent(liste);
    break;
  }
}
