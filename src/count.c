/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:44:03 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 14:57:02 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int			ft_count_him(t_filler *st, int i, int j)
{
	int		nb_him;
	int		x;
	int		y;
	int		save;

	x = i + st->lp_delta_x;
	y = j + st->lp_delta_y;
	save = j;
	nb_him = 0;
	while (i < x)
	{
		j = save;
		while (j < y)
		{
			if (ft_strchr(st->him, st->map[i][j]) != NULL)
				nb_him++;
			j++;
		}
		i++;
	}
	return (nb_him);
}

int			ft_count_wildcard(t_filler *st)
{
	int		nb_card;
	int		x;
	int		y;

	x = 0;
	nb_card = 0;
	while (x < st->lp_delta_x)
	{
		y = 0;
		while (y < st->lp_delta_y)
		{
			if (st->little[x][y] == '*')
				nb_card++;
			y++;
		}
		x++;
	}
	return (nb_card);
}

int			ft_count_wildcard_cp(t_filler *st, char **cp)
{
	int		nb_card;
	int		x;
	int		y;

	x = 0;
	nb_card = 0;
	while (x < st->lp_delta_x)
	{
		y = 0;
		while (y < st->lp_delta_y)
		{
			if (cp[x][y] == '*')
				nb_card++;
			y++;
		}
		x++;
	}
	return (nb_card);
}

int			ft_count_him_cp(t_filler *st, char **cp)
{
	int		nb_him;
	int		x;
	int		y;

	x = 0;
	nb_him = 0;
	while (x < st->lp_delta_x)
	{
		y = 0;
		while (y < st->lp_delta_y)
		{
			if (ft_strchr(st->him, cp[x][y]) != NULL)
				nb_him++;
			y++;
		}
		x++;
	}
	return (nb_him);
}

int			ft_count_nb_link(t_filler *st, int i, int j)
{
	int k;
	int l;
	int	nb;

	ft_superpose_map_and_piece(st, i, j);
	l = i;
	k = j;
	nb = 0;
	while (i < l + st->lp_delta_x)
	{
		j = k;
		while (j < k + st->lp_delta_y)
		{
			if (ft_strchr("*", st->piece_map[i][j]) != NULL)
				nb = nb + ft_count_nb_link1(st, i, j);
			j++;
		}
		i++;
	}
	return (nb);
}
