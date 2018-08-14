/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:09:29 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/14 12:28:22 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	colourise(mode_t mode)
{
	const mode_t	type = mode & S_IFMT;

	if (type == S_IFDIR)
	{
		set_style(F_F_BLACK);
		if (mode & S_IWOTH)
			set_style(mode & S_ISTXT ? F_B_YELLOW : F_B_GREEN);
		else
			set_style(F_F_BLUE);
	}
	else if (type == S_IFREG && mode & S_IXUSR)
	{
		set_style(F_F_BLACK);
		if (mode & S_ISGID)
			set_style(F_B_CYAN);
		else if (mode & S_ISUID)
			set_style(F_B_RED);
		else
			set_style(F_F_RED);
	}
	else if (type == S_IFCHR || type == S_IFBLK)
	{
		set_style(F_F_BLUE);
		set_style(type == S_IFCHR ? F_B_CYAN : F_B_YELLOW);
	}
	else if (type == S_IFIFO)
		set_style(F_F_YELLOW);
	else if (type == S_IFSOCK)
		set_style(F_F_GREEN);
	else if (type == S_IFLNK)
		set_style(F_F_MAGENTA);
}

void	print_list(void)
{
	const size_t	cols = (g_term_cols - 6) / (g_info.list_width + 2);
	const size_t	rows = (g_term_lines - 7) / g_info.list_length;
	size_t			i;
	size_t			j;
	t_list			*dup;

	dup = g_info.list;
	j = 0;
	if (cols * rows > g_info.list_length)
	{
	}
	else
		while (dup)
		{
			i = 0;
			while (i < cols && dup)
			{
				SET_POS(4 + (g_info.list_width + 2) * i, 4 + (j * 2));
				if (j * cols + i == g_info.active)
					SET_UNDERLINE();
				if (((t_entry *)dup->content)->active)
					SET_REV_VID();
				colourise(((t_entry *)dup->content)->mode);
				ft_printf("%-*s", g_info.list_width,
					((t_entry *)dup->content)->name);
				UNSET_UL_REV_VID();
				set_style(0);
				dup = dup->next;
				i++;
			}
			while (i < cols)
			{
				SET_POS(4 + (g_info.list_width + 2) * i, 4 + (j * 2));
				ft_printf("%-*s", g_info.list_width, "");
				i++;
			}
			j++;
		}
		while (j < rows)
		{
			i = 0;
			while (i < cols)
			{
				SET_POS(4 + (g_info.list_width + 2) * i, 4 + (j * 2));
				ft_printf("%-*s", g_info.list_width, "");
				i++;
			}
			j++;
		}
}
