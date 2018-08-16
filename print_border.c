/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:01:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 14:31:40 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	border_top_bottom(void)
{
	size_t		i;
	size_t		j;
	const int	cols[4] = {0, 1, g_term_lines - 2, g_term_lines - 1};

	j = 0;
	while (j < 4)
	{
		SET_POS(0, cols[j]);
		set_style(F_F_MAGENTA);
		ft_putstr_fd(j < 2 ? "//" : "\\\\", g_tty);
		set_style(F_F_RED);
		i = 2;
		while (i++ < g_term_cols - 2)
			ft_putchar_fd('-', g_tty);
		set_style(F_F_MAGENTA);
		ft_putstr_fd(j < 2 ? "\\\\" : "//", g_tty);
		set_style(F_F_DEFAULT);
		j++;
	}
}

void	border_left_right(void)
{
	size_t j;

	j = 2;
	while (j < g_term_lines - 2)
	{
		SET_POS(0, j);
		set_style(F_F_RED);
		ft_putstr_fd("||", g_tty);
		set_style(F_NORMAL);
		SET_POS(g_term_cols - 2, j);
		set_style(F_F_RED);
		ft_putstr_fd("||", g_tty);
		j++;
	}
}

void	display_border(void)
{
	CLEAR_SCREEN();
	if (g_term_cols < 9 || g_term_lines < 8)
	{
		SET_POS(0, 0);
		ft_putstr_fd("Window is too small. Please resize", g_tty);
		return ;
	}
	SET_POS((g_term_cols - 20) / 2, 2);
	set_style(F_F_CYAN);
	SET_UNDERLINE();
	ft_putstr_fd("FT_SELECT_by_dslogrov", g_tty);
	UNSET_UNDERLINE();
	set_style(F_NORMAL);
	border_top_bottom();
	border_left_right();
	set_style(F_NORMAL);
}
