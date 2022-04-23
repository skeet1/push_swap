/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:18:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 17:01:46 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ind_stack(t_stack_a **a)
{
	int			i;
	t_stack_a	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->l = 1;
		tmp->ind = i++;
		tmp = tmp->p;
	}
}

void	ft_new_lis(int tl, int t1l, int t_prev_ind, int t1_ind)
{
	tl = t1l;
	t_prev_ind = t1_ind;
}

int	ft_find_lis(t_stack_a **a)
{
	t_stack_a	*tmp;
	t_stack_a	*tmp1;
	int			lis;

	ft_ind_stack(a);
	lis = 1;
	tmp = *a;
	while (tmp)
	{
		tmp1 = *a;
		tmp->prev_ind = -1;
		while (tmp1->ind < tmp->ind)
		{
			if (tmp->n > tmp1->n)
			{
				if (tmp1->l + 1 > tmp->l)
					ft_new_lis(tmp->l, tmp1->l + 1, tmp->prev_ind, tmp1->ind);
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
	t_stack_a	*tmp;
	int			prev;

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

void	ft_leave_lis_in_a(t_stack_a **a, t_stack_a **b, int size)
{
	t_stack_a	*tmp;
	int			i;

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
