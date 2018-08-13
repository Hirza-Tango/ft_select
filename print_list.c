/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:09:29 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/13 23:01:51 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
/*
void	colourise(mode_t mode)
{
	const mode_t	type = mode & S_IFMT;

	if (type == S_ISDIR)
	{
		set_style(F_F_BLACK);
		if (mode & S_IWOTH)
			set_style(mode & S_ISTXT ? F_B_YELLOW : F_B_GREEN);
		else
			set_style(F_F_BLUE);
	}
	else if (type == S_ISREG && mode & S_IXUSR)
	{
		set_style(F_F_BLACK);
		if (mode & S_ISGID)
			set_style(F_B_CYAN);
		else if (mode & S_ISUID)
			set_style(F_B_RED);
		else
			set_style(F_F_RED);		
	}
	else if (type == S_ISCHR || type == S_ISBLK)
	{
		set_style(F_F_BLUE);
		set_style(type == S_ISCHR ? F_B_CYAN : F_B_YELLOW);
	}
	else if (type == S_ISPIPE)
		set_style(F_F_YELLOW);
	else if (type == S_ISSOCK)
		set_style(F_F_GREEN);
	else if (type == S_ISLNK)
		set_style(F_F_MAGENTA);

}*/

void	print_list(t_listinfo info)
{
	const size_t	cols = (g_term_cols - 6) / (info.list_width + 2);
	const size_t	rows = (g_term_lines - 7) / info.list_length;
	size_t			i;
	size_t			j;
	t_list			*dup;

	dup = info.list;
	i = 0;
	j = 0;
	if (cols * rows >= info.list_length)
	{

	}
	else
		while (dup)
		{
			i = 0;
			while (i < cols && dup)
			{
				SET_POS(4 + (info.list_width + 2) * i, 4 + (j * 2));
				if (!info.active--)
					SET_UNDERLINE();
				if (((t_entry *)dup->content)->active)
					SET_REV_VID();
				//colourise(((t_entry *)dup->content)->mode);
				ft_printf("%-*s", info.list_width, ((t_entry *)dup->content)->name);
				UNSET_UL_REV_VID();
				set_style(0);
				dup = dup->next;
				i++;
			}
			j++;
		}
}