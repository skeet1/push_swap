/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:19:20 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 15:49:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_ind_pair(t_stack_a **a, int n)
{
	t_stack_a *tmp;
	int ind_min;
	int min;

	ft_ind_stack(a);
	tmp = *a;
	while (tmp->p)
	{
		if ((tmp->n < n && tmp->p->n > n))
			return (tmp->p->ind);
		tmp = tmp->p;
	}
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
	if (min > n)
		return (ind_min);
	tmp = *a;
	min = tmp->n;
	tmp = tmp->p;
	ind_min = 0;
	while (tmp)
	{
		if (min < tmp->n)
		{
			min = tmp->n;
			ind_min = tmp->ind;
		}
		tmp = tmp->p;
	}
	if (min < n)
		return (ind_min + 1);
	return (0);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_num_of_move_need(t_stack_a **a, t_stack_a **b)
{
	t_stack_a *t1;
	t_stack_a *t2;
	t_stack_a *test;
	int ind_p;

	ft_ind_stack(b);
	ft_ind_stack(a);
	t1 = *b;
	int i = 0;
	while (t1)
	{
		t2 = *a;
		ind_p = ft_ind_pair(a, t1->n);
		t1->ind_pair = ind_p;
		if (ind_p > ft_lstsize(*a) / 2)
			ind_p = ft_lstsize(*a) - ind_p;
		if (t1->ind_pair > ft_lstsize(*a) / 2 && t1->ind > ft_lstsize(*b) / 2)
			ind_p = ft_max(ind_p, ft_lstsize(*b) - t1->ind);
		else if (t1->ind_pair <= ft_lstsize(*a) / 2 && t1->ind <= ft_lstsize(*b) / 2)
			ind_p = ft_max(ind_p, t1->ind);
		else
			ind_p += t1->ind;
		test = *b;
		t1->need = ind_p + 1;
		t1 = t1->p;
		i++;
	}
}

int	ft_ind_pair_min_move(t_stack_a **b, t_stack_a **a)
{
	t_stack_a *tmp;
	int min_move;
	int ind;

	tmp = *b;
	min_move = 1000000;
	while (tmp)
	{
		if (tmp->need < min_move)
		{
			min_move = tmp->need;
			ind = tmp->ind_pair;
		}
		tmp = tmp->p;
	}
	if (ind == ft_lstsize(*a))
		ind = 0;
	return (ind);
}

int	ft_ind_min_move(t_stack_a **b)
{
	t_stack_a *tmp;
	int min_move;
	int ind;

	tmp = *b;
	min_move = 1000000;
	while (tmp)
	{
		if (tmp->need < min_move)
		{
			min_move = tmp->need;
			ind = tmp->ind;
		}
		tmp = tmp->p;
	}
	return (ind);
}