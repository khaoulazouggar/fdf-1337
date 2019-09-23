/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:29:32 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/19 23:46:14 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		para(t_var *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	f->etat = 0;
	f->step = steps(f->tab, f->l, f->c);
	draw(*f, 0);
}

void		event(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->cp[i][j].x = f->tab[i][j].x;
			f->cp[i][j].y = f->tab[i][j].y;
			iso(&f->cp[i][j].x, &f->cp[i][j].y, &f->tab[i][j].z, f->k);
			f->cp[i][j].y += (f->tab[i][j].z * f->h);
			f->cp[i][j].color += 100000;
			if (f->cp[i][j].z)
				f->cp[i][j].color += 500000;
			j++;
		}
		i++;
	}
	f->k += 0.2;
	centralisation(f);
}
