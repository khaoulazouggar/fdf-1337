/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:00:45 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 16:32:09 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_moins(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->tab[i][j].x /= 2;
			f->tab[i][j].y /= 2;
			f->cp[i][j].x /= 2;
			f->cp[i][j].y /= 2;
			j++;
		}
		i++;
	}
	centralisation(f);
}

void		zoom_plus(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->tab[i][j].x *= 2;
			f->tab[i][j].y *= 2;
			f->cp[i][j].x *= 2;
			f->cp[i][j].y *= 2;
			j++;
		}
		i++;
	}
	centralisation(f);
}

void		trans(t_var *f, int keycode)
{
	if (keycode == 124)
		f->step.a += 100;
	if (keycode == 123)
		f->step.a -= 100;
	if (keycode == 125)
		f->step.b += 100;
	if (keycode == 126)
		f->step.b -= 100;
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	if (f->etat == 0)
		draw(*f, 0);
	else
		draw(*f, 1);
}

void		centralisation(t_var *f)
{
	if (f->etat == 0)
	{
		f->step = steps(f->tab, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 0);
	}
	else
	{
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

int			key_press(int keycode, t_var *t)
{
	(keycode == 53) ? exit(1) : 1;
	(keycode == 78) ? zoom_moins(t) : 1;
	(keycode == 69) ? zoom_plus(t) : 1;
	(keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126) ?
		trans(t, keycode) : 1;
	(keycode == 8) ? centralisation(t) : 1;
	(keycode == 31) ? haut_incri(t) : 1;
	(keycode == 34) ? haut_decri(t) : 1;
	(keycode == 2) ? iso_a(t) : 1;
	(keycode == 35) ? para(t) : 1;
	(keycode == 1) ? more_iso(t) : 1;
	(keycode == 49) ? color_change(t) : 1;
	(keycode == 4) ? event(t) : 1;
	return (0);
}
