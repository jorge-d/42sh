/*
** compare.c for Str Compare, key and normal in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/bind
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Sat May  8 11:47:10 2010 julien di-marco
** Last update Sat May 15 21:27:41 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_readline.h"

/*
** Strcmh && Strml
** it's like strcmp but with ">=" or "<="
*/

int		strcmh(char *key, char *key2)
{
  int		i;

  i = 0;
  while (key[i] && key2[i] && key[i] >= key2[i])
    i++;
  return (key[i] - key2[i]);
}

int		strcml(char *key, char *key2)
{
  int		i;

  i = 0;
  while (key[i] && key2[i] && key[i] <= key2[i])
    i++;
  return (key[i] - key2[i]);
}

/*
** Strkeyh && strkeyl
** those functions make the same action of strcmh
** & strcml but with the CTRL modification.
** So Key must be the one in the bind database && read,
** The string read !
**
*/

int		strkeyh(char *key, char *read)
{
  char		sub;
  int		i;
  int		j;

  j = 0;
  i = 0;
  sub = 0;
  while (key[i] && read[j])
    {
      if (key[i] == '^' && key[i + 1])
	  sub = CTRL(key[++i]);
      else
	sub = key[i];
      if (!(read[j] >= sub))
	return (sub - read[j]);
      i++;
      j++;
    }
  return (key[i] - read[j]);
}

int		strkeyl(char *key, char *read)
{
  char		sub;
  int		i;
  int		j;

  j = 0;
  i = 0;
  sub = 0;
  while (key[i] && read[j])
    {
      if (key[i] == '^' && key[i + 1])
	  sub = CTRL(key[++i]);
      else
	sub = key[i];
      if (!(read[j] <= sub))
	return (sub - read[j]);
      i++;
      j++;
    }
  return (key[i] - read[j]);
}

/*
** Cm_key - Strcmp like
** this function do a strcmp but with the CTRL action
*/

int		cmp_key(char *key, char *read, int n)
{
  char		substitute;
  int		i;
  int		j;

  j = 0;
  i = 0;
  substitute = 0;
  while ((j <= n) && (key[i] && read[j]))
    {
      if (!i && key[i] == '^' && key[i + 1])
	  substitute = CTRL(key[++i]);
      else
	substitute = key[i];
      if (substitute != read[j])
	return (substitute - read[j]);
      i++;
      j++;
    }
  return (key[i] - read[j]);
}
