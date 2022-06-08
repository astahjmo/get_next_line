/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/08 17:40:42 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handler_line(char *cache, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		b_read;

	b_read = 1;
	if (!cache)
		cache = malloc(BUFFER_SIZE + 1);
	if (!cache)
		return (NULL);
	while (!ft_strchr(cache, '\n') && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		cache = ft_strjoin(cache, buffer);
	}
	return (cache);
}

char *get_line(char *cache)
{
	int	count;
	char *line;

	count = 2;
	while (cache[count] != '\n')
		count++;
	line = malloc(count * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, cache, count);
	ft_memcpy(cache, cache + count + 1, ft_strlen(cache));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0)
		return (NULL);
	
	cache = handler_line(cache, fd);
	line = get_line(cache);
	return (line);
}
