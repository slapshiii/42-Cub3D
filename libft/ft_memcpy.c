/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:16 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:29:16 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	i = 0;
	if (!dst && !src && n)
		return (dst);
	c_src = (unsigned char*)src;
	c_dst = (unsigned char*)dst;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	dst = (void*)c_dst;
	return (dst);
}
