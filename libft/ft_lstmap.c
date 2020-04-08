/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:11:04 by phnguyen          #+#    #+#             */
/*   Updated: 2019/11/14 06:06:18 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f) (void*), void (*del) (void*))
{
	t_list	*res;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst != NULL)
	{
		if ((temp = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&res, temp);
			lst = lst->next;
		}
	}
	return (res);
}
