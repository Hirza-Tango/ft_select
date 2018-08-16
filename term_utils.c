/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:44:36 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 15:27:10 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			set_style(char style)
{
	if (ft_strequ(getenv("TERM"), "xterm-256color"))
	{
		ft_putstr_fd("\033[", g_tty);
		ft_putnbr_fd(style, g_tty);
		ft_putchar_fd('m', g_tty);
	}
}

void			set_win_size(void)
{
	struct winsize	w;

	if (ioctl(g_tty, TIOCGWINSZ, &w) == -1)
	{
		g_term_cols = tgetnum("co");
		g_term_lines = tgetnum("li");
	}
	else
	{
		g_term_cols = w.ws_col;
		g_term_lines = w.ws_row;
	}
}

int				ft_putchar_err(int c)
{
	ft_putchar_fd((char)c, g_tty);
	return (1);
}

unsigned char	ft_listwidth(t_list *list)
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		ret = MAX(ft_strlen(((t_entry *)list->content)->name), ret);
		list = list->next;
	}
	return (ret);
}
