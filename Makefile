##
## Makefile for Makefile in /Users/Mataejoon/ETNA/piscine_c/j8/Makefile
## 
## Made by Mathieu TAN
## Login   <tan_m@etna-alternance.net>
## 
## Started on  Wed Mar 28 14:25:21 2012 Mathieu TAN
## Last update Fri Dec 21 01:44:47 2012 Mathieu TAN
##

NAME		=	a.out
SRCS		=	main.c			\
			_strcmp.c		\
 			dlist_ins_sort.c
# 			dlist_ins_prev.c	\
# 			dlist_ins_next.c	\
# 			dlist_init.c		\

CC		=	gcc
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-W -Wall -pedantic -ansi -I./includes -g3

$(NAME)		: $(OBJS)
		$(CC) -o $(NAME) $(OBJS) -L. -ldlist

.c.o		:
		$(CC) $(CFLAGS) -c $<

all		: $(NAME)

clean		:
		rm -f $(OBJS)

fclean		: clean
		rm -rf *~ *#

re		: fclean all