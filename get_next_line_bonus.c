/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:44:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 16:02:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_hasnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_majtmp(char *tmp)
{
	int		i;
	int		j;
	char	*maj;

	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	if (!(maj = malloc(sizeof(*maj) * (ft_strlen(tmp) - i + 1))))
		return (0);
	i++;
	while (tmp[i])
		maj[j++] = tmp[i++];
	maj[j] = '\0';
	free(tmp);
	return (maj);
}

char	*ft_newline(char *tmp)
{
	char	*nl;
	int		i;

	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!(nl = malloc(sizeof(*nl) * (i + 1))))
		return (0);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		nl[i] = tmp[i];
		i++;
	}
	nl[i] = '\0';
	return (nl);
}

int		get_next_line(int fd, char **line)
{
	char		*lu;
	static char	*tmp[256];
	int			len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(lu = malloc(sizeof(*lu) * (BUFFER_SIZE + 1))))
		return (-1);
	len = BUFFER_SIZE;
	while (len != 0 && !(ft_hasnewline(tmp[fd])))
	{
		if ((len = read(fd, lu, BUFFER_SIZE)) == -1)
		{
			free(lu);
			return (-1);
		}
		lu[len] = '\0';
		tmp[fd] = ft_joinofgnl(tmp[fd], lu);
	}
	free(lu);
	*line = ft_newline(tmp[fd]);
	tmp[fd] = ft_majtmp(tmp[fd]);
	if (len == 0)
		return (0);
	return (1);
}
