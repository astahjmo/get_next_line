/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:53:59 by astaroth          #+#    #+#             */
/*   Updated: 2022/06/20 17:54:03 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_new_buffer(char *s1, char *s2)
{
	size_t	str_size;
	char	*new_str;
	size_t	count;
	size_t	aux;

	aux = 0;
	count = 0;
	str_size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	new_str = ft_alloc(str_size + 1, sizeof(char));
	while (s1 && s1[count])
	{
		new_str[count] = s1[count];
		count++;
	}
	while (s2 && s2[aux])
	{
		new_str[count] = s2[aux];
		aux++;
		count++;
	}
	new_str[count] = '\0';
	return (new_str);
}

char	*ft_alloc(size_t mem, size_t size)
{
	char	*buffer;
	size_t	count;

	count = 0;
	if ((mem * size / size != mem))
		return (NULL);
	buffer = malloc(mem * size);
	while (count < ((mem * size) / size))
	{
		buffer[count] = '\0';
		count++;
	}
	return (buffer);
}

char	*ft_strchr(char *str, int find)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] == find)
			return (&str[count]);
		count++;
	}
	return (NULL);
}
