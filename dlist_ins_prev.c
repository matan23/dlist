/*
** dlist_ins_prev.c for dlist in /Users/mataejoon/sandbox/lib
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Tue Dec 18 18:47:00 2012 Mathieu TAN
** Last update Sat Feb  9 12:56:23 2013 Mathieu TAN
*/

#include "dlist.h"

static t_dlist_elem	*create_node_elem(const void *data)
{
  t_dlist_elem		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->data = (void *)data;
  return (new);
}

int		dlist_ins_prev(t_dlist *list, t_dlist_elem *elem, const void *data)
{
  t_dlist_elem	*new;

  if ((elem == NULL && DLIST_SIZE(list) > 0) ||
      (!(new = create_node_elem(data))))
    return (0);
  if (!DLIST_SIZE(list))
    {
      list->head = new;
      list->tail = new;
      new->next = NULL;
      new->prev = NULL;
    }
  else
    {
      new->prev = elem->prev;
      new->next = elem;
      if (new->prev)
	new->prev->next = new;
      else
	list->head = new;
      elem->prev = new;
    }
  list->size++;
  return (1);
}
