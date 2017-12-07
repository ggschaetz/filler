/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_start_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:16:36 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/11 10:35:31 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_identifi_start_position(t_filler *st)
{
	int i;
	int j;

	i = 0;
	while (i < st->map_x)
	{
		j = 0;
		while (j < st->map_y)
		{
			if (ft_strchr(st->me, st->map[i][j]) != NULL)
			{
				st->start_i = i;
				st->start_j = j;
			}
			j++;
		}
		i++;
	}
}
