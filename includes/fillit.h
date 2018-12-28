/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:03:54 by sdremora          #+#    #+#             */
/*   Updated: 2018/12/27 15:27:22 by bsprigga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define ERROR -1
# define TRUE 1
# define FALSE 0
# define TETR_POINT_NUM 4
# define MAP_CHR_EMPTY '.'

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_elem
{
	t_point		*point[TETR_POINT_NUM];
	char		chr;
}				t_elem;

t_list			*read_file(int argc, char const **argv);
t_list			*text_to_list(t_list **lines_list, char *filename);
void			check_valid_chars_n_rows \
(int *iter, char *line, t_list **lines_list);
void			check_last_element(t_list **lines_list);
void			check_num_blocks(t_list **lines_list);
void			lines_to_tetr(t_list *lines_list, t_list **tetr_list);
void			insert_to_tetr_list \
(t_list **tetr_list, int count_dot, int x, int y);
void			check_num_figures(t_list **lines_list);
void			check_blocks_size(t_list **lines_list);
void			check_figures_validity(t_list **tetr_list);
int				check_coord(t_point *curr_p, int i, t_list *tmp);

char			**found_resolve(t_list *tetr_list);
void			eval_resolve(t_list **resolve_list);
void			print_resolve(char **map);

void			f_error(t_list **tetr_list);
size_t			ft_lstsize(t_list *list);
t_point			*new_point(int x, int y);
void			dell_elem(void *content, size_t size);
void			str_ar_del(char ***str_ar);

int				get_min_size_map(t_list *tetr_list);
char			**map_copy(char **map, int map_size);
char			**map_generate(int map_size);
t_list			*ft_lst_attach(void const *content, size_t content_size);
void			point_increment(t_point *point, int map_size);

void			del_lines_elem(void *content, size_t size);
void			f_error2(t_list **tetr_list);
void			f_error_empty();

#endif
