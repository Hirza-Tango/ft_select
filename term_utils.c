/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:44:36 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/08 18:50:26 by dslogrov         ###   ########.fr       */
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