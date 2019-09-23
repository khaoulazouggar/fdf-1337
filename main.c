/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:38:54 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 18:05:36 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_point **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_tmp(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_var		f;
	t_point		**tab;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf [file_name]\n");
		return (0);
	}
	else
	{
		f.mlx_ptr = mlx_init();
		f.win_ptr = mlx_new_window(f.mlx_ptr, 2100, 1500, av[1]);
		f = ft_stock_cord(av, &f);
		f.error == 1 ? error() : 1;
		f.h = 0;
		f.k = 0;
		f.step = steps(f.tab, f.l, f.c);
		draw(f, 0);
		mlx_hook(f.win_ptr, 2, 0, &key_press, &f);
		mlx_loop(f.mlx_ptr);
		ft_free(f.tab);
		ft_free(f.cp);
	}
}
