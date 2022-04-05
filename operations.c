/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:33:14 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/05 15:03:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack_a **s, int p)
{
    int size;
    t_stack_a *tmp;
    int fn;
    int sn;

    size = 0;
    tmp = *s;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    if (size > 1)
    {
        tmp = *s;
        fn = tmp->n;
        sn = tmp->p->n;
        tmp->n = sn;
        tmp->p->n = fn;
    }
    if (p)
        ft_putstr("sa\n");
}

void    sb(t_stack_a **s, int p)
{
    int size;
    t_stack_a *tmp;
    int fn;
    int sn;

    size = 0;
    tmp = *s;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    if (size > 1)
    {
        tmp = *s;
        fn = tmp->n;
        sn = tmp->p->n;
        tmp->n = sn;
        tmp->p->n = fn;
    }
    if (p)
        ft_putstr("sb\n");
}

void    ss(t_stack_a **a, t_stack_a **b)
{
    sa(a, 0);
    sb(b, 0);
}

void    ra(t_stack_a **s, int p)
{
    int size;
    t_stack_a *tmp;
    int fn;

    size = 0;
    tmp = *s;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    if (size > 1)
    {
        tmp = *s;
        fn = tmp->n;
        *s = tmp->p;
        addBack(s, fn);
    }
    if (p)
        ft_putstr("ra\n");
}

void    rb(t_stack_a **s, int p)
{
    int size;
    t_stack_a *tmp;
    int fn;

    size = 0;
    tmp = *s;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    if (size > 1)
    {
        tmp = *s;
        fn = tmp->n;
        *s = tmp->p;
        addBack(s, fn);
    }
    if (p)
        ft_putstr("rb\n");
}

void rr(t_stack_a **a, t_stack_a **b)
{
    ra(a, 0);
    rb(b, 0);
    ft_putstr("rr\n");
}

void    pa(t_stack_a **a, t_stack_a **b)
{
    int     sb;
    t_stack_a *tb;

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
        addFront(a, tb->n);
        *b = tb->p;
    }
}

void    pb(t_stack_a **a, t_stack_a **b)
{
    int     sa;
    t_stack_a *ta;

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
        addFront(b, ta->n);
        *a = ta->p;
    }
}

void    rra(t_stack_a **a, int p)
{
    t_stack_a *tmp;
    
    tmp = *a;
    while (tmp->p->p)
    {
        tmp = tmp->p;
    }
    addFront(a, tmp->p->n);
    tmp->p = NULL;
    if (p)
        ft_putstr("rra\n");
}

void    rrb(t_stack_a **b, int p)
{
    t_stack_a *tmp;
    
    tmp = *b;
    while (tmp->p->p)
    {
        tmp = tmp->p;
    }
    addFront(b, tmp->p->n);
    tmp->p = NULL;
    if (p)
        ft_putstr("rrb\n");
}

void    rrr(t_stack_a **a, t_stack_a **b)
{
    rra(a, 0);
    rrb(b, 0);
    ft_putstr("rrr\n");
}