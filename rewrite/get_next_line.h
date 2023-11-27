/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:09 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/27 23:03:15 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*ft_strjoin_gnl(const char *pile, const char *buffer);
void	ft_residu(char *buffer);

void	*ft_free(void *p);
int		ft_strlen(const char *src);
int		ft_strchr(const char *str, char c);
char	*ft_strdup_gnl(const char *src);
void	ft_buffclear(char *buffer, size_t n);

#endif