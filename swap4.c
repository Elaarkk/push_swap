/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:43:08 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:35:20 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ra_n(t_stack **stack_a)
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
}

void	rb_n(t_stack **stack_b)
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
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	ra_n(stack_a);
	rb_n(stack_b);
	write (1, "rr\n", 3);
}
