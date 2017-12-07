/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:14:52 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 14:17:18 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_map(char *line, t_filler *st)
{
	ft_identifi_size_map(line, st);
	ft_identifi_start_end_map(st);
	if (st->flagm == 0)
	{
		ft_malloc_map(st);
		st->flagm = 1;
	}
}
