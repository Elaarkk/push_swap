/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:49:35 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/11 18:21:41 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	first = tmp->next;
	first->prev = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_a);
	tmp->next->next = NULL;
	*stack_a = first;
	write (1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	first = tmp->next;
	first->prev = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_b);
	tmp->next->next = NULL;
	*stack_b = first;
	write (1, "rb\n", 3);
}

void	rra(t_stack **stack_a)
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
			write (1, "rra\n", 4);
			return ;
		}
	}
}

void	rrb(t_stack **stack_b)
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
			write (1, "rrb\n", 4);
			return ;
		}
	}
}
