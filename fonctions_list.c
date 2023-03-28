/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:15:04 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:15:08 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lstsize(t_steak *lst)
{
	int		i;
	t_steak	*p;

	i = 0;
	p = lst;
	if (lst)
	{
		i++;
		p = p->next;
	}
	while (p != lst)
	{
		i++;
		p = p->next;
	}
	return (i);
}

t_steak	*init_steak(char *a)
{
	t_steak	*lst;

	lst = (t_steak *)malloc(sizeof(t_steak));
	lst->field = a;
	lst->next = lst;
	lst->prev = lst;
	return (lst);
}

t_steak	*add_elem(t_steak *lst, char *element)
{
	t_steak	*temp;
	t_steak	*p;

	temp = (t_steak *)malloc(sizeof(t_steak));
	p = lst->next;
	lst->next = temp;
	temp->field = element;
	temp->next = p;
	temp->prev = lst;
	p->prev = temp;
	return (temp);
}

t_steak	*delete_elem(t_steak *lst)
{
	t_steak	*prev;
	t_steak	*next;

	next = NULL;
	if (ft_lstsize(lst) > 1)
	{
		prev = lst->prev;
		next = lst->next;
		prev->next = lst->next;
		next->prev = lst->prev;
		free(lst);
	}
	else
	{
		free(lst);
		lst = NULL;
	}
	return (next);
}

void	list_print(t_steak *lst)
{
	t_steak	*p;

	p = lst;
	if (p != NULL)
	{
		write(1, p->field, ft_strlen(p->field));
		write(1, " ", 1);
		p = p->next;
		while (p != lst)
		{
			write(1, p->field, ft_strlen(p->field));
			write(1, " ", 1);
			p = p->next;
		}
	}
}
