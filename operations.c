/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:33:14 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 16:03:01 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack_a **a, int p)
{
	int			size;
	t_stack_a	*tmp;
	int			fn;
	int			sn;

	size = 0;
	tmp = *a;
	while (tmp)
	{
		size++;
		tmp = tmp->p;
	}
	if (size > 1)
	{
		tmp = *a;
		fn = tmp->n;
		sn = tmp->p->n;
		tmp->n = sn;
		tmp->p->n = fn;
	}
	if (p)
		ft_putstr("sa\n");
}

void	ft_sb(t_stack_a **b, int p)
{
	int			size;
	t_stack_a	*tmp;
	int			fn;
	int			sn;

	size = 0;
	tmp = *b;
	while (tmp)
	{
		size++;
		tmp = tmp->p;
	}
	if (size > 1)
	{
		tmp = *b;
		fn = tmp->n;
		sn = tmp->p->n;
		tmp->n = sn;
		tmp->p->n = fn;
	}
	if (p)
		ft_putstr("sb\n");
}

void	ft_ss(t_stack_a **a, t_stack_a **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	ft_putstr("ss\n");
}
