/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/10 22:33:17 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_req(char *cache, char *buffer)
{
	char	*new_cache;

	new_cache = ft_strjoin(cache, buffer);
	if (*cache)
		free(cache);
	cache = NULL;
	return (new_cache);
}

char	*handler_cache(int fd, char *cache)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	b_readed;	

	b_readed = 1;
	while (!ft_strchr(buffer, '\n') && b_readed != 0)
	{
		b_readed = read(fd, buffer, BUFFER_SIZE);
		cache = ft_req(cache, buffer);
	}
	return (cache);
}

char	*get_line(char *buffer, char *line)
{
	int	count;

	count = 0;
	while (buffer[count] != '\n' && buffer[count])
		count++;
	line = (char *) malloc(count + 2);
	line[count++] = '\0';
	ft_memcpy(line, buffer, count);
	ft_memcpy(buffer, buffer + count, count);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*cache;
	char			*line;
	int				count;
	
	count = 0;
	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!cache)
	{
		cache = (char *)malloc(BUFFER_SIZE + 1);
		if (!cache)
			return (NULL);
		while (count++ < BUFFER_SIZE)
			cache[count] = '\0';
	}
	else
		cache = handler_cache(fd, cache);
	line = get_line(cache, line);
	return (line);
}
