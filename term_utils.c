/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:44:36 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/14 11:37:28 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			set_style(char style)
{
	if (ft_strequ(getenv("TERM"), "xterm-256color"))
	{
		ft_putstr("\033[");
		ft_putnbr(style);
		ft_putchar('m');
	}
}

void			set_win_size(void)
{
	struct winsize	w;

	ioctl(2, TIOCGWINSZ, &w);
	g_term_cols = w.ws_col;
	g_term_lines = w.ws_row;
}

int				ft_putchar_err(int c)
{
	ft_putchar_fd((char)c, 2);
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
