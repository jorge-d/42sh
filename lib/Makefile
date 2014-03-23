##
## Makefile for make bsq in /u/all/strzel_a/cu/rendu/c/bsq
## 
## Made by alexandre strzelewicz
## Login   <strzel_a@epitech.net>
## 
## Started on  Mon Nov  2 15:52:47 2009 alexandre strzelewicz
## Last update Thu Jun  3 11:42:01 2010 dimitri jorge
##

################### - Project Config - ###################

NAME            = lib_neolib_$(ARCHI)-$(OS).a

LIBRARY		= ../
INCLUDE		= ./inc/

GNL		= ./gnl/
MYLIB		= ./mylib/
OTHER		= ./other/
XLIB		= ./xlib/

##########################################################

SRCS		= $(GNL)get_next_line.c			\
		  \
		  $(OTHER)free_table.c			\
		  \
		  $(MYLIB)my_strcmp.c			\
		  $(MYLIB)my_strncmp.c			\
		  $(MYLIB)my_strcat.c			\
		  $(MYLIB)my_strncat.c			\
		  $(MYLIB)my_strlen.c			\
		  $(MYLIB)my_strncpy.c			\
		  $(MYLIB)my_tabcpy.c			\
		  $(MYLIB)my_putchar.c			\
		  $(MYLIB)my_outc.c			\
		  $(MYLIB)my_tablen.c			\
		  $(MYLIB)my_strcpy.c			\
		  $(MYLIB)my_memset.c			\
		  $(MYLIB)my_strdup.c			\
		  $(MYLIB)my_str_to_wordtab.c   	\
		  $(MYLIB)my_tab_malloc.c   	        \
		  \
		  $(XLIB)xmalloc.c			\
		  $(XLIB)xcalloc.c			\
		  $(XLIB)xopen.c			\
		  $(XLIB)xread.c			\
		  $(XLIB)xwrite.c			\
		  $(XLIB)xfree.c			\
		  $(XLIB)xpipe.c			\
	 	  $(XLIB)xclose.c			\
		  $(XLIB)xclosedir.c			\
		  $(XLIB)xstat.c			\
		  $(XLIB)xlstat.c			\
		  $(XLIB)xfork.c			\
		  $(XLIB)xreadlink.c			\
		  $(XLIB)xwaitpid.c			\
		  $(XLIB)xexecve.c			\
		  $(XLIB)xopendir.c			\
		  $(XLIB)xdup2.c			\
	 	  $(XLIB)xtgoto.c			\
	 	  $(XLIB)xoutc.c			\
		  $(XLIB)xtgetstr.c			\
		  $(XLIB)xchdir.c			\
		  $(XLIB)xtputs.c			\
		  $(XLIB)xtgetent.c			\
		  $(XLIB)xsignal.c

OBJS		= $(SRCS:.c=.o)

####################### : Generic - Action : #######################

CC              = $(CC_${OSTYPE})

CC_$(OSTYPE)	= gcc
CC_FreeBSD      = gcc
CC_darwin	= gcc
CC_solaris2.10  = /usr/sfw/bin/gcc
CC_solaris      = /usr/sfw/bin/gcc
CC_linux	= /usr/bin/gcc
CC_i486-linux   = gcc

OS		= $(shell uname -s)
OS		!= uname -s
ARCHI		= $(shell uname -m)
ARCHI		!= uname -m

AR		= ar r
RAN		= ranlib
CHECK		= /u/all/astek/public/norme

STRIP		= /bin/cat
PRINTF		= /usr/bin/printf
CP		= cp -R
RM		= rm -f

CFLAGS		+= -I$(INCLUDE) -D_$(OS)_ -W -Wall -ansi -pedantic
LDFLAGS		= -ltermcap

####################### : Generic - Regles : #######################

build	: $(NAME) ok

$(NAME)	: $(OBJS)
	@$(PRINTF) "\nCreating.........\n"
	@$(AR) $(NAME) $(OBJS)
	@$(PRINTF) "Ranlib library.........\n"
	@$(RAN) $(NAME)
	@$(PRINTF) "Flag used with $(CC): \033[33m$(CFLAGS)\033[m \n"
	@$(PRINTF) "Library name is: \033[33m$(NAME)\033[m\n"

all     : strip $(NAME)

mrpropre: strip $(NAME) clean

clean	:
	 @$(RM) $(OBJS)
	 @$(PRINTF) "\033[31m[OK]\033[m CLEAN: \n$(OBJS))\n"

fclean	: clean
	@$(RM) $(NAME)
	@$(PRINTF) "\033[31m[OK]\033[m FCLEAN: $(NAME)\n\n"

re	: strip fclean $(NAME)

.SUFFIXES: .c.o

.PHONY	: clean fclean all re strip

.c.o :
	@$(CC) -c $< -o $(<:.c=.o) $(CFLAGS)
	@$(PRINTF) "\033[31m[OK]\033[m $<\n"

####################################################################

ok	:
	@$(PRINTF) "\033[31m[OK]\033[m Lib creation done. \n\n"

check	:
	@ $(CHECK) `find . -name "*.[ch]"`

strip 	:
	@$(STRIP) .strip

####################################################################