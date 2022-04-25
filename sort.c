/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:05 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/25 01:55:18 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack_a *a)
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

void	ft_sort1(t_stack_a **a, t_stack_a **b)
{
	int			lis;
	t_stack_a	*tmp;

	lis = ft_find_lis(a);
	ft_mark_lis(a, lis);
	ft_leave_lis_in_a(a, b, ft_lstsize(*a));
	ft_num_of_move_need(a, b);
	while (ft_lstsize(*b))
	{
		if (if_rrr(a, b, ft_ind_min_move(b), ft_ind_pmm(b, a)))
			ft_move_with_rrr(a, b, ft_ind_min_move(b));
		else if (if_rr(a, b, ft_ind_min_move(b), ft_ind_pmm(b, a)))
			ft_move_with_rr(a, b, ft_ind_min_move(b));
		else
			ft_move_to_a(a, b, ft_ind_min_move(b), ft_ind_pmm(b, a));
		tmp = *b;
		ft_ind_stack(a);
		ft_ind_stack(b);
		ft_num_of_move_need(a, b);
	}
	ft_final_sort(a);
}

void	ft_sort(t_stack_a **a, t_stack_a **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_ra(a, 1);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
	else
	{
		ft_sort1(a, b);
	}
}
