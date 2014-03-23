##
## Makefile for mysh in /u/all/jorge_d/cu/MINISHELL2
##
## Made by dimitri jorge
## Login   <jorge_d@epitech.net>
##
## Started on  Mon Feb 15 16:58:05 2010 dimitri jorge
## Last update Thu Jun  3 18:00:32 2010 julien di-marco
##

####################### - Project Config - #######################

NAME		= vsh

INCLUDE		= ./inc/
LIBRARY		= ./lib/
SR		= ./srcs/
PROJECT		= $(SR) $(INCLUDE) $(LIBRARY)

LEXOR		= $(SR)lexor/
PARSOR		= $(SR)ll_parsor/
INIT_FUNCS	= $(SR)initialisation/
CONF_FILE	= $(SR)conf_file/
GLOB		= $(SR)alias_glob/
ENV_L		= $(SR)set_environ/
FREE_FUNCS	= $(SR)free_functions/

READLINE	= $(SR)my_readline/
 TERMCAP	= $(READLINE)termcap/
 UTILS		= $(READLINE)utils/
 GETLINE	= $(READLINE)getline/
 BIND		= $(READLINE)bind/
 FUNCTIONS	= $(READLINE)functions/
 HISTORY	= $(READLINE)history/

BUILTINS	= $(SR)builtins/
 ENV		= $(BUILTINS)env_functions/
 ALIAS		= $(BUILTINS)alias/
 HREACT		= $(BUILTINS)hreact/

EXECUTION	= $(SR)execution/
 EXEC_UTILS	= $(EXECUTION)utils/

ACOMP		= $(SR)auto_complete/
 AC_TYPE	= $(ACOMP)auto_complete_type/
 AC_FUNC	= $(ACOMP)auto_complete_funcs/
 F_LIST		= $(ACOMP)fill_list/
 DISP		= $(ACOMP)display/

##################################################################

SRCS		= $(SR)main.c					\
		  $(SR)get_full_path.c				\
		  $(SR)check_builtins.c				\
		  $(SR)prompt.c					\
		  \
		  $(LEXOR)check_flags.c				\
		  $(LEXOR)check_line_syntax_1.c			\
		  $(LEXOR)check_line_syntax_2.c			\
		  $(LEXOR)check_redirection_syntax.c		\
		  $(LEXOR)check_syntax_error.c			\
		  $(LEXOR)check_type.c				\
		  $(LEXOR)check_type_2.c			\
		  \
		  $(PARSOR)main_of_parsing.c			\
		  $(PARSOR)command.c				\
		  $(PARSOR)or_and_pipe.c			\
		  $(PARSOR)parsing.c				\
		  $(PARSOR)redir.c				\
		  $(PARSOR)special_case.c			\
		  \
		  $(INIT_FUNCS)put_env_in_list.c		\
		  $(INIT_FUNCS)init_program.c			\
		  $(INIT_FUNCS)exit.c				\
		  $(INIT_FUNCS)init_secondary.c			\
		  \
		  $(CONF_FILE)conf_file.c			\
		  \
		  $(GLOB)expend_alias.c				\
		  $(GLOB)glob_env.c				\
		  $(GLOB)parsing_1.c				\
		  $(GLOB)check_glob.c				\
		  $(GLOB)addin.c				\
		  \
		  $(ENV_L)aff_set.c				\
		  $(ENV_L)get_set.c				\
		  $(ENV_L)my_set.c				\
		  $(ENV_L)my_unset.c				\
		  $(ENV_L)init_set.c				\
		  \
		  $(FREE_FUNCS)free_env.c			\
		  $(FREE_FUNCS)free_tree.c			\
		  $(FREE_FUNCS)free_struct.c			\
		  \
		  $(BUILTINS)my_cd.c				\
		  $(BUILTINS)builtin_ptr.c			\
		  $(BUILTINS)builtin_ptr_2.c			\
		  $(BUILTINS)builtin_ptr_3.c			\
		  $(BUILTINS)change_disp_config.c		\
		  $(BUILTINS)bindkey.c				\
		    $(ENV)get_env.c				\
		    $(ENV)my_unsetenv.c				\
		    $(ENV)my_setenv.c				\
		    $(ENV)aff_env.c				\
		    \
		    $(HREACT)win_zise.c				\
		    $(HREACT)display_lateral.c			\
		    $(HREACT)display_lateral_functions.c	\
		    $(HREACT)display_optimised.c		\
		    $(HREACT)safe_execute_cmd.c			\
		    $(HREACT)verify_content.c			\
		    \
		    $(ALIAS)alias_funcs.c			\
		    $(ALIAS)alias_builtin.c			\
		  \
		  $(EXECUTION)execute_pipes.c			\
		  $(EXECUTION)execute_pipes_2.c			\
		  $(EXECUTION)simple_command.c			\
		  $(EXECUTION)left_redirection.c		\
		  $(EXECUTION)main_execution.c			\
		  $(EXECUTION)prepare_command.c			\
		  $(EXECUTION)right_redirection.c		\
		    $(EXEC_UTILS)write_status.c			\
		    $(EXEC_UTILS)check_env_var.c		\
		    $(EXEC_UTILS)check_tilde.c			\
		    $(EXEC_UTILS)close_fds.c			\
		    $(EXEC_UTILS)list_to_tab.c			\
		    $(EXEC_UTILS)set_fds.c			\
		    $(EXEC_UTILS)unset_quotes.c			\
		  \
		  $(READLINE)my_readline.c			\
		    $(BIND)defaults.c				\
		    $(BIND)free_database.c			\
		    $(BIND)bindkey.c				\
		    $(BIND)simple_key.c				\
		    $(BIND)simple_inter.c			\
		    $(BIND)complicated_inter.c			\
		    $(BIND)key_interval.c			\
		    $(BIND)functions.c				\
		    $(BIND)utils.c				\
		    $(BIND)compare.c				\
		    $(BIND)add_list.c				\
		    $(BIND)insert_list.c			\
		    $(BIND)show_bind.c				\
		    \
		    $(FUNCTIONS)move_cursor.c			\
		    $(FUNCTIONS)clear.c				\
		    $(FUNCTIONS)self_insert_command.c		\
		    $(FUNCTIONS)clear_line.c			\
		    $(FUNCTIONS)overwrite_mode.c		\
		    $(FUNCTIONS)down_line_or_history.c		\
		    $(FUNCTIONS)up_line_or_history.c		\
		    $(FUNCTIONS)backward_char.c			\
		    $(FUNCTIONS)backward_delete_char.c		\
		    $(FUNCTIONS)accept_line.c			\
		    $(FUNCTIONS)delete_char_or_list_or_eof.c	\
		    $(FUNCTIONS)complete_word.c			\
		    $(FUNCTIONS)line.c				\
		    \
		    $(GETLINE)getline.c				\
		    $(GETLINE)utils.c				\
		    \
		    $(TERMCAP)init_readline.c			\
		    $(TERMCAP)reset_readline.c			\
		    $(TERMCAP)apply_term.c			\
		    \
		    $(HISTORY)history.c				\
		    $(HISTORY)add_hist.c			\
		    $(HISTORY)save_to_file.c			\
		    \
		    $(UTILS)print_prompt.c			\
		  \
		  $(ACOMP)completion_priority.c			\
		    $(AC_TYPE)completion_builtin.c		\
		    $(AC_TYPE)completion_alias.c		\
		    $(AC_TYPE)completion_set_environ.c		\
		    $(AC_TYPE)display_files.c			\
		    $(AC_TYPE)completion_file.c			\
		    $(AC_FUNC)ia_completion.c			\
		    $(AC_FUNC)forge_command.c			\
		    \
		    $(F_LIST)add_slashes.c			\
		    $(F_LIST)completion_inter.c			\
		    $(F_LIST)completion_final.c			\
		    $(F_LIST)completion_opt.c			\
		    $(F_LIST)funcs.c				\
		    \
		    $(DISP)display_list.c			\
		    $(DISP)display_funcs.c

OBJS		= $(SRCS:.c=.o)

###################### : Generic - Define : ######################

CC              = $(CC_${OSTYPE})

CC_$(OSTYPE)	= gcc
CC_FreeBSD      = gcc
CC_darwin	= gcc
CC_solaris      = /usr/sfw/bin/gcc
CC_linux	= /usr/bin/gcc

MOPT		= $(MOPT_${OSTYPE})

MOPT_$(OSTYPE)	= -C
MOPT_NetBSD	= -I

OS		= $(shell uname -s)
OS		!= uname -s
ARCHI		= $(shell uname -m)
ARCHI		!= uname -m

STRIP		= /bin/cat
PRINTF		= /usr/bin/printf
CP		= cp
RM		= rm -f

COMP		= gzip -fr
UMCOMP		= gunzip -fr
TAR		= tar
GZIP		= gzip

CFLAGS		+= -I$(INCLUDE) -D_${OS}_ $(FLAGS)
LDFLAGS		= -ltermcap -L$(LIBRARY) -l_neolib_$(ARCHI)-$(OS)

FLAGS		+= -W -Wall -Wextra -O3 -ansi -pedantic \
		  -funroll-loops -pipe -s

##Debug Flags - Uncoment & comment up definition
#FLAGS		=  -W -Wall -ansi -pedantic -g3

CHECK		= /u/all/astek/public/norme

####################### : Generic - Rules : #######################

all		: strip library $(NAME) ok

$(NAME)		: $(OBJS)
		@ $(PRINTF) "\nFlag used with $(CC): \033[33m$(FLAGS)\033[m\n"
		@ $(PRINTF) "Executable name is: \033[33m$(NAME)\033[m\n"
		  $(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

install		: strip fclean libraryf library $(NAME) clean libraryc ok

mrpropre	: all clean

clean		:
		@ $(RM) $(OBJS)
		@ $(PRINTF) "\033[31m[OK]\033[m CLEAN  $(NAME) - objs\n"

fclean		: clean
		@ $(RM) $(NAME)
		@ $(PRINTF) "\033[31m[OK]\033[m FCLEAN $(NAME)\n\n"

re		: strip library fclean $(NAME) ok

.c.o		:
		@ $(CC) -o $@ -c $< $(CFLAGS)
		@ $(PRINTF) "\033[31m[OK]\033[m ---> $< \n"

.PHONY		: clean fclean

.SUFFIXES	: .c.o

####################### : Library - Rules : ######################

library		:
		@(cd $(LIBRARY) && $(MAKE))

libraryre	:
		@(cd $(LIBRARY) && $(MAKE) re)

libraryc	:
		@(cd $(LIBRARY) && $(MAKE) clean)

libraryf	:
		@(cd $(LIBRARY) && $(MAKE) fclean)

####################### : Compres - Rules : ######################

comp		: libraryf fclean
		$(COMP) $(SRCS)

ucomp		: $(UMCOMP) $(SRCS)

tar		: libraryf fclean
		$(TAR) cvf - $(PROJECT) | $(GZIP) -9c > $(NAME).tar.gz
		$(RM) -r $(PROJECT)

untar		:
		$(TAR) xf $(NAME).tar.gz
		$(RM) $(NAME).tar.gz

##################################################################

check	:
	@ $(CHECK) `find . -name "*.[ch]"`

strip	:
	@ $(STRIP) .strip

ok	:
	@ $(PRINTF) "\033[31m[OK]\033[m Compilation done. \n\n"

coffee	:
	@ $(STRIP) .coffee

caffe	:
	@ $(STRIP) .coffee

##################################################################