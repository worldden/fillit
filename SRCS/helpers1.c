/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:40:15 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/01 18:31:10 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structures.h"

void	out_square(char **sq, char size)
{
	int		i;
	int		j;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			write(1, &(sq[i][j]), 1);
		write(1, "\n", 1);
	}
}

char	get_max_square_size(t_list *lst)
{
	char	lsize;
	char	sqsize;

	sqsize = 4;
	lsize = ft_lst_size(lst) * 4;
	while ((sqsize * sqsize) < lsize)
		sqsize++;
	return (sqsize + 2);
}

char	**create_square(char size)
{
	char	**sq;
	int		i;

	sq = (char **)malloc(size * sizeof(char *));
	i = -1;
	while (++i < size)
	{
		sq[i] = (char *)malloc(size * sizeof(char));
		ft_memset(sq[i], '.', size);
	}
	return (sq);
}

void	clear_figure(char **sq, t_x_and_y bias, t_x_and_y *xy)
{
	int		i;

	i = -1;
	while (++i < 4)
		sq[bias.x + xy[i].x][bias.y + xy[i].y] = '.';
}

void	paste_figure(char **sq, t_x_and_y bias, t_x_and_y *xy, char c)
{
	int		i;

	i = -1;
	while (++i < 4)
		sq[bias.x + xy[i].x][bias.y + xy[i].y] = c;
}
