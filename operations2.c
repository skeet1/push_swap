/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:51:49 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/24 13:30:48 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack_a **a, t_stack_a **b)
{
	int			sb;
	t_stack_a	*tb;

	sb = 0;
	tb = *b;
	while (tb)
	{
		sb++;
		tb = tb->p;
	}
	if (sb > 0)
	{
		tb = *b;
		ft_add_front(a, tb->n);
		*b = tb->p;
		free(tb);
	}
	ft_putstr("pa\n");
}

void	ft_pb(t_stack_a **a, t_stack_a **b)
{
	int			sa;
	t_stack_a	*ta;

	sa = 0;
	ta = *a;
	while (ta)
	{
		sa++;
		ta = ta->p;
	}
	if (sa > 0)
	{
		ta = *a;
		ft_add_front(b, ta->n);
		*a = ta->p;
		free(ta);
	}
	ft_putstr("pb\n");
}

void	ft_rra(t_stack_a **a, int p)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	t_stack_a	*head;

	if (ft_lstsize(*a) < 2)
		return ;
	head = *a;
	tmp1 = *a;
	while (tmp1->p->p != NULL)
		tmp1 = tmp1->p;
	tmp2 = tmp1->p;
	tmp2->p = head;
	tmp1->p = NULL;
	*a = tmp2;
	if (p)
		ft_putstr("rra\n");
}

void	ft_rrb(t_stack_a **b, int p)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	t_stack_a	*head;

	if (ft_lstsize(*b) < 2)
		return ;
	head = *b;
	tmp1 = *b;
	while (tmp1->p->p != NULL)
		tmp1 = tmp1->p;
	tmp2 = tmp1->p;
	tmp2->p = head;
	tmp1->p = NULL;
	*b = tmp2;
	if (p)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_stack_a **a, t_stack_a **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	ft_putstr("rrr\n");
}
