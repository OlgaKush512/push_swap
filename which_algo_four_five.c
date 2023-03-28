/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_algo_four_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:31:13 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:31:15 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_four(t_steak **arr, t_steak **brr)
{
	while (ft_lstsize(*brr) != 1)
	{
		if ((ft_atoi((*arr)->field) == 2))
		{
			write(1, "ra\n", 3);
			*arr = swap_r(*arr);
		}
		else
		{
			write(1, "pb\n", 3);
			*brr = push(arr, *brr);
		}
	}
	sort_three_one(arr);
	write(1, "pa\n", 3);
	*arr = push(brr, *arr);
	sort_four_body(arr);
}

void	sort_four_body(t_steak **arr)
{
	if (ft_atoi((*arr)->field) > ft_atoi((*arr)->next->field)
		&& (ft_atoi((*arr)->field) < ft_atoi((*arr)->prev->field)))
	{
		write(1, "sa\n", 3);
		*arr = swap_s(*arr);
	}
	else if ((ft_atoi((*arr)->field) > ft_atoi((*arr)->prev->field)))
	{
		write(1, "ra\n", 3);
		*arr = swap_r(*arr);
	}
}

void	sort_five(t_steak **arr, t_steak **brr)
{
	while (ft_lstsize(*brr) != 2)
	{
		if ((ft_atoi((*arr)->field) == 2) || ft_atoi((*arr)->field) == 3)
		{
			write(1, "ra\n", 3);
			*arr = swap_r(*arr);
		}
		else
		{
			write(1, "pb\n", 3);
			*brr = push(arr, *brr);
		}
	}
	sort_five_body(arr, brr);
}

void	sort_five_body(t_steak **arr, t_steak **brr)
{
	int	i;

	i = 0;
	sort_three_one(arr);
	while (i < 2)
	{
		write(1, "pa\n", 3);
		*arr = push(brr, *arr);
		if (ft_atoi((*arr)->field) > ft_atoi((*arr)->next->field)
			&& (ft_atoi((*arr)->field) < ft_atoi((*arr)->prev->field)))
		{
			write(1, "sa\n", 3);
			*arr = swap_s(*arr);
		}
		else if ((ft_atoi((*arr)->field) > ft_atoi((*arr)->prev->field)))
		{
			write(1, "ra\n", 3);
			*arr = swap_r(*arr);
		}
		i++;
	}
}
