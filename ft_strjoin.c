/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:57:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/24 11:43:53 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	while (s1[++i])
		s[i] = s1[i];
	s[i] = ' ';
	while (s2[++j])
		s[i + j + 1] = s2[j];
	s[i + j + 1] = '\0';
	free(s1);
	return (s);
}
