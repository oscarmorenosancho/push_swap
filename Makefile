# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/19 16:20:53 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAMEB := checker

SRC_R:= push_swap.c

SRCB_R:= push_swap_bonus.c

SRC_PATH := src/
SRCB_PATH := src_bonus/
LIBFT_PATH := libft/

SRC := ${addprefix $(SRC_PATH), $(SRC_R)}

SRCB := ${addprefix $(SRCB_PATH), $(SRCB_R)}

OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)

DEPS := $(SRC:.c=.d)
DEPSB := $(SRCB:.c=.d)

CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
CFD := -MMD
RM	:= 	rm -f

HEADER := ${addprefix $(SRC_PATH), push_swap.h}
HEADERB := ${addprefix $(SRCB_PATH), push_swap_bonus.h}
LIBFT_H := ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A := ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D := ${addprefix $(LIBFT_PATH), libft.d}
LIBS_FLAGS := -I ${LIBFT_H}
LIBFT_D_CONT := $(shell cat ${LIBFT_D})

src/%.o : src/%.c ${HEADER}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -I ${LIBFT_H} -c $< -o $@

src_bonus/%.o : src_bonus/%.c ${HEADERB}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERB} -I ${LIBFT_H} -c $< -o $@

all : $(NAME)

bonus : $(NAMEB)
	@touch $@

-include $(DEPS)
$(NAME) : ${LIBFT_A} ${OBJ}
	${CC} ${CFLAGS} -I ${HEADER} ${LIBS_FLAGS} ${OBJ} ${LIBFT_A}  -o $@

-include $(DEPSB)
$(NAMEB) : ${LIBFT_A} ${OBJB}
	${CC} ${CFLAGS} -I ${HEADERB} ${LIBS_FLAGS} ${OBJB} ${LIBFT_A} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	make bonus -C libft

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(RM) bonus
	make fclean -C libft

re: fclean all

.PHONY : clean fclean re all