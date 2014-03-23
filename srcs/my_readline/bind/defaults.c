/*
** defaults.c for Default Bind list in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu May  6 15:50:41 2010 julien di-marco
** Last update Thu May 20 16:53:33 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"

t_defb		def_db[] = {
  {" ", "~", "self-insert", DEFAULT},
  {"^A", NULL, "beginning-of-line", DEFAULT},
  {"^[[H", NULL, "beginning-of-line", DEFAULT},
  {"^[OH", NULL, "beginning-of-line", DEFAULT},
  {"^E", NULL, "end-of-line", DEFAULT},
  {"^[[F", NULL, "end-of-line", DEFAULT},
  {"^[OF", NULL, "end-of-line", DEFAULT},
  {"^O", NULL, "overwrite-mode", DEFAULT},
  {"^L", NULL, "clear-screen", DEFAULT},
  {"^[[2~", NULL, "overwrite-mode", DEFAULT},
  {"^[[D", NULL, "backward-char", DEFAULT},
  {"^[[C", NULL, "forward-char", DEFAULT},
  {"^j", NULL, "accept-line", DEFAULT},
  {"^H", NULL, "backward-delete-char", DEFAULT},
  {"^D", NULL, "delete-char-or-list-or-eof", DEFAULT},
  {"^[[3~", NULL, "backward-delete-char", DEFAULT},
  {{'\t', '\0'}, NULL, "complete-word", DEFAULT},
  {{127, '\0'}, NULL, "backward-delete-char", DEFAULT},
  {"^N", NULL, "down-line-or-history", DEFAULT},
  {"^P", NULL, "up-line-or-history", DEFAULT},
  {"^C", NULL, "clear-line", DEFAULT},
  {"^[[A", NULL, "up-line-or-history", DEFAULT},
  {"^[[B", NULL, "down-line-or-history", DEFAULT},
  {{0}, NULL, NULL, 0},
};

int		default_database(t_rl *base)
{
  int		i;
  int		out;

  i = 0;
  out = EXIT_SUCCESS;
  while (def_db[i].key && def_db[i].name && def_db[i].flags)
    {
      out = bind_key(def_db[i].key, def_db[i].key2, \
		     def_db[i].name, &base->bind);
      i++;
    }
  return (out);
}
