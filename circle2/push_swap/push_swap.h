/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:18:23 by aputri-a          #+#    #+#             */
/*   Updated: 2024/09/24 14:53:13 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		*a_num;
	char	**a_arr;
	char	**b_arr;
	int		size_a;
	int		size_b;
}				t_list;

// from initial_setup.c
t_list	struct_setup(int size_a);
int		fill_struct(char **argv, t_list *s);
void	done(t_list *stacks, int error);

// from helper_functions.c
int		ft_atoi(char *num);
int		ft_strchr(int *arr, int num, int size);
size_t	ft_strlen(const char *str);
int		quaternary_len(int num);
int		ft_strcmp(char *s1, char *s2);

// from stacka_setup.c
int		check_duplicate(int *stack, int size);
int		*fill_initial(char **argv, t_list *stacks);
int		change_numbers(t_list *s);
int		fill_quaternary(t_list *s, int max, char ***new_stack);
char	**convert_to_quaternary(t_list *s);

// from stackb_setup.c
char	**fill_stackb(t_list *s);
void	fill_b_arr(t_list *s, char **arr);

// from operation_sp.c
void	sa(t_list *stacks, int print);
void	sb(t_list *stacks, int print);
void	ss(t_list *stacks, int print);
void	pa(t_list *stacks, int print);
void	pb(t_list *stacks, int print);

// from operation_rotate.c
void	ra(t_list *stacks, int print);
void	rb(t_list *stacks, int print);
void	rr(t_list *stacks, int print);

// from operation_rr.c
void	rra(t_list *stacks, int print);
void	rrb(t_list *stacks, int print);
void	rrr(t_list *stacks, int print);

// from stack_helpers.c
int		search_num(char **s, int digit, char a, char b);
int		topa(t_list *s, int digit, char a, char b);
int		bota(t_list *s, int digit, char a, char b);
int		topb(t_list *s, int digit, char a, char b);
int		botb(t_list *s, int digit, char a, char b);

// from check_group.c
int		is_group1(char *num, int digit);
int		is_group2(char *num, int digit);
int		is_group3(char *num, int digit);
int		is_group4(char *num, int digit);
int		half(t_list *s, int digit);

// from search_group.c
int		search_group1(char **stack, int digit);
int		search_group2(char **stack, int digit);
int		search_group3(char **stack, int digit);
int		search_group4(char **stack, int digit);

// from solve.c
int		check_sorted(t_list *s);
void	push_swap(t_list *s);
void	radix(t_list *s);

// from base_cases.c
void	basecase_3(t_list *stacks);
void	basecase_4(t_list *stacks);
void	basecase_4_1(t_list *stacks);
void	basecase_56(t_list *stacks);

// from last_two_digits_sort.c
void	last_digits_sort(t_list *s, int digit);
int		ld_move_g123(t_list *s, int digit, int rbq);
int		ld_move_g12(t_list *s, int digit, int rbq);
int		ld_move_g3(t_list *s, int d, int rbq);

// from lds_g12.c
void	ld_sort_g2(t_list *s, int digit);
void	ld_sort_11_32(t_list *s, int d);
void	ld_sort_03_10(t_list *s, int digit, int *top);
void	ld_sort_g1(t_list *s, int digit);
int		ld_sort_02_33(t_list *s, int digit, int raq);

// from lds_g34.c
int		ld_sort_g4(t_list *s, int d, int q);
int		ld_sort_21_22_30(t_list *s, int digit, int rbq);
void	ld_sort_g3(t_list *s, int digit);
void	ld_sort_12_13(t_list *s, int digit, int top);

// from one_digit_sort.c
void	one_digit_sort(t_list *s, int digit);
void	odmove_03(t_list *s, int digit, int i, int rotate);
void	ods_1(t_list *s, int digit, int i, int rotate);
void	odsort_03(t_list *s, int digit, int i, int rotate);

// from ods_cleanup.c
void	ods_cleanup_a(t_list *s, int i, int size, int rotate);
void	ods_cleanup_b(t_list *s, int i, int size, int rotate);

// from two_digits_sort.c
void	two_digits_sort(t_list *s, int digit);
void	td_sort_g2(t_list *s, int digit, int rotate);
void	td_sort_g2_32(t_list *s, int digit, int rotate);
void	td_sort_g2_0310(t_list *s, int digit, int rotate);
void	td_cleanup(t_list *s, int *i, int *size, int *rotate);

// from td_move.c
void	td_move_all(t_list *s, int digit, int i, int rotate);
int		td_move_g12(t_list *s, int digit, int *i, int size);
int		td_move_g3(t_list *s, int digit, int *i, int size);
int		td_move_g4(t_list *s, int digit, int *i, int size);

// from tds_g3.c
void	td_sort_g3(t_list *s, int digit, int i);
void	td_sort_g3_2031(t_list *s, int digit);
void	td_sort_g3_13(t_list *s, int digit, int top);
void	td_sort_g3_12(t_list *s, int digit, int i);

// from tds_g14.c
void	td_sort_g1(t_list *s, int digit, int i);
void	td_sort_g1_33(t_list *s, int digit, int i, int size);
void	td_sort_g1_01(t_list *s, int digit, int i, int size);
void	td_sort_g4(t_list *s, int digit, int rotate);
void	td_sort_g4_22(t_list *s, int digit, int *rotate);

// from first_half.c
void	first_two_digits_half(t_list *s, int digit);
void	firsthalf_sort2(t_list *s, int digit);
void	firsthalf_sort01(t_list *s, int digit, int rotate);

// from fh_move.c
void	firsthalf_move012(t_list *s, int digit, int i, int rotate);
int		firsthalf_move01(t_list *s, int digit, int *i, int size);
int		firsthalf_move2(t_list *s, int digit, int *rotate);
void	firsthalf_cleanup(t_list *s, int i, int size, int rotate);

// from fh_last.c
void	firsthalf_last(t_list *s, int digit, int rotate);
void	firsthalf_last_10(t_list *s, int digit, int *rotate);
void	firsthalf_last_1213(t_list *s, int digit, int *rotate);
void	firsthalf_last_1100_part1(t_list *s, int digit, int *rotate);
void	firsthalf_last_1100_part2(t_list *s, int digit, int *rotate);

#endif
