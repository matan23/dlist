/*
** dlist_destroy.c for dlist in /Users/mataejoon/sandbox/lib
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Tue Dec 18 18:46:37 2012 Mathieu TAN
** Last update Sat Feb  9 13:20:27 2013 Mathieu TAN
*/

#include <stdio.h>

#include <string.h>
#include "dlist.h"

void	dlist_destroy(t_dlist *list)
{
  void	*data;

  while (DLIST_SIZE(list) > 0)
    {
      if (dlist_remove(list, DLIST_TAIL(list), (void **)&data) == 0 &&
	  list->destroy != NULL)
	{
	  printf("appel a destroy\n");
	  list->destroy(data);
	}
    }
  memset(list, 0, sizeof(*list));
}
