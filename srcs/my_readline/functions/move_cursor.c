/*
** move_cursor.c for Move Cursor Functions in /Users/lifely/Developer/project/42shsvn/trunk
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon May 17 04:25:22 2010 julien di-marco
** Last update Sun May 23 05:23:23 2010 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"42sh.h"
#include	"my_readline.h"

static int	move_backward(t_rl *base, int count)
{
  int		i;

  while (((i = ROW(base->info.i, base)) < -count))
    {
      count += i + 1;
      base->info.i -= i + 1;
      apply_term("up");
      if (gl_st.size.ts_cols - (i + 1))
	apply_tparm("RI", (gl_st.size.ts_cols - (i + 1)));
    }
  base->info.i += count;
  if (count)
    apply_tparm("LE", -count);
  return (1);
}

static int	move_forward(t_rl *base, int count)
{
  int		i;

  i = (gl_st.size.ts_cols - ROW(base->info.i, base));
  while ((i = ((gl_st.size.ts_cols - ROW(base->info.i, base)))) <= count)
    {
      if (ROW(base->info.i, base))
	apply_tparm("LE", ROW(base->info.i, base));
      count -= i;
      apply_term("do");
      base->info.i += i;
    }
  base->info.i += count;
  if (count)
    apply_tparm("RI", count);
  return (1);
}

int		move_cursor(t_rl *base, int count)
{
  apply_term("vi");
  if (base && count < 0 && ((base->info.i + count) >= 0))
    move_backward(base, count);
  else if (base && count > 0 && (((base->info.i + count)) <= base->info.nb))
    move_forward(base, count);
  apply_term("ve");
  return (1);
}

int		_move_cursor(t_rl *base, int count)
{
  t_rl		new;

  new.info.buffer = NULL;
  new.info.tmp = NULL;
  new.info.i = base->info.i;
  new.info.nb = base->info.nb;
  new.info.insert_m = base->info.insert_m;
  new.p_len = base->p_len;
  new.flags = base->flags;
  new.bind = NULL;
  apply_term("vi");
  if (base && count < 0 && ((base->info.i + count) >= 0))
    move_backward(&new, count);
  else if (base && count > 0 && (((base->info.i + count)) <= base->info.nb))
    move_forward(&new, count);
  apply_term("ve");
  return (1);
}

