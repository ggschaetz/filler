/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superpose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:28:11 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:25:13 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_superpose_map_and_piece(t_filler *st, int i, int j)
{
	int		x;
	int		y;
	int		k;
	int		l;

	x = 0;
	k = 0;
	st->piece_map = ft_strdup_tab(st->map, st->piece_map, st->map_x, st->map_y);
	while (x < st->map_x)
	{
		y = 0;
		l = 0;
		while (y < st->map_y)
		{
			if (x >= i && y >= j && x < i + st->lp_delta_x && \
					y < j + st->lp_delta_y && \
					ft_strchr(st->me, st->map[x][y]) == NULL)
				st->piece_map[x][y] = st->little[k][l++];
			y++;
		}
		if (l != 0)
			k++;
		x++;
	}
}

char		**ft_superpose_map(t_filler *st, char **cp, int i, int j)
{
	int		tab[3];
	int		max_x;
	int		max_y;

	tab[0] = 0;
	tab[2] = j;
	max_x = i + st->lp_delta_x;
	max_y = j + st->lp_delta_y;
	while (i < max_x)
	{
		j = tab[2];
		tab[1] = 0;
		while (j < max_y)
		{
			if (st->map[i][j] != '.' && \
					ft_strchr(st->him, st->map[i][j]) == NULL)
				cp[tab[0]][tab[1]] = st->map[i][j];
			j++;
			tab[1]++;
		}
		i++;
		tab[0]++;
	}
	return (cp);
}
