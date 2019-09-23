/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzouggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:42:58 by kzouggar          #+#    #+#             */
/*   Updated: 2019/05/18 18:34:51 by kzouggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char				*ft_srest(char *tab)
{
	if (ft_strchr(tab, '\n'))
		return (ft_strcpy(tab, ft_strchr(tab, '\n') + 1));
	if (ft_len(tab) > 0)
		return (ft_strcpy(tab, ft_strchr(tab, '\0')));
	return (NULL);
}

int						get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*tab[4864];
	char		*tmp;
	int			c;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(0);
	while ((!ft_strchr(tab[fd], '\n') && (c = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[c] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_len(tab[fd]));
	if (!ft_srest(tab[fd]))
	{
		ft_strdel(&tab[fd]);
		ft_strdel(line);
		return (0);
	}
	return (1);
}
