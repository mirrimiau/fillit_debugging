/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:53:23 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/03 13:53:25 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

int	parse_playas(t_filler *f)
{
	char	*playa_num;

	if (!ft_strstr(f->line, PLAYA_NUM_LN))
		return (-1);
	playa_num = ft_strchr(f->line, 'p') + 1;
	if (ft_strncmp(playa_num, "1", 1) == 0)
	{
		f->our_playa = PLAYA1;// O
		f->other_playa = PLAYA2;// X
	}
	else
	{
		f->our_playa = PLAYA2;// X
		f->other_playa = PLAYA1;// O
	}
	return (0);
}

int	parse_board(t_filler *f)
{
	int		i;
	int		j;
	char	*ln;

	i = 0;
	while (i < f->b_rows)
	{
		get_next_line(f->fd, &f->line);
		ln = ft_strchr(f->line, ' ') + 1;
		j = 0;
		while (j < f->b_cols)
		{
			f->board[i][j] = ln[j];
			j++;
		}
		f->board[i][j] = 0;
		ft_strdel(&f->line);
		i++;
	}
	//print_char2darr(f->board);// <========== delete me!!!!
	return (0);
}

int	parse_piece(t_filler *f)
{
	int	ret;
	int	i;
	int	j;

	ret = get_next_line(f->fd, &f->line);
	if (!ft_strstr(f->line, PIECE_SIZE_LN) || ret <= 0)
		return (-1);
	get_size(f->line, &f->p_rows, &f->p_cols);
	ft_strdel(&f->line);
	f->piece = alloc_char_2darr(f->p_rows, f->p_cols);
	if (!f->piece)
		return (-1);
	//ft_printf("piece size: %d %d\n", f->p_rows, f->p_cols);// delete me!!
	i = 0;
	while (i < f->p_rows)
	{
		get_next_line(f->fd, &f->line);
		j = 0;
		while (j < f->p_cols)
		{
			f->piece[i][j] = f->line[j];
			j++;
		}
		f->piece[i][j] = 0;
		ft_strdel(&f->line);
		i++;
	}
//	print_char2darr(f->piece);// <========== delete me!!!!
	if (place_piece(f) == 0)
		ret = 0;
	else
		ret = -1;
	free_char_2darr(f->piece);
	free(f->piece);
	return (ret);
}

int	get_size(char *ln, int *rows, int *cols)
{
	char	*tmp;

	if (!ft_strstr(ln, BOARD_SIZE_LN) && !ft_strstr(ln, PIECE_SIZE_LN))
		return (-1);
	tmp = ln;
	tmp = ft_strchr(tmp, ' ') + 1;
	*rows = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	*cols = ft_atoi(tmp);
	return (0);
}
