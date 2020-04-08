/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:48:32 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 14:13:32 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_delete(char **res, int k)
{
	while (k--)
	{
		free(res[k]);
		res[k] = NULL;
	}
	free(res);
	res = NULL;
}

static int	word_count(const char *str, char c)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != c)
				&& (str[i + 1] == c || !(str[i + 1])))
			res++;
		i++;
	}
	return (res);
}

static char	*ft_strndup(const char *str, int n)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * n + 1);
	if (!(res))
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**add_tab(const char *str, char c, char **res, int word)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < (int)ft_strlen(str) && k < word)
	{
		j = 0;
		while (!(str[i + j] == c) && str[i + j])
			j++;
		if (((str[i + j] == c || !(str[i + j])) && j))
		{
			if (!(res[k] = ft_strndup(&str[i], j)))
			{
				ft_delete(res, k);
				return (NULL);
			}
			k++;
			i = i + j;
		}
		i++;
	}
	res[k] = 0;
	return (res);
}

char		**ft_split(const char *s, char c)
{
	char	**res;
	int		word;

	if (!s)
		return (NULL);
	word = word_count(s, c);
	if ((res = malloc(sizeof(char*) * (word + 1))))
	{
		if (!(res = add_tab(s, c, res, word)))
			return (NULL);
		return (res);
	}
	return (NULL);
}
