/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:40:47 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/01 18:42:04 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structures.h"

char	check_border(char size, t_x_and_y bias, t_x_and_y *xy, char **sq)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if ((bias.x + xy[i].x + 1) > size)
			return (0);
		if ((bias.y + xy[i].y + 1) > size)
			return (0);
		if (sq[bias.x + xy[i].x][bias.y + xy[i].y] != '.')
			return (0);
	}
	return (1);
}

void	matcpy(char **d, char **s, char size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			d[i][j] = s[i][j];
	}
}

char	sq_size(char **sq, char size)
{
	t_x_and_y	xy;
	char		max;

	max = 0;
	xy.x = -1;
	while (++xy.x < size)
	{
		xy.y = size;
		while (--xy.y > 0)
			if (sq[xy.x][xy.y] != '.')
			{
				if ((xy.y + 1) > max)
					max = xy.y + 1;
				break ;
			}
		xy.y = size;
		while (--xy.y > 0)
			if (sq[xy.y][xy.x] != '.')
			{
				if ((xy.y + 1) > max)
					max = xy.y + 1;
				break ;
			}
	}
	return (max);
}

char	bound_check(char ret, t_list *new, t_list **start)
{
	if (ret < 4)
	{
		ft_freeall(start);
		return (0);
	}
	move_to_start(new->xy);
	ft_lstadd(start, new);
	return (1);
}
