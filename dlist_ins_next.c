/*
** dlist_ins_next.c for dlist in /Users/mataejoon/sandbox/lib
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Tue Dec 18 18:46:52 2012 Mathieu TAN
** Last update Sat Feb  9 12:56:10 2013 Mathieu TAN
*/

#include <stdio.h>
#include "dlist.h"

static t_dlist_elem	*create_node_elem(const void *data)
{
  t_dlist_elem		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->data = (void *)data;
  return (new);
}

int		dlist_ins_next(t_dlist *list, t_dlist_elem *elem, const void *data)
{
  t_dlist_elem	*new;

  if ((elem == NULL && DLIST_SIZE(list) > 0) ||
      (!(new = create_node_elem(data))))
    return (0);
  if (DLIST_SIZE(list) == 0)
    {
      list->head = new;
      list->tail = new;
      new->next = NULL;
      new->prev = NULL;
    }
  else
    {
      new->next = elem->next;
      new->prev = elem;
      if (new->next)
	new->next->prev = new;
      else
	list->tail = new;
      elem->next = new;
    }
  list->size++;
  return (1);
}
