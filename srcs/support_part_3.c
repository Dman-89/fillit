/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_part_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:38:04 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/27 15:10:57 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_lines_elem(void *content, size_t size)
{
	free(content);
	size = 0;
}

void	f_error2(t_list **tetr_list)
{
	ft_lstdel(tetr_list, del_lines_elem);
	ft_putstr("error\n");
	exit(ERROR);
}

void	f_error_empty(void)
{
	ft_putstr("error\n");
	exit(ERROR);
}
