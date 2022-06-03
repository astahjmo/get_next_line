/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:06:47 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/03 14:47:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strncopy(char *dest, const char *src, size_t n)
{
	size_t				count;

	if (!(dest || src))
		return (NULL);
	count = 0;
	while (++count < n)
		*dest++ = *src++;
	return (dest);
}

int	ft_strrchr(char *src, int c)
{
	int		count;

	while (*src++)
	{
		if (*src == (char) c)
			return (count + 2);
		count++;
	}
	return (0);
}
