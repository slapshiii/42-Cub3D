/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:20:54 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/19 07:27:51 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!size || !count)
		return (malloc(0));
	if ((ptr = (void*)malloc(size * sizeof(char) * count)))
	{
		ft_bzero(ptr, size * count);
		return (ptr);
	}
	return (NULL);
}
