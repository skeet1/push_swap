/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:51:18 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 16:08:46 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack_a **a, int p)
{
	int			size;
	t_stack_a	*tmp;
	int			fn;

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
		*a = tmp->p;
		ft_add_back(a, fn);
		free(tmp);
	}
	if (p)
		ft_putstr("ra\n");
}

void	ft_rb(t_stack_a **b, int p)
{
	int			size;
	t_stack_a	*tmp;
	int			fn;

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
		*b = tmp->p;
		ft_add_back(b, fn);
		free(tmp);
	}
	if (p)
		ft_putstr("rb\n");
}

void	ft_rr(t_stack_a **a, t_stack_a **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	ft_putstr("rr\n");
}
