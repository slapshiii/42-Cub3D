/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:29:40 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 10:17:20 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if ((res = (char*)ft_calloc(len + 1, sizeof(char))))
	{
		if (!s || start > ft_strlen(s))
			return (res);
		while (start-- && *s)
			s++;
		while (i < len && s[i])
		{
			res[i] = s[i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
