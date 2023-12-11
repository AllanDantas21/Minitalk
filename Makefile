NAMEC = client
NAMES = server
PRINTF = libftprintf.a
LIBFT = libft.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		@make -C libft
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) libft/$(LIBFT) -o $(NAMEC)
	
$(NAMES) : $(OBJS)
		@make -C printf
		@make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) libft/$(LIBFT) -o $(NAMES)

clean : 
		@make clean -C printf
		@make clean -C libft
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${OBJBC}
		${RM} ${OBJBS}

fclean : clean
		@make fclean -C printf
		@make fclean -C libft
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(BONUS_NAMEC)
		${RM} $(BONUS_NAMES)
		${RM} $(PRINTF)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all bonus clean fclean re
		