/*
** set_environ.h<2> for asdsd in /u/all/strzel_a/svn/42shsvn/trunk
** 
** Made by alexandre strzelewicz
** Login   <strzel_a@epitech.net>
** 
** Started on  Tue May 11 16:36:54 2010 alexandre strzelewicz
<<<<<<< .mine
** Last update Sat May 22 18:34:57 2010 alexandre strzelewicz
=======
** Last update Sun May 16 17:16:51 2010 alexandre strzelewicz
>>>>>>> .r156
*/

#ifndef				SET_ENVIRON_H_
#define				SET_ENVIRON_H_

/*
**	Defines
*/

# define HIST_FILE_PATH		"./.42shistory"
# define CONF_FILE_PATH		"./.42shrc"

# define DEFAULT_PROMPT	"\033[1;31;1m-V-\033[0m %U@%p" \
  				" \033[1;31;1m>>>\033[0m "

# define D_HIST_DOUBLOON	"1"
# define DEFAULT_HREACT		"0"
# define DEFAULT_HISTSIZE	"100"
# define DEFAULT_OPT_HREACT	"0"

# define COMPLETION_STATE_STR	"COMPLETION_STATE"
# define COMPLETION_CHOICE_STR  "COMPLETION_CHOICE"

# define MAX_SET_VAL_SIZE	256

typedef struct  s_defvar
{
  char		*name[3];
}		t_defvar;

/*
**	Prototypes
*/

char		*set_it(char *var, char *value);
char		*get_set_from_list(char *var);

int		fill_default_set_environ(void);

int		unset_new(char **args);
int		aff_set(t_tree *);
int		set_new(char **args, t_tree *);
void		set_env_to_set(void);

#endif				/* !SET_ENVIRON_H_ */
