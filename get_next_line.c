/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/10 20:36:01 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_req(char *cache, char *buffer)
{
	char	*new_cache;

	new_cache = ft_strjoin(cache, buffer);
	free(cache);
	return (new_cache);
}

char	*handler_cache(int fd, char *cache)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	b_readed;

	b_readed = 1;
	if (!cache)
		cache = (char *)malloc(BUFFER_SIZE + 1);
	while (ft_strchr(buffer, '\n') && b_readed != 0)
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
	line[count +1] = '\0';
	ft_memcpy(line, buffer, count + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*cache;
	char			*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!cache)
		cache = handler_cache(fd, cache);
	line = get_line(cache, line);
	return (line);
}
