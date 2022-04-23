/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:20:33 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 15:49:49 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_move(t_stack_a **b)
{
	t_stack_a *tmp;
	int min_move;

	tmp = *b;
	min_move = 1000000;
	while (tmp)
	{
		if (tmp->need < min_move)
			min_move = tmp->need;
		tmp = tmp->p;
	}
	return (min_move);
}

void	ft_move_stack_b_to_a(t_stack_a **a, t_stack_a **b, int if_rra, int num_move)
{
	t_stack_a *tmp;

	ft_ind_stack(a);

	tmp = *b;
	if (if_rra)
	{
		while (--num_move)
			ft_rra(a, 1);
	}
	else
	{
		while (--num_move)
			ft_ra(a, 1);
	}
	ft_pa(a, b);
	ft_ind_stack(a);
}

void    ft_final_sort(t_stack_a **a)
{
	int ind_min;
	int l;

	ind_min = ft_ind_of_min(a);
	ft_ind_stack(a);
	if (ind_min >= ft_lstsize(*a) / 2)
	{
		l = ft_lstsize(*a) - ind_min + 1;
		while (l--)
			ft_rra(a, 1);
	}
	else
	{
		l = ind_min;
		while (--l)
			ft_ra(a, 1);
	}
}

int ft_get_by_index(t_stack_a **s, int ind_min_move)
{
	t_stack_a *tmp;

	tmp = *s;
	ft_ind_stack(s);
	while (tmp)
	{
		if (tmp->ind == ind_min_move)
			return (tmp->n);
		tmp = tmp->p;
	}
	return (0);
}

void    ft_move_with_rrr(t_stack_a **a, t_stack_a **b, int ind_min_move)
{
	int el_b;
	int el_a;
	t_stack_a *t_a;
	t_stack_a *t_b;

	el_b = ft_get_by_index(b, ind_min_move);
	el_a = ft_get_by_index(a, ft_ind_pair_min_move(b, a));
	t_a = *a;
	t_b = *b;
	while (t_a->n != el_a && t_b->n != el_b)
	{
		ft_rrr(a, b);
		t_a = *a;
		t_b = *b;
	}
	while (t_a->n != el_a)
	{
		ft_rra(a, 1);
		t_a = *a;
		t_b = *b;
	}
	while (t_b->n != el_b)
	{
		ft_rrb(b, 1);
		t_a = *a;
		t_b = *b;
	}
	ft_pa(a, b);
}