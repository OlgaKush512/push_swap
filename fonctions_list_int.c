/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_list_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:15:16 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:15:19 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_steak	*fill_steak_a_int(int *arr_i, int len)
{
	int		i;
	t_steak	*lst1;
	t_steak	*tmp;

	i = 0;
	lst1 = init_steak(ft_itoa(arr_i[i]));
	tmp = lst1;
	while (i++ < len - 1)
		tmp = add_elem(tmp, ft_itoa(arr_i[i]));
	free(arr_i);
	return (lst1);
}

t_steak	*fill_steak_a_bin(int *arr_i, int len)
{
	int		i;
	t_steak	*lst1;
	t_steak	*tmp;

	i = 0;
	lst1 = init_steak(fill_up_bin(arr_i[i], like_log(len)));
	tmp = lst1;
	while (i++ < len - 1)
		tmp = add_elem(tmp, fill_up_bin(arr_i[i], like_log(len)));
	free(arr_i);
	return (lst1);
}
