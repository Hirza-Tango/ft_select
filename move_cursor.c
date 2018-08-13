/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:21:16 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/13 22:56:39 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	move_up(t_listinfo *info)
{
	const size_t	cols = (g_term_cols - 6) / (info->list_width + 2);
	const size_t	rows = info->list_length / cols + 1;

	if (!info->active - cols < 0L)
		info->active += info->list_length;
	info->active -= cols;
}

void	move_down(t_listinfo *info)
{
	const size_t	cols = (g_term_cols - 6) / (info->list_width + 2);
	const size_t	rows = info->list_length / cols + 1;

	if (info->active + cols >= info->list_length)
		info->active -= rows * cols;
	info->active += cols;
}

/*void	move_left(t_listinfo *info)
{
	const size_t	cols = (g_term_cols - 6) / (info->list_width + 2);

	if (!info->active_col)
		info->active_col = cols - 1;
	else
		info->active_col--;
}

void	move_right(t_listinfo *t)
{

}
*/