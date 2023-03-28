/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:16:09 by okushnir          #+#    #+#             */
/*   Updated: 2021/08/19 18:16:12 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_steak
{
	char			*field;
	struct s_steak	*next;
	struct s_steak	*prev;
}				t_steak;

//algos.c
void		radix_sort(t_steak **arr, t_steak **brr);
void		radix_sort_body(t_steak **arr, t_steak **brr, int y);
t_steak		*gathering(t_steak	**arr, t_steak **brr);

//fonctions_arr.c
int			*simplifyzer(int *arr_i, int len);
int			*simplifyzer_body(int *arr_i, int len, int max, int i);
int			*fill_array_a(int argc, char **argv);
char		*fill_up_bin(int nb, int len);

// fonctions_list_int.c
t_steak		*fill_steak_a_int(int *arr_i, int len);
t_steak		*fill_steak_a_bin(int *arr_i, int len);

// fonctions_list.c
int			ft_lstsize(t_steak *lst);
t_steak		*init_steak(char *a);
t_steak		*add_elem(t_steak *lst, char *element);
t_steak		*delete_elem(t_steak *lst);
void		list_print(t_steak *lst);

// fonctions_main.c
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);

// check_args.c
int			check_args_body(int argc, char **argv);
int			check_args_min_max(int argc, char **argv);
int			check_doublons(int argc, char **argv);
int			check_digits(int argc, char **argv);
int			check_no_sorted(int argc, char **argv);

// instructions.c
t_steak		*swap_s(t_steak *lst1);
t_steak		*swap_r(t_steak *lst1);
t_steak		*swap_rr(t_steak *lst1);
t_steak		*push(t_steak **arr1, t_steak *arr2);

// instructions_swap.c
void		swap_near(t_steak *lst1, t_steak *lst2);
void		swap_near_two(t_steak *lst1, t_steak *lst2);

// math.c
int			ft_power(int nb, int power);
int			like_log(int nb);

// putnbr_bin.c
void		ft_putnbr_base(int nbr, char *base);
char		*check_arr(char *arr, int len);
char		*ajout_zero(char *arr, int len);
char		*make_number(int n, int len, char *str);
int			nb_elem(int n);

// which_algo.c
void		sorting_algo(t_steak **arr, t_steak **brr);
void		sort_two(t_steak **arr);
void		sort_three_one(t_steak **arr);
void		sort_three_two(t_steak **arr, int a, int b, int c);

// which_algo_four_five.c
void		sort_four(t_steak **arr, t_steak **brr);
void		sort_four_body(t_steak **arr);
void		sort_five(t_steak **arr, t_steak **brr);
void		sort_five_body(t_steak **arr, t_steak **brr);

// main.c
void		ft_putnbr(int n);
int			check_args(int argc, char **argv);
void		push_swap(t_steak **arr, t_steak **brr, int *arr_i, int len);

// ft_itoa.c
char		*ft_strcpy(char *dst, const char *src);
int			nb_elem_int(int n);
char		*make_number_int(int n, int len, char *str);
char		*ft_itoa(int n);

// ft_atoi.c
long long	ft_atoi(const char *str);

// fonctions_delete.c
void		del(void *element);
void		ft_lstdelone(t_steak *lst, void (*del)(void*));
void		ft_lstclear(t_steak **lst, void (*del)(void*));

#endif
