/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:09:29 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 15:24:09 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		colourise(mode_t mode)
{
	if ((mode & __S_IFMT) == __S_IFDIR)
	{
		set_style(F_F_BLACK);
		if (mode & S_IWOTH)
			set_style(mode & __S_ISVTX ? F_B_YELLOW : F_B_GREEN);
		else
			set_style(F_F_BLUE);
	}
	else if ((mode & __S_IFMT) == __S_IFREG && mode & S_IXUSR)
	{
		set_style(F_F_BLACK);
		if (mode & S_ISGID || mode & S_ISUID)
			set_style(mode & S_ISGID ? F_B_CYAN : F_B_RED);
		else
			set_style(F_F_RED);
	}
	else if ((mode & __S_IFMT) == __S_IFCHR || (mode & __S_IFMT) == __S_IFBLK)
	{
		set_style(F_F_BLUE);
		set_style((mode & __S_IFMT) == __S_IFCHR ? F_B_CYAN : F_B_YELLOW);
	}
	(mode & __S_IFMT) == __S_IFIFO ? set_style(F_F_YELLOW) : (void)0;
	(mode & __S_IFMT) == __S_IFSOCK ? set_style(F_F_GREEN) : (void)0;
	(mode & __S_IFMT) == __S_IFLNK ? set_style(F_F_MAGENTA) : (void)0;
}

static t_list	*print_row(int j, t_list *list)
{
	size_t			i;
	const size_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);

	i = 0;
	while (i < cols && list)
	{
		SET_POS(4 + (g_info.list_width + 2) * i, 4 + (j * 2));
		j * cols + i == g_info.active ? SET_UNDERLINE() : (void)0;
		((t_entry *)list->content)->active ? SET_REV_VID() : (void)0;
		colourise(((t_entry *)list->content)->mode);
		ft_printf_fd(g_tty, "%-*s", g_info.list_width,
			((t_entry *)list->content)->name);
		UNSET_UL_REV_VID();
		set_style(0);
		list = list->next;
		i++;
	}
	if (i == cols)
		return (list);
	while (i < cols)
	{
		SET_POS(4 + (g_info.list_width + 2) * i++, 4 + (j * 2));
		ft_printf_fd(g_tty, "%-*s", g_info.list_width, "");
	}
	return (NULL);
}

static void		print_middle(void)
{
	const size_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);
	const size_t	rows = (g_term_lines - 7) / 2;
	size_t			i;
	size_t			j;
	t_list			*dup;

	j = 0;
	dup = g_info.list;
	while ((dup = print_row(j, dup)))
		j++;
	j++;
	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			SET_POS(4 + (g_info.list_width + 2) * i, 4 + (j * 2));
			ft_printf_fd(g_tty, "%-*s", g_info.list_width, "");
			i++;
		}
		j++;
	}
}

void			display_list(void)
{
	const size_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);
	const size_t	rows = (g_term_lines - 7) / 2;

	if (g_term_cols < 9 || g_term_lines < 8)
		return ;
	if ((cols * rows) < g_info.list_length)
	{
		SET_POS(4, 4);
		ft_putstr_fd("Cannot display without scrolling.", g_tty);
	}
	else
		print_middle();
}
