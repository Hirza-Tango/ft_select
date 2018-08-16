/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:25:31 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/16 15:46:34 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

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

void		list_toggle(void)
{
	size_t			i;
	t_list			*dup;

	i = 0;
	dup = g_info.list;
	while (dup)
	{
		if (i++ == g_info.active)
			((t_entry *)dup->content)->active =
				((t_entry *)dup->content)->active ^ 1;
		dup = dup->next;
	}
	move_right();
}

void		list_print(void)
{
	int i;

	i = 0;
	while (g_info.list)
	{
		if (((t_entry *)g_info.list->content)->active)
		{
			if (i)
				ft_putchar(' ');
			else
				i = 1;
			ft_putstr(((t_entry *)g_info.list->content)->name);
		}
		g_info.list = g_info.list->next;
	}
}
