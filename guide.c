/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:34:53 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 19:09:10 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				stayerf(t_var f)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = 1500;
	p1.y = 1300;
	p2.x = (1500 + 2100) / 2;
	p2.y = 1300;
	p1.color = 14437123;
	p2.color = 15117316;
	draw_line(p1, p2, f);
	p1.x = (1500 + 2100) / 2;
	p1.y = 1300;
	p2.x = 2100;
	p2.y = 1300;
	p1.color = 15117316;
	p2.color = 14437123;
	draw_line(p1, p2, f);
}

static void				stayer(t_var f, int x, int y)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = x;
	p1.y = y;
	p2.x = (x + 2050) / 2;
	p2.y = y;
	p1.color = 14437123;
	p2.color = 15117316;
	draw_line(p1, p2, f);
	p1.x = (x + 2050) / 2;
	p1.y = y;
	p2.x = 2050;
	p2.y = y;
	p1.color = 15117316;
	p2.color = 14437123;
	draw_line(p1, p2, f);
}

static void				grd_ptt_lg(t_var f, int i)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = 1500;
	p1.y = 0;
	p2.x = 1500;
	p2.y = 1500;
	p1.color = 15117316;
	p2.color = 14437123;
	draw_line(p1, p2, f);
	p1.x = 1770;
	p1.y = 130;
	p2.x = 1860;
	p2.y = 130;
	p1.color = 14437123;
	p2.color = 15117316;
	draw_line(p1, p2, f);
}

static void				suite(t_var f)
{
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 860, 14080991,
			"changement de couleur                : [space]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 970, 14080991,
			"translation                          : [->...]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1080, 14080991,
			"centralisation                       : [c]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1190, 14080991,
			"iso and hold h ;)                    : [h]");
}

void					menu(t_var f)
{
	int i;
	int y;

	i = 0;
	y = 350;
	while (i++ < 8)
	{
		stayer(f, 1550, y);
		y += 110;
	}
	grd_ptt_lg(f, 0);
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1780, 100, 11458289,
			"MENU :");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 310, 14080991,
			"zoom                                 : [+ / -]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 420, 14080991,
			"parallel                             : [p]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 530, 14080991,
			"iso                                  : [d]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 640, 14080991,
			"hauteur                              : [o / i]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 750, 14080991,
			"changement de l'angle de vue         : [s]");
	suite(f);
	stayerf(f);
}
