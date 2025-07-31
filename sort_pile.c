/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:58 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:09:09 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	count_node(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a && stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

void	init_a(t_stack **stack_a, t_stack **stack_b)
{
	init_position(stack_a);
	init_position(stack_b);
	init_target_node(stack_a, stack_b);
	init_cost_value(stack_a, stack_b);
	init_is_good_one(stack_a);
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*node_push;

	tmp_a = *stack_a;
	init_a(stack_a, stack_b);
	while (tmp_a)
	{
		if (tmp_a->is_good_one)
			node_push = tmp_a;
		tmp_a = tmp_a->next;
	}
	push_node_to_b(&node_push, stack_a, stack_b);
}

void	sorting_start(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (count_node(stack_a) > 3 && is_sorted(stack_a) == 0)
		pb(&stack_a, &stack_b);
	if (count_node(stack_a) > 3 && is_sorted(stack_a) == 0)
		pb(&stack_a, &stack_b);
	while (count_node(stack_a) > 3 && is_sorted(stack_a) == 0)
		push_to_stack_b(&stack_a, &stack_b);
	if (count_node(stack_a) == 3 && is_sorted(stack_a) == 0)
		sort_three(&stack_a);
	if (count_node(stack_b) > 1)
		clean_b(&stack_b);
	while (count_node(stack_b) > 0)
		push_to_a(&stack_a, &stack_b);
	while (is_sorted(stack_a) == 0)
		rra(&stack_a);
	ft_free(&stack_a);
}
