#directories
IDIR = inc
ODIR = obj
SDIR = src
LDIR = libftprintf
#compiler settings
CC = gcc
CFLAGS = -std=c11
CCFLAGS = -std=c11 -Og -g3 -fsanitize=address-Wall -Wextra -Werror -Wpedantic
#FLAGS = $(CCFLAGS) -I $(IDIR) -I $(LDIR)/$(IDIR)
#dependencies

BONUS = checker
BONUS_MAIN = checker.c

NAME = push_swap
NAME_MAIN = push_swap.c

LIB = libftprintf.a
#headers
DEPS := $(wildcard $(IDIR)/*.h)
#sources
SRCS := $(wildcard $(SDIR)/*.c)
#objects
_OBJS = $(SRCS:.c=.o)
OBJS = $(subst $(SDIR),$(ODIR),$(_OBJS))

#TARGETS
all: $(NAME) bonus

#make library
$(LDIR)/$(LIB):
	@make -C $(LDIR)

#make objects
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@


#make excecutable
$(NAME): $(OBJS) $(LDIR)/$(LIB)
	@$(CC) $(FLAGS) $^ $(NAME_MAIN) -o $@

bonus: $(BONUS)

$(BONUS): $(OBJS) $(LDIR)/$(LIB)
	@$(CC) $(FLAGS) $^ $(BONUS_MAIN) -o $@

.PHONY: clean uninstall reinstall

#delete all files
fclean: clean
	@rm -f $(NAME)
	@make $@ -C $(LDIR)

#remove all temp files
clean:
	@rm -rf $(ODIR)
	@make $@ -C $(LDIR)

re: clean all

#rebuild project