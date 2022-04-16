/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:05 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/16 20:54:39 by mkarim           ###   ########.fr       */
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

int ind_of_max(t_stack_a **a)
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
    return (ind_m);
}

int ind_of_min(t_stack_a **a)
{
    int m;
    int ind_m;
    t_stack_a *tmp;
    int i;

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
    return (ind_m);
}

void    sort_four(t_stack_a **a, t_stack_a **b)
{
    int ind_max;

    ind_max = ind_of_max(a);
    if (ind_max > 2)
        while (ind_max++ <= 4)
            rra(a, 1);
    else
        while (--ind_max)
            ra(a, 1);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    ra(a, 1);
}

void sort_five(t_stack_a **a, t_stack_a **b)
{
    int ind_max;
    int ind_min;

    ind_max = ind_of_max(a);
    if (ind_max > 3)
        while (ind_max++ <= 5)
            rra(a, 1);
    else
        while (--ind_max)
            ra(a, 1);
    pb(a, b);
    ind_min = ind_of_min(a);
    if (ind_min > 2)
        while (ind_min++ <= 4)
            rra(a, 1);
    else
        while (--ind_min)
            ra(a, 1);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
    ra(a, 1);
}

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

void    ft_mark_lis(t_stack_a **a, int lis)
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
            ra(a, 1);
        else
            pb(a, b);
        tmp = tmp->p;
    }
    ft_ind_stack(a);
    ft_ind_stack(b);
}

void    ft_num_of_move_need(t_stack_a **a, t_stack_a **b)
{
    t_stack_a *t1;
    t_stack_a *t2;
    int need;

    ft_ind_stack(b);
    ft_ind_stack(a);
    t1 = *b;
    while (t1)
    {
        t2 = *a;
        need = 1;
        while (t2)
        {
            if (t1->n > t2->n)
                need++;
            else
                break;
            t2 = t2->p;
        }
        t1->need = need + t1->ind;
        t1 = t1->p;
    }
}

int     ft_ind_min_move(t_stack_a **b)
{
    t_stack_a *tmp;
    int min_move;
    int ind;

    tmp = *b;
    min_move = 1000000;
    while (tmp)
    {
        if (tmp->need < min_move)
        {
            min_move = tmp->need;
            ind = tmp->ind;
        }
        tmp = tmp->p;
    }
    return (ind);
}

int     ft_min_move(t_stack_a **b)
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

void    ft_move_stack_b_to_a(t_stack_a **a, t_stack_a **b, int ind, int num_move)
{
    // int l;

    // l = ind;
    // if (ind > num_move - ind - 1)
    //     l = num_move - ind - 1;
    // if (l > ind)
    //     l = ind;
    // while (l--)
    // {
    //     if (num_move - 1 > ind)
    //         rr(a, b);
    //     else
    //         rb(a, 1);
    //     ind--;
    //     num_move -= 2;
    // }
    // while (ind-- > 0)
    // {
    //     rb(a, 1);
    //     num_move--;
    // }
    // while (--num_move)
    //     ra(a, 1);
    // pa(a, b);

    
    int i;
    
    i = 1;
    while (ind--)
    {
        rb(b, 1);
        num_move--;
    }
    while (i++ < num_move)
        ra(a, 1);
    pa(a, b);
    // i = 1;
    // while (i++ < num_move)
    //     rra(a, 1);
}

void    ft_final_sort(t_stack_a **a)
{
    int ind_min;
    int l;

    ind_min = ind_of_min(a);
    ft_ind_stack(a);
    if (ind_min >= ft_lstsize(*a) / 2)
    {
        l = ft_lstsize(*a) - ind_min + 1;
        while (l--)
            rra(a, 1);
    }
    else
    {
        l = ind_min;
        while (l--)
            ra(a, 1);
    }
}

void    ft_sort1(t_stack_a **a, t_stack_a **b)
{
    int lis;
    
    lis = ft_find_lis(a);
    ft_mark_lis(a, lis);
    ft_leave_lis_in_a(a, b, ft_lstsize(*a));
    ft_num_of_move_need(a, b);
    printf("infos : %d and %d\n", ft_ind_min_move(b), ft_min_move(b));
    while (ft_lstsize(*b))
    {
        ft_move_stack_b_to_a(a, b, ft_ind_min_move(b), ft_min_move(b));
        ft_ind_stack(a);
        ft_ind_stack(b);
        ft_num_of_move_need(a, b);
    }
    ft_final_sort(a);
    ft_ind_stack(a);
}

void    ft_sort(t_stack_a **a, t_stack_a **b)
{
    int size;

    size = ft_lstsize(*a);
    if (size == 2)
        ra(a, 1);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
        ft_sort1(a, b);
}