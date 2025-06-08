/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdl_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:04:00 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/17 22:10:46 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDL_LIST_H
# define CDL_LIST_H

# include "push_swap.h"
# include <stdbool.h>
# include <stddef.h>

# ifndef CDL_H
#  define CDL_H

typedef struct s_cdl_node
{
	int					data;
	struct s_cdl_node	*prev;
	struct s_cdl_node	*next;
}						t_cdl_node;

typedef struct s_cdl_list
{
	int					size;
	t_cdl_node			*head;
	t_cdl_node			*tail;
}						t_cdl_list;
# endif

void					init_list(t_cdl_list *list);
t_cdl_node				*create_node(int data);
int						push_front(t_cdl_list *list, t_cdl_node *node);
int						push_back(t_cdl_list *list, t_cdl_node *node);
t_cdl_node				*pop_front(t_cdl_list *list);
t_cdl_node				*pop_back(t_cdl_list *list);
int						rotate(t_cdl_list *list);
int						reverse_rotate(t_cdl_list *list);
int						swap_top2(t_cdl_list *list);
bool					is_sorted(t_cdl_list *list, bool (*cmp)(int, int));
bool					is_ascending(int n1, int n2);
bool					is_descending(int n1, int n2);
// list utils
int						print_list(t_cdl_list *list);
int						list_to_array(t_cdl_list *list, int array[]);

#endif
