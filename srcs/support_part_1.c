/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:03:09 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/27 13:16:47 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	f_error(t_list **tetr_list)
{
	ft_lstdel(tetr_list, dell_elem);
	ft_putstr("error\n");
	exit(ERROR);
}

/*
**	Возвращает количество элементов в списке.
*/

size_t	ft_lstsize(t_list *list)
{
	t_list	*cur_elem;
	size_t	size;

	size = 0;
	cur_elem = list;
	while (cur_elem != NULL)
	{
		cur_elem = cur_elem->next;
		size++;
	}
	return (size);
}

t_point	*new_point(int x, int y)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

/*
**	Функция для затирания фигуры в листе.
*/

void	dell_elem(void *content, size_t size)
{
	t_elem	*elem;

	elem = (t_elem *)content;
	size = 0;
	free(elem->point[0]);
	free(elem->point[1]);
	free(elem->point[2]);
	free(elem->point[3]);
	free(elem);
}

/*
**	Затирает массив строк.
*/

void	str_ar_del(char ***str_ar)
{
	int		i;
	char	**lines;

	i = 0;
	lines = *str_ar;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	str_ar = NULL;
}
