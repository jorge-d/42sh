/*
** main.c for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Wed Dec 23 02:59:49 2009 dimitri jorge
** Last update Sun May 23 03:42:45 2010 julien di-marco
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "42sh.h"
#include "my_readline.h"

int		vsh(int ac, char **av, char **env)
{
  t_shell	shell;
  char		*str;

  (void)ac;
  (void)av;
  init_program(&shell, env);
  while ((shell.flag & SH_EXIT) &&
	 (str = my_readline(&shell, generate_prompt())))
    {
      lexor_and_parsor(str, &shell);
      main_execution(&shell);
    }
  exit_42sh(&shell);
  return (EXIT_SUCCESS);
}

int		main(int ac, char **av, char **env)
{
  return (vsh(ac, av, env));
}
