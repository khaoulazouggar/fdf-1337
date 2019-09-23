/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:07:16 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 01:09:01 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		haut_decri(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 1)
	{
		f->h++;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].y += f->cp[i][j].z;
				j++;
			}
		}
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		haut_incri(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 1)
	{
		f->h--;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].y -= f->cp[i][j].z;
				j++;
			}
		}
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		iso(double *x, double *y, double *z, double k)
{
	double a;
	double b;

	a = *x;
	b = *y;
	*x = (a - b) * cos(0.523599 + k);
	*y = (b + a) * sin(0.523599 + k) - *z;
}

void		iso_a(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 0)
	{
		f->etat = 1;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].x = f->tab[i][j].x;
				f->cp[i][j].y = f->tab[i][j].y;
				f->cp[i][j].z = f->tab[i][j].z;
				iso(&f->cp[i][j].x, &f->cp[i][j].y,
						&f->cp[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
		}
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	f->step = steps(f->cp, f->l, f->c);
	draw(*f, 1);
}

void		more_iso(t_var *f)
{
	int i;
	int j;

	if (f->etat == 1)
	{
		i = 0;
		f->k += 0.2;
		while (i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].x = f->tab[i][j].x;
				f->cp[i][j].y = f->tab[i][j].y;
				iso(&f->cp[i][j].x, &f->cp[i][j].y,
						&f->tab[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
			i++;
		}
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}
