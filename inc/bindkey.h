/*
** bindkey.h for bindkey in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline/new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 20 23:25:41 2010 julien di-marco
** Last update Tue May 11 16:40:51 2010 julien di-marco
*/

#ifndef		BINDKEY_H__
# define	BINDKEY_H__

/*
**	Structures & Other definitions
*/

typedef struct	s_bind_funct
{
  char		*name;
  int		(*func)();
  char		*comment;
}		t_bind_funct;

typedef struct	s_bind
{
  char		*key;
  char		*key2;
  int		flags;
  t_bind_funct	*func;
}		t_bind;

typedef struct s_defb
{
  char		key[1024];
  char		*key2;
  char		*name;
  int		flags;
}		t_defb;

/*
**	s_bdb - Bind DataBases
*/

typedef	struct	s_bdb
{
  t_bind	*keybind;
  struct s_bdb	*next;
  struct s_bdb	*prev;
}		t_bdb;

/*
**	Defines
*/

# define CTRL(x)	(x&037)

# define READSIZE	10

/*
**  t_bind structure - flags posibilities !
*/

# define LOCK		1
# define INTER		2
# define DEFAULT	4

/*
**	Functions - Bindkey - > ./bind/
*/

int		bind_key(char *key, char *key2, char *name, t_bdb **head);

int		free_database(t_bdb **head);

/*
**  Simple_key
*/

int		key_search(char *key, t_bdb **bind);
int		create_key(char *key, t_bind *bind, t_bdb **foot);
int		mod_key(char *key, t_bind *bind, t_bdb **foot);
int		split_inter(char *key, t_bind *new, t_bdb **foot);

int		merge_left_inter(char *key, t_bind *bind, t_bdb **foot);
int		merge_right_inter(char *key, t_bind *bind, t_bdb **foot);
int		complicated_inter(char *key, t_bind *bind, t_bdb **foot);

/*
** Key_Inter
*/

int		key_inter_search(char *key, char *key2, t_bdb **bind);
int		create_inter(char *key, char *key2, t_bind *bind, t_bdb **foot);

/*
** Functions
*/

void		*get_func(char *name);

/*
** Utils
*/

int		db_corrupt(t_bdb *head, t_bdb **bind);
int		key_sub(char *key);

/*
** bind Database
*/

int		rev_list(t_bdb **foot);
int		add_list(t_bdb **foot, t_bind *bind);

int		show_bind(t_bdb *head);
int		insert_list(t_bdb **foot, t_bind *bind);

/*
** Compare keys
*/

int		cmp_key(char *key, char *read, int n);
int		strkeyl(char *key, char *read);
int		strkeyh(char *key, char *read);
int		strcml(char *key, char *key2);
int		strcmh(char *key, char *key2);

#endif		/* !BINDKEY_H__ */
