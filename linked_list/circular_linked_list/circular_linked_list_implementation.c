/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list_implementation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <jko@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:52:54 by jko               #+#    #+#             */
/*   Updated: 2020/03/07 23:43:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_linked_list *list_init(void);
t_node *create_elem(void *data);
int list_add(t_linked_list *list, void *data, int n);
int list_size(t_linked_list *list);
t_node *list_get(t_linked_list *list, int n);
int list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2));
void list_remove(t_linked_list *list, int n, void (*free_data)(void *));
void list_clear(t_linked_list *list, void (*free_data)(void *));
void free_list(t_linked_list *list, void (*free_data)(void *));
void list_foreach(t_linked_list *list, void (*f)(void *));
void list_move_head_to_next(t_linked_list *list);
void list_move_head_to_prev(t_linked_list *list);


int main(int argc, char *argv[])
{
	
	return 0;
}


# include "list.h"
# define TRUE 1
# define FALSE 0
typedef char bool;

t_linked_list	*list_init(void)
{
	t_linked_list *list;

	list = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (list == 0)
		return (0);
	list->size = 0;
	list->head = 0;
	return (list);
}

t_node		*create_elem(void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->data = data;
	node->prev = 0;
	node->next = 0;
	return (node);
}

int		list_size(t_linked_list *list)
{
	if (list == 0)
		return (0);
	return (list->size);
}

void		list_move_head_to_next(t_linked_list *list)
{
}

void		list_move_head_to_prev(t_linked_list *list)
{
}


static int	calculate_index(unsigned int size, int n)
{
	if (size == 0)
		return (0);
	return (n % size);
}

static t_node	*move_node(t_node *curr, int direction)
{
	if (curr == 0 || direction == 0)
		return (curr);
	if (direction > 0)
		return (curr->next);
	return (curr->prev);
}

t_node		*list_get(t_linked_list *list, int n)
{
	t_node	*curr;
	int	direction;

	if (list == 0)
		return (0);
	direction = 1;
	if ((n = calculate_index(list->size, n)) < 0)
		direction = -1;
	curr = list->head;
	while (curr && n)
	{
		curr = move_node(curr, n);
		n += direction;
	}
	return (curr);
}

static int	insert_prev(t_linked_list *list, t_node *curr, void *data, bool change_head)
{
	t_node	*new;

	if (list == 0 || (new = create_elem(data)) == 0)
		return (-1);
	list->size++;
	new->prev = curr->prev;



}

int		list_add_last(t_linked_list *list, void *data)
{
	t_node *new;

	if (list == 0)
		return (-1);
	if (list->size > 0)
		return (insert_prev(list, list->head, data, FALSE));
	if ((new = create_elem(data)) == 0)
		return (-1);
	list->size++;
	list->head = new;
	new->prev = new;
	new->next = new;
	return (0);
}

int		list_add(t_linked_list *list, void *data, int n)
{
	t_node	*curr;

	if (list == 0)
		return (-1);
	if ((curr = list_get(list, n)) == 0)
		return (list_add_last(list, data));
	if ((n = calculate_index(list->size, n)) < 0)
		return (insert_next(list, curr, data, n == 0));
	return (insert_prev(curr, data, n == 0));
}

int		list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2))
void		list_remove(t_linked_list *list, int n, void (*free_data)(void *))
void		list_clear(t_linked_list *list, void (*free_data)(void *))
void		free_list(t_linked_list *list, void (*free_data)(void *))
void		list_foreach(t_linked_list *list, void (*f)(void *))


