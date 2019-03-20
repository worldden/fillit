/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:37:17 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/01 18:42:30 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structures.h"

void	assign_map(char tet[4][4], char *s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tet[i][j] = *s;
			s++;
		}
		s++;
	}
}

char	valid(char tet[4][4])
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i][j] != '.' && tet[i][j] != '#')
				return (0);
			if (tet[i][j] == '#')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

void	move_to_start(t_x_and_y *xy)
{
	int		k;
	char	min;

	k = 0;
	min = xy[0].x;
	while (++k < 4)
		if (xy[k].x < min)
			min = xy[k].x;
	k = -1;
	while (++k < 4)
		xy[k].x = xy[k].x - min;
	k = 0;
	min = xy[0].y;
	while (++k < 4)
		if (xy[k].y < min)
			min = xy[k].y;
	k = -1;
	while (++k < 4)
		xy[k].y = xy[k].y - min;
}

char	valitet(char tet[4][4], int x, int y, t_x_and_y **xy)
{
	char	k;

	if ((x >= 0 && x < 4) && (y >= 0 && y < 4))
		if (tet[x][y] == '#')
		{
			tet[x][y] = '.';
			k = valitet(tet, x + 1, y, xy) + 1;
			if (k < 4)
				k += valitet(tet, x - 1, y, xy) + valitet(tet, x, y + 1, xy);
			tet[x][y] = '#';
			(**xy).x = y;
			(**xy).y = x;
			(*xy)++;
			return (k);
		}
	return (0);
}

char	bound(char tet[4][4], t_list **start)
{
	char		ret;
	int			x;
	int			y;
	t_list		*new;
	t_x_and_y	*tmp;

	new = ft_lstnew();
	if (new == 0)
		return (0);
	tmp = new->xy;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (tet[x][y] == '#')
			{
				ret = valitet(tet, x, y, &(new->xy));
				new->xy = tmp;
				if (bound_check(ret, new, start) == 0)
					return (0);
				return (ret);
			}
	}
	return (0);
}
