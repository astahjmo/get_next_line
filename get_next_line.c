/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/03 16:05:51 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	handler_next_line(char *buffer, int offset)
{
	offset -= 1;
	ft_strncopy(buffer, (buffer + offset), BUFFER_SIZE);
}

void	ft_realloc(char *buffer, int count)
{
	static char	*new_buffer;

	new_buffer = malloc(BUFFER_SIZE * count);
	ft_strncopy(new_buffer, buffer, BUFFER_SIZE * count);
	free(buffer);
	buffer = new_buffer;
}

char	*handler_line(char *buffer)
{
	int		idx_count;
	char	*new_line;
	int		count;

	count = 1;
	idx_count = ft_strrchr(buffer, '\n');
	while (!(ft_strrchr(buffer, '\n')))
	{
		ft_realloc(buffer, count);
		count++;
	}
	new_line = malloc(idx_count + 2);
	new_line[idx_count + 2] = '\0';
	ft_strncopy(new_line, buffer, idx_count + 1);
	handler_next_line(buffer, idx_count);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	int			offset;
	char		*line;

	cache = malloc(BUFFER_SIZE + 1);
	if (!(*cache))
		offset = read(fd, cache, BUFFER_SIZE);
	line = handler_line(cache);
	return (line);
}
