/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_part_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:37:48 by bsprigga          #+#    #+#             */
/*   Updated: 2018/12/27 15:20:42 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_blocks_size(t_list **lines_list)
{
	t_list	*tmp;
	int		block_height;

	tmp = *lines_list;
	block_height = 0;
	while (tmp)
	{
		if (++block_height <= 4)
		{
			ft_strlen(((char *)tmp->content)) != 4 ? f_error2(lines_list) : 1;
		}
		else if (block_height > 4)
		{
			block_height = 0;
			ft_strlen(((char *)tmp->content)) != 0 ? f_error2(lines_list) : 1;
		}
		tmp = tmp->next;
	}
}

void		check_num_figures(t_list **lines_list)
{
	int		i;
	int		j;
	int		cnt_resh;
	t_list	*tmp;

	tmp = *lines_list;
	i = -1;
	cnt_resh = 0;
	while (tmp)
	{
		if (++i < 4)
		{
			j = -1;
			while (((char *)(tmp->content))[++j])
				((char *)(tmp->content))[j] == '#' ? cnt_resh++ : 1;
		}
		else
		{
			i = -1;
			cnt_resh != 4 ? f_error2(lines_list) : 1;
			cnt_resh = 0;
		}
		tmp = tmp->next;
	}
}

void		insert_to_tetr_list(t_list **tetr_list, int count_dot, int x, int y)
{
	static t_elem	*tetr;
	static int		i;
	static int		j;
	static char		counter = 'A';

	if (count_dot == 0)
	{
		if (!(tetr = (t_elem *)malloc(sizeof(t_elem))))
			f_error(tetr_list);
		tetr->point[0] = new_point(0, 0);
		i = x;
		j = y;
	}
	else if (count_dot > 0 && count_dot < 4)
	{
		if (!(tetr->point[count_dot] = new_point(x - i, y - j)))
			f_error(tetr_list);
	}
	else if (count_dot == 4)
	{
		tetr->chr = counter;
		ft_lstadd(tetr_list, ft_lst_attach(tetr, sizeof(t_elem)));
		counter++;
	}
}

void		lines_to_tetr(t_list *lines_list, t_list **tetr_list)
{
	int		i;
	int		j;
	int		count_dots;

	count_dots = 0;
	i = 0;
	while (lines_list)
	{
		j = -1;
		while (((char *)(lines_list->content))[++j])
			if (((char*)(lines_list->content))[j] == '#')
			{
				insert_to_tetr_list(tetr_list, count_dots, j, i);
				count_dots++;
			}
		if (count_dots == 4)
		{
			insert_to_tetr_list(tetr_list, count_dots, j, i);
			count_dots = 0;
		}
		i == 4 ? i = 0 : i++;
		lines_list = lines_list->next;
	}
}
