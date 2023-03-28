/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:16:22 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:16:29 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_steak	*swap_s(t_steak *lst1)
{
	t_steak	*lst2;

	lst2 = lst1->next;
	if (ft_lstsize(lst1) != 2)
		swap_near(lst1, lst2);
	else
		swap_near_two(lst1, lst2);
	return (lst2);
}

t_steak	*swap_r(t_steak *lst1)
{
	int		len;
	int		i;
	t_steak	*p;

	len = ft_lstsize(lst1);
	i = 0;
	p = lst1;
	while (i < len - 2)
	{
		p = swap_s(p);
		p = p->prev;
		i++;
	}
	p = swap_s(p);
	return (p);
}

t_steak	*swap_rr(t_steak *lst1)
{
	t_steak	*lst_root;
	t_steak	*lst_last;
	void	*tmp;

	lst_last = lst1->prev;
	tmp = lst_last->field;
	lst_root = lst1;
	lst_root = delete_elem(lst_last);
	lst_last = lst_root->prev;
	lst_root = add_elem(lst_last, tmp);
	return (lst_root);
}

t_steak	*push(t_steak **arr1, t_steak *arr2)
{
	void	*tmp;

	tmp = 0;
	if (!arr2)
	{
		tmp = (*arr1)->field;
		arr2 = init_steak(tmp);
		*arr1 = delete_elem(*arr1);
	}
	else
	{
		tmp = (*arr1)->field;
		*arr1 = delete_elem(*arr1);
		arr2 = add_elem(arr2->prev, tmp);
	}
	return (arr2);
}
