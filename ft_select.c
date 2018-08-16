/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:53:49 by tango             #+#    #+#             */
/*   Updated: 2018/08/16 14:29:57 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	entry_del(void *content, size_t size)
{
	(void)(content && size);
}

static void	delete(void)
{
	ft_lstrm(&(g_info.list), g_info.active, entry_del);
	g_info.list_length--;
	if (!g_info.list_length)
		signals(SIGTERM);
	if (g_info.active == g_info.list_length)
		g_info.active--;
}

void		handle_char(long c)
{
	if (c == 10)
	{
		reset_term();
		list_print();
		exit(0);
	}
	if (c == 27)
		signals(SIGINT);
	if (c == 4283163)
		move_up();
	if (c == 4348699)
		move_down();
	if (c == 4479771)
		move_left();
	if (c == 4414235)
		move_right();
	if (c == 8 || c == 127 || c == 2117294875L)
		delete();
	if (c == 32)
		list_toggle();
}

int			main(int argc, char **argv)
{
	long		input;

	g_info = init_list(argc, argv);
	init_term();
	display_border();
	parse_signals();
	while (1)
	{
		display_list();
		input = 0;
		read(g_tty, &input, 8);
		handle_char(input);
	}
}
