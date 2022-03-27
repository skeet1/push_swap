/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:33:24 by mkarim            #+#    #+#             */
/*   Updated: 2022/03/27 11:41:59 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print(t_stack_a *arg)
{
    while (arg != NULL)
    {
        printf("%d\n", arg->n);
        arg = arg->p;
    }
}

t_stack_a *newNode(int n)
{
    t_stack_a *ret;

    ret = (t_stack_a *)malloc(sizeof(t_stack_a));
    ret->n = n;
    ret->p = NULL;

    return ret;
}

void addBack(t_stack_a **s, int n)
{
    t_stack_a *tmp;
    t_stack_a *new = newNode(n);
    
    tmp = *s;
    if (tmp)
    {
        while (tmp->p)
        {
            tmp = tmp->p;
        }
        tmp->p = new;
    }
    else
    {
        *s = new;
    }
}

int main(int argc, char **argv)
{
    int i;
    t_stack_a *arg = NULL;

    i = 1;
    if (argc == 1)
        return (0);
    else
    {
        while (i < argc)
        {
            if (ft_check_arg(argv[i]) == 0)
                return (ft_putstr("Error\n"), 0);
            addBack(&arg, ft_atoi(argv[i]));
            i++;
        }
    }
    if (ft_check_dup(arg) == 0)
        return (ft_putstr("Error\n"), 0);
    ft_putstr("args good\n");
    print(arg);
}