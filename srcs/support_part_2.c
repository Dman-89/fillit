/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:03:09 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/28 11:10:49 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Определяет размер минимальной карты исходя из
**	количества фигур и их площади.
*/

int		get_min_size_map(t_list *tetr_list)
{
	int		tetrs_count;
	int		size;

	size = 2;
	tetrs_count = ft_lstsize(tetr_list);
	while (tetrs_count * TETR_POINT_NUM > size * size)
		size++;
	return (size);
}

char	**map_copy(char **map, int map_size)
{
	char	**copy;
	int		i;

	copy = (char **)ft_memalloc(sizeof(char *) * (map_size + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		copy[i] = ft_strdup(map[i]);
		if (copy[i] == NULL)
		{
			while (--i > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

/*
**	Содание пустой карты. Все её элементы равны MAP_CHR_EMPTY (.)
*/

char	**map_generate(int map_size)
{
	char	**map;
	int		y;

	map = (char **)ft_memalloc(sizeof(char *) * (map_size + 1));
	if (map == NULL)
		return (NULL);
	y = 0;
	while (y < map_size)
	{
		map[y] = ft_strnew(map_size);
		if (map[y] == NULL)
		{
			while (--y > 0)
				free(map[y]);
			free(map);
			return (NULL);
		}
		ft_memset(map[y], MAP_CHR_EMPTY, map_size);
		y++;
	}
	map[map_size] = NULL;
	return (map);
}

/*
**	Содаем новый элемент списка и кидаем в него контент
*/

t_list	*ft_lst_attach(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = (void *)content;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}

/*
**	Для избавления в solve в found_resolve от второго цикла.
**	Гоняет х и y, по всей карте.
*/

void	point_increment(t_point *point, int map_size)
{
	point->x++;
	if (point->x == map_size)
	{
		point->x = 0;
		point->y++;
	}
}
