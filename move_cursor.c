/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/13 16:46:06 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	move_up(t_listinfo *info)
{
	const size_t		rows = (g_term_lines - 8) / 2;

	if (!info->active_row)
		info->active_row = rows - 1;
	else
		info->active_row--;
}

void	move_down(t_listinfo *info)
{
	const size_t		rows = (g_term_lines - 8) / 2;

	if (info->active_row == rows - 1)
		info->active_row = 0;
	else
		info->active_row++;
}

void	move_left(t_listinfo *t)
{

}

void	move_right(t_listinfo *t)
{

}