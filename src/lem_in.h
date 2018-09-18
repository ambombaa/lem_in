/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:20:18 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/12 10:21:24 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct		s_string
{
	char			*str;
	struct s_string	*next;
}					t_string;

typedef struct		s_ant
{
	char			*ant_name;
	struct s_string	*room;
}					t_ant;

typedef struct		s_colony
{
	t_ant			ant;
	struct s_colony *next;
}					t_colony;

typedef	struct		s_pathfinding
{
	t_string		*path;
	int				found;
	t_string		*closedset;
	t_string		*tmp;
	char			*current;
	char			*t;
}					t_pathfinding;

typedef struct		s_location
{
	char				**rooms;
	char				*rooms_list;
	char				*ants_str;
	char				*links;
	int					room_quantity;
	int					ants;
	int					current_room;
	int					last_path_index;
	int					**table;
	int					good[2];
	int					new_line;
	int					init_2;
	t_string			*lin;
	t_string			*path;
	char				*current;
	t_string			*wae;
	char				**s;
	struct s_location	*map;
	int					len;
	int					i;
}					t_location;

void				ants_number(t_location *map, char *line);
void				rooms(t_location *map, char *line);
void				links(t_location *map, char *line);
int					is_empty(char *s);
void				add_rooms(t_location *map);
void				create_tab(t_location *map);
int					solution(t_location *map, int i);
void				count_ants(t_location *map, char *line);
void				ft_append(t_string **head, char *new_data);
char				*check_inputs(char *s1, char *s2, int clean);
void				free_array(char **array, t_location *map, int error);
int					room_index(t_location *map, char *room_name, int start);
void				result(t_location *map, t_string *l);
void				exit_func(t_location *map, int error);
t_string			*ft_create_links(char *links);
void				init(t_location *map);
int					is_in(char *str, char *find);
int					is_in_list(t_string *path, char *str);
t_string			*find_str(t_string *l, char *f, t_string *p, t_string *c);
char				*next_in(char *str, char *current);
void				ft_del_last(t_string **head);
void				delete_node(t_string **head_ref, char *key);
t_string			*find_path(char *start, char *end, t_string *links);
size_t				count_nodes(void **str);
int					ft_lstlen(t_string *str);
int					find_index(char **arr, char *str);
void				to_list(t_string **wae, char *str);
t_string			*find_last(t_string *last);
int					ft_lstlen(t_string *str);
int					find_index(char **arr, char *str);
void				to_list(t_string **wae, char *str);
void				process(t_location *map, char *line, int *flag);
int					ft_lstlen(t_string *str);
void				to_list(t_string **wae, char *str);
void				ft_assign_routs(t_colony *ants, t_string *da_wae);
void				ft_trans_ant(t_colony **head, t_colony *new_data);
void				ft_append_ant(t_colony **head, char *new_data);
void				ft_display(t_colony *ants);
char				*ft_itoa(int n);
t_colony			*ft_get_ants(t_location *map);
t_colony			*ft_pop(t_colony **head);
void				ft_push_to(t_colony **dest, t_colony **src);
void				ft_move_ants_in_maize(t_colony **ants);
void				ft_remove_ants_at_end(t_colony **ants_in_maize,
							t_location *map);
void				ft_delete_ant(t_colony **head_ref, char *key);
char				*ft_find_last(char *links, char *str);

size_t				ft_double_ptr_len(void **str);

#endif
