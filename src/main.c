/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:32:33 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/13 16:54:26 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	ft_handler_parce(t_filler *st, char *line)
{
	if (ft_strncmp(line, "$$$ exec", 8) == 0)
		ft_identifi_player(st, line);
	else if (ft_strncmp(line, "Plateau ", 8) == 0)
		ft_map(line, st);
	else if (st->id_line >= st->startm && st->id_line <= st->endm && \
			st->id_line > 0)
		ft_stock_row_map(line, st);
	else if (ft_strncmp(line, "Piece ", 6) == 0)
		ft_piece(line, st);
	else if (st->id_line >= st->startp && st->id_line <= st->endp && \
			st->id_line > 2)
		ft_stock_row_piece(line, st);
	if (st->player == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	if (st->id_line == st->endp)
		st->flag = 1;
	st->id_line++;
}

void	ft_init_var(t_filler *st)
{
	st->flagm = 0;
	st->flagp = 0;
	st->id_line = 0;
	st->id_l_map = 0;
	st->id_l_piece = 0;
	st->l_p_top = -1;
	st->l_p_bot = 0;
	st->l_p_right = 0;
	st->l_p_left = 0;
	st->flag = 0;
	st->map_x = 0;
	st->map_y = 0;
	st->piece_x = 0;
	st->piece_y = 0;
	st->startm = 0;
	st->endm = 0;
	st->startp = 0;
	st->endp = -1;
	st->lp_delta_x = 0;
	st->lp_delta_y = 0;
	st->pos_ok = 0;
	st->touch_bord_left = 0;
	st->touch_bord_right = 0;
	st->oriente = 0;
}

int		ft_handler_ia(t_filler *st)
{
	char *x;
	char *y;

	ft_stock_little_piece(st);
	ft_positioning(st);
	x = ft_itoa(st->xx);
	y = ft_itoa(st->yy);
	ft_putstr(x);
	ft_putstr(" ");
	ft_putstr(y);
	ft_putstr("\n");
	free(x);
	free(y);
	ft_free_for_new_lap(st);
	st->tour = 1;
	return (0);
}

int		main(void)
{
	t_filler	*st;
	char		*line;
	int			i;

	st = NULL;
	st = ft_malloc_struct(st);
	st->tour = 0;
	st->player = 0;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (i == 0)
		{
			ft_init_var(st);
			i += 1;
		}
		ft_handler_parce(st, line);
		if (st->flag == 1)
			i = ft_handler_ia(st);
		free(line);
	}
	ft_free_struct(st);
	return (0);
}
