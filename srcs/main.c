/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:00:16 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/27 15:39:30 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_list	*tetr_list;
	char	**resolve;

	tetr_list = read_file(argc, argv);
	ft_lstreverse(&tetr_list);
	resolve = found_resolve(tetr_list);
	print_resolve(resolve);
	ft_lstdel(&tetr_list, dell_elem);
	str_ar_del(&resolve);
	return (0);
}
