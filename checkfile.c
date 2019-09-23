/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:25:54 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/21 21:05:26 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_len_line(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i])
		{
			c++;
			while (str[i] != ' ' && str[i] != '\t' && str[i])
				i++;
		}
	}
	return (c);
}

t_vect		ft_check(char **av)
{
	int		fd;
	char	*tmp;
	t_vect	f;

	fd = open(av[1], O_RDONLY);
	if (get_next_line(fd, &tmp) <= 0)
		error();
	if (!(f.a = ft_len_line(tmp)))
		error();
	ft_strdel(&tmp);
	f.b = 1;
	while (get_next_line(fd, &tmp))
	{
		if (ft_len_line(tmp) < f.a)
		{
			ft_strdel(&tmp);
			ft_putstr("Found wrong line length. Exiting.\n");
			exit(0);
		}
		f.b++;
		ft_strdel(&tmp);
	}
	return (f);
}

t_var		ft_stock_cord(char **av, t_var *f)
{
	t_vect	i;
	t_vect	j;
	int		fd;
	int		v;
	t_var	error;

	error.error = 1;
	i = ft_check(av);
	if (i.a > 0 && i.b > 0)
	{
		f->c = i.a;
		f->l = i.b;
		v = scale_calcul(*f);
		fd = open(av[1], O_RDONLY);
		if (!(f->tab = (t_point**)malloc(sizeof(t_point*) * f->l)) ||
				!(f->cp = (t_point**)malloc(sizeof(t_point*) * f->l)))
			return (error);
		j.a = 0;
		fill_data(fd, f, j, v);
		close(fd);
		f->etat = 0;
		return (*f);
	}
	return (*f);
}

int			scale_calcul(t_var f)
{
	int scalex;
	int scaley;

	scalex = 1;
	scaley = 1;
	while (scalex * f.l < (1500 * 0.5))
		scalex++;
	while (scaley * f.c < (1500 * 0.5))
		scaley++;
	return ((scalex > scaley) ? scaley : scalex);
}

t_vect		steps(t_point **tab, int ligne, int colon)
{
	int		i;
	int		j;
	t_vect	x;
	t_vect	y;
	t_vect	step;

	i = -1;
	x.a = 0;
	x.b = 0;
	y.a = 0;
	y.b = 0;
	while (++i < ligne)
	{
		j = -1;
		while (++j < colon)
		{
			x.a = (tab[i][j].x > x.a) ? tab[i][j].x : x.a;
			x.b = (tab[i][j].x < x.b) ? tab[i][j].x : x.b;
			y.a = (tab[i][j].y > y.a) ? tab[i][j].y : y.a;
			y.b = (tab[i][j].y < y.b) ? tab[i][j].y : y.b;
		}
	}
	step.a = 1500 / 2 - (x.a + x.b) / 2;
	step.b = 1500 / 2 - (y.a + y.b) / 2;
	return (step);
}
