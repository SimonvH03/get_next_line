/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:09 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/07 17:50:48 by svan-hoo         ###   ########.fr       */
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
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*ft_strjoin_gnl(const char *pile, const char *buffer);
void	ft_residu(char *buffer);

void	*ft_free(char **p);
int		ft_strlen(const char *src);
int		ft_strchr(const char *str, char c);
char	*ft_strdup_gnl(const char *src);
void	ft_buffclear(char *buffer, size_t n);

#endif