#ifndef DLIST_H_
# define DLIST_H_

# include <stdlib.h>

/* types */
typedef struct		s_dlist_elem
{
  void			*data;
  struct s_dlist_elem	*next;
  struct s_dlist_elem	*prev;
}			t_dlist_elem;


typedef struct	s_dlist
{
  int		size;
  void		(*destroy)(void *data);
  int		(*cmp)(const char *s1, const char *s2);
  t_dlist_elem	*head;
  t_dlist_elem	*tail;
}		t_dlist;

/* functions */
void	dlist_init(t_dlist *list, void (*destroy)(void *data),
		   int (*cmp)(const char *s1, const char *s2));
void	dlist_destroy(t_dlist *list);
int	dlist_ins_next(t_dlist *list, t_dlist_elem *elem, const void *data);
int	dlist_ins_prev(t_dlist *list, t_dlist_elem *elem, const void *data);
int	dlist_remove(t_dlist *list, t_dlist_elem *elem, void **data);

/* macros */
# define DLIST_SIZE(list) ((list)->size)
# define DLIST_HEAD(list) ((list)->head)
# define DLIST_TAIL(list) ((list)->tail)
# define DLIST_IS_HEAD(list, elem) ((elem) == (list)->head ? 1 : 0)
# define DLIST_IS_TAIL(list, elem) ((elem) == (list)->tail ? 1 : 0)
# define DLIST_DATA(elem) ((elem)->data)
# define DLIST_NEXT(elem) ((elem)->next)
# define DLIST_PREV(elem) ((elem)->prev)

#endif	/* !DLIST_H_ */
