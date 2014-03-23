/*
** get_next.c for 42sh in /u/all/sabbag_a/cu/gnl
**
** Made by fares sabbagh
** Login   <sabbag_a@epitech.net>
**
** Started on  Sat May 22 18:51:02 2010 fares sabbagh
** Last update Thu Jun  3 11:32:39 2010 julien di-marco
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"
#include "get_next.h"

static int	my_get_size(t_buff *stack)
{
  int		res;

  res = 0;
  while (stack)
    {
      res += stack->size;
      stack = stack->next;
    }
  return (res);
}

static char	*my_pop(t_buff **stack)
{
  int		size;
  char		*res;
  t_buff	*tmp;

  res = NULL;
  if ((size = my_get_size(*stack))
      && (res = xmalloc((size + 4) * sizeof(*res))))
    {
      res[size] = '\0';
      while (*stack)
	{
	  size = my_get_size(*stack);
	  strncpy(res + (size - (*stack)->size),
		  (*stack)->str, (*stack)->size);
	  tmp = *stack;
	  *stack = (*stack)->next;
	  xfree(tmp->str);
	  xfree(tmp);
	}
    }
  return (res);
}

static int	my_push(t_buff **stack, char *str, int size)
{
  t_buff	*new;

  if (size > 0 && str)
    if ((new = xcalloc(1, sizeof(*new))))
      if ((new->str = xmalloc((size + 4) * sizeof(*(new->str)))))
	{
	  new->size = size;
	  strncpy(new->str, str, size);
	  if (*stack)
	    new->next = *stack;
	  else
	    new->next = NULL;
	  *stack = new;
	  return (size);
	}
  return (0);
}

static char	*verif(const int fd, t_buff **stack, char *buff, int str_size)
{
  if (str_size > 0 && my_push(stack, buff, str_size))
    {
      xfree(buff);
      return (get_next_line(fd));
    }
  else
    {
      xfree(buff);
      return (my_pop(stack));
    }
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*res;
  static t_buff *stack;
  int		tot_size;
  int		str_size;
  char		*buff;

  buff = NULL;
  if ((i = 0) || stack)
    while (i < stack->size)
      if (stack->str[i++] == '\n')
	{
	  str_size = stack->size;
	  tot_size = my_get_size(stack) - str_size;
	  if ((res = my_pop(&stack)))
	    my_push(&stack, res + tot_size + i, str_size - i);
	  if (res)
	    res[tot_size + i - 1] = '\0';
	  return (res);
	}
  if ((buff = xmalloc((BUF_SIZE + 4) * sizeof(*buff))) && \
      (str_size = read(fd, buff, BUF_SIZE)) != (-1))
    return (verif(fd, &stack, buff, str_size));
  xfree(buff);
  xfree(my_pop(&stack));
  return (NULL);
}
