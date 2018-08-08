/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:53:49 by tango             #+#    #+#             */
/*   Updated: 2018/08/08 18:36:05 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_term(void)
{	
	set_win_size();
	tcgetattr(0, &g_inherit_term);
	g_term = g_inherit_term;
	g_term.c_lflag &= ~(ECHO | ICANON | ISIG);
	tcsetattr(0, 0, &g_term);
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