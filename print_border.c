/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:01:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/10 13:05:00 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	print_border()
{
	size_t i;
	size_t j;
	
	j = 0;
	CLEAR_SCREEN();
	SET_POS(3, (g_term_cols - 20) / 2); //position at cen
	SET_STYLE(F_F_BLACK);
	SET_UNDERLINE();
	ft_putstr("FT_SELECT by dslogrov");
	UNSET_UNDERLINE();
	SET_STYLE(F_NORMAL);
	/*SET_POS(1, 1);
	while (j < 2)
	{
		SET_STYLE(F_F_MAGENTA);
		ft_putstr("////");
		SET_STYLE(F_F_RED);
		i = 4;
		//while (i++ < g_term_cols - 4)
		//	ft_putchar('-');
		SET_STYLE(F_F_MAGENTA);
		ft_putstr("\\\\\\\\");
		SET_STYLE(F_F_DEFAULT);
		j++;
	}
	while (j < g_term_lines - 2)
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
		ft_putstr("\\\\\\\\");
		SET_STYLE(F_F_RED);
		i = 4;
		//while (i++ < g_term_cols - 4)
		//	ft_putchar('-');
		SET_STYLE(F_F_MAGENTA);
		ft_putstr("////");
	}
	*/
	SET_STYLE(F_NORMAL);
}

int main()
{
	//tputs(tgetstr("cl", NULL), 1, ft_putchar_err);
	//ft_putstr("\e[2J");
}