/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:17:44 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 14:19:52 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_piece(char *line, t_filler *st)
{
	ft_identifi_size_piece(line, st);
	ft_identifi_start_end_piece(st);
	if (st->flagp == 0)
	{
		ft_malloc_piece(st);
		st->flagp = 1;
	}
}
