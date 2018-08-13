/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:01:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/13 11:34:44 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	border_top_bottom(void)
{
	size_t i;
	size_t j;
	const int cols[4] = {0, 1, g_term_lines - 2, g_term_lines - 1};

	j = 0;
	while (j < 4)
	{
		SET_POS(0, cols[j]);
		SET_STYLE(F_F_MAGENTA);
		if (j < 2)
			ft_putstr("//");
		else
			ft_putstr("\\\\");
		SET_STYLE(F_F_RED);
		i = 2;
		while (i++ < g_term_cols - 2)
			ft_putchar('-');
		SET_STYLE(F_F_MAGENTA);
		if (j < 2)
			ft_putstr("\\\\");
		else
			ft_putstr("//");
		SET_STYLE(F_F_DEFAULT);
		j++;
	}
}

void	border_left_right(void)
{
	size_t i;
	size_t j;

	j = 2;
	while (j < g_term_lines - 2)
	{
		SET_POS(0, j);
		SET_STYLE(F_F_RED);
		ft_putstr("||");
		SET_STYLE(F_NORMAL);
		SET_POS(g_term_cols - 2, j);
		SET_STYLE(F_F_RED);
		ft_putstr("||");
		j++;
	}
}

void	print_border()
{
	size_t i;
	size_t j;

	CLEAR_SCREEN();
	SET_POS((g_term_cols - 20) / 2, 3); //position at cen
	SET_STYLE(F_F_CYAN);
	SET_UNDERLINE();
	ft_putstr("FT_SELECT by dslogrov");
	UNSET_UNDERLINE();
	SET_STYLE(F_NORMAL);
	border_top_bottom();
	border_left_right();
	/*j = 3;
	while (j < g_term_lines - 3)
	{
		SET_POS(j + 1, 1);
		if (j == g_term_lines / 2)
		{
			SET_STYLE(F_F_YELLOW);
			ft_putstr("<<");
		}
		else
		{
			SET_STYLE(F_F_RED);
			ft_putstr("||");
		}
		SET_POS(j + 1, g_term_cols - 1);
		if (j == g_term_lines / 2)
		{
			SET_STYLE(F_F_YELLOW);
			ft_putstr(">>");
		}
		else
		{
			SET_STYLE(F_F_RED);
			ft_putstr("||");
		}
		j++;
	}
	while (j++ < g_term_lines)
	{
		SET_POS(j, 1);
		SET_STYLE(F_F_MAGENTA);
		ft_putstr("\\\\");
		SET_STYLE(F_F_RED);
		i = 1;
		while (i++ < g_term_cols - 2)
			ft_putchar('-');
		SET_STYLE(F_F_MAGENTA);
		ft_putstr("//");
	}*/
	SET_STYLE(F_NORMAL);
}
