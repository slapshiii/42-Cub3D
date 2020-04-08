/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:01:00 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 02:19:52 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*byte;
	size_t			i;

	byte = (unsigned char*)b;
	i = 0;
	while (len > i)
	{
		byte[i] = (unsigned char)c;
		i++;
	}
	b = (void*)byte;
	return (b);
}
