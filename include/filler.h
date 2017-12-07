/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:10:06 by gschaetz          #+#    #+#             */
/*   Updated: 2017/05/12 15:35:03 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct		s_filler
{
	int				fd;

	int				pos_ok;
	int				oriente;
	int				touch_bord_left;
	int				touch_bord_right;
	int				start_i;
	int				start_j;
	char			*me;
	char			*him;
	int				tour;
	int				id_line;
	int				flag;
	int				player;
	char			**map;
	int				flagm;
	int				id_l_map;
	int				map_x;
	int				map_y;
	int				startm;
	int				endm;
	char			**piece;
	int				flagp;
	int				id_l_piece;
	int				piece_x;
	int				piece_y;
	int				startp;
	int				endp;
	int				l_p_top;
	int				l_p_bot;
	int				l_p_right;
	int				l_p_left;
	char			**little;
	int				lp_delta_x;
	int				lp_delta_y;
	int				xx;
	int				yy;
	int				nb_link_piece;
	int				nb_link_piece1;
	char			**piece_map;
}					t_filler;

t_filler			*ft_malloc_struct(t_filler *st);
void				ft_malloc_map(t_filler *st);
void				ft_malloc_piece(t_filler *st);
void				ft_malloc_little_piece(t_filler *st);
void				ft_free_for_new_lap(t_filler *st);
void				ft_free_piece_map(t_filler *st);
void				ft_map(char *line, t_filler *st);
void				ft_piece(char *line, t_filler *st);
void				ft_identifi_player(t_filler *st, char *line);
void				ft_identifi_size_map(char *line, t_filler *st);
void				ft_identifi_start_end_map(t_filler *st);
void				ft_identifi_size_piece(char *line, t_filler *st);
void				ft_identifi_size_little_piece(t_filler *st);
void				ft_identifi_start_end_piece(t_filler *st);
void				ft_identifi_start_position(t_filler *st);
void				ft_stock_row_map(char *line, t_filler *st);
void				ft_stock_row_piece(char *line, t_filler *st);
void				ft_stock_little_piece(t_filler *st);
void				ft_positioning(t_filler *st);
void				ft_stock_positionning(t_filler *st, int i, int j);
int					ft_try_positioning(t_filler *st, int i, int j);
int					ft_check_new_map(t_filler *st, int i, int j);
void				ft_check_and_try_pos(t_filler *st, int i, int j);
void				ft_choice_orientation(t_filler *st);
void				ft_touch_bord(t_filler *st);
int					ft_count_wildcard(t_filler *st);
int					ft_count_wildcard_cp(t_filler *st, char **cp);
int					ft_count_him_cp(t_filler *st, char **cp);
int					ft_count_him(t_filler *st, int i, int j);
int					ft_count_nb_link(t_filler *st, int i, int j);
int					ft_count_nb_link1(t_filler *st, int i, int j);
int					ft_count_nb_point_little(t_filler *st);
char				**ft_superpose_map(t_filler *st, char **cp, int i, int j);
void				ft_free_cp(t_filler *st, char **cp);
void				ft_superpose_map_and_piece(t_filler *st, int i, int j);
void				ft_compare_positionning(t_filler *st, int i, int j);
void				ft_free_struct(t_filler *st);

#endif
