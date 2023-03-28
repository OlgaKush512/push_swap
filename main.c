/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:16:43 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:16:48 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-1 * n);
		ft_putchar('-');
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	check_args(int argc, char **argv)
{
	if (check_args_body(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (check_args_body(argc, argv) == -1)
		exit (-1);
	else if (check_args_body(argc, argv) == 2)
		exit (2);
	else if (check_args_body(argc, argv) == 3)
		exit (3);
	return (1);
}

void	push_swap(t_steak **arr, t_steak **brr, int *arr_i, int len)
{
	void	(*f)(void*);

	f = &del;
	if (len > 5)
	{
		*arr = fill_steak_a_bin(arr_i, len);
		radix_sort(arr, brr);
		ft_lstclear(arr, f);
	}
	else
	{
		*arr = fill_steak_a_int(arr_i, len);
		sorting_algo(arr, brr);
		ft_lstclear(arr, f);
	}
}

int	main(int argc, char **argv)
{
	t_steak	*arr;
	t_steak	*brr;
	int		*arr_i;
	void	(*fon_ptr)(void*);

	fon_ptr = &del;
	arr = NULL;
	brr = NULL;
	if (check_args(argc, argv) == 1)
	{
		arr_i = fill_array_a(argc, argv);
		arr_i = simplifyzer(arr_i, argc - 1);
		push_swap(&arr, &brr, arr_i, argc - 1);
	}
	ft_lstclear(&arr, fon_ptr);
	free(arr);
	return (0);
}
