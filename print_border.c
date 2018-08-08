/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:01:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/08 18:42:00 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	print_border()
{
	size_t i;
	size_t j;
	char tmp[1];
	
	j = 0;
	CLEAR_SCREEN();
	SET_POS(3, (g_term_cols - 20) / 2); //position at cen
	SET_STYLE(F_F_BLACK);
	printf("\e[37m"); //black
	printf("\e[4m"); //underline

	printf("FT_SELECT by dslogrov");
	printf("\e[0m"); //reset
	printf("\e[H"); //Cursor home
	printf("\e[34m");
	while (j < 2)
	{
		printf("\e[35m"); //magenta
		printf("////");
		printf("\e[31m"); //red
		i = 4;
		while (i++ < g_term_cols - 4)
			printf("-");
		printf("\e[35m"); //magenta
		printf("\\\\\\\\");
		printf("\e[24m");
		j++;
	}
	while (j < g_term_lines - 2)
	{
		printf("\e[%zuH", j + 1); //position at left
		if (j == g_term_lines / 2)
		{
			printf("\e[33m"); //red
			printf("<<");
		}
		else
		{
			printf("\e[31m"); //red
			printf("||");
		}
		printf("\e[%zu;%zuH", j + 1, g_term_cols - 1); //position right
		if (j == lines / 2)
		{
			printf("\e[33m"); //red
			printf(">>");
		}
		else
		{
			printf("\e[31m"); //red
			printf("||");
		}
		j++;
	}
	while (j++ < g_term_lines)
	{
		printf("\e[%zuH", j);
		printf("\e[35m"); //magenta
		printf("\\\\\\\\");
		printf("\e[31m"); //red
		i = 4;
		while (i++ < g_term_cols - 4)
			printf("-");
		printf("\e[35m"); //magenta
		printf("////");
	}
	printf("\e[m");
}

int main()
{
	print_border();
}