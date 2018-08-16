/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:54:51 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 14:33:12 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	init_error(int tty)
{
	const char		*terminal = getenv("TERM");
	char			findings;

	if (!terminal)
	{
		ft_putendl_fd("Error: TERM variable not found", 2);
		exit(1);
	}
	if (!isatty(g_tty))
	{
		ft_putendl_fd("Error: not a tty. Please call from a tty", 2);
		exit(1);
	}
	if ((findings = tgetent(NULL, terminal)) != 1)
	{
		if (!findings)
			ft_putendl_fd("Error: TERM entry not in terminfo database", g_tty);
		else if (findings < 0)
			ft_putendl_fd("Error: Terminfo database could not be found", g_tty);
		exit(1);
	}
}

void		init_term(void)
{
	struct termios	term;

	g_tty = open(ttyname(2), O_RDWR);
	init_error(g_tty);
	set_win_size();
	tcgetattr(g_tty, &g_inherit_term);
	term = g_inherit_term;
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_oflag &= ~OPOST;
	tcsetattr(g_tty, TCSAFLUSH, &term);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_err);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
}

int			reset_term(void)
{
	tputs(tgetstr("te", NULL), 1, ft_putchar_err);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
	tcsetattr(g_tty, 0, &g_inherit_term);
	close(g_tty);
	return (0);
}
