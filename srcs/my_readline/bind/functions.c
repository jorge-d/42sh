/*
** functions.c for Function Board + utils functions in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed May  5 18:26:02 2010 julien di-marco
** Last update Sat May 22 20:38:30 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

t_bind_funct	funct_list[] = {
  {"self-insert-command", self_insert_command, \
   "Insert a command to the terminal\n"},
 {"self-insert", self_insert_command, \
  "Insert a command to the terminal\n"},
 {"backward-char", backward_char, \
  "Move back a character\n"},
 {"forward-char", forward_char, \
  "Move forward one character\n"},
 {"accept-line", accept_line, \
  "Execute command\n"},
 {"newline", accept_line, \
  "Execute command\n"},
 {"backward-delete-char", backward_delete_char, \
  "Delete the character behind cursor\n"},
 {"delete-char-or-list-or-eof", delete_char_or_lt_or_eof, \
  "signal end of file\n"},
 {"complete-word", complete_word, \
   "Zsh like completion\n"},
  {"up-line-or-history", up_line_or_history, \
   "Move to previous history line\n"},
  {"up-history", up_line_or_history, \
   "Move to previous history line\n"},
  {"down-line-or-history", down_line_or_history, \
   "Move to next history line\n"},
  {"down-history", down_line_or_history, \
   "Move to next history line\n"},
  {"beginning-of-line", beginning_of_line, \
   "Move to beginning of line\n"},
  {"end-of-line", end_of_line, \
   "Move cursor to end of line\n"},
  {"overwrite-mode", overwrite_mode, \
   "Toggle between overwrite mode and insert mode.\n"},
  {"clear-line", clear_line, \
   "Clear screen leaving the prompt.\n"},
  {"clear-screen", clear_it, \
   "Clear screen leaving current line on top\n"},
  {NULL, NULL, NULL},
};

int		show_funcs()
{
  int		i;

  i = -1;
  while (funct_list[++i].name)
    printf("%s\n\t%s", funct_list[i].name, funct_list[i].comment);
  return (EXIT_SUCCESS);
}

void		*get_func(char *name)
{
  int		i;

  i = 0;
  if (name)
    {
      while (funct_list[i].name)
	{
	  if (!strcmp(funct_list[i].name, name))
	    return (&funct_list[i]);
	  else
	    i++;
	}
    }
  fprintf(stderr, E_NOFUNC);
  return (NULL);
}


