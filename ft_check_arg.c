/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:37:42 by mkarim            #+#    #+#             */
/*   Updated: 2022/03/27 13:36:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_arg(char *s)
{
    int     i;
    
    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_check_dup(t_stack_a *arg)
{
    t_stack_a   *c;
    
    while (arg->p != NULL)
    {
        c = arg->p;
        while (c)
        {
            if (c->n == arg->n)
                return  (0);
            c = c->p;
        }
        arg = arg->p;
    }
    return (1);
}

int ft_check_sort(t_stack_a *arg)
{
    t_stack_a *c;
    int     s;
    int     i;

    i = 0;
    s = 0;
    while (arg->p != NULL)
    {
        c = arg->p;
        if (arg->n < c->n)
            s++;
        arg = arg->p;
        i++;
    }
    if (s == i)
        return (1);
    return (0);
}