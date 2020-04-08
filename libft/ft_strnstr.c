/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:08:12 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:53:53 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	if (!(haystack[j] == '\0' || len == 0))
		while (haystack[j] && j < len)
		{
			i = 0;
			while (haystack[j + i] == needle[i] && j + i < len)
			{
				i++;
				if (needle[i] == '\0')
					return ((char*)haystack + j);
			}
			j++;
		}
	return (NULL);
}
