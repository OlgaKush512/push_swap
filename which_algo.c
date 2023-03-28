/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:19:01 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:19:05 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sorting_algo(t_steak **arr, t_steak **brr)
{
	int	nbr;

	nbr = ft_lstsize(*arr);
	if (nbr == 2)
		sort_two(arr);
	else if (nbr == 3)
		sort_three_one(arr);
	else if (nbr == 4)
		sort_four(arr, brr);
	else if (nbr > 3 && nbr <= 5)
		sort_five(arr, brr);
}

void	sort_two(t_steak **arr)
{
	write(1, "sa\n", 3);
	*arr = swap_s(*arr);
}

void	sort_three_one(t_steak **arr)
{
	int	a;
	int	b;
	int	c;

	a = atoi((*arr)->field);
	b = atoi((*arr)->next->field);
	c = atoi((*arr)->prev->field);
	if (a < b && b < c)
		;
	else if (a > b && a < c)
	{
		write(1, "sa\n", 3);
		*arr = swap_s(*arr);
	}
	else if (a > b && a > c && b < c)
	{
		write(1, "ra\n", 3);
		*arr = swap_r(*arr);
	}
	else
		sort_three_two(arr, a, b, c);
}

void	sort_three_two(t_steak **arr, int a, int b, int c)
{
	if (a < b && a < c)
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		*arr = swap_s(*arr);
		*arr = swap_r(*arr);
	}
	else if (a < b && a > c)
	{
		write(1, "rra\n", 4);
		*arr = swap_rr(*arr);
	}
	else if (a > b && a > c && b > c)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		*arr = swap_s(*arr);
		*arr = swap_rr(*arr);
	}
}
