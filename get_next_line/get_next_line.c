/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:57:13 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 01:38:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (s == NULL || start > (unsigned int)ft_strlen(s))
	{
		if (!(dest = (char*)malloc(sizeof(char))))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*dest;

	i = 0;
	n = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dest[i] = (char)s1[i];
		i++;
	}
	while (n < ft_strlen(s2))
	{
		dest[i] = (char)s2[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_put_save_in_tab(char *tabfd)
{
	if (ft_strchr(tabfd, '\n'))
	{
		ft_strcpy(tabfd, ft_strchr(tabfd, '\n') + 1);
		return (tabfd);
	}
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tabfd[255];
	int			checkfd;
	char		*tmp;
	int			flag;

	flag = 0;
	if (fd < 0 || !line || (!(tabfd[fd]) && (tabfd[fd] =
ft_strnew(0)) == NULL) || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	while (!(ft_strchr(tabfd[fd], '\n')) &&
(checkfd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[checkfd] = '\0';
		tmp = tabfd[fd];
		tabfd[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	*line = ft_substr(tabfd[fd], 0, ft_strclen(tabfd[fd], '\n'));
	flag = (ft_strchr(tabfd[fd], '\n') == NULL) ? 1 : 0;
	tmp = ft_put_save_in_tab(tabfd[fd]);
	if (flag == 1)
		free(tabfd[fd]);
	tabfd[fd] = tmp;
	return (flag == 1 || tabfd[fd] == NULL) ? 0 : 1;
}
