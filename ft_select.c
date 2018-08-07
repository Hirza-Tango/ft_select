/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <tango@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:53:49 by tango             #+#    #+#             */
/*   Updated: 2018/08/04 18:02:47 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_term(void)
{	
	tcgetattr(0, &g_inherit_term);
	g_term = g_inherit_term;
	g_term.c_lflag &= ~(ECHO | ICANON | ISIG);
	tcsetattr(0, 0, &g_term);
}

void	redraw(int sig)
{
	if (sig == SIGWINCH)
		//redraw window
		(void)0;
}

void	reset_term(int sig)
{
	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT
	|| sig == SIGHUP || sig == SIGTSTP)
	{
		tcsetattr(0, 0, &g_inherit_term);
		exit(0);
	}
}

void	handle_char(char c)
{
	char	holder;

	if (c == 10)
	{
		//return selections
		reset_term(SIGTERM);
	}
	if (c == 27)
	{
		if (read(0, &holder, 1) != 1)
		{
			//return nothing
			reset_term(SIGTERM);
		}
		if (holder == '[')
		{
			read(0, &holder, 1);
			if (holder == 'A')
				//UP
				(void)0;
			if (holder == 'B')
				//DOWN
				(void)0;
			if (holder == 'C')
				//LEFT
				(void)0;
			if (holder == 'D')
				//RIGHT
				(void)0;
		} 
	}
	if (c == 8 || c == 127)
		//delete entry or return nothing
		(void)0;
	if (c == 20)
		//toggle selection
		(void)0;
	//ignore other keys
}

int		main(int argc, char **argv, char **env)
{
	char input;

	init_term();

	while (1)
	{
		read(0, &input, 1);
		handle_char(input);
	}
	reset_term(SIGTERM);
}