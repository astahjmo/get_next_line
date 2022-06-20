/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:25:41 by astaroth          #+#    #+#             */
/*   Updated: 2022/06/20 16:01:53 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char    *shift_left(char *buffer)
{
	size_t    count;
	size_t     shift;
	char     *new_buffer;


	shift = 0;
	count = -1;
	if (!*buffer)
	{
		free (buffer);
		buffer = NULL;
		return (buffer);
	}
	while (buffer[shift] != '\n')
		shift++;
	new_buffer = malloc(ft_strlen(buffer));
	while (buffer[++shift])
		new_buffer[++count] = buffer[shift];
	new_buffer[++count] = '\0';
	free (buffer);
	buffer = NULL;
	return (new_buffer);
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
	line = ft_alloc(shleft + 2, sizeof(char));
	while (count <= shleft)
	{
		line[count] = buffer[count];
		count++;
	}
	return (line);
}

char	*buffer_handler(char *buffer, int fd)
{
	char	*temp;
	char	*switch_aux;
	int		r_bytes;

	r_bytes = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && r_bytes != 0)
	{
		r_bytes = read(fd, temp, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free (temp);
			return (NULL);
		}
		temp[r_bytes] = '\0';
		switch_aux = ft_new_buffer(buffer, temp);
		free (buffer);
		buffer = switch_aux;
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer[fd] = buffer_handler(buffer[fd], fd);
	line = get_linex(buffer[fd]);
	buffer[fd] = shift_left(buffer[fd]);
	return (line);
}
