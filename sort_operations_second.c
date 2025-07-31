/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:56:45 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:37:05 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && first > third && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
	else if (first < second && first < third)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	check_target_a(t_stack **stack_a, t_stack **stack_b, int checker)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (checker == tmp_a->value)
	{
		tmp_b->target = tmp_a;
		return ;
	}
	while (1)
	{
		while (tmp_a)
		{
			if (tmp_a->value == checker)
			{
				tmp_b->target = tmp_a;
				return ;
			}
			tmp_a = tmp_a->next;
		}
		tmp_a = *stack_a;
		checker++;
	}
}

void	find_target_a(t_stack **stack_a, t_stack **stack_b)
{
	int	checker;

	checker = (*stack_b)->value + 1;
	if (is_max(*stack_a, *stack_b))
		find_amin(stack_a, stack_b);
	else
		check_target_a(stack_a, stack_b, checker);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	if (tmp_b->target->is_on_top)
	{
		while (tmp_b->target->rank > 0)
		{
			ra(stack_a);
			tmp_b->target->rank--;
		}
	}
	if (tmp_b->target->is_on_top == 0)
	{
		while (tmp_b->target->rank + 1 < count_node(*stack_a))
		{
			rra(stack_a);
			tmp_b->target->rank++;
		}
		rra(stack_a);
	}
	pa(stack_a, stack_b);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	init_b(stack_a, stack_b);
	find_target_a(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
}
