/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:25:27 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/06 13:50:03 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int    main(int argc, char **argv)
{
    int i;
    t_stack_a *a;
    t_stack_a *b;
    static char **args;

    i = 2;
    if (argc == 1)
        return (0);
    else
    {
        while (i < argc)
            argv[1] = ft_strjoin(argv[1], argv[i++]);
        args = ft_split(argv[1], ' ');
        i = 0;
        while (args[i])
        {
            if (ft_check_arg(args[i]) == 0)
                return (ft_putstr("Error\n"), 0);
            addBack(&a, ft_atoi(args[i++]));
        }
    }
    while (1)
    {
        if (!ft_strcmp(get_next_line(0), "sa"))
            sa(&a, 0);
        else if (!ft_strcmp(get_next_line(0), "sb"))
            sb(&b, 0);
        else if (!ft_strcmp(get_next_line(0), "ss"))
            ss(&a, &b);
        else if (!ft_strcmp(get_next_line(0), "pa"))
            pa(&a, &b);
        else if (!ft_strcmp(get_next_line(0), "pb"))
            pb(&a, &b);
        else if (!ft_strcmp(get_next_line(0), "ra"))
            ra(&a, 0);
        else if (!ft_strcmp(get_next_line(0), "rb"))
            rb(&a, 0);
        else if (!ft_strcmp(get_next_line(0), "rr"))
            rr(&a, &b);
        else if (!ft_strcmp(get_next_line(0), "rra"))
            rra(&a, 0);
        else if (!ft_strcmp(get_next_line(0), "rrb"))
            rrb(&b, 0);
        else if (!ft_strcmp(get_next_line(0), "rrr"))
            rrr(&a, &b);
        if (ft_check_sort(a))
            ft_putstr("OK\n");
        else
            ft_putstr("KO\n");
    }
}