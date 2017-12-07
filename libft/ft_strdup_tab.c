/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:43:48 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/05 17:41:59 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(char **map, char **cp, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (!(cp = (char **)malloc(sizeof(char *) * (x))))
		return (NULL);
	while (i < x)
		cp[i++] = ft_strnew(y);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			cp[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (cp);
}
