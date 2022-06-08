/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos < johmatos@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:06:47 by johmatos          #+#    #+#             */
/*   Updated: 2022/06/08 17:39:14 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *src)
{
  int count;

  if (!src)
	  return (0);
  count = 0;
  while(src[count])
    count++;
  return (count);
}

char	*ft_strchr(char *src, int c)
{
	int		count;

	count = 0;
	while (src[count])
	{
		if (src[count] == (char)c)
		{
			return ((char *)&src[count]);
		}
		count++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*d;
	const unsigned char	*s;

	if (!(dest || src))
		return (NULL);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	count = -1;
	while (++count < n)
		d[count] = s[count];
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstt;
	size_t	srcc;
    size_t src_count;

	dstt = 0;
	srcc = 0;
	src_count = 0;

	while (src[src_count])
			src_count++;
	while (dst[dstt] && dstt < size)
		dstt++;
	while (src[srcc] && (dstt + srcc + 1) < size)
	{
		dst[dstt + srcc] = src[srcc];
		srcc++;
	}
	if (dstt != size)
		dst[dstt + srcc] = 0;
	return (dstt + src_count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, ft_strlen(s1) +1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}
