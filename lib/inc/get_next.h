/*
** get_next.h for 42sh in /u/all/sabbag_a/cu/gnl
**
** Made by fares sabbagh
** Login   <sabbag_a@epitech.net>
**
** Started on  Sat May 22 18:50:46 2010 fares sabbagh
** Last update Sat May 22 18:50:48 2010 fares sabbagh
*/

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#define BUF_SIZE (1024)

typedef struct	s_buff
{
  int		size;
  char		*str;
  struct s_buff *next;
}		t_buff;

char		*get_next_line(const int);

#endif /* !_GET_NEXT_LINE_H_ */
