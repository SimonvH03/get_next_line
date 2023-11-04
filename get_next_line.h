/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:09 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/04 02:19:18 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *c);
char	*ft_strjoin_ptr(const char *pre, const char *suf, int size);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_splitdup(const char *s, const char c);

#endif