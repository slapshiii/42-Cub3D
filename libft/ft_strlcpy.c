/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:41:30 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:20:38 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t res;

	if (!src)
		return (0);
	res = ft_strlen(src);
	if (!dst || dstsize == 0)
		return (res);
	if (dstsize > 0)
	{
		while (--dstsize > 0 && *src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (res);
}
