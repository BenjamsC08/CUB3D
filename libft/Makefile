CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCC = srcs/strs/ft_free_strs.c srcs/strs/ft_split.c srcs/strs/ft_strsdup.c srcs/strs/ft_print_strs.c srcs/strs/ft_unsplit.c srcs/strs/ft_strslen.c srcs/strs/ft_strsjoin.c srcs/garbage_coll/ft_gc.c srcs/char/ft_iswhitespace.c srcs/char/ft_isalnum.c srcs/char/ft_isprint.c srcs/char/ft_isdigit.c srcs/char/ft_ishex.c srcs/char/ft_is_incharset.c srcs/char/ft_tolower.c srcs/char/ft_toupper.c srcs/char/ft_isalpha.c srcs/char/ft_isascii.c srcs/to_ascii/ft_intlen.c srcs/to_ascii/ft_ltoa.c srcs/to_ascii/ft_xtoa.c srcs/to_ascii/ft_xlen.c srcs/to_ascii/ft_itoa.c srcs/to_ascii/ft_utoa.c srcs/bits/ft_print_bits.c srcs/bits/ft_swap_bits.c srcs/bits/ft_reverse_bits.c srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c srcs/lists/ft_lstadd_front.c srcs/lists/ft_lstclear.c srcs/lists/ft_lstlast.c srcs/lists/ft_lstmap.c srcs/lists/ft_lstnew.c srcs/lists/ft_lstremove_if.c srcs/lists/ft_lstiter.c srcs/lists/ft_lstsize.c srcs/lists/ft_lstdelone.c srcs/lists/ft_lstfind_middle.c srcs/lists/ft_lstadd_back.c srcs/put/ft_putendl.c srcs/put/ft_putuint.c srcs/put/ft_putnbr.c srcs/put/ft_putlong.c srcs/put/ft_putstr.c srcs/put/ft_putchar.c srcs/put/ft_putptr.c srcs/put/ft_puthex.c srcs/sort/quicksort/ft_quicksort.c srcs/str/ft_onlyhex.c srcs/str/ft_substr.c srcs/str/ft_only_charset.c srcs/str/ft_strjoin.c srcs/str/ft_remove_charset.c srcs/str/ft_only_alnum.c srcs/str/ft_strrchr.c srcs/str/ft_strncmp.c srcs/str/ft_only_ascii.c srcs/str/ft_strcasestr.c srcs/str/ft_strstr.c srcs/str/ft_strlen.c srcs/str/ft_strdup.c srcs/str/ft_striteri.c srcs/str/ft_strchr.c srcs/str/ft_strnstr.c srcs/str/ft_remove_substring.c srcs/str/ft_only_alpha.c srcs/str/ft_strlcat.c srcs/str/ft_only_print.c srcs/str/ft_only_whitespace.c srcs/str/ft_strlcpy.c srcs/str/ft_strmapi.c srcs/str/ft_str_cut.c srcs/str/ft_strtrim.c srcs/str/ft_str_add_char.c srcs/str/ft_strrev.c srcs/str/ft_strndup.c srcs/str/ft_only_digit.c srcs/memory/ft_bzero.c srcs/memory/ft_memset.c srcs/memory/ft_calloc.c srcs/memory/ft_memcmp.c srcs/memory/ft_memchr.c srcs/memory/ft_memmove.c srcs/memory/ft_memcpy.c srcs/printf/ft_printf.c srcs/printf/ft_dprintf.c srcs/integer/ft_atoi.c srcs/integer/ft_rrange.c srcs/integer/ft_atol.c srcs/integer/ft_isprime.c srcs/integer/ft_min_max.c srcs/integer/ft_abs.c srcs/integer/ft_range.c srcs/integer/ft_swap.c
OBJ = $(SRCC:.c=.o)
NAME = libft.a
INCLUDE = includes/
VALID = \033[1;32m
NOTVALID = \033[1;31m
LOADING = \033[1;33m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n$(VALID) - libft: compilation succeed \t✅\n"
	@ar rcs $@ $^

%.o: %.c $(INCLUDE)
	@printf "\r$(LOADING) - libft: compilation \t\t🔃 "
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ #> /dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR)/$(OBJ)
	@echo "$(VALID) - libft: clean \t\t✅"

fclean: clean
	@rm -f $(NAME)
	@echo "$(VALID) - libft: fclean \t\t✅"

re: fclean all

cList:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '

nbC:
	@find -wholename "./srcs/*.c" | wc -l

.PHONY: all clean fclean re cList nbC
