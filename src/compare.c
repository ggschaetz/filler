/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:04:29 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:35:15 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_choice_orientation(t_filler *st)
{
	if (st->start_i > (st->map_x / 2) + 2)
		st->oriente = 1;
	else
		st->oriente = 0;
}

void		ft_oriente0(t_filler *st, int i, int j)
{
	st->xx = i - st->l_p_top;
	st->yy = j - st->l_p_left;
	st->nb_link_piece = st->nb_link_piece1;
}

void		ft_border(t_filler *st, int i, int j)
{
	if (st->oriente == 1 || st->oriente == 0)
	{
		if (st->touch_bord_left == 0)
		{
			if ((j - st->l_p_left) < st->yy && i - st->l_p_top >= st->xx - 2)
			{
				st->xx = i - st->l_p_top;
				st->yy = j - st->l_p_left;
			}
		}
		else
		{
			if ((j - st->l_p_left) > st->yy && i - st->l_p_top >= st->xx)
			{
				st->xx = i - st->l_p_top;
				st->yy = j - st->l_p_left;
			}
		}
	}
}

void		ft_compare_positionning(t_filler *st, int i, int j)
{
	st->nb_link_piece1 = 0;
	st->nb_link_piece1 = ft_count_nb_link(st, i, j);
	if (st->map_x > 24 || st->oriente == 0)
		st->nb_link_piece++;
	if (st->touch_bord_left == 1 && st->touch_bord_right == 1 && \
			st->nb_link_piece1 < st->nb_link_piece && st->oriente == 1)
		ft_oriente0(st, i, j);
	else if (st->oriente == 0 && st->touch_bord_left == 1 && \
			st->touch_bord_right == 1 && st->nb_link_piece1 < st->nb_link_piece)
		ft_oriente0(st, i, j);
	else if (st->touch_bord_left == 0 || st->touch_bord_right == 0)
		ft_border(st, i, j);
}
