/*
** _strcmp.c for my_ls in /Users/mataejoon/programming/lib/dlist
** 
** Made by Mathieu TAN
** Login   <tan_m@etna-alternance.net>
** 
** Started on  Thu Dec 20 20:15:43 2012 Mathieu TAN
** Last update Fri Dec 21 01:22:25 2012 Mathieu TAN
*/

#include <stdio.h>

#define	ISUPCASE(c)	((c) >= 'A' && (c) <= 'Z')
#define	ISLOWCASE(c)	((c) >= 'a' && (c) <= 'z')

static char lowercase(char c)
{
  if (ISLOWCASE(c))
    return (c - ('a' - 'A'));
  return (c);
}

int	_strcasecmp(char *s1, char *s2)
{
  while (*s1 && *s2)
    {
      if (lowercase(*s1) - lowercase(*s2))
	return (lowercase(*s1) - lowercase(*s2));
      s1++;
      s2++;
    }
  return (lowercase(*s1) - lowercase(*s2));
}

int	_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2)
    {
      if (*s1 - *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}

int	_strncmp(char *s1, char *s2, int n)
{
  int	res;
  int	i;

  i = 0;
  res = s1[i] - s2[i];
  while ((s1[i] || s2[i]) && i < n)
    {
      res = s1[i] - s2[i];
      if (res)
	return (res);
      i++;
    }
  return (res);
}
