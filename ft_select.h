/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:41:42 by tango             #+#    #+#             */
/*   Updated: 2018/08/10 13:02:51 by dslogrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <ft_printf.h>

# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <termcap.h>
# include <signal.h>

struct termios	g_inherit_term;
struct termios	g_term;
size_t			g_term_cols;
size_t			g_term_lines;
int				g_tty;

enum			e_font_effects
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

typedef struct	s_entry
{
	char	name[255];
	char	mode;
}				t_entry;

# define SET_POS(x,y) (tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_putchar_err))
# define SET_UNDERLINE() (tputs(tgetstr("us", NULL), 1, ft_putchar_err))
# define UNSET_UNDERLINE() (tputs(tgetstr("ue", NULL), 1, ft_putchar_err))
# define SET_REV_VID() (tputs(tgetstr("mr", NULL), 1, ft_putchar_err))
# define UNSET_UL_REV_VID() (tputs(tgetstr("me", NULL), 1, ft_putchar_err))
# define SET_STYLE(x) (ft_printf("\e[%zum", x))
# define CLEAR_SCREEN() (tputs(tgetstr("cl", NULL), 1, ft_putchar_err))

void			set_win_size(void);
int				ft_putchar_err(int c);

#endif