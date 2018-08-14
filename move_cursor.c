/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/14 13:38:17 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	move_up(void)
{
	const intmax_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);
	const intmax_t	rows = g_info.list_length / cols + 1;

	if ((intmax_t)g_info.active - cols < 0L)
	{
		g_info.active = g_info.active % cols + (rows - 1) * cols;
		if (g_info.active > g_info.list_length - 1)
			g_info.active -= cols;
	}
	else
		g_info.active -= cols;
}

void	move_down(void)
{
	const size_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);

	g_info.active += cols;
	if (g_info.active >= g_info.list_length)
		g_info.active %= cols;
}

void	move_left(void)
{
	if (!g_info.active)
		g_info.active = g_info.list_length - 1;
	else
		g_info.active--;
}

void	move_right(void)
{
	if (g_info.active == g_info.list_length - 1)
		g_info.active = 0;
	else
		g_info.active++;
}

void	list_toggle(void)
{
	size_t			i;
	t_list			*dup;

	i = 0;
	dup = g_info.list;
	while (dup)
	{
		if (i++ == g_info.active)
			((t_entry *)dup->content)->active =
				((t_entry *)dup->content)->active ^ 1;
		dup = dup->next;
	}
	move_right();
}
