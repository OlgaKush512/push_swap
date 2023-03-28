/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:23:26 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:23:32 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_near(t_steak *lst1, t_steak *lst2)
{
	t_steak	*prev1;
	t_steak	*prev2;
	t_steak	*next1;
	t_steak	*next2;

	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;
	lst2->next = lst1;
	lst2->prev = prev1;
	lst1->next = next2;
	lst1->prev = lst2;
	next2->prev = lst1;
	prev1->next = lst2;
	next1->next = lst1;
	prev2->prev = lst2;
}

void	swap_near_two(t_steak *lst1, t_steak *lst2)
{
	t_steak	*prev1;
	t_steak	*prev2;
	t_steak	*next1;
	t_steak	*next2;

	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;
	lst1->next = lst2;
	lst1->prev = lst2;
	lst2->next = lst1;
	lst2->prev = lst1;
	next1->next = lst1;
	prev1->next = lst1;
	next2->prev = lst2;
	prev2->prev = lst2;
}
