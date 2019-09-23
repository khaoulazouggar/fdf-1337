/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:27:46 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 19:10:42 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	part1(t_bres v, void *mlx_ptr, void *win_ptr, t_vect start)
{
	t_vect	bigola;
	int		color;
	int		inc1;
	int		inc2;

	v.p = (2 * v.dy) - v.dx;
	v.i = -1;
	inc1 = 2 * (v.dy - v.dx);
	inc2 = 2 * (v.dy);
	while (++v.i < v.dx)
	{
		if (v.p >= 0)
		{
			v.p = v.p + inc1;
			v.ord += v.stepy;
		}
		else
			v.p = v.p + inc2;
		v.abs += v.stepx;
		bigola.a = v.abs;
		bigola.b = v.ord;
		color = get_color(bigola, v.beg, v.end);
		mlx_pixel_put(mlx_ptr, win_ptr, v.abs + start.a, v.ord +
				start.b, color);
	}
}

void	part2(t_bres v, void *mlx_ptr, void *win_ptr, t_vect start)
{
	t_vect	bigola;
	int		color;
	int		inc1;
	int		inc2;

	v.p = (2 * v.dx) - v.dy;
	v.i = -1;
	inc1 = 2 * (v.dx - v.dy);
	inc2 = 2 * (v.dx);
	while (++v.i < v.dy)
	{
		if (v.p >= 0)
		{
			v.p = v.p + inc1;
			v.abs += v.stepx;
		}
		else
			v.p = v.p + inc2;
		v.ord += v.stepy;
		bigola.a = v.abs;
		bigola.b = v.ord;
		color = get_color(bigola, v.beg, v.end);
		mlx_pixel_put(mlx_ptr, win_ptr, v.abs +
				start.a, v.ord + start.b, color);
	}
}

void	draw_line(t_point p1, t_point p2, t_var f)
{
	t_bres	v;
	int		color;

	v.beg.x = p1.x;
	v.beg.y = p1.y;
	v.beg.color = p1.color;
	v.end.x = p2.x;
	v.end.y = p2.y;
	v.end.color = p2.color;
	v.abs = p1.x;
	v.ord = p1.y;
	v.dx = p2.x - p1.x;
	v.dy = p2.y - p1.y;
	v.stepx = (v.dx > 0) ? 1 : -1;
	v.stepy = (v.dy > 0) ? 1 : -1;
	v.dx = abs(v.dx);
	v.dy = abs(v.dy);
	mlx_pixel_put(f.mlx_ptr, f.win_ptr, v.abs + f.step.a, v.ord +
			f.step.b, p1.color);
	if (v.dx > v.dy)
		part1(v, f.mlx_ptr, f.win_ptr, f.step);
	else
		part2(v, f.mlx_ptr, f.win_ptr, f.step);
}

void	draw(t_var f, int var)
{
	int i;
	int j;

	i = -1;
	if (var == 0)
		while (++i < f.l)
		{
			j = -1;
			while (++j < f.c)
			{
				j + 1 < f.c ? draw_line(f.tab[i][j], f.tab[i][j + 1], f) : 1;
				i + 1 < f.l ? draw_line(f.tab[i + 1][j], f.tab[i][j], f) : 1;
			}
		}
	else
		while (++i < f.l)
		{
			j = -1;
			while (++j < f.c)
			{
				j + 1 < f.c ? draw_line(f.cp[i][j], f.cp[i][j + 1], f) : 1;
				i + 1 < f.l ? draw_line(f.cp[i + 1][j], f.cp[i][j], f) : 1;
			}
		}
	menu(f);
}
