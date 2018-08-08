/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/08 18:36:11 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	signals(int sig)
{
	if (sig == SIGINT || sig == SIGTERM || sig == SIGQUIT
	|| sig == SIGHUP || sig == SIGTSTP)
	{
		tcsetattr(0, 0, &g_inherit_term);
		exit(0);
	}
	else if (sig == SIGWINCH)
	{
		set_term_size();
		print_border();
		print_list();
	}
}
