/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:10:13 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 10:25:09 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_check_set(char const *set, char const c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = 0;
	while (ft_check_set(set, s1[len - 1]) && len > 1)
		len--;
	while (ft_check_set(set, s1[start]) && len > 0)
	{
		len--;
		start++;
	}
	if (len <= 0)
		return (ft_strdup("\0"));
	return (ft_substr(s1, start, len));
}
