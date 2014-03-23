/*
** main_execution.c for 42sh in /u/all/jorge_d/cu/svn/parserll/trunk/src/execution
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May  6 15:43:08 2010 dimitri jorge
** Last update Thu May 27 17:25:21 2010 dimitri jorge
*/

#include <sys/types.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "parserll.h"
#include "42sh.h"

int		execute_it(t_tree *tree, t_shell *st_shell)
{
  if (tree->type == IS_OR && execute_it(tree->left, st_shell) == EXIT_FAILURE)
    return (execute_it(tree->right, st_shell));
  if (tree->type == IS_AND && execute_it(tree->left, st_shell) == EXIT_SUCCESS)
    return (execute_it(tree->right, st_shell));
  else if (tree->type == IS_PIPE)
    return (execute_pipe_start(tree, st_shell));
  else if (tree->type == IS_CMD)
    return (execute_simple_command(tree, st_shell));
  else if (tree->type == IS_RIGHT || tree->type == IS_D_RIGHT)
    return (right_redirection(tree, st_shell));
  else if (tree->type == IS_LEFT || tree->type == IS_D_LEFT)
    return (left_redirection(tree, st_shell));
  return (EXIT_FAILURE);
}

void		main_execution(t_shell *st_shell)
{
  t_tree	*parse;
  int		flag;

  flag = 0;
  parse = st_shell->st_tree;
  st_shell->my_env = list_to_table(gl_st.st_env);
  while (flag == 0 && parse)
    {
      if (execute_it(parse, st_shell) == FATAL_ERROR)
	flag = 1;
      close_trees_fd(parse);
      parse = parse->next;
    }
  xfree(st_shell->my_env);
  st_shell->my_env = NULL;
  free_tree(st_shell->st_tree);
  st_shell->st_tree = NULL;
}
