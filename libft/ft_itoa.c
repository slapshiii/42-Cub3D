/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:32:10 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/14 02:28:30 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 0)
	{
		n = n / 10;
		if (n == 0)
			n = n - 10;
		len++;
	}
	return (len);
}

static void	ft_fillstr(unsigned int num, char *res, int index)
{
	unsigned int	div;

	div = 1;
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		res[index] = ((num / div) % 10) + '0';
		index++;
		div = div / 10;
	}
	res[index] = '\0';
}

char		*ft_itoa(int n)
{
	char			*res;
	unsigned int	num;
	int				index;

	index = 0;
	if (n <= -2147483648LL)
	{
		res = ft_substr("-2147483648", 0, 12);
		return (res);
	}
	if ((res = (char*)malloc(sizeof(char) * (ft_intlen(n)))))
	{
		if (n < 0)
		{
			num = -n;
			res[index] = '-';
			index++;
		}
		else
			num = n;
		ft_fillstr(num, res, index);
		return (res);
	}
	return (NULL);
}
