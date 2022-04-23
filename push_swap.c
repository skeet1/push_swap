/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:33:24 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 15:50:48 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print(t_stack_a *arg)
{
	while (arg != NULL)
	{
		printf("%d : %d and l : %d and prev is %d\n", arg->ind, arg->n, arg->lis, arg->need);
		arg = arg->p;
	}
}

t_stack_a *ft_new_node(int n)
{
	t_stack_a *ret;

	ret = (t_stack_a *)malloc(sizeof(t_stack_a));
	ret->n = n;
	ret->p = NULL;

	return ret;
}

void ft_add_back(t_stack_a **s, int n)
{
	t_stack_a *tmp;
	t_stack_a *new;

	new = ft_new_node(n);
	tmp = *s;
	if (tmp)
	{
		while (tmp->p)
		{
			tmp = tmp->p;
		}
		tmp->p = new;
		new->prev = tmp;
	}
	else
	{
		*s = new;
	}
}

void    ft_add_front(t_stack_a **s, int n)
{
	t_stack_a *new;

	new = ft_new_node(n);
	new->p = *s;
	new->prev = NULL;
	*s = new;
}

int main(int argc, char **argv)
{
	int i;
	t_stack_a *a;
	t_stack_a *b;
	static char **args;

	i = 2;
	if (argc == 1)
		return (0);
	else
	{
		while (i < argc)
			argv[1] = ft_strjoin(argv[1], argv[i++]);
		args = ft_split(argv[1], ' ');
		i = 0;
		while (args[i])
		{
			if (ft_check_arg(args[i]) == 0)
				return (ft_putstr("Error\n"), 0);
			ft_add_back(&a, ft_atoi(args[i++]));
		}
	}
	if (ft_check_dup(a) == 0)
		return (ft_putstr("Error\n"), 0);
	if (ft_check_sort(a))
		return (ft_putstr("is sorted \n"), 0);
	b = NULL;
	ft_sort(&a, &b);
}
