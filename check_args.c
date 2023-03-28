/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:14:21 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:14:24 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_args_body(int argc, char **argv)
{
	if (argc == 1)
		return (-1);
	else if (argc == 2)
	{
		if (check_digits(argc, argv) == 0)
			return (0);
		return (3);
	}
	else if (check_doublons(argc, argv) == 0)
		return (0);
	else if (check_digits(argc, argv) == 0)
		return (0);
	else if (check_no_sorted(argc, argv) == 2)
		return (2);
	else if (check_args_min_max(argc, argv) == 0)
		return (0);
	return (1);
}

int	check_args_min_max(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((ft_atoi(argv[i]) > 2147483647) || (ft_atoi(argv[i]) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	check_doublons(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[y]))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y] != '\0')
		{
			if (!ft_isdigit(argv[i][y++]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_no_sorted(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[y]))
				return (1);
			y++;
		}
		i++;
	}
	return (2);
}
