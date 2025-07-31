/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:56:45 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:04:47 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_b(t_stack **stack_a, t_stack **stack_b)
{
	init_position(stack_a);
	init_position(stack_b);
}

void	clean_b(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	init_position(stack_b);
	if (is_max(*stack_b, tmp))
		return ;
	find_bmax(stack_b, &tmp);
	if (tmp->target->is_on_top)
	{
		while (tmp->target->rank > 0)
		{
			rb(stack_b);
			tmp->target->rank--;
		}
	}
	else
	{
		while (tmp->target->rank + 1 < count_node(*stack_b))
		{
			rrb(stack_b);
			tmp->target->rank++;
		}
		rrb(stack_b);
	}
}
