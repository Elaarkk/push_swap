/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:44 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/11 04:41:06 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sa(t_stack **stack_a)
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
	write (1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
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
	write (1, "sb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	if ((*stack_b)->next)
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	else
		(*stack_b) = NULL;
	ft_lstadd_front(stack_a, tmp);
	*stack_a = tmp;
	write (1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	if ((*stack_a)->next)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else
		(*stack_a) = NULL;
	ft_lstadd_front(stack_b, tmp);
	*stack_b = tmp;
	write (1, "pb\n", 3);
}
