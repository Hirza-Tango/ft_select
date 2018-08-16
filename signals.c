/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 17:34:05 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	parse_signals(void)
{
	signal(SIGINT, signals);
	signal(SIGTERM, signals);
	signal(SIGHUP, signals);
	signal(SIGPIPE, signals);
	signal(SIGALRM, signals);
	signal(SIGWINCH, signals);
	signal(SIGTSTP, signals);
	signal(SIGCONT, signals);
	signal(SIGXCPU, signals);
	signal(SIGXFSZ, signals);
	signal(SIGVTALRM, signals);
	signal(SIGPROF, signals);
	signal(SIGXCPU, signals);

}

void	signals(int sig)
{
	const unsigned char	buffer[2] = {g_inherit_term.c_cc[VSUSP], 0};

	if (sig == SIGINT || sig == SIGTERM || sig == SIGHUP || sig == SIGPIPE ||
		sig == SIGALRM || sig == SIGXCPU || sig == SIGXFSZ || sig == SIGVTALRM
		|| sig == SIGPROF || sig == SIGXCPU)
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
