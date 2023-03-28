/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:14:04 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:14:08 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	radix_sort(t_steak **arr, t_steak **brr)
{
	int		y;
	int		len;
	int		nb_pos;
	void	(*f)(void*);

	f = &del;
	y = 1;
	len = ft_lstsize(*arr);
	nb_pos = like_log(len);
	while (y <= nb_pos)
	{
		radix_sort_body(arr, brr, y);
		y++;
	}
	ft_lstclear(brr, f);
}

void	radix_sort_body(t_steak **arr, t_steak **brr, int y)
{
	int		i;
	int		len;
	int		nb_pos;

	i = 0;
	len = ft_lstsize(*arr);
	nb_pos = like_log(len);
	while (i < len--)
	{
		if ((*arr)->field[(nb_pos - y)] == '0')
		{
			write(1, "pb\n", 3);
			*brr = push(arr, *brr);
		}
		else
		{
			write(1, "ra\n", 3);
			*arr = swap_r(*arr);
		}
	}
	*arr = gathering(arr, brr);
	free(*brr);
}

t_steak	*gathering(t_steak	**arr, t_steak **brr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(*brr);
	while (i < len--)
	{
		write(1, "pa\n", 3);
		*arr = push(brr, *arr);
	}
	free(*brr);
	return (*arr);
}
