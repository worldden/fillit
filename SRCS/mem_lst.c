/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:36:20 by dbolilyi          #+#    #+#             */
/*   Updated: 2018/05/01 18:33:19 by dbolilyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structures.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

t_list	*ft_lstnew(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->xy = (t_x_and_y *)malloc(4 * sizeof(t_x_and_y));
	new->next = 0;
	return (new);
}

void	ft_lstadd(t_list **start, t_list *new)
{
	t_list	*tmp;

	if (*start == 0)
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_freeall(t_list **start)
{
	t_list	*tmp;

	while (*start != 0)
	{
		tmp = (*start)->next;
		free((*start)->xy);
		free(*start);
		*start = tmp;
	}
}

char	ft_lst_size(t_list *lst)
{
	char	i;

	if (lst == 0)
		return (0);
	i = 1;
	while (lst->next != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
