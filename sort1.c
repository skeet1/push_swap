/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:18:07 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 16:05:52 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack_a **a)
{
	t_stack_a	*tmp;
	int			f;
	int			s;
	int			t;

	tmp = *a;
	f = tmp->n;
	s = tmp->p->n;
	t = tmp->p->p->n;
	if (f < s && t < s && f < t)
	{
		ft_sa(a, 1);
		ft_ra(a, 1);
	}
	else if (t < s && t < f && s < f)
	{
		ft_sa(a, 1);
		ft_rra(a, 1);
	}
	else if (s < f && s < t && t < f)
		ft_ra(a, 1);
	else if (t < s && t < f && f < s)
		ft_rra(a, 1);
	else if (s < f && s < t && f < t)
		ft_sa(a, 1);
}

int	ft_ind_of_max(t_stack_a **a)
{
	int			m;
	int			ind_m;
	t_stack_a	*tmp;
	int			i;

	ind_m = 0;
	tmp = *a;
	m = -2147483648;
	i = 0;
	while (tmp)
	{
		tmp->ind = ++i;
		if (tmp->n > m)
		{
			ind_m = tmp->ind;
			m = tmp->n;
		}
		tmp = tmp->p;
	}
	return (ind_m);
}

int	ft_ind_of_min(t_stack_a **a)
{
	int			m;
	int			ind_m;
	t_stack_a	*tmp;
	int			i;

	ind_m = 0;
	tmp = *a;
	m = 2147483647;
	i = 0;
	while (tmp)
	{
		tmp->ind = ++i;
		if (tmp->n < m)
		{
			ind_m = tmp->ind;
			m = tmp->n;
		}
		tmp = tmp->p;
	}
	return (ind_m);
}

void	ft_sort_four(t_stack_a **a, t_stack_a **b)
{
	int	ind_max;

	ind_max = ft_ind_of_max(a);
	if (ind_max > 2)
		while (ind_max++ <= 4)
			ft_rra(a, 1);
	else
		while (--ind_max)
			ft_ra(a, 1);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_ra(a, 1);
}

void	ft_sort_five(t_stack_a **a, t_stack_a **b)
{
	int	ind_max;
	int	ind_min;

	ind_max = ft_ind_of_max(a);
	if (ind_max > 3)
		while (ind_max++ <= 5)
			ft_rra(a, 1);
	else
		while (--ind_max)
			ft_ra(a, 1);
	ft_pb(a, b);
	ind_min = ft_ind_of_min(a);
	if (ind_min > 2)
		while (ind_min++ <= 4)
			ft_rra(a, 1);
	else
		while (--ind_min)
			ft_ra(a, 1);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
	ft_ra(a, 1);
}
