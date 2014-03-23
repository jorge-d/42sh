/*
** readstd.c for mysh in /u/all/strzel_a/cu/rendu/c/my_ls
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Mon Dec  7 15:08:13 2009 alexandre strzelewicz
** Last update Thu Jun  3 12:14:08 2010 dimitri jorge
*/

#ifndef _ALIAS_GLOB_H_
#define _ALIAS_GLOB_H_

# define MAX_ALIAS_NAME 128
# define MAX_ALIAS_SIZE 256
# define MAX_CMD_SIZE	256

char		**operate_env_globbing(char **cmd, t_env *st_env);
char		**expend_alias(char **cmd, t_alias *st_alias);
char		**operate_globbing(char **cmd);

char		**parse_str(char *, char );
char		**insert_in_tab(char **, char **, int *);

int		is_it_glob(char *seq);

int		put_alias_in_list(t_alias **begin, char *alias, char *cmd);
int		remove_alias_from_list(t_alias **st_alias);

int		add_new_alias(char **cmd, t_shell *st_shell);
int		unset_alias(char **cmd, t_shell *st_shell);

void		remove_sequence_quote(char **cmd, t_tree *);

char		**operate_quote(char **cmd, t_shell *st_shell);

#endif /* _ALIAS_GLOB_H_ */
