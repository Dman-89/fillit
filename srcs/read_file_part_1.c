/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_part_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsprigga <bsprigga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:37:48 by bsprigga          #+#    #+#             */
/*   Updated: 2018/12/27 15:58:16 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_num_blocks(t_list **lines_list)
{
	t_list	*tmp;
	int		i;
	int		num_blocks;

	num_blocks = 0;
	tmp = *lines_list;
	i = 0;
	while (tmp)
	{
		num_blocks > 26 ? f_error2(lines_list) : 1;
		if (i == 4)
		{
			((char *)tmp->content)[0] = '\0';
			i = -1;
			num_blocks++;
		}
		else
			((char *)tmp->content)[4] = '\0';
		tmp = tmp->next;
		i++;
	}
}

void		check_last_element(t_list **lines_list)
{
	t_list	*tmp;
	char	*l;

	tmp = *lines_list;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			if (((char *)tmp->content)[4] == '\n' && \
			ft_strlen(((char *)tmp->content)) == 5)
			{
				(l = (char *)ft_memalloc(sizeof(l) * 1)) < 0 ? \
				f_error2(lines_list) : 1;
				ft_lstadd(lines_list, ft_lst_attach(l, ft_strlen(l)));
			}
			else
				f_error2(lines_list);
		}
		tmp = tmp->next;
	}
}

void		check_valid_chars_n_rows(int *iter, char *line, t_list **lines_list)
{
	int i;

	i = -1;
	if (*iter == 4)
	{
		if (ft_strlen(line) != 1 && line[0] != '\n')
			f_error2(lines_list);
		*iter = -1;
	}
	else if (ft_strlen(line) == 5)
		while (++i < 5)
		{
			if (i < 4 && line[i] != '.' && line[i] != '#')
				f_error2(lines_list);
			else if (i == 4 && line[i] != '\n')
				f_error2(lines_list);
		}
	else
		f_error2(lines_list);
}

t_list		*text_to_list(t_list **lines_list, char *filename)
{
	int		fd;
	int		iter;
	int		read_status;
	char	*l;
	t_list	*elem;

	((fd = open(filename, O_RDONLY)) == -1) ? f_error_empty() : 1;
	iter = -1;
	while (1)
	{
		(l = (char *)ft_memalloc(sizeof(l) * 5)) < 0 ? f_error2(lines_list) : 1;
		if (++iter < 4 && ((read_status = read(fd, l, 5)) < 0))
			f_error2(lines_list);
		else if (iter == 4)
			(((read_status = read(fd, l, 1))) < 0) ? f_error2(lines_list) : 1;
		if (read_status == 0)
		{
			free(l);
			return (*lines_list);
		}
		check_valid_chars_n_rows(&iter, l, lines_list);
		if (!(elem = ft_lst_attach(l, ft_strlen(l))))
			f_error2(lines_list);
		ft_lstadd(lines_list, elem);
	}
}

t_list		*read_file(int argc, char const **argv)
{
	t_list	*lines_list;
	t_list	*tetr_list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	lines_list = NULL;
	if ((lines_list = text_to_list(&lines_list, (char *)argv[1])) == NULL)
		f_error_empty();
	check_last_element(&lines_list);
	ft_lstreverse(&lines_list);
	check_num_blocks(&lines_list);
	check_blocks_size(&lines_list);
	check_num_figures(&lines_list);
	tetr_list = NULL;
	lines_to_tetr(lines_list, &tetr_list);
	ft_lstdel(&lines_list, del_lines_elem);
	check_figures_validity(&tetr_list);
	return (tetr_list);
}
