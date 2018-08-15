/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dslogrov <dslogrove@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 19:41:42 by tango             #+#    #+#             */
/*   Updated: 2018/08/15 15:53:54 by dslogrov         ###   ########.fr       */
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
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_entry
{
	char	*name;
	mode_t	mode;
	char	active;
}				t_entry;

typedef struct	s_listinfo
{
	t_list	*list;
	size_t	list_length;
	size_t	list_width;
	size_t	active;
}				t_listinfo;

struct termios	g_inherit_term;
size_t			g_term_cols;
size_t			g_term_lines;
t_listinfo		g_info;
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

# define SET_POS(x,y) (tputs(tgoto(tgetstr("cm", NULL), x, y), 1, ft_putchar_err))
# define SET_UNDERLINE() (tputs(tgetstr("us", NULL), 1, ft_putchar_err))
# define UNSET_UNDERLINE() (tputs(tgetstr("ue", NULL), 1, ft_putchar_err))
# define SET_REV_VID() (tputs(tgetstr("mr", NULL), 1, ft_putchar_err))
# define UNSET_UL_REV_VID() (tputs(tgetstr("me", NULL), 1, ft_putchar_err))
# define CLEAR_SCREEN() (tputs(tgetstr("cl", NULL), 1, ft_putchar_err))

void			set_win_size(void);
int				ft_putchar_err(int c);
void			set_style(char style);
void			init_term(void);
void			print_border(void);
void			parse_signals(void);
void			signals(int sig);
unsigned char	ft_listwidth(t_list *list);
void			print_list(void);
void			list_toggle(void);

void			move_up(void);
void			move_down(void);
void			move_left(void);
void			move_right(void);

#endif