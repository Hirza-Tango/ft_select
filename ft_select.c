/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:53:49 by tango             #+#    #+#             */
/*   Updated: 2018/08/13 16:41:07 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	init_term(void)
{	
	if (tgetent(NULL, getenv("TERM")) != 1)
	{
		//TODO: more thorough error handling
		ft_putstr("Error: Could not load entry\n");
		exit(1);
	}
	set_win_size();
	tcgetattr(2, &g_inherit_term);
	g_term = g_inherit_term;
	g_term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(2, 0, &g_term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_err);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
}

void	handle_char(long c)
{
	if (c == 10)
	{
		//return selections
		SET_POS(5, g_term_cols / 2);
		ft_putstr("ENTR");
		signals(SIGINT);
	}
	if (c == 27)
	{
		signals(SIGINT);
	}
	if (c == 4283163)
	{
		move_up();
	}
	if (c == 4348699)
	{
		move_down();
	}
	if (c == 4479771)
	{
		SET_POS(5, g_term_cols / 2);
		ft_putstr("LEFT");
	}
	if (c == 4414235)
	{
		SET_POS(5, g_term_cols / 2);
		ft_putstr("RIGH");
	}
	if (c == 8 || c == 127 || c == 2117294875L)
	{
		SET_POS(5, g_term_cols / 2);
		ft_putstr("DEL ");
	}
	if (c == 32)
		//toggle selection
	{
		SET_POS(5, g_term_cols / 2);
		ft_putstr("SPC ");
	}
	//ignore other keys
}

t_listinfo	init_list(int argc, char **argv)
{
	t_list 		*list;
	struct stat	s;
	t_listinfo	info;
	t_entry		ent;

	list = NULL;
	while (--argc)
	{
		ent.name = argv[argc];
		ent.mode = lstat(argv[argc], &s) ? 0 : s.st_mode;
		ent.active = 0;
		ft_lstadd(&list, ft_lstnew(&ent, sizeof (ent)));
	}
	info.active_row = 0;
	info.active_col = 0;
	info.list = list;
	info.list_length = ft_lstlen(list);
	info.list_width = ft_listwidth(list);
	info.left_col = 0;
	return (info);
}

int		main(int argc, char **argv, char **env)
{
	long input;

	g_list_info = init_list(argc, argv);
	parse_signals();
	init_term();
	while (1)
	{
		print_border();
		print_list();
		input = 0;
		read(2, &input, 8);
		handle_char(input);
	}
}