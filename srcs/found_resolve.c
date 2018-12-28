/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:23:00 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/28 11:09:03 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Возвращает:
**	TRUE - Вставить фигуру можно
**	FALSE - нельзя
*/

int		can_push_tetr(char **map, int map_size, t_list *tetrs, t_point *point)
{
	int		i;
	int		x1;
	int		y1;
	t_elem	*tetr;

	i = 0;
	tetr = (t_elem *)tetrs->content;
	while (i < TETR_POINT_NUM)
	{
		x1 = point->x + tetr->point[i]->x;
		y1 = point->y + tetr->point[i]->y;
		if (x1 < 0 || y1 < 0)
			return (FALSE);
		if (x1 >= map_size || y1 >= map_size)
			return (FALSE);
		if (map[y1][x1] != MAP_CHR_EMPTY)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
**	Размещает на карте символ детали.
*/

void	tetr_put(char **map, t_list *tetrs, t_point *point)
{
	int		i;
	int		x1;
	int		y1;
	t_elem	*tetr;

	i = 0;
	tetr = (t_elem *)tetrs->content;
	while (i < TETR_POINT_NUM)
	{
		x1 = point->x + tetr->point[i]->x;
		y1 = point->y + tetr->point[i]->y;
		map[y1][x1] = tetr->chr;
		i++;
	}
}

/*
**	Просто для сокращения строк в solve
*/

char	**error_in_resolve(int *status)
{
	*status = ERROR;
	return (NULL);
}

/*
**	Рекурсивная функция.
**	Берет из tetr_list первую фигуру и пытается вставить её
**	на карту в самый верхний левый угол, если вставить удается
**	то вызывает себя же, со смещенным tetr_list.
**	Если вставить не удалось, переходим на следующую точку.
**	Карта закончилась? Возвращаем ноль - решений нет.
**	Переменная status нужна для случая выделения малоком нуля.
**	В таком случае все функции в стеке
**	должны очистить карты и выйти.
*/

char	**solve(t_list *tetr_list, char **map, int map_size, int *status)
{
	char	**resolve;
	char	**next_resolve;
	t_point point;

	point.x = 0;
	point.y = 0;
	while (point.y < map_size)
	{
		if (can_push_tetr(map, map_size, tetr_list, &point) == TRUE)
		{
			resolve = map_copy(map, map_size);
			if (resolve == NULL)
				return (error_in_resolve(status));
			tetr_put(resolve, tetr_list, &point);
			if (tetr_list->next == NULL)
				return (resolve);
			next_resolve = solve(tetr_list->next, resolve, map_size, status);
			str_ar_del(&resolve);
			if (next_resolve != NULL || *status == ERROR)
				return (next_resolve);
		}
		point_increment(&point, map_size);
	}
	return (NULL);
}

/*
**	Гоняет функцую solve, пока она не найдет решения.
**	При каждой итерации размер карты увеличивается.
**	Если функция solve изменила status на ERROR, закрываем программу.
*/

char	**found_resolve(t_list *tetr_list)
{
	int		map_size;
	char	**resolve;
	char	**empty_map;
	int		status;

	map_size = get_min_size_map(tetr_list);
	resolve = NULL;
	status = TRUE;
	while (resolve == NULL)
	{
		if (!(empty_map = map_generate(map_size))
			f_error(&tetr_list);
		resolve = solve(tetr_list, empty_map, map_size, &status);
		str_ar_del(&empty_map);
		if (status == ERROR)
			f_error(&tetr_list);
		map_size++;
	}
	return (resolve);
}
