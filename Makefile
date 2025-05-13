##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME = libhashtable.a

SRCS = src/hash.c \
       src/new_hashtable.c \
       src/delete_hashtable.c \
       src/free_all.c \
       src/ht_delete.c \
       src/ht_dump.c \
       src/ht_insert.c \
       src/ht_search.c \
       src/list/add_end.c \
       src/list/add_front.c \
       src/list/cat_list.c \
       src/list/create_list.c \
       src/list/del_end.c \
       src/list/del_front.c \
       src/list/del_node.c \
       src/lib/my_getnbr.c \
       src/lib/my_putchar.c \
       src/lib/my_put_nbr.c \
       src/lib/my_putstr.c \
       src/lib/my_printf.c \
       src/lib/my_revstr.c \
       src/lib/my_len_array.c \
       src/lib/my_base.c \
       src/lib/my_hexa.c \
       src/lib/my_put_bignbr.c \
       src/lib/my_get_double.c \
       src/lib/my_len_int.c \
       src/lib/base_specifiers.c \
       src/lib/my_adressptr.c \
       src/lib/advanced_specifiers.c \
       src/lib/my_put_nbr_unsigned.c \
       src/lib/my_int_to_str.c \
       src/lib/my_printf.c \
       src/lib/aeg_specifiers.c \
       src/lib/my_putscience.c \
       src/lib/my_shorter.c \
       src/lib/my_strlen.c \
       src/lib/my_strcat.c \
       src/lib/my_strdup.c \
       src/lib/my_strupcase.c \
       src/lib/my_strncpy.c \
       src/lib/my_strcpy.c \
       src/lib/my_strcmp.c \
       src/lib/my_str_to_words_array.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra
CFLAGS += -I./include -g

CS = coding-style . .

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cs: fclean
	$(CS)
