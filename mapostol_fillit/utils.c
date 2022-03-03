/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:53:43 by mapostol          #+#    #+#             */
/*   Updated: 2022/03/03 13:53:44 by mapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

char	**alloc_char_2darr(int rows, int cols)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * rows + 1);
	if (!arr)
		return (0);
	i = 0;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols);// null-ended strings
		if (!arr[i])
		{
			free_char_2darr(arr);
			return (0);
		}
		i++;
		arr[i] = 0;
	}
	return (arr);
}

void	free_char_2darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(arr + i);
		i++;
	}
}
