/*
** dlist_remove.c for dlist in /Users/mataejoon/sandbox/lib
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Tue Dec 18 18:47:07 2012 Mathieu TAN
** Last update Tue Dec 18 18:47:08 2012 Mathieu TAN
*/

#include "dlist.h"

int	dlist_remove(t_dlist *list, t_dlist_elem *elem, void **data)
{
  if (!elem || !DLIST_SIZE(list))
    return (0);
  *data = elem->data;
  if (elem == list->head)
    {
      list->head = elem->next;
      if (!list->head)
	list->tail = NULL;
      else
	list->head->prev = NULL;
    }
  else
    {
      elem->prev->next = elem->next;
      if (elem->next == NULL)
	list->tail = elem->prev;
      else
	elem->next->prev = elem->prev;
    }
  free(elem);
  list->size--;
  return (1);
}
