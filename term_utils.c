/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:44:36 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/10 13:04:15 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**	Sets terminal style to the given parameters
*/

void	set_win_size(void)
{
	struct winsize	w;

	ioctl(g_tty, TIOCGWINSZ, &w);
	g_term_cols = w.ws_col;
	g_term_lines = w.ws_row;
}

int		ft_putchar_err(int c)
{
	ft_putchar_fd((char)c, 2);
	return (1);
}
