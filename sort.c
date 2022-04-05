/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:05 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/05 17:22:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack_a **a)
{
    t_stack_a *tmp;
    int f;
    int s;
    int t;

    tmp = *a;
    f = tmp->n;
    s = tmp->p->n;
    t = tmp->p->p->n;
    if (f < s && t < s && f < t)
    {
        sa(a, 1);
        ra(a, 1);
    }
    else if (t < s && t < f && s < f)
    {
        sa(a, 1);
        rra(a, 1);
    }
    else if (s < f && s < t && t < f)
        ra(a, 1);
    else if (t < s && t < f && f < s)
        rra(a, 1);
    else if (s < f && s < t && f < t)
        sa(a, 1);
}

void    sort(t_stack_a **a, t_stack_a **b)
{
    t_stack_a *tmp;
    int size;

    size = 0;
    tmp = *a;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    if (size == 3)
    sort_three(a);
    (void)b;
}