/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:27:52 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:54:42 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	int				is_on_top;
	int				cost_value;
	int				is_good_one;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	sa(t_stack **stack);

void	sb(t_stack **stack_b);

void	ss(t_stack **stack_a, t_stack **stack_b);

t_stack	*create_list(int n, t_stack *stack_a);

void	ft_lstadd_back(t_stack **lst, t_stack *new_lst);

void	ft_lstadd_front(t_stack **lst, t_stack *new_lst);

void	pa(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);

void	rb(t_stack **stack_b);

void	rr(t_stack **stack_a, t_stack **b);

void	rra(t_stack **stack_a);

void	rrb(t_stack **stack_b);

void	rrr(t_stack **stack_a, t_stack **b);

void	ft_error(t_stack *stack_a, t_stack *stack_b);

void	ft_free(t_stack **lst);

long	ft_atoi(const char *nptr);

int		check_long(char *str, t_stack *stack_a);

int		check_argv(char *str);

int		is_not_similar(t_stack *stack);

int		check_nb(char *str);

void	sorting_start(t_stack *stack_a);

void	init_rank(t_stack **stack_a);

void	init_position(t_stack **stack_a);

void	init_target_node(t_stack **stack_a, t_stack **stack_b);

int		count_node(t_stack *stack_a);

int		is_max(t_stack *stack_a, t_stack *stack_b);

int		is_min(t_stack *stack_a, t_stack *stack_b);

void	find_amin(t_stack **stack_a, t_stack **stack_b);

void	find_bmax(t_stack **stack_a, t_stack **stack_b);

void	init_cost_value(t_stack **stack_a, t_stack **stack_b);

void	init_is_good_one(t_stack **stack_a);

void	push_node_to_b(t_stack **push_node, t_stack **stack_a,
			t_stack **stack_b);

int		is_sorted(t_stack *stack_a);

void	sort_three(t_stack **stack_a);

void	push_to_a(t_stack **stack_a, t_stack **stack_b);

void	init_b(t_stack **stack_a, t_stack **stack_b);

void	clean_b(t_stack **stack_b);

int		final_verif(t_stack *stack_a);

#endif
