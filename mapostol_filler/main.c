/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:53:54 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/03 13:53:56 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "filler.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
#include <stdio.h>
#include <fcntl.h>

static int	init_filler(t_filler *f);

int	main(void)
{
	t_filler	f;// try to allocate it in the heap??
	int			ret;
	char buf[100];
	int fd;
	int fp;
	  	fp = open ("file.txt", O_WRONLY);
	if (init_filler(&f) < 0)// find player and set all fields in 'f' to ZERO
		return (-1);
	while (1)
	{

		//sleep (1);
		ret = get_next_line(f.fd, &f.line);// Plateau line (Board size)
		write(fp, f.line, strlen(f.line));
		write(fp, "\n", 1);
		if (f.runs == 0)
		{
			if (ret <= 0 || get_size(f.line, &f.b_rows, &f.b_cols) < 0)
				return (-1);
			else
			{
			//	ft_printf("board size: %d %d\n", f.b_rows, f.b_cols);// delete me!!
				f.board = alloc_char_2darr(f.b_rows, f.b_cols);
				if (!f.board)
					return (-1);
			}
		}

		if (ret == 0)
			break;
		ft_strdel(&f.line);
		get_next_line(f.fd, &f.line);// Board Column Header line
		ft_strdel(&f.line);
		if (parse_board(&f, fp) < 0)
			break ;
		if (parse_piece(&f, fp) == 0)
		{
			ft_printf("%d %d\n", f.y, f.x);
		}
		else
		{
			ft_putstr("0 0\n");
			return (-1);
		}
		f.runs++;
	}
	close (fp);
	system ("leaks mapostol.filler");
	return (0);
}

static int	init_filler(t_filler *f)
{
	int	ret;
//	int fd = open ("testmap", O_RDONLY);
	ft_bzero(f, sizeof(*f));
	//f->fd = fd;
	ret = get_next_line(f->fd, &f->line);// player line
	if (ret <= 0 || parse_playas(f) < 0)
		return (-1);
	ft_strdel(&f->line);
	//ft_printf("our playa: %c other playa: %c\n", f->our_playa, f->other_playa);
	//printf("%d %d", f->x, f->y);
	return (0);
}
