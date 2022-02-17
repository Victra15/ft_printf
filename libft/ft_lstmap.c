/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 01:20:34 by yolee             #+#    #+#             */
/*   Updated: 2022/01/07 04:43:28 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*map_lst;

	if (lst == NULL)
		return (NULL);
	map_lst = ft_lstnew(f(lst->content));
	if (map_lst == NULL)
		return (NULL);
	temp = map_lst;
	while (lst->next != NULL)
	{
		temp->next = ft_lstnew(f(lst->next->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&map_lst, del);
			break ;
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (map_lst);
}
