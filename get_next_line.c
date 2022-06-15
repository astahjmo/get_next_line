/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:19:24 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/15 20:11:44 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_line(char *buffer)
{
	char	*line;
	size_t	count;
	size_t	cpy;

	cpy = -1;
	count = 0;
	while (buffer[count] != '\n' && buffer[count])
		count++;
	line = ft_alloc(count + 2, sizeof(char));
	while (++cpy <= count)
		line[cpy] = buffer[cpy];
	line[cpy] = '\0';
	cpy = 0;
	count++;
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
	char	read_buff[BUFFER_SIZE + 1];
	int		status;
	char	*temp;

	status = BUFFER_SIZE;
	while (!ft_strchr(buffer, '\n') && status == BUFFER_SIZE)
	{
		status = read(fd, read_buff, BUFFER_SIZE);
		read_buff[status] = '\0';
		if (status < 0)
			return (NULL);
		temp = ft_new_buffer(buffer, read_buff);
		free (buffer);
		buffer = temp;
	}
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
	if ((buffer != NULL || !ft_strchr(buffer, '\n')))
	{
		buffer = ft_handler_buffer(buffer, fd);
	}
	if (!ft_strlen(buffer))
		return (line);
	line = get_line(buffer);
	return (line);
}
