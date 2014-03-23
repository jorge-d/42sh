/*
** my_put_nbr.c for 42sh in /u/all/jorge_d/cu/public/colles2
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Tue May 18 16:31:34 2010 dimitri jorge
** Last update Tue May 18 16:31:36 2010 dimitri jorge
*/

void		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr((nb / 10) * -1);
      my_putchar(((nb % 10) * -1) + '0');
    }
  else
    {
      if (nb >= 10)
	my_put_nbr(nb / 10);
      my_putchar((nb % 10) + '0');
    }
}

