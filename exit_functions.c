/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:03 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:04:26 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_free(&stack_a);
	if (stack_b)
		ft_free(&stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!(*lst))
		return ;
	while (*lst)
	{
		i++;
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
