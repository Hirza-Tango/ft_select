/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/13 14:30:24 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	parse_signals(void)
{
	const int sigs[] = {SIGINT, SIGTERM, SIGQUIT, SIGHUP, SIGTSTP, SIGWINCH, 0};
	int i;

	i = 0;
	while (sigs[i])
		signal(sigs[i++], signals);
}

void	signals(int sig)
{
	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT
	|| sig == SIGHUP || sig == SIGTSTP)
	{
		tputs(tgetstr("te", NULL), 1, ft_putchar_err);
		tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
		tcsetattr(2, 0, &g_inherit_term);
		exit(0);
	}
	else if (sig == SIGWINCH)
	{
		set_win_size();
		print_border();
		//print_list();
	}
}
