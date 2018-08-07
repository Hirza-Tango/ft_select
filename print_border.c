/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:01:25 by dslogrov          #+#    #+#             */
/*   Updated: 2018/08/07 14:48:42 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	print_border()
{
	struct winsize w;
	ioctl(1, TIOCGWINSZ, &w);
	
	size_t cols = w.ws_col;
	size_t lines = w.ws_row - 1;
	size_t i;
	size_t j;
	char tmp[1];
	
	j = 0;
	printf("\e[1J"); //clear screen
	printf("\e[3;%zuH", (cols - 20) / 2); //position at center
	printf("\e[37m"); //black
	printf("\e[4m"); //underline
	printf("\e[42m");
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
		while (i++ < cols - 4)
			printf("-");
		printf("\e[35m"); //magenta
		printf("\\\\\\\\");
		printf("\e[24m");
		j++;
	}
	while (j < lines - 2)
	{
		printf("\e[%zuH", j + 1); //position at left
		if (j == lines / 2)
		{
			printf("\e[33m"); //red
			printf("<<");
		}
		else
		{
			printf("\e[31m"); //red
			printf("||");
		}
		printf("\e[%zu;%zuH", j + 1, cols - 1); //position right
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
	while (j++ < lines)
	{
		printf("\e[%zuH", j);
		printf("\e[35m"); //magenta
		printf("\\\\\\\\");
		printf("\e[31m"); //red
		i = 4;
		while (i++ < cols - 4)
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