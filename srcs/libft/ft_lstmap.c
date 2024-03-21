/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:54:59 by yegkim            #+#    #+#             */
/*   Updated: 2023/10/18 16:12:37 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*result;
	t_list	*newlst;
	void	*fret;

	if (!lst || !f || !del)
		return (0);
	cur = lst;
	result = 0;
	while (cur)
	{
		fret = f(cur->content);
		newlst = ft_lstnew(fret);
		if (newlst == 0)
		{
			ft_lstclear(&result, del);
			free(fret);
			fret = 0;
			return (0);
		}
		ft_lstadd_back(&result, newlst);
		cur = cur->next;
	}
	return (result);
}
