/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:10 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/12 23:31:16 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_position(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		tmp->rank = i++;
		if (i <= (count_node((*stack_a)) / 2))
			tmp->is_on_top = 1;
		else
			tmp->is_on_top = 0;
		tmp = tmp->next;
	}
}

void	check_target_b(t_stack **stack_a, t_stack **stack_b, int checker)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (checker == tmp_b->value)
	{
		tmp_a->target = tmp_b;
		return ;
	}
	while (1)
	{
		while (tmp_b)
		{
			if (tmp_b->value == checker)
			{
				tmp_a->target = tmp_b;
				return ;
			}
			tmp_b = tmp_b->next;
		}
		tmp_b = *stack_b;
		checker--;
	}
}

void	init_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		checker;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		checker = tmp_a->value - 1;
		if (is_min(tmp_a, (*stack_b)))
			find_bmax(&tmp_a, stack_b);
		else
			check_target_b(&tmp_a, stack_b, checker);
		tmp_a = tmp_a->next;
	}
}

void	init_cost_value(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->is_on_top && tmp_a->target->is_on_top)
			tmp_a->cost_value = (tmp_a->rank + tmp_a->target->rank) / 2
				+ (tmp_a->rank + tmp_a->target->rank) % 2;
		else if (tmp_a->is_on_top == 0 && tmp_a->target->is_on_top == 0)
			tmp_a->cost_value = (((count_node((*stack_a)) - (tmp_a->rank + 1))
						+ (count_node((*stack_b)) - (tmp_a->target->rank + 1)))
					/ 2 + ((count_node((*stack_a)) - (tmp_a->rank + 1))
						+ (count_node((*stack_b)) - (tmp_a->target->rank + 1)))
					% 2)
				+ 1;
		else if (tmp_a->is_on_top && tmp_a->target->is_on_top == 0)
			tmp_a->cost_value = tmp_a->rank + ((count_node((*stack_b))
						- (tmp_a->target->rank + 1)) + 1);
		else if (tmp_a->is_on_top == 0 && tmp_a->target->is_on_top)
			tmp_a->cost_value = ((count_node((*stack_a)) - (tmp_a->rank + 1))
					+ 1) + tmp_a->target->rank;
		tmp_a = tmp_a->next;
	}
}

void	init_is_good_one(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*good_tmp;
	int		cost_min;

	tmp = *stack_a;
	cost_min = tmp->cost_value;
	tmp->is_good_one = 1;
	good_tmp = tmp;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->cost_value < cost_min)
		{
			tmp->is_good_one = 1;
			good_tmp->is_good_one = 0;
			cost_min = tmp->cost_value;
			good_tmp = tmp;
		}
		else
			tmp->is_good_one = 0;
		tmp = tmp->next;
	}
}
