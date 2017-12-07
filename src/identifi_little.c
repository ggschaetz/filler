/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifi_little.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:54:12 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:10:09 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_identifi_top_bot_little(t_filler *st)
{
	int i;
	int j;

	i = 0;
	while (i < st->piece_x)
	{
		j = 0;
		while (j < st->piece_y)
		{
			if (st->piece[i][j] == '*' && st->l_p_top == -1)
				st->l_p_top = i;
			if (st->piece[i][j] == '*')
				st->l_p_bot = i;
			j++;
		}
		i++;
	}
}

void		ft_identifi_left_right_little(t_filler *st)
{
	int	tab[4];

	tab[0] = 0;
	tab[2] = -1;
	tab[3] = st->piece_y + 1;
	while (tab[0] < st->piece_x)
	{
		tab[1] = 0;
		while (tab[1] < st->piece_y)
		{
			if (st->piece[tab[0]][tab[1]] == '*' && tab[1] > tab[2])
			{
				st->l_p_right = tab[1];
				tab[2] = tab[1];
			}
			if (st->piece[tab[0]][tab[1]] == '*' && tab[1] < tab[3])
			{
				st->l_p_left = tab[1];
				tab[3] = tab[1];
			}
			tab[1]++;
		}
		tab[0]++;
	}
}

void		ft_identifi_size_little_piece(t_filler *st)
{
	ft_identifi_top_bot_little(st);
	ft_identifi_left_right_little(st);
	st->lp_delta_x = st->l_p_bot - st->l_p_top + 1;
	st->lp_delta_y = st->l_p_right - st->l_p_left + 1;
}
