/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaarbe+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/16 16:28:05 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_line(char *buffer)
{
	char	*line;
	size_t	count;
	size_t	cpy;

	cpy = 0;
	count = 0;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[count] && buffer[count] != '\n')
		count++;
	line = ft_alloc(count + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (cpy <= count)
	{
		line[cpy] = buffer[cpy];
		cpy++;
	}
	line[cpy] = '\0';
	cpy = 0;
	while (buffer[count])
	{
		buffer[cpy] = buffer[count];
		cpy++;
		count++;
	}
	buffer[cpy] = '\0';
	return (line);
}

char	*ft_handler_buffer(char *buffer, int fd)
{
	char	*read_buff;
	int		status;
	char	*temp;

	status = BUFFER_SIZE;
	read_buff = ft_alloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(buffer, '\n') && status != 0)
	{
		status = read(fd, read_buff, BUFFER_SIZE);
		read_buff[BUFFER_SIZE] = '\0';
		if (status < 0)
		{
			free (buffer);
			free(read_buff);
			return (NULL);
		}
		temp = ft_new_buffer(buffer, read_buff);
		free (buffer);
		buffer = temp;
	}
	free (read_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
		buffer = ft_alloc(BUFFER_SIZE, sizeof(char));
	buffer = ft_handler_buffer(buffer, fd);
	if (!buffer)
		return (line);
	line = get_line(buffer);
	return (line);
}
