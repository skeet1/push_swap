/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:18:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 15:48:32 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int    ft_lstsize(t_stack_a *a)
{
	int		i;

	i = 0;
	while (a != NULL)
	{
		a = a->p;
		i++;
	}
	return (i);
}

void    ft_ind_stack(t_stack_a **a)
{
	int     i;
	t_stack_a *tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->l = 1;
		tmp->ind = i++;
		tmp = tmp->p;
	}
}

int    ft_find_lis(t_stack_a **a)
{
	t_stack_a *tmp;
	t_stack_a *tmp1;
	int lis;
	int tl;

	ft_ind_stack(a);
	lis = 1;
	tmp = *a;
	tl = 1;
	while (tmp)
	{
		tmp1 = *a;
		tmp->prev_ind = -1;
		while (tmp1->ind < tmp->ind)
		{
			if (tmp->n > tmp1->n)
			{
				tl = tmp1->l + 1;
				if (tl > tmp->l)
				{
					tmp->l = tl;
					tmp->prev_ind = tmp1->ind;
				}
				if (lis < tmp->l)
					lis = tmp->l;
			}
			tmp1 = tmp1->p;
		}
		tmp = tmp->p;
	}
	return (lis);
}

void	ft_mark_lis(t_stack_a **a, int lis)
{
	t_stack_a *tmp;
	int prev;

	tmp = *a;
	while (tmp)
	{
		if (tmp->l == lis)
		{
			tmp->lis = 1;
			prev = tmp->prev_ind;
			while (tmp)
			{
				if (tmp->ind == prev)
				{
					tmp->lis = 1;
					prev = tmp->prev_ind;
				}
				tmp = tmp->prev;
			}
			return ;
		}
		else
			tmp->lis = 0;
		tmp = tmp->p;
	}
}

void    ft_leave_lis_in_a(t_stack_a **a, t_stack_a **b, int size)
{
	t_stack_a *tmp;
	int i;

	tmp = *a;
	i = 0;
	while (i++ < size)
	{
		if (tmp->lis)
			ft_ra(a, 1);
		else
			ft_pb(a, b);
		tmp = tmp->p;
	}
	ft_ind_stack(a);
	ft_ind_stack(b);
}