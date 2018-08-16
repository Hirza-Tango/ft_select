/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 15:03:32 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	parse_signals(void)
{
	signal(SIGINT, signals);
	signal(SIGTERM, signals);
	signal(SIGQUIT, signals);
	signal(SIGHUP, signals);
	signal(SIGWINCH, signals);
	signal(SIGTSTP, signals);
	signal(SIGCONT, signals);
}

void	signals(int sig)
{
	const unsigned char	buffer[2] = {g_inherit_term.c_cc[VSUSP], 0};

	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT || sig == SIGHUP)
		exit(reset_term());
	else if (sig == SIGTSTP)
	{
		reset_term();
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, buffer);
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, signals);
		init_term();
		display_border();
		display_list();
	}
	else if (sig == SIGWINCH)
	{
		set_win_size();
		display_border();
		display_list();
	}
}
