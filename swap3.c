/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:49:40 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:35:10 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sa_n(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp->prev = tmp->next;
	tmp2->next = tmp;
	(*stack_a) = tmp2;
}

void	sb_n(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp = *stack_b;
	tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	tmp->prev = tmp->next;
	tmp2->next = tmp;
	(*stack_b) = tmp2;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	sa_n(stack_a);
	sb_n(stack_b);
	write(1, "ss\n", 3);
}
