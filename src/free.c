/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:37:07 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 14:57:11 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_free_struct(t_filler *st)
{
	int i;

	i = 0;
	free(st);
}

void		ft_free_cp(t_filler *st, char **cp)
{
	int i;

	i = 0;
	while (i < st->lp_delta_x)
		free(cp[i++]);
	free(cp);
	cp = NULL;
}

void		ft_free_piece_map(t_filler *st)
{
	int i;

	i = 0;
	while (i < st->map_x)
		free(st->piece_map[i++]);
	free(st->piece_map);
	st->piece_map = NULL;
}

void		ft_free_for_new_lap(t_filler *st)
{
	int i;
	int	y;
	int j;

	i = 0;
	y = 0;
	j = 0;
	while (i < st->map_x)
		free(st->map[i++]);
	while (y < st->piece_x)
		free(st->piece[y++]);
	while (j < st->lp_delta_x)
		free(st->little[j++]);
	free(st->map);
	free(st->piece);
	free(st->little);
	st->map = NULL;
	st->piece = NULL;
	st->little = NULL;
}
