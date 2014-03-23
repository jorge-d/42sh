/*
** parserll.h for  in /u/all/shkurt_j/svn/42shsvn/trunk
** 
** Made by joni shkurti
** Login   <shkurt_j@epitech.net>
** 
** Started on  Tue May 11 18:40:10 2010 joni shkurti
** Last update Sun May 23 03:37:42 2010 julien di-marco
*/

#ifndef			PARSERLL_H_
# define		PARSERLL_H_

# define MAX_LINESIZE	2048

/*
** Define Redirection
*/

# define LEFT_R		"<"
# define RIGHT_R	">"
# define D_LEFT_R	"<<"
# define D_RIGHT_R	">>"
# define PIPE		"|"

/*
** Define Execution
*/

# define AND		"&"
# define AND_BIN	"&&"
# define OR_BIN		"||"
# define SEMICOLON	";"

/*
**  Data type
*/


# define IS_CMD		0
# define IS_FILE	1
# define IS_PIPE	2
# define IS_RIGHT	3
# define IS_D_RIGHT	4
# define IS_LEFT	5
# define IS_D_LEFT	6
# define IS_AND		7
# define IS_OR		8

#ifndef		FALSE
# define FALSE		0
#endif		/* !FALSE */
#ifndef		TRUE
# define TRUE		1
#endif		/* !TRUE */

typedef enum			s_bool
{
  FAUX = 0, VRAI = 1
}				t_bool;

typedef struct		s_cmd
{
  int			len;
  char			**args;
}			t_cmd;

typedef struct		s_tree
{
  int			type;
  int			fd_in;
  int			fd_out;
  char			*full_path;
  char			**args;
  t_cmd			cmd;
  struct s_tree		*left;
  struct s_tree		*right;
  struct s_tree		*next;
}			t_tree;

typedef struct		s_token
{
  int			i;
  char			**board;
}			t_token;

/*
**  Main fonctions
*/

void			parser_ll(char *);
char			*format_line(char *);

/*
** parsing,c
*/

t_bool			alloc_tree(t_tree **, t_tree *);
t_tree			*init_tree(void);
t_tree			*make_parsing(char **);

/*
** BNF
*/

t_bool			expression(t_tree **, t_token *);
t_bool			or_exp(t_tree **, t_token *);
t_bool			and_exp(t_tree **, t_token *);
t_bool			pipe_exp(t_tree **, t_token *);
t_bool			redir_exp(t_tree **, t_token *);
t_bool			redir_left_norm(t_tree **, t_token *);
t_bool			redir_left_spe(t_tree **, t_token *);
t_bool			redir_right(t_tree **, t_token *);
t_bool			redir_right_norm(t_tree **, t_token *);
t_bool			redir_right_spe(t_tree **, t_token *);
t_bool			command_exp(t_tree **, t_token *);
t_bool			cmd_exp(t_tree **, t_token *);
t_bool			args_exp(t_tree **, t_token *);
t_bool			file_exp(t_tree **, t_token *);
t_bool			special_case(t_tree **, t_token *);

/*
** check flags
*/

int			check_if_line_is_valid(char *);
int			check_quote_flag(char, int);

/*
** check type
*/

t_bool			is_left_redir(char *);
t_bool			is_right_redir(char *);
t_bool			is_pipe(char *);
t_bool			is_and_or_or_bin(char *);
t_bool			is_semi_colon(char *);
t_bool			is_redir_or_sep(char *);
t_bool			is_redir(char *);
t_bool			is_sep(char *);
t_bool			is_redir_no_pipe(char *);

int			is_directory(char *);

/*
** check syntax
*/

char			**check_syntax_error(const char *);
int			check_left_redir_syntax(char **, int);
int			check_right_redir_syntax(char **, int);
int			check_pipe_and_or(char **, int);

/*
** Library
*/

void			free_tree(t_tree *);
void			*xmalloc(int);
char			**my_str_to_wordtab(char *);
char			**malloc_table(char **, char *, int);

int			my_tablen(char **);
void			free_table(char **);

#endif			/* !PARSERLL_H_ */
