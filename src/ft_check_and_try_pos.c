/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_try_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:39:39 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:36:56 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_check_and_try_pos(t_filler *st, int i, int j)
{
	if (ft_try_positioning(st, i, j) == 1)
	{
		if (ft_check_new_map(st, i, j) == 1)
		{
			if (st->pos_ok == 0)
			{
				ft_stock_positionning(st, i, j);
				ft_free_piece_map(st);
			}
			else
			{
				ft_compare_positionning(st, i, j);
				ft_free_piece_map(st);
			}
		}
	}
}
