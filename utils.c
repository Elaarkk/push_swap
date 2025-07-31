/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:50:12 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/10 19:58:29 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack	*create_list(int n, t_stack *stack_a)
{
	t_stack		*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		ft_error(stack_a, 0);
	list->value = n;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;
	t_stack	*previous;

	p = *lst;
	previous = p;
	if (!new)
		return ;
	if (*lst)
	{
		while (p->next)
		{
			p = p->next;
			previous = p;
		}
		p->next = new;
		p = new;
		new->prev = previous;
	}
	else
		*lst = new;
	return ;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		new->prev = NULL;
		(*lst)->prev = new;
		*lst = new;
	}
	else if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
	}
	return ;
}

long	ft_atoi(const char *nptr)
{
	long	i;
	long	signe;
	long	number;

	i = 0;
	signe = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - 48) + (number * 10);
		i++;
	}
	return (number * signe);
}
