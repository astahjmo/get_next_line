/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:25:41 by astaroth          #+#    #+#             */
/*   Updated: 2022/06/17 18:15:29 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
char 	*get_linex(char *buffer);
char 	*buffer_handler(char *buffer, int fd)
{
	char 	*temp;
	int 	r_bytes;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	r_bytes = read(fd, temp, BUFFER_SIZE);
	temp[r_bytes] = '\0';
	while (!ft_strchr(temp, '\n') && (r_bytes != 0 || !(r_bytes < BUFFER_SIZE))
}


char 	*get_next_line(int fd)
{
	static char 	*buffer[MAX_FD];
	char 			*line;
	
	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_alloc(BUFFER_SIZE + 1 , sizeof(char));
	if (!ft_strchr(buffer[fd], '\n'))
	{
		buffer[fd] = buffer_handler(buffer[fd], fd);
		if (ft_strchr(buffer[fd], '\n'))
			line = get_linex(buffer[fd]);
		else if (!buffer[fd])
			return (NULL);
		else 
			return (buffer[fd]);
	}
	return (NULL);
}
