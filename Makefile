NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
MAKE	:= make
AR		:= ar rcs
RM		:= rm -rf

SRC_DIR 	:= src
OBJ_DIR		:= obj
INC_DIR		:= include
SRCS		:= $(wildcard $(SRC_DIR)/*.c)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR	:= libft
LIBFT_LIB_A := $(LIBFT_DIR)/libft.a
LIBFT_LIB   := ft

ifdef DEBUG
	CFLAGS += -DDEBUG
endif
ifdef TESTB
	CFLAGS += -DTESTB
endif
ifdef LIST2ARR
	CFLAGS += -DLIST2ARR
endif

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	CHECKER_CMD = ./checker_linux
else ifeq ($(UNAME), Darwin)
	CHECKER_CMD = ./checker_Mac
else
	CHECKER_CMD = xargs -I{} echo {}
endif
ifdef VALGRIND
	VALGRIND_CMD = valgrind --leak-check=full --show-leak-kinds=all -q
endif

all		: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_LIB_A)
	$(CC) $(CFLAGS) $(OBJS) \
	-I$(INC_DIR) \
	-I$(LIBFT_DIR)/include -L$(LIBFT_DIR) -l$(LIBFT_LIB) \
	-o $@

$(LIBFT_LIB_A)	:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) \
	-I$(INC_DIR) \
	-I$(LIBFT_DIR)/include \
	-c $< -o $@

clean	:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean	: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) a.out

re		: fclean all

test_sort_n6	: $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -l$(LIBFT_LIB_SHORT) -o a.out
	ARGS="2 1 3 6 5 8"; $(VALGRIND_CMD) ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	$(VALGRIND_CMD)  ./a.out  "2 1 3" 6 "5 8" | $(CHECKER_CMD) "2 1 3" 6 "5 8"
	ARGS="3 1 2 4 5"; $(VALGRIND_CMD) ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS

test_sort_n3	: $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -l$(LIBFT_LIB_SHORT) -o a.out
	ARGS="1 2"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="2 1"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="42 -1"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="1 2 3"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="1 3 2"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="2 1 3"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="2 3 1"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="3 1 2"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="3 2 1"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS
	ARGS="-3 -12 -111"; ./a.out $$ARGS | $(CHECKER_CMD) $$ARGS

test_list : $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) tests/test_cdl_list.c src/cdl_list*.c -I$(INC_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -l$(LIBFT_LIB_SHORT) -o a.out
	./a.out

test_sort : $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) tests/test_sort.c src/sort.c -I$(INC_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -l$(LIBFT_LIB_SHORT) -o a.out
	./a.out

# test	:
# 	$(CC) tests/test_ops.c $(SRC_DIR)/*.c -I$(INC_DIR)
# 	./a.out

.PHONY	: all clean fclean re test
