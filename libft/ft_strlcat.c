/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:48:45 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:38:38 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t res;

	if (!src && !dst)
		return (dstsize);
	i = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	if (i + 1 < dstsize)
	{
		while (*src && i + 1 < dstsize)
		{
			dst[i] = *src;
			src++;
			i++;
		}
		dst[i] = '\0';
	}
	return (res);
}
