/*
** hreact.h for 42sh in /u/all/jorge_d/cu/svn/42shsvn/trunk
** 
** Made by dimitri jorge
** Login   <jorge_d@epitech.net>
** 
** Started on  Thu May 20 22:32:06 2010 dimitri jorge
** Last update Sat May 22 16:28:29 2010 alexandre strzelewicz
*/

#ifndef _HREACT_H_
#define _HREACT_H_

# define X_BEGIN_FRAME		60
# define Y_BEGIN_FRAME		2
# define X_MAX_WIDHT_FRAME	70
# define Y_MAX_LENGHT_FRAME	50
# define SPE_SPACE		5
# define SPE_SPACE_OPT		15
# define TOP_FRAME_CARACTER	'-'
# define FRAME_INTERSECTION	"+"
# define MAX_LENGHT_COM		1024

# define MAX_CMD		2

# define DISP_STATE		0x01
# define DISP_REACTUALIZE	0x02
# define DISP_FORK		0x04

# define PIPE_TAB_SIZE		2

# define MAX_FILE_DISP		70

# define STDOUT			1
# define STDIN			0

# define CURSOR_SAVE		apply_term("sc")
# define CURSOR_RESTORE		apply_term("rc")
# define CURSOR_OFF		apply_term("vi")
# define CURSOR_ON		apply_term("ve")
# define CURSOR_HOME		apply_term("ho")

# ifndef AREA_SIZE
#  define AREA_SIZE 4096
# endif

# include "42sh.h"

typedef int	pipe_t;

char		gl_resize;

char		*get_next_line2(const int fd);
void		usage_hreact(void);
int		hreact_config(char **, t_shell *);
void	        hreact_displaying(t_shell *);
void		sigwinch_gest();
void		dlf_display_top_frame(t_shell *);
void		dl_clear_disp(t_shell *, int *oldline);
void		*dl_init_spe_disp(t_hreact *st_hreact);
void		dl_reduce_line_size(char *buf, t_shell *);
char		*dl_tab_to_str(char **strTab);
int		win_size(t_shell *st_shell);

void		optimized_hreact_parent(t_shell *shell, int *old, pipe_t *p);
void		safe_exec_line(char *cmd, t_shell *st_shell);
int		check_if_too_much_files(void);

#endif /* _HREACT_H_ */
