/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:39:35 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 02:30:03 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_src;
	unsigned char	*c_dst;

	i = 0;
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if ((unsigned char)c == c_src[i])
			return ((void*)&c_dst[i + 1]);
		i++;
	}
	return (NULL);
}
