/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:57:39 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:37:54 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "fcntl.h"
# include "libft.h"

int		get_next_line(int fd, char **line);
size_t	ft_strclen(const char *str, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strnew(size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_put_save_in_tab(char *tabfd);

#endif
