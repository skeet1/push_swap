/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:49:15 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 21:50:15 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_in_stack(t_stack_a **a)
{
	t_stack_a	*tmp;
	int			min;

	tmp = *a;
	min = tmp->n;
	tmp = tmp->p;
	while (tmp)
	{
		if (min > tmp->n)
		{
			min = tmp->n;
		}
		tmp = tmp->p;
	}
	return (min);
}

int	ft_max_in_stack(t_stack_a **a)
{
	t_stack_a	*tmp;
	int			max;

	tmp = *a;
	max = tmp->n;
	tmp = tmp->p;
	while (tmp)
	{
		if (max < tmp->n)
		{
			max = tmp->n;
		}
		tmp = tmp->p;
	}
	return (max);
}
