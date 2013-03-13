#ifndef FAKE_H_
# define FAKE_H_

typedef struct	s_data
{
  char		*name;
}		t_data;

int		_strcasecmp(char *s1, char *s2);
int		dlist_ins_sort(t_dlist *list, const void *data);


#endif	/* !FAKE_H_ */
