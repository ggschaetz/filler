/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identifi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:02:52 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 14:48:40 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void		ft_identifi_player(t_filler *st, char *line)
{
	if (ft_strchr(line, '1') != NULL)
		st->player = 1;
	else
		st->player = 2;
}

void		ft_identifi_size_map(char *line, t_filler *st)
{
	int		i;
	int		j;
	char	*cp;

	cp = ft_strnew(10);
	j = 0;
	i = 8;
	while (ft_isdigit(line[i]) == 0)
		i++;
	while (line[i] != ' ')
		cp[j++] = line[i++];
	cp[j] = '\0';
	st->map_x = ft_atoi(cp);
	i++;
	j = 0;
	while (line[i] != ':')
		cp[j++] = line[i++];
	cp[j] = '\0';
	st->map_y = ft_atoi(cp);
	free(cp);
}

void		ft_identifi_start_end_map(t_filler *st)
{
	st->startm = 3 - st->tour;
	st->endm = st->startm + st->map_x - 1;
}

void		ft_identifi_size_piece(char *line, t_filler *st)
{
	int		i;
	int		j;
	char	*cp;

	i = 5;
	j = 0;
	cp = ft_strnew(10);
	while (ft_isdigit(line[i]) == 0)
		i++;
	while (line[i] != ' ')
		cp[j++] = line[i++];
	cp[j] = '\0';
	st->piece_x = ft_atoi(cp);
	i++;
	j = 0;
	while (line[i] != ':')
		cp[j++] = line[i++];
	cp[j] = '\0';
	st->piece_y = ft_atoi(cp);
	free(cp);
}

void		ft_identifi_start_end_piece(t_filler *st)
{
	st->startp = st->endm + 2;
	st->endp = st->startp + st->piece_x - 1;
}
