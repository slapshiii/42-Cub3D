/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:56:55 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 10:27:10 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((res = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
	{
		if (ft_strlcpy(res, s1, len1 + len2 + 1) == len1)
			if (ft_strlcat(res, s2, len1 + len2 + 1) == len1 + len2)
				return (res);
	}
	return (NULL);
}
