/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 03:57:00 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:34:51 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	both_top(t_stack **push_node, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	tmp_a = *push_node;
	while (tmp_a->rank > 0 && tmp_a->target->rank > 0)
	{
		rr(stack_a, stack_b);
		tmp_a->rank--;
		tmp_a->target->rank--;
	}
	while (tmp_a->rank > 0)
	{
		ra(stack_a);
		tmp_a->rank--;
	}
	while (tmp_a->target->rank > 0)
	{
		rb(stack_b);
		tmp_a->target->rank--;
	}
}

void	both_bottom(t_stack **push_node, t_stack **stack_a, t_stack **stack_b)
{
	int		nb_a;
	int		nb_b;
	t_stack	*tmp_a;

	tmp_a = *push_node;
	nb_a = count_node(*stack_a);
	nb_b = count_node(*stack_b);
	while (tmp_a->rank + 1 < nb_a && tmp_a->target->rank + 1 < nb_b)
	{
		rrr(stack_a, stack_b);
		tmp_a->rank++;
		tmp_a->target->rank++;
	}
	while (tmp_a->rank + 1 < nb_a)
	{
		rra(stack_a);
		tmp_a->rank++;
	}
	while (tmp_a->target->rank + 1 < nb_b)
	{
		rrb(stack_b);
		tmp_a->target->rank++;
	}
	rrr(stack_a, stack_b);
}

void	first_top(t_stack **push_node, t_stack **stack_a, t_stack **stack_b)
{
	int		nb_b;
	t_stack	*tmp_a;

	tmp_a = *push_node;
	nb_b = count_node(*stack_b);
	while (tmp_a->rank > 0)
	{
		ra(stack_a);
		tmp_a->rank--;
	}
	while (tmp_a->target->rank + 1 < nb_b)
	{
		rrb(stack_b);
		tmp_a->target->rank++;
	}
	rrb(stack_b);
}

void	first_bottom(t_stack **push_node, t_stack **stack_a, t_stack **stack_b)
{
	int		nb_a;
	t_stack	*tmp_a;

	tmp_a = *push_node;
	nb_a = count_node(*stack_a);
	while (tmp_a->rank + 1 < nb_a)
	{
		rra(stack_a);
		tmp_a->rank++;
	}
	while (tmp_a->target->rank > 0)
	{
		rb(stack_b);
		tmp_a->target->rank--;
	}
	rra(stack_a);
}

void	push_node_to_b(t_stack **push_node, t_stack **stack_a,
		t_stack **stack_b)
{
	t_stack	*tmp_a;

	tmp_a = *push_node;
	if (tmp_a->is_on_top && tmp_a->target->is_on_top)
		both_top(push_node, stack_a, stack_b);
	else if (tmp_a->is_on_top == 0 && tmp_a->target->is_on_top == 0)
		both_bottom(push_node, stack_a, stack_b);
	else if (tmp_a->is_on_top && tmp_a->target->is_on_top == 0)
		first_top(push_node, stack_a, stack_b);
	else if (tmp_a->is_on_top == 0 && tmp_a->target->is_on_top)
		first_bottom(push_node, stack_a, stack_b);
	pb(stack_a, stack_b);
}
