#include <string.h>
#include <stdio.h>
#include "dlist.h"
#include "fake.h"

void		list_dump(t_dlist *list, t_dlist_elem *elem)
{
  t_data	*d;

  while (elem)
    {
      d = elem->data;
      printf("list->data->name = [%s]\n", d->name);
      elem = elem->next;
    }
}

int		main(int ac, char **av)
{
  t_dlist	*list;
  t_data	*d;

  list = malloc(sizeof(*list));
  dlist_init(list, free, strcmp);
  while (*av)
    {
      d = malloc(sizeof(*d));
      d->name = *av;
      dlist_ins_sort(list, d);
      av++;
    }
  list_dump(list, list->head);
  return (0);
}

/* int	main(int ac, char **av) */
/* { */
/*   printf("[%d]\n", _strcasecmp(av[1], av[2])); */
/*   return (0); */
/* } */
