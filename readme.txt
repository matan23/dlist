gcc -W -Wall -Werror -c dlist*.c _strcmp.c -I./includes
ar rcs libdlist.a *.o
