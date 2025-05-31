SRCS = \
	./source/core_code.c \
	./source/find_minishell.c \
	./source/show_banner.c \
	./source/put_color/put_color.c

GRN = "\e[1;32m
END = \e[0m"

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

AR = ar -U -r -u -s 

NAME = archive.a

$(NAME): $(OBJS)
	@echo $(GRN)Make $(NAME)$(END)
	$(AR) $@ $(OBJS)

all: $(NAME)
	@echo $(GRN)$(NAME) make done.$(END)

RM = rm -f

clean:
	@echo $(GRN)Make clean.$(END)
	$(RM) $(OBJS)
fclean: clean
	@echo $(GRN)Make fclean.$(END)
	$(RM) $(NAME)

re: fclean
	@echo $(GRN)Make re.$(END)
	make all

.PHONY: all clean fclean re
