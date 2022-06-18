/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:25:41 by astaroth          #+#    #+#             */
/*   Updated: 2022/06/18 14:39:13 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

void	shift_left(char *buffer, int shift)
{
	size_t	count;

	count = -1;
	if (!buffer)
		return ;
	if (buffer[shift] == '\0')
		return ;
	while (buffer[++shift])
		buffer[++count] = buffer[shift];
	buffer[++count] = '\0';
}

char	*get_linex(char *buffer)
{
	size_t	shleft;
	size_t	count;
	char	*line;

	shleft = 0;
	count = 0;
	if (!buffer)
		return (NULL);
	while (buffer[shleft] && buffer[shleft] != '\n')
		shleft++;
	if (shleft == 0)
		return (NULL);
	line = ft_alloc(shleft + 2, sizeof(char));
	while (count <= shleft)
	{
		line[count] = buffer[count];
		count++;
	}
	shift_left(buffer, shleft);
	return (line);
}

char	*buffer_handler(char *buffer, int fd)
{
	char	*temp;
	char	*switch_aux;
	int		r_bytes;

	r_bytes = BUFFER_SIZE;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	while (((!ft_strchr(buffer, '\n')) && (r_bytes != 0 
					|| !(r_bytes < BUFFER_SIZE))))
	{
		r_bytes = read(fd, temp, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free (temp);
			return (NULL);
		}
		if (r_bytes == 0)
		{
			free (temp);
			return (buffer);
		}
		temp[r_bytes] = '\0';
		switch_aux = ft_new_buffer(buffer, temp);
		free (buffer);
		buffer = switch_aux;
	}
	free (temp);

	return (switch_aux);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_alloc(BUFFER_SIZE + 1, sizeof(char));
	buffer[fd] = buffer_handler(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = get_linex(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
