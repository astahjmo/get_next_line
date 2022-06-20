/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:55:43 by astaroth          #+#    #+#             */
/*   Updated: 2022/06/20 17:58:01 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# define MAX_FD 1024

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int find);
char	*ft_strlcat(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_alloc(size_t mem, size_t size);
char	*ft_new_buffer(char *s1, char *s2);
#endif
