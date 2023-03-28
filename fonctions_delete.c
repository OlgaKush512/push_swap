/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:14:45 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:14:49 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	del(void *element)
{
	if (element != NULL)
		free(element);
}

void	ft_lstdelone(t_steak *lst, void (*del)(void*))
{
	if (lst == (void *)0 || del == (void *)0)
		return ;
	del(lst->field);
	free(lst);
}

void	ft_lstclear(t_steak **lst, void (*del)(void*))
{
	t_steak	*tmp_c;
	t_steak	*tmp_n;

	tmp_c = *lst;
	if (tmp_c != NULL)
	{
		tmp_c = tmp_c->next;
		while (tmp_c != *lst)
		{
			tmp_n = tmp_c->next;
			ft_lstdelone(tmp_c, del);
			tmp_c = tmp_n;
		}
	}
	ft_lstdelone(*lst, del);
	*lst = (void *)0;
}
