/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:31:07 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:35:42 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_target(t_filler *st)
{
	if (st->player == 1)
	{
		st->me = ft_strdup("Oo\0");
		st->him = ft_strdup("Xx\0");
	}
	else
	{
		st->me = ft_strdup("Xx\0");
		st->him = ft_strdup("Oo\0");
	}
}

int		ft_try_positioning(t_filler *st, int i, int j)
{
	int	tab[5];
	int max_y;

	tab[0] = j;
	tab[1] = 0;
	tab[3] = i + st->lp_delta_x;
	max_y = j + st->lp_delta_y;
	tab[2] = 0;
	while (i < tab[3])
	{
		j = tab[0];
		while (j < max_y)
		{
			if (ft_strchr(st->me, st->map[i][j]) != NULL)
				tab[2]++;
			if (ft_strchr(".", st->map[i][j]) != NULL)
				tab[1]++;
			j++;
		}
		i++;
	}
	if (tab[2] == 0 || tab[1] < ft_count_wildcard(st) - 1)
		return (0);
	return (1);
}

int		ft_check_new_map(t_filler *st, int i, int j)
{
	int		nb_him0;
	int		nb_him1;
	int		nb_wald0;
	int		nb_wald1;
	char	**cp;

	cp = NULL;
	cp = ft_strdup_tab(st->little, cp, st->lp_delta_x, st->lp_delta_y);
	nb_him0 = ft_count_him(st, i, j);
	nb_wald0 = ft_count_wildcard(st);
	cp = ft_superpose_map(st, cp, i, j);
	nb_wald1 = ft_count_wildcard_cp(st, cp);
	nb_him1 = ft_count_him_cp(st, cp);
	ft_free_cp(st, cp);
	if (nb_him0 == nb_him1 && nb_wald0 - 1 == nb_wald1)
		return (1);
	return (0);
}

void	ft_stock_positionning(t_filler *st, int i, int j)
{
	st->nb_link_piece = 0;
	st->nb_link_piece = ft_count_nb_link(st, i, j);
	st->xx = i - st->l_p_top;
	st->yy = j - st->l_p_left;
	st->pos_ok = 1;
}

void	ft_positioning(t_filler *st)
{
	int i;
	int j;

	i = 0;
	ft_target(st);
	ft_identifi_start_position(st);
	ft_choice_orientation(st);
	ft_touch_bord(st);
	while (i <= st->map_x - st->lp_delta_x)
	{
		j = 0;
		while (j <= st->map_y - st->lp_delta_y)
		{
			ft_check_and_try_pos(st, i, j);
			j++;
		}
		i++;
	}
	free(st->me);
	free(st->him);
}
