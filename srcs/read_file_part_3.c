/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_filepart_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:37:48 by bsprigga          #+#    #+#             */
/*   Updated: 2018/12/27 15:22:23 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_coord(t_point *curr_p, int i, t_list *tmp)
{
	int		res;
	int		j;
	t_point	*changing_p;

	res = 0;
	j = -1;
	while (++j < 4)
	{
		changing_p = ((t_elem *)tmp->content)->point[j];
		if (i == j)
			continue;
		if ((curr_p->x + 1) == changing_p->x && curr_p->y == changing_p->y)
			res++;
		if ((curr_p->x - 1) == changing_p->x && curr_p->y == changing_p->y)
			res++;
		if ((curr_p->y + 1) == changing_p->y && curr_p->x == changing_p->x)
			res++;
		if ((curr_p->y - 1) == changing_p->y && curr_p->x == changing_p->x)
			res++;
	}
	return (res);
}

void		check_figures_validity(t_list **tetr_list)
{
	t_list	*tmp;
	int		i;
	int		sum_figure;
	t_point	*curr_p;

	tmp = *tetr_list;
	while (tmp)
	{
		i = -1;
		sum_figure = 0;
		while (++i < 4)
		{
			curr_p = ((t_elem *)tmp->content)->point[i];
			sum_figure += check_coord(curr_p, i, tmp);
		}
		tmp = tmp->next;
		if (sum_figure < 6)
			f_error(tetr_list);
	}
}
