/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:21:17 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 17:42:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_with_rr(t_stack_a **a, t_stack_a **b, int ind_min_move)
{
	int			el_b;
	int			el_a;
	t_stack_a	*t_a;
	t_stack_a	*t_b;

	ft_let(&el_a, ft_gbi(a, ft_ind_pmm(b, a)), &el_b, ft_gbi(b, ind_min_move));
	t_a = *a;
	t_b = *b;
	while (t_a->n != el_a && t_b->n != el_b)
	{
		ft_rr(a, b);
		t_a = *a;
		t_b = *b;
	}
	while (t_a->n != el_a)
	{
		ft_ra(a, 1);
		t_a = *a;
	}
	while (t_b->n != el_b)
	{
		ft_rb(b, 1);
		t_b = *b;
	}
	ft_pa(a, b);
}

int	if_rrr(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_pair)
{
	ft_ind_stack(a);
	ft_ind_stack(b);
	if (ind_min_move > ft_lstsize(*b) / 2 && ind_pair > ft_lstsize(*a) / 2)
		return (1);
	return (0);
}

int	if_rr(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_pair)
{
	ft_ind_stack(a);
	ft_ind_stack(b);
	if (ind_min_move <= ft_lstsize(*b) / 2 && ind_pair <= ft_lstsize(*a) / 2)
		return (1);
	return (0);
}

void	ft_move_to_a_assist(t_stack_a **a, int ind_p_mm)
{
	int	l;

	l = 0;
	if (ind_p_mm > ft_lstsize(*a) / 2)
	{
		l = ft_lstsize(*a) - ind_p_mm;
		while (l--)
			ft_rra(a, 1);
	}
	else
	{
		l = ind_p_mm;
		while (l--)
			ft_ra(a, 1);
	}
}

void	ft_move_to_a(t_stack_a **a, t_stack_a **b, int ind_mm, int ind_p_mm)
{
	int		el_a;
	int		el_b;
	int		l;

	el_a = ft_gbi(a, ind_p_mm);
	el_b = ft_gbi(b, ind_mm);
	l = 0;
	if (ind_mm > ft_lstsize(*b) / 2)
	{
		l = ft_lstsize(*b) - ind_mm;
		while (l--)
			ft_rrb(b, 1);
	}
	else
	{
		l = ind_mm;
		while (l--)
			ft_rb(b, 1);
	}
	ft_move_to_a_assist(a, ind_p_mm);
	ft_pa(a, b);
}
