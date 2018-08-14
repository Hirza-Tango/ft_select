/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:53:49 by tango             #+#    #+#             */
/*   Updated: 2018/08/14 14:58:37 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		entry_del(void *content, size_t size)
{
	(void)(content && size);
}

void		delete(void)
{
	ft_lstrm(&(g_info.list), g_info.active, entry_del);
	g_info.list_length--;
	if (!g_info.list_length)
		signals(SIGTERM);
	if (g_info.active == g_info.list_length)
		g_info.active--;
}

void		init_term(void)
{
	const char	*terminal = getenv("TERM");
	char		findings;

	if (!terminal)
	{
		ft_putendl_fd("Error: TERM variable not found", g_tty);
		exit(1);
	}
	if ((findings = tgetent(NULL, terminal)) != 1)
	{
		if (!findings)
			ft_putendl_fd("Error: No entry for TERM in terminfo database", g_tty);
		else if (findings < 0)
			ft_putendl_fd("Error: Terminfo database could not be found", g_tty);
		exit(1);
	}
	g_tty = open(ttyname(0), O_RDWR | O_NDELAY);
	set_win_size();
	tcgetattr(g_tty, &g_inherit_term);
	g_term = g_inherit_term;
	g_term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(g_tty, 0, &g_term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_err);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
}

void		handle_char(long c)
{
	if (c == 10)
	{
		//return selections
		signals(SIGINT);
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

t_listinfo	init_list(int argc, char **argv)
{
	t_list		*list;
	struct stat	s;
	t_listinfo	info;
	t_entry		ent;

	list = NULL;
	while (--argc)
	{
		ent.name = argv[argc];
		ent.mode = lstat(argv[argc], &s) == -1 ? 0 : s.st_mode;
		ent.active = 0;
		ft_lstadd(&list, ft_lstnew(&ent, sizeof(ent)));
	}
	if (!list)
	{
		ft_putendl("No arguments given");
		exit(0);
	}
	info.active = 0;
	info.list = list;
	info.list_length = ft_lstlen(list);
	info.list_width = ft_listwidth(list);
	return (info);
}

int			main(int argc, char **argv)
{
	long		input;

	g_info = init_list(argc, argv);
	parse_signals();
	init_term();
	print_border();
	while (1)
	{
		print_list();
		input = 0;
		read(0, &input, 8);
		handle_char(input);
	}
}
