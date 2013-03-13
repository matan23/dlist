/*
** dlist_init.c for dlist in /Users/mataejoon/sandbox/lib
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Tue Dec 18 18:46:45 2012 Mathieu TAN
** Last update Fri Dec 21 01:40:31 2012 Mathieu TAN
*/

#include "dlist.h"

void	dlist_init(t_dlist *list, void (*destroy)(void *data),
		   int (*cmp)(const char *s1, const char *s2))
{
  list->size = 0;
  list->destroy = destroy;
  list->cmp = cmp;
  list->head = NULL;
  list->tail = NULL;
}
