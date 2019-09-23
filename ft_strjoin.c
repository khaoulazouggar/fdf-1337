/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 23:14:27 by kzouggar          #+#    #+#             */
/*   Updated: 2019/09/20 16:20:26 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tab;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((tab = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
	{
		tab = ft_strcat(tab, s1);
		tab = ft_strcat(tab, s2);
		return (tab);
	}
	return (NULL);
}
