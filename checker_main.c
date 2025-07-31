/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:48:43 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:55:08 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_long(char *str, t_stack *stack_a)
{
	long	nb;

	nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
	{
		free(str);
		ft_error(stack_a, 0);
	}
	return (0);
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_not_similar(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	tmp = tmp->next;
	while (tmp && stack)
	{
		while (tmp)
		{
			if (tmp->value == stack->value)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
		tmp = stack->next;
	}
	return (1);
}

int	check_nb(char *str)
{
	int	i;
	int	only_spaces;

	i = 0;
	only_spaces = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			only_spaces = 1;
		i++;
	}
	return (only_spaces);
}
