/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:41:42 by tango             #+#    #+#             */
/*   Updated: 2018/08/08 17:41:28 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>

# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <signal.h>

struct termios	g_inherit_term;
struct termios	g_term;

enum	e_font_effects
{
	F_NORMAL	= 0,
	F_INV_VIDEO = 7,
	F_UNDERLINE = 4,
	F_UNDERLINE_OFF = 24,
	F_INV_VIDEO_OFF = 27,
	F_F_BLACK	= 30,
	F_F_RED		= 31,
	F_F_GREEN	= 32,
	F_F_YELLOW	= 33,
	F_F_BLUE	= 34,
	F_F_MAGENTA	= 35,
	F_F_CYAN	= 36,
	F_F_WHITE	= 37,
	F_F_DEFAULT = 39,
	F_B_BLACK	= 40,
	F_B_RED		= 41,
	F_B_GREEN	= 42,
	F_B_YELLOW	= 43,
	F_B_BLUE	= 44,
	F_B_MAGENTA	= 45,
	F_B_CYAN	= 46,
	F_B_WHITE	= 47,
	F_B_DEFAULT = 49
};

#endif