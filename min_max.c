/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:48:54 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:36:20 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_max(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value < stack_b->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	is_min(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_b;
	while (tmp)
	{
		if (tmp->value > stack_a->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	find_bmax(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		max;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	max = tmp_b->value;
	tmp_a->target = tmp_b;
	while (tmp_b)
	{
		if (tmp_b->value > max)
		{
			max = tmp_b->value;
			tmp_a->target = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
}

void	find_amin(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	min = tmp_a->value;
	tmp_b->target = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->value < min)
		{
			min = tmp_a->value;
			tmp_b->target = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
}
