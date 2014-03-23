/*
** message.h for Error Message & other Message in /u/all/di-mar_j/cu/svn/VSHsvn/branches/my_readline-new
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Mon Apr 19 17:18:43 2010 julien di-marco
** Last update Sat May 15 15:58:53 2010 julien di-marco
*/

#ifndef		MESSAGE_RL_H_
# define	MESSAGE_RL_H_

# define NAME		"42sh"

/*
**	Termcap Folder - Init & Reset Fonctions
*/

# define E_RESET	NAME": Readline Error: can't reset that term\n"
# define E_DUMB		NAME": Terminal using dumb terminal setting's\n"
# define E_TERMINAL	NAME": Cannot open /etc/terminal\n"

/*
**	GetNextLine - Error
*/

# define E_GNL		NAME": error trying to read your entry\n"
# define E_PROMPT	NAME": error trying to display the prompt\n"

/*
**	Bind key
*/

# define E_BDB_CORUPT	NAME": the bind keys DataBase is corupt\n"
# define E_NOFUNC	NAME": bad command name [%s]\n", name

#endif		/* !MESSAGE_RL_H_ */
