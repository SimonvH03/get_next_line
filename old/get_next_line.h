/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:09 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/24 21:40:51 by svan-hoo         ###   ########.fr       */
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

char	*ft_read_nl(int fd, char *pile);
char	*ft_splitdup_nl(const char *src);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_safe_err_exit(const char *pile, const char *ptr);
char	*ft_strnjoin(const char *s1, const char *s2, int n);
char	*ft_residu(const char *src);
char	*get_next_line(int fd);

#endif