/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:44:43 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:35:26 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	rra_n(t_stack **stack_a)
{
	t_stack	*first;

	if (!*stack_a)
		return ;
	first = *stack_a;
	while (*stack_a && (*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = first;
	(*stack_a)->prev = NULL;
	first->prev = (*stack_a);
	while (first)
	{
		first = first->next;
		if (first->next == (*stack_a))
		{
			first->next = NULL;
			return ;
		}
	}
}

void	rrb_n(t_stack **stack_b)
{
	t_stack	*first;

	if (!*stack_b)
		return ;
	first = *stack_b;
	while (*stack_b && (*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = first;
	(*stack_b)->prev = NULL;
	first->prev = (*stack_b);
	while (first)
	{
		first = first->next;
		if (first->next == (*stack_b))
		{
			first->next = NULL;
			return ;
		}
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	rra_n(stack_a);
	rrb_n(stack_b);
	write (1, "rrr\n", 4);
}
