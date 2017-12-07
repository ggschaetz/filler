/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_for_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:12:48 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/02 17:29:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_stock_row_map(char *line, t_filler *st)
{
	int i;
	int j;

	i = 0;
	j = 4;
	while (j <= st->map_y + 4)
		st->map[st->id_l_map][i++] = line[j++];
	st->id_l_map++;
}
