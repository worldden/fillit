/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:09:48 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/01 18:42:57 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STRUCTURES_H
# define __STRUCTURES_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct		s_x_and_y
{
	int		x;
	int		y;
}					t_x_and_y;

typedef struct		s_list
{
	t_x_and_y		*xy;
	struct s_list	*next;
}					t_list;

typedef struct		s_csm
{
	char			**sq;
	char			size;
	char			**sqm;
	char			sz;
}					t_csm;

void				*ft_memset(void *s, int c, size_t n);
t_list				*ft_lstnew();
void				ft_lstadd(t_list **start, t_list *new);
void				ft_freeall(t_list **start);
char				ft_lst_size(t_list *lst);
void				assign_map(char tet[4][4], char *s);
char				valid(char tet[4][4]);
void				move_to_start(t_x_and_y *xy);
char				valitet(char tet[4][4], int x, int y, t_x_and_y **xy);
char				bound(char tet[4][4], t_list **start);
char				read_map(char *filename, t_list **lst);
void				out_square(char **sq, char size);
char				get_max_square_size(t_list *lst);
char				**create_square(char size);
void				clear_figure(char **sq, t_x_and_y bias, t_x_and_y *xy);
void				paste_figure(char **sq, t_x_and_y bias, t_x_and_y *xy,
		char c);
char				check_border(char size, t_x_and_y bias, t_x_and_y *xy,
		char **sq);
void				matcpy(char **d, char **s, char size);
char				sq_size(char **sq, char size);
void				blabla6(t_list *lst, t_csm *cs, char c);
void				find_square2(t_list *lst);
char				bound_check(char ret, t_list *new, t_list **start);

#endif
