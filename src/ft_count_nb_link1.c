/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb_link1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:41:58 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:02:38 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			ft_count_nb_link1(t_filler *st, int i, int j)
{
	int		nb;
	int		tab[4];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	nb = 0;
	if (i == 0)
		tab[0] = 1;
	if (i == st->map_x - 1)
		tab[2] = 1;
	if (j == 0)
		tab[1] = 1;
	if (j == st->map_y - 1)
		tab[3] = 1;
	if (tab[0] == 0 && ft_strchr(st->me, st->piece_map[i - 1][j]) != NULL)
		nb++;
	if (tab[1] == 0 && ft_strchr(st->me, st->piece_map[i][j - 1]) != NULL)
		nb++;
	if (tab[2] == 0 && ft_strchr(st->me, st->piece_map[i + 1][j]) != NULL)
		nb++;
	if (tab[3] == 0 && ft_strchr(st->me, st->piece_map[i][j + 1]) != NULL)
		nb++;
	return (nb);
}
