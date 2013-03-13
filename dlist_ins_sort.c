/*
** dlist_ins_sort.c for dlist in /Users/mataejoon/programming/lib/dlist
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Thu Dec 20 20:39:44 2012 Mathieu TAN
** Last update Fri Dec 21 01:41:10 2012 Mathieu TAN
*/

#include <stdio.h>

#include "dlist.h"
#include "fake.h"

int	cmp_node(t_dlist *list, t_data *new, t_dlist_elem *elem)
{
  int		res;
  t_data	*d2;

  d2 = elem->data;
  res = list->cmp(new->name, d2->name);
  printf("s1=%s, s2=%s : %d\n", new->name, d2->name, res);
  return (res);
}

int		dlist_ins_sort(t_dlist *list, const void *data)
{
  t_dlist_elem	*elem;

  elem = list->head;
  while (elem)
    {
      if (cmp_node(list, (t_data *)data, elem) >= 0)
	elem = elem->next;
      else
	{
	  printf("prev: data[%s]\n", ((t_data*)data)->name);
	  return (dlist_ins_prev(list, elem, data));
	}
    }
  printf("next: data[%s]\n", ((t_data*)data)->name);
  return (dlist_ins_next(list, list->tail, data));
}
