/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:58:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/07/14 19:43:54 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libftprintf/inc/libftprintf.h"

typedef struct s_stack {
	int				val;
	struct s_stack	*next;
}t_stack;

typedef struct s_transf_price {
	int	move_count[2];
	int	val;
}t_transf_price;

# define STACK_A 1
# define STACK_B 2
# define STACK_UNDEF 3

//Mathmatical Operations

int				min(int a, int b);
int				max(int a, int b);
int				abs(int a);

//Create stack

t_stack			*stack_new(int val);
void			add_to_stack(t_stack **stack, int val);
void			reverse_stack(t_stack **stack);//its actually a util

//Print Check

void			print_stack(t_stack *stack);
void			print_arr(int *arr, int size);
void			print_t_transf(t_transf_price *tp, int tp_size);

//Swaps

void			swap(t_stack **stack);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			silent_ss(t_stack **stack_a, t_stack **stack_b);

//Pushing

void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			silent_pa(t_stack **a, t_stack **b);
void			silent_pb(t_stack **a, t_stack **b);

//Rotation

void			rotate(t_stack **stack);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			silent_rr(t_stack **a, t_stack **b);

//Reverse rotate

void			rev_rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			silent_rrr(t_stack **a, t_stack **b);

//Utils

int				get_stack_size(t_stack *stack);
void			free_stack(t_stack **stack);
int				*stack_to_arr(t_stack *stack);
int				get_stack_mid_val(t_stack *stack);
int				get_stack_val_index(t_stack *stack, int val);

//Parsing 

t_stack			*init_stack_a(int ac, char**av);
void			sub_error(t_stack **a);

//Error checking
int				check_dup_sub(t_stack *stack, int val);
int				check_is_sorted(t_stack *stack);
int				check_is_int(int ac, char **av);
int				check_dup_stack(t_stack *stack);

//Small sort 

void			small_sort(t_stack **a, t_stack **b, int ac);
void			sort_two(t_stack **a);
void			sort_three(t_stack **a);

//BIG SORT

void			big_sort(t_stack **a, t_stack **b);

//Small Sort Reverse

void			rev_sort_two(t_stack **a);
void			rev_sort_three(t_stack **a);

//Bubble sort 

void			ft_bubble_sort(int *arr, int n);
void			ft_swap(int *xp, int *yp);

//Median Transfer

void			transfer_below_median(t_stack **a, t_stack **b, int median);

//Manipulating the stack

int				get_stack_min_elem(t_stack *stack);
int				get_stack_max_elem(t_stack *stack);
void			put_min_elem_on_top(t_stack **stack, int stack_id);
t_stack			*copy_stack(t_stack *src);

//Largest increasing sequence functions

int				*get_lis(int *arr, int size, int *lis_size, int i);
void			move_lis_to_b(t_stack **a, t_stack **b);

//Optimal transfer

t_transf_price	*get_transf_price(t_stack *a, t_stack *b, int *tp_size);
int				get_position_in_a(int val, t_stack *a);
int				pick_best_move_index(t_transf_price *tp, int tp_size);

#endif
