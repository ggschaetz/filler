/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch_bord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:38:10 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/11 12:39:22 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_touch_bord(t_filler *st)
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
				if (j == 0)
					st->touch_bord_left = 1;
				else if (j == st->map_y - 1)
					st->touch_bord_right = 1;
			}
			j++;
		}
		i++;
	}
}
