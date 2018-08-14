/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/14 14:48:38 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	parse_signals(void)
{
	const int	sigs[6] = {SIGINT, SIGTERM, SIGQUIT, SIGHUP, SIGWINCH};
	int			i;

	i = 0;
	while (i < 6)
		signal(sigs[i++], signals);
}

void	signals(int sig)
{
	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT
	|| sig == SIGHUP)
	{
		tputs(tgetstr("te", NULL), 1, ft_putchar_err);
		tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
		tcsetattr(g_tty, 0, &g_inherit_term);
		exit(0);
	}
	else if (sig == SIGWINCH)
	{
		set_win_size();
		print_border();
		print_list();
	}
}
