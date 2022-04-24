/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:49:15 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/24 13:18:40 by mkarim           ###   ########.fr       */
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

int	ft_miiin(t_stack_a **a, int ind)
{
	t_stack_a	*tmp;
	int			min;
	int			ind_min;

	tmp = *a;
	min = tmp->n;
	tmp = tmp->p;
	ind_min = 0;
	while (tmp)
	{
		if (min > tmp->n)
		{
			min = tmp->n;
			ind_min = tmp->ind;
		}
		tmp = tmp->p;
	}
	if (ind)
		return (ind_min);
	return (min);
}

int	ft_maaax(t_stack_a **a, int ind)
{
	t_stack_a	*tmp;
	int			max;
	int			ind_max;

	tmp = *a;
	max = tmp->n;
	tmp = tmp->p;
	ind_max = 0;
	while (tmp)
	{
		if (max < tmp->n)
		{
			max = tmp->n;
			ind_max = tmp->ind;
		}
		tmp = tmp->p;
	}
	if (ind)
		return (ind_max);
	return (max);
}
