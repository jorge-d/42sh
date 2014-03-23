/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
**
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
**
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Sat May 22 14:28:23 2010 fares sabbagh
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"
#include "auto_complete.h"
#include "set_environ.h"

static char	**tab_malloc(char **table, char *str, int nb)
{
  if (!(table = xcalloc((nb + 1), sizeof(*table))))
    return (NULL);
  while (nb >= 0)
    if (!(table[nb--] = xcalloc((my_strlen(str) + 1), sizeof(*table))))
      return (NULL);
  return (table);
}

static int	value_counter(char *str)
{
  int		i;
  int		value_number;

  i = 0;
  value_number = 0;
  while (str && str[i])
    {
      if (str[i] != ':')
        {
          value_number++;
          while (str[i] && str[i] != ':')
            i++;
          i--;
        }
      i++;
    }
  return (value_number);
}

static char	**_val_to_tab(char *str)
{
  int		i;
  int		j;
  int		value_nbr;
  char		**table;

  table = NULL;
  i = 0;
  j = 0;
  value_nbr = value_counter(str);
  if (!str || !(table = tab_malloc(table, str, value_nbr)))
    return (NULL);
  while (*str)
    {
      table[i][j++] = *str++;
      if (*str == ':' || *str == '\0')
        {
          table[i][j++] = '/';
          table[i++][j] = '\0';
          j = 0;
          if (*str == ':')
            str++;
        }
    }
  table[i] = NULL;
  return (table);
}

int		builtin_completion(char *command, t_list **st_list)
{
  struct dirent	*d;
  DIR		*directory;
  int		count_2;
  char		**table;
  char		*path;

  count_2 = 0;
  table = NULL;
  d = NULL;
  directory = NULL;
  if ((!(path = get_env_from_list("PATH")) &&
       !(path = get_set_from_list("PATH"))) || !(table = _val_to_tab(path)))
    return (FATAL_ERROR);
  while (table && table[count_2])
    {
      directory = opendir(table[count_2]);
      if (directory)
	while ((d = readdir(directory)))
	  if (strncmp(command, d->d_name, strlen(command)) == 0)
	    put_in_list(d->d_name, st_list, 0);
      xclosedir(directory);
      count_2++;
    }
  free_table(table);
  return (1);
}
