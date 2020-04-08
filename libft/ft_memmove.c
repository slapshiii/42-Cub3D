/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:54:49 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:31:29 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	size_t			i;

	if (!dst && !src && len)
		return (dst);
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	i = 0;
	if (c_dst < c_src)
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	else
		while (i < len)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	return (dst);
}
