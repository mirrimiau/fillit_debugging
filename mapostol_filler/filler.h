/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:53:09 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/03 13:53:16 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE		32
# define PLAYA_NUM_LN	"$$$ exec p"
# define BOARD_SIZE_LN	"Plateau"
# define PIECE_SIZE_LN	"Piece"
# define FIRST_BOARD_LN	"000"
# define PLAYA1			'O'
# define PLAYA2			'X'

#include <stdio.h> // <=======Don't forget to delete this!!!

/*
**	Type definitions
*/
typedef struct s_filler
{
	char	**board;
	char	**piece;
	char	*line;
	char	our_playa;
	char	other_playa;
	int		b_rows;
	int		b_cols;
	int		p_rows;
	int		p_cols;
	int		fd;
	int		x;
	int		y;
	int		runs;// testing
}	t_filler;

/*
**	Prototypes
*/
int		parse_playas(t_filler *f);
int		get_size(char *line, int *rows, int *cols);
int		parse_board(t_filler *f, int fp);
int		parse_piece(t_filler *f);
int		place_piece(t_filler *f);
char	**alloc_char_2darr(int rows, int cols);
void	free_char_2darr(char **arr);

void	print_char2darr(char **str);

#endif
