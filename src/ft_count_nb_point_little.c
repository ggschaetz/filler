/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb_point_little.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:31:19 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:02:44 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			ft_count_nb_point_little(t_filler *st)
{
	int i;
	int j;
	int	point;

	i = 0;
	point = 0;
	while (i < st->lp_delta_x)
	{
		j = 0;
		while (j < st->lp_delta_y)
		{
			if (st->little[i][j] == '.')
				point++;
			j++;
		}
		i++;
	}
	return (point);
}
