/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:23:47 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/27 13:23:54 by sdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_resolve(char **map)
{
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		ft_putstr(map[y]);
		ft_putchar('\n');
		y++;
	}
}
