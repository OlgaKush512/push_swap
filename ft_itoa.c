/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:15:53 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:15:55 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*orig;

	orig = dst;
	while (*src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = *src;
	return (orig);
}

int	nb_elem_int(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		++i;
	}
	return (i + sign);
}

char	*make_number_int(int n, int len, char *str)
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
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	len = nb_elem_int(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	else if (n == 2147483647)
		return (ft_strcpy(str, "2147483647"));
	if (str == (void *)0)
		return ((void *)0);
	make_number_int(n, len, str);
	return (str);
}
