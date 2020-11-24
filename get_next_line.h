/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:51:14 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 16:11:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_joinofgnl(char *s1, char *s2);
int		ft_hasnewline(char *str);
char	*ft_majtmp(char *tmp);
char	*ft_newline(char *tmp);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif 
