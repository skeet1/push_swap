/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:05 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/23 13:40:10 by mkarim           ###   ########.fr       */
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

int     ft_ind_pair(t_stack_a **a, int n)
{
    t_stack_a *tmp;
    int ind_min;
    int min;
    
    ft_ind_stack(a);
    tmp = *a;
    while (tmp->p)
    {
        if ((tmp->n < n && tmp->p->n > n))
            return (tmp->p->ind);
        tmp = tmp->p;
    }
    tmp = *a;
    min = tmp->n;
    tmp = tmp->p;
    ind_min = 0;
    while (tmp)
    {
        if (min > tmp->n)
        {
            min = tmp->n;
            ind_min = tmp->ind;
        }
        tmp = tmp->p;
    }
    if (min > n)
        return (ind_min);
    tmp = *a;
    min = tmp->n; // min and ind_min stand now for max and ind_max 
    tmp = tmp->p;
    ind_min = 0;
    while (tmp)
    {
        if (min < tmp->n)
        {
            min = tmp->n;
            ind_min = tmp->ind;
        }
        tmp = tmp->p;
    }
    if (min < n)
        return (ind_min + 1);
    return (0);
}

int     ft_el_pair(t_stack_a **a, int n)
{
    t_stack_a *tmp;

    tmp = *a;
    while (tmp->p)
    {
        if ((tmp->n > n && tmp->p->n < n) || (tmp->n < n && tmp->p->n > n))
            return (tmp->p->ind);
        tmp = tmp->p;
    }
    return (0);
}

int    ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

void    ft_num_of_move_need(t_stack_a **a, t_stack_a **b)
{
    t_stack_a *t1;
    t_stack_a *t2;
    t_stack_a *test;
    int ind_p;

    ft_ind_stack(b);
    ft_ind_stack(a);
    t1 = *b;
    int i = 0;
    while (t1)
    {
        t2 = *a;
        ind_p = ft_ind_pair(a, t1->n);
        t1->ind_pair = ind_p;
        // if (!i && t1->n == 27)
        //     printf("pair index %d and his index is %d\n", ft_ind_pair(a, t1->n), t1->ind);
        if (ind_p > ft_lstsize(*a) / 2)
            ind_p = ft_lstsize(*a) - ind_p;
        if (t1->ind_pair > ft_lstsize(*a) / 2 && t1->ind > ft_lstsize(*b) / 2)
            ind_p = ft_max(ind_p, ft_lstsize(*b) - t1->ind);
        else if (t1->ind_pair <= ft_lstsize(*a) / 2 && t1->ind <= ft_lstsize(*b) / 2)
            ind_p = ft_max(ind_p, t1->ind);
        else
            ind_p += t1->ind;
        test = *b;
        t1->need = ind_p + 1;
        t1 = t1->p;
        i++;
    }
}

int     ft_ind_pair_min_move(t_stack_a **b)
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
            ind = tmp->ind_pair;
        }
        tmp = tmp->p;
    }
    return (ind);
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

void    ft_move_stack_b_to_a(t_stack_a **a, t_stack_a **b, int if_rra, int num_move)
{
    t_stack_a *tmp;
    
    ft_ind_stack(a);

    tmp = *b;
    if (if_rra)
    {
        while (--num_move)
            rra(a, 1);
    }
    else
    {
        while (--num_move)
            ra(a, 1);
    }
    pa(a, b);
    ft_ind_stack(a);
}

void    ft_final_sort(t_stack_a **a)
{
    int ind_min;
    int l;

    ind_min = ind_of_min(a);
    ft_ind_stack(a);
    // printf("ind min %d\n", ind_min);
    if (ind_min >= ft_lstsize(*a) / 2)
    {
        l = ft_lstsize(*a) - ind_min + 1;
        while (l--)
            rra(a, 1);
    }
    else
    {
        l = ind_min;
        while (--l)
            ra(a, 1);
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
    el_a = ft_get_by_index(a, ft_ind_pair_min_move(b));
    t_a = *a;
    t_b = *b;
    // if (!i)
    // {
    //     printf("ind mm %d and ind pair %d ------ and el a is : %d and el b is : %d\n ----------", ind_min_move, ft_ind_pair_min_move(b), el_a, el_b);
    //     return ;
    // }
    while (t_a->n != el_a && t_b->n != el_b)
    {
        rrr(a, b);
        t_a = *a;
        t_b = *b;
    }
    while (t_a->n != el_a)
    {
        rra(a, 1);
        t_a = *a;
        t_b = *b;
    }
    while (t_b->n != el_b)
    {
        rrb(b, 1);
        t_a = *a;
        t_b = *b;
    }
    pa(a, b);
}

void    ft_move_with_rr(t_stack_a **a, t_stack_a **b, int ind_min_move)
{
    int el_b;
    int el_a;
    t_stack_a *t_a;
    t_stack_a *t_b;

    el_b = ft_get_by_index(b, ind_min_move);
    el_a = ft_get_by_index(a, ft_ind_pair_min_move(b));
    t_a = *a;
    t_b = *b;
    // printf("\n\n--------- el a is %d el b is %d ------------\n\n\n", el_a, el_b);
    while (t_a->n != el_a && t_b->n != el_b)
    {
        rr(a, b);
        t_a = *a;
        t_b = *b;
    }
    while (t_a->n != el_a)
    {
        ra(a, 1);
        t_a = *a;
        t_b = *b;
    }
    while (t_b->n != el_b)
    {
        rb(b, 1);
        t_a = *a;
        t_b = *b;
    }
    pa(a, b);
}

int if_rrr(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_pair)
{
    ft_ind_stack(a);
    ft_ind_stack(b);
    if (ind_min_move > ft_lstsize(*b) / 2 && ind_pair > ft_lstsize(*a) / 2)
        return (1);
    return (0);
}

int if_rr(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_pair)
{
    ft_ind_stack(a);
    ft_ind_stack(b);
    if (ind_min_move <= ft_lstsize(*b) / 2 && ind_pair <= ft_lstsize(*a) / 2)
        return (1);
    return (0);
}

int if_rra(t_stack_a **a, int ind)
{

    ft_ind_stack(a);
    if (ind > ft_lstsize(*a) / 2)
        return (1);
    return (0);
}

void    ft_move_to_a(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_p_min_move)
{
    int el_a;
    int el_b;
    int l;

    el_a = ft_get_by_index(a, ind_p_min_move);
    el_b = ft_get_by_index(b, ind_min_move);
    l = 0;
    if (ind_min_move > ft_lstsize(*b) / 2)
    {
        l = ft_lstsize(*b) - ind_min_move;
        while (l--)
            rrb(b, 1);
    }
    else
    {
        l = ind_min_move;
        while (l--)
            rb(b, 1);
    }
    if (ind_p_min_move > ft_lstsize(*a) / 2)
    {
        l = ft_lstsize(*a) - ind_p_min_move;
        while (l--)
            rra(a, 1);
    }
    else
    {
        l = ind_p_min_move;
        while (l--)
            ra(a, 1);
    }
    pa(a, b);
}

void    ft_sort1(t_stack_a **a, t_stack_a **b)
{
    int lis;
    t_stack_a *tmp;
    
    lis = ft_find_lis(a);
    ft_mark_lis(a, lis);
    ft_leave_lis_in_a(a, b, ft_lstsize(*a));
    ft_num_of_move_need(a, b);
    // printf("---------------------------------------A-----------------\n");
    // print(*a);
    // printf("---------------------------------------B-----------------\n");
    // print(*b);
    // printf("min move is : %d --- ind min move is : %d --- index pair is : %d\n", ft_min_move(b), ft_ind_min_move(b), ft_ind_pair_min_move(b));
    // if (if_rrr(a, b, ft_ind_min_move(b), ft_ind_pair_min_move(b)))
    //     ft_move_with_rrr(a, b, ft_ind_min_move(b));
    while (ft_lstsize(*b))
    {
        if (if_rrr(a, b, ft_ind_min_move(b), ft_ind_pair_min_move(b)))
            ft_move_with_rrr(a, b, ft_ind_min_move(b));
        else if (if_rr(a, b, ft_ind_min_move(b), ft_ind_pair_min_move(b)))
            ft_move_with_rr(a, b, ft_ind_min_move(b));
        else
            ft_move_to_a(a, b, ft_ind_min_move(b), ft_ind_pair_min_move(b));
        ft_ind_stack(a);
        // ft_move_stack_b_to_a(a, b, if_rra(a, ft_ind_pair(a, tmp->n)), tmp->need);
        ft_ind_stack(b);
        tmp = *b;
        // printf("---------------------------------------A-----------------\n");
        // print(*a);
        // printf("---------------------------------------B-----------------\n");
        // print(*b);
        ft_ind_stack(a);
        ft_ind_stack(b);
        ft_num_of_move_need(a, b);
        // if (!i)
        //     printf("min move is : %d --- ind min move is : %d --- index pair is : %d\n", ft_min_move(b), ft_ind_min_move(b), ft_ind_pair_min_move(b));
    }
    
    ft_final_sort(a);
    // ft_ind_stack(a);
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
    {
        ft_sort1(a, b);
    }
}
