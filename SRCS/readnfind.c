/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnfind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:39:14 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/03 15:46:40 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structures.h"

char	read_map(char *filename, t_list **lst)
{
	int		fd;
	char	n;
	char	buf[20];
	char	tet[4][4];

	n = 1;
	fd = open(filename, O_RDONLY);
	while (n > 0)
	{
		if (read(fd, buf, 20) != 20)
			return (0);
		if ((buf[4] != '\n') || (buf[9] != '\n') ||
				(buf[14] != '\n') || (buf[19] != '\n'))
			return (0);
		assign_map(tet, buf);
		*buf = valid(tet);
		if (*buf != 4)
			return (0);
		*buf = bound(tet, lst);
		if (*buf < 4)
			return (0);
		n = read(fd, buf, 1);
	}
	return (1);
}

void	blabla6(t_list *lst, t_csm *cs, char c)
{
	t_x_and_y	b;

	b.y = -1;
	while (++b.y < cs->size)
	{
		b.x = -1;
		while (++b.x < cs->size)
		{
			if (check_border(cs->size - 1, b, lst->xy, cs->sq) == 0)
				continue ;
			paste_figure(cs->sq, b, lst->xy, c);
			if (lst->next == 0)
			{
				cs->sz = sq_size(cs->sq, cs->size);
				if (cs->sz < cs->size)
				{
					matcpy(cs->sqm, cs->sq, cs->sz);
					cs->size = cs->sz;
				}
			}
			else
				blabla6(lst->next, cs, c + 1);
			clear_figure(cs->sq, b, lst->xy);
		}
	}
}

void	find_square2(t_list *lst)
{
	t_csm		cs;

	cs.size = get_max_square_size(lst);
	cs.sq = create_square(cs.size);
	cs.sqm = create_square(cs.size);
	blabla6(lst, &cs, 'A');
	out_square(cs.sqm, cs.size);
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	lst = 0;
	if (argc != 2)
	{
		write(1, "usage: fillit input_name\n", 25);
		return (0);
	}
	if (read_map(argv[1], &lst) == 0)
		write(1, "error\n", 6);
	else
		find_square2(lst);
	return (0);
}
