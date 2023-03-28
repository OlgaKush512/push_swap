/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:14:33 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:14:38 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*fill_array_a(int argc, char **argv)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr != NULL)
	{
		i = 0;
		while (i < (argc - 1))
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	return (arr);
}

int	*simplifyzer(int *arr_i, int len)
{
	int	i;
	int	*tmp;
	int	max;

	i = 0;
	tmp = NULL;
	max = 0;
	while (i < len)
	{
		if (max < arr_i[i])
			max = arr_i[i];
		i++;
	}
	i = 0;
	tmp = simplifyzer_body(arr_i, len, max, i);
	free(arr_i);
	return (tmp);
}

int	*simplifyzer_body(int *arr_i, int len, int max, int i)
{
	int	y;
	int	min;
	int	index;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		y = 0;
		min = max;
		while (y < len)
		{
			if (min >= arr_i[y])
			{
				index = y;
				min = arr_i[y];
			}	
			y++;
		}
		arr_i[index] = max + 1;
		tmp[index] = i++;
	}
	return (tmp);
}

char	*fill_up_bin(int nb, int len)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (len + 1));
	arr = make_number(nb, nb_elem(nb), arr);
	arr = check_arr(arr, len);
	return (arr);
}
