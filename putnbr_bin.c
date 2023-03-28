/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:18:48 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:18:51 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	result;

	result = (unsigned int)nbr;
	size = 2;
	if (result >= 2)
	{
		ft_putnbr_base(result / size, base);
		ft_putnbr_base(result % size, base);
	}
	else
	{
		write(1, base + result, 1);
	}
}

char	*check_arr(char *arr, int len)
{
	char		*res;

	if ((int)ft_strlen(arr) < len)
	{
		res = ajout_zero(arr, len);
		free(arr);
	}
	else
	{
		res = arr;
	}
	return (res);
}

char	*ajout_zero(char *arr, int len)
{
	int		zero;
	int		i;
	char	*arr_zero;
	char	*res;

	zero = len - (int)ft_strlen(arr);
	arr_zero = (char *)malloc(sizeof(char) * (zero + 1));
	i = 0;
	while (i < zero)
	{
		arr_zero[i] = '0';
		i++;
	}
	arr_zero[i] = '\0';
	res = ft_strjoin(arr_zero, arr);
	free(arr_zero);
	return (res);
}

char	*make_number(int n, int len, char *str)
{
	int	i;

	i = len;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (--len >= 0 && n != 0)
	{
		str[len] = (n % 2) + 48;
		n /= 2;
	}
	str[i] = '\0';
	return (str);
}

int	nb_elem(int n)
{
	int	i;

	i = 0;
	while (n >= 1)
	{
		n = n / 2;
		++i;
	}
	return (i);
}
