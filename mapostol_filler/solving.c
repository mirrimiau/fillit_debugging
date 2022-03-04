/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:53:32 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/03 13:53:34 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

static int	check_collisions(t_filler *f);

int	place_piece(t_filler *f)
{
	f->y = 0;
	while (f->y + f->p_rows <= f->b_rows)
	{
		f->x = 0;
		while (f->x  + f->p_cols <= f->b_cols)
		{
			if (check_collisions(f) == 0)
				return (0);
			f->x++;
		}
		f->y++;
	}
	return (-1);
}

static int	check_collisions(t_filler *f)
{
	int		i;
	int		j;
	int		single_collision;
	char	cell;
	
	single_collision = 0;
	i = 0;
	while (i < f->p_rows)
	{
		j = 0;
		while (j < f->p_cols && single_collision <= 1)
		{
			cell = ft_toupper(f->board[f->y + i][f->x + j]);
			if (f->piece[i][j] == '*' && cell == f->our_playa)
				single_collision++;
			else if (f->piece[i][j] == '*' && cell == f->other_playa)
				return (-1);
			j++;
		}
		i++;
	}
	if (single_collision == 1)
		return (0);
	return (-1);
}
