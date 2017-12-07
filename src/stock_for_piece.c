/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_for_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:30:12 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:16:19 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_stock_row_piece(char *line, t_filler *st)
{
	int i;

	i = 0;
	while (i < st->piece_y)
	{
		st->piece[st->id_l_piece][i] = line[i];
		i++;
	}
	st->id_l_piece++;
}

void		ft_stock_little_piece(t_filler *st)
{
	int i;
	int j;

	i = 0;
	ft_identifi_size_little_piece(st);
	ft_malloc_little_piece(st);
	while (i < st->lp_delta_x)
	{
		j = 0;
		while (j < st->lp_delta_y)
		{
			st->little[i][j] = st->piece[st->l_p_top + i][st->l_p_left + j];
			j++;
		}
		i++;
	}
	i = 0;
}
