/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:26:22 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 18:10:27 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_point;

typedef struct		s_vect
{
	int				a;
	int				b;
}					t_vect;

typedef struct		s_var
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				l;
	int				c;
	int				error;
	int				h;
	int				etat;
	double			k;
	t_point			**tab;
	t_point			**cp;
	t_vect			step;
}					t_var;

typedef struct		s_bres
{
	t_point			beg;
	t_point			end;
	int				abs;
	int				ord;
	int				dx;
	int				dy;
	int				stepx;
	int				stepy;
	int				p;
	int				i;

}					t_bres;

char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_len_line(char *str);
t_vect				ft_check(char **av);
t_var				ft_stock_cord(char **av, t_var *f);
int					scale_calcul(t_var f);
t_vect				steps(t_point **tab, int ligne, int colon);
void				part1(t_bres v, void *mlx_ptr, void *win_ptr, t_vect start);
void				part2(t_bres v, void *mlx_ptr, void *win_ptr, t_vect start);
void				draw_line(t_point p1, t_point p2, t_var f);
void				draw(t_var f, int var);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
char				**ft_split_whitespaces(char *str);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *str);
void				zoom_moins(t_var *f);
void				zoom_plus(t_var *f);
void				trans(t_var *f, int keycode);
void				centralisation(t_var *f);
int					key_press(int keycode, t_var *t);
void				haut_decri(t_var *f);
void				haut_incri(t_var *f);
void				iso(double *x, double *y, double *z, double k);
void				iso_a(t_var *f);
void				more_iso(t_var *f);
void				para(t_var *f);
void				event(t_var *f);
int					ft_atoi_hex(char *str);
int					comma(char *str);
void				fill_data(int fd, t_var *f, t_vect j, int v);
void				free_tmp(char **tab);
void				error(void);
void				*ft_memset(void *b, int c, size_t len);
void				color_change(t_var *f);
int					get_color(t_vect current, t_point start, t_point end);
void				menu(t_var f);
#endif
