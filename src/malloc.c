/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:35:22 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:26:08 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

t_filler	*ft_malloc_struct(t_filler *st)
{
	if (!(st = (t_filler *)malloc(sizeof(t_filler))))
		return (NULL);
	return (st);
}

void		ft_malloc_map(t_filler *st)
{
	int i;

	i = 0;
	if (!(st->map = (char **)malloc(sizeof(char *) * (st->map_x + 1))))
		return ;
	while (i < st->map_x)
		st->map[i++] = ft_strnew(st->map_y);
	st->map[i] = NULL;
}

void		ft_malloc_piece(t_filler *st)
{
	int i;

	i = 0;
	if (!(st->piece = (char **)malloc(sizeof(char *) * (st->piece_x + 1))))
		return ;
	while (i < st->piece_x)
		st->piece[i++] = ft_strnew(st->piece_y);
	st->piece[i] = NULL;
}

void		ft_malloc_little_piece(t_filler *st)
{
	int i;

	i = 0;
	if (!(st->little = (char **)malloc(sizeof(char *) * (st->lp_delta_x + 1))))
		return ;
	while (i < st->lp_delta_x)
		st->little[i++] = ft_strnew(st->lp_delta_y);
	st->little[i] = NULL;
}
