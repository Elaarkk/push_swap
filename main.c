/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:56:18 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/13 00:56:56 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_number(char *str, t_stack *stack_a)
{
	int		i;
	int		j;
	char	*nb;

	i = 0;
	j = -1;
	if (str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != ' ' && str[i] != '\0')
		ft_error(stack_a, 0);
	nb = malloc(i + 1);
	if (!nb)
		return (0);
	while (j++ < i - 1)
	{
		nb[j] = str[j];
	}
	nb[j] = '\0';
	check_long(nb, stack_a);
	i = ft_atoi(nb);
	return (free(nb), i);
}

t_stack	*assign_number(t_stack *stack_a, char **argv, int argc)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < argc)
	{
		if (!check_argv(argv[i]))
			ft_error(stack_a, 0);
		check_long(argv[i], stack_a);
		if (!stack_a)
		{
			stack_a = create_list(ft_atoi(argv[i]), stack_a);
			if (!stack_a)
				ft_error(0, 0);
		}
		else
			ft_lstadd_back(&stack_a, create_list(ft_atoi(argv[i]),
					stack_a));
		index++;
		i++;
	}
	return (stack_a);
}

t_stack	*assign_onearg(t_stack *stack_a, char *str)
{
	int	i;

	i = 0;
	if (!check_nb(str))
		ft_error(0, 0);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!stack_a)
		{
			stack_a = create_list(get_number(&str[i], stack_a), stack_a);
			if (!stack_a)
				ft_error(0, 0);
		}
		else if (str[i] != '\0')
			ft_lstadd_back(&stack_a, create_list(get_number(&str[i], stack_a),
					stack_a));
		while (str[i] && (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
			i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		stack_a = assign_onearg(stack_a, argv[1]);
	if (argc > 2)
		stack_a = assign_number(stack_a, argv, argc);
	if (!is_not_similar(stack_a))
		ft_error(stack_a, 0);
	sorting_start(stack_a);
}
