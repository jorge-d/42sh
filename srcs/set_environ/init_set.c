/*
** init_set.c for dsf in /u/all/strzel_a/svn/42shsvn/trunk
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Tue May 11 15:27:36 2010 alexandre strzelewicz
** Last update Thu May 20 17:22:24 2010 julien di-marco
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"
#include "set_environ.h"

t_defvar	set_var[] = {
  {{"DEFAULT", "CONF_FILE", CONF_FILE_PATH}},
  {{"DEFAULT", "PROMPT", DEFAULT_PROMPT}},
  {{"DEFAULT", "HISTSIZE", DEFAULT_HISTSIZE}},
  {{"DEFAULT", "HISTFILE", HIST_FILE_PATH}},
  {{"DEFAULT", "HIST_DOUBLOON", D_HIST_DOUBLOON}},
  {{"DEFAULT", "HREACT_DISP", DEFAULT_HREACT}},
  {{"DEFAULT", "HREACT_OPT", DEFAULT_OPT_HREACT}},
  {{"DEFAULT", COMPLETION_STATE_STR, "1"}},
  {{"DEFAULT", COMPLETION_CHOICE_STR, "1"}},
  {{"DEFAULT", "COMPLETION_BIN", "1"}},
  {{"DEFAULT", "COMPLETION_ALIAS", "1"}},
  {{"DEFAULT", "COMPLETION_SET", "1"}},
  {{NULL, NULL, NULL}},
  };

int		fill_default_set_environ(void)
{
  int		i;

  i = 0;
  while (set_var[i].name[0])
    set_new(set_var[i++].name, NULL);
  return (RT_SUCCESS);
}
