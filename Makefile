NAME := fillit
INCLUDES := includes libft/includes/
SRCS := found_resolve.c main.c print_resolve.c \
		read_file_part_1.c read_file_part_2.c read_file_part_3.c \
		support_part_1.c support_part_2.c support_part_3.c
OBJ := $(patsubst %.c, %.o, $(SRCS))
FLAGS := -Wall -Wextra -Werror
VPATH := . srcs

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME): libft/libft.a $(OBJ)
	gcc $(FLAGS) $(OBJ) -lft -Llibft -o $@

%.o: %.c
	gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: clean re all fclean
