/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Tue May 18 18:24:39 2010 dimitri jorge
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "my_readline.h"
#include "auto_complete.h"

int			calc_longest_word_list(t_list *st_list)
{
  int			longest_size;

  longest_size = 1;
  while (st_list != NULL)
    {
      if (my_strlen(st_list->data) > longest_size)
	longest_size = my_strlen(st_list->data);
      st_list = st_list->previous;
    }
  return (longest_size);
}

int			how_much_column(int longest_size)
{
  struct winsize	shell_size;
  int			column_number;

  column_number = 0;
  longest_size += MORE_SPACE + 5;
  if (ioctl(0, TIOCGWINSZ, &shell_size) < 0)
    perror("error in ioctl in how_much_column :");
  if (!(column_number = (shell_size.ws_col / longest_size)))
    return (1);
  return (column_number);
}

int			how_much_line(int arg_nb, int column_number)
{
  struct winsize	shell_size;
  int			line_number;

  line_number = 0;
  if (ioctl(0, TIOCGWINSZ, &shell_size) < 0)
    perror("error in ioctl in how_much_line : ");
  if (column_number != 0)
    line_number = (arg_nb - 1) / column_number;
  if (shell_size.ws_row < column_number)
    perror("Shell row = too small : ");
  return (line_number);
}
