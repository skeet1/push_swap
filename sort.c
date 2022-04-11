/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:05 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/10 12:10:23 by mkarim           ###   ########.fr       */
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

void    sort_four(t_stack_a **a, t_stack_a **b)
{
    int min;
    int ind_min;
    t_stack_a *tmp;
    int i;

    ind_min = 0;
    tmp = *a;
    min = 2147483647;
    i = 0;
    while (tmp)
    {
        tmp->ind = ++i;
        if (tmp->n < min)
        {
            ind_min = tmp->ind;
            min = tmp->n;
        }
        tmp = tmp->p;
    }
    while (--ind_min)
        ra(a, 1);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_stack_a **a, t_stack_a **b)
{
    int m;
    int ind_m;
    t_stack_a *tmp;
    int i;

    ind_m = 0;
    tmp = *a;
    m = -2147483648;
    i = 0;
    while (tmp)
    {
        tmp->ind = ++i;
        if (tmp->n > m)
        {
            ind_m = tmp->ind;
            m = tmp->n;
        }
        tmp = tmp->p;
    }
    while (--ind_m)
        ra(a, 1);
    pb(a, b);
    ind_m = 0;
    tmp = *a;
    m = 2147483647;
    i = 0;
    while (tmp)
    {
        tmp->ind = ++i;
        if (tmp->n < m)
        {
            ind_m = tmp->ind;
            m = tmp->n;
        }
        tmp = tmp->p;
    }
    while (--ind_m)
        ra(a, 1);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
    ra(a, 1);
}

t_stack_a *find_lis(t_stack_a **a)
{
    
}

void    ft_sort_b(t_stack_a **a, t_stack_a **b)
{
    t_stack_a *lis;
    
    lis = find_lis(a);
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
    if (size == 2)
        ra(a, 1);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
        ft_sort_b(a, b);
}