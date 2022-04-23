/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:19:20 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 21:53:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		ft_min_in_stack(t_stack_a **a)
// {
// 	t_stack_a	*tmp;
// 	int			min;

// 	tmp = *a;
// 	min = tmp->n;
// 	tmp = tmp->p;
// 	while (tmp)
// 	{
// 		if (min > tmp->n)
// 		{
// 			min = tmp->n;
// 		}
// 		tmp = tmp->p;
// 	}
// 	return (min);
// }

// int		ft_max_in_stack(t_stack_a **a)
// {
// 	t_stack_a	*tmp;
// 	int			max;

// 	tmp = *a;
// 	max = tmp->n;
// 	tmp = tmp->p;
// 	while (tmp)
// 	{
// 		if (max < tmp->n)
// 		{
// 			max = tmp->n;
// 		}
// 		tmp = tmp->p;
// 	}
// 	return (max);
// }

int	ft_ind_pair(t_stack_a **a, int n)
{
	t_stack_a	*tmp;
	int			ind_min;
	int			min;
	int			max;
	int			ind_max;

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


	// ind_min = ft_ind_of_min(a);
	// min = ft_min_in_stack(a);


	if (min > n)
		return (ind_min);
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


	// max = ft_max_in_stack(a);
	// ind_max = ft_ind_of_max(a);
	if (max < n)
		return (ind_max + 1);
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
	t_stack_a	*t1;
	t_stack_a	*t2;
	int			ind_p;

	ft_ind_stack(b);
	ft_ind_stack(a);
	t1 = *b;
	while (t1)
	{
		t2 = *a;
		ind_p = ft_ind_pair(a, t1->n);
		t1->ind_pair = ind_p;
		if (ind_p > ft_lstsize(*a) / 2)
			ind_p = ft_lstsize(*a) - ind_p;
		if (t1->ind_pair > ft_lstsize(*a) / 2 && t1->ind > ft_lstsize(*b) / 2)
			ind_p = ft_max(ind_p, ft_lstsize(*b) - t1->ind);
		else if (t1->ind_pair <= ft_lstsize(*a) / 2
			&& t1->ind <= ft_lstsize(*b) / 2)
			ind_p = ft_max(ind_p, t1->ind);
		else
			ind_p += t1->ind;
		t1->need = ind_p + 1;
		t1 = t1->p;
	}
}

int	ft_ind_pmm(t_stack_a **b, t_stack_a **a)
{
	t_stack_a	*tmp;
	int			min_move;
	int			ind;

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
	t_stack_a	*tmp;
	int			min_move;
	int			ind;

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
