/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:25:56 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 16:45:51 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_atoi_hex(char *str)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (str[i])
	{
		r = r * 16;
		if (str[i] >= '0' && str[i] <= '9')
			r += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			r += -55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			r += -87;
		i++;
	}
	return (r);
}

int			comma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (ft_strlen(&str[i + 1]) > 2)
			{
				if (str[i + 1] == '0' && str[i + 2] == 'x')
					return (ft_atoi_hex(&str[i + 3]));
			}
			return (16777215);
		}
		i++;
	}
	return (16777215);
}

void		fill_data(int fd, t_var *f, t_vect j, int v)
{
	char	**tmp;
	char	*t1;

	while (get_next_line(fd, &t1))
	{
		tmp = ft_split_whitespaces(t1);
		j.b = -1;
		if (!(f->tab[j.a] = (t_point*)malloc(sizeof(t_point) * f->c)) ||
				!(f->cp[j.a] = (t_point*)malloc(sizeof(t_point) * f->c)))
			return ;
		while (++j.b < f->c)
		{
			f->tab[j.a][j.b].y = j.a * v;
			f->tab[j.a][j.b].x = j.b * v;
			f->tab[j.a][j.b].z = ft_atoi(tmp[j.b]);
			f->tab[j.a][j.b].color = comma(tmp[j.b]);
			f->cp[j.a][j.b].color = f->tab[j.a][j.b].color;
		}
		free_tmp(tmp);
		ft_strdel(&t1);
		j.a++;
	}
}
