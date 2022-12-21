# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/21 18:05:51 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAMEB := checker

SRC_R:= push_swap.c

SRCB_R:= push_swap_bonus.c

SRCU_R:= ft_check_duplicated.c\
	ft_check_n_get_argument.c\
	ft_take_arguments.c\
	ft_log_error_exit.c\
	ft_new_stack_el.c\
	ft_dllstfindfirstinrange.c\
	ft_stack_head_order_n_bit.c\
	ft_putstackcmd_fd.c

SRC_PATH := src/
SRCB_PATH := src_bonus/
SRCU_PATH := src_utils/
LIBFT_PATH := libft/

SRC := ${addprefix $(SRC_PATH), $(SRC_R)}

SRCB := ${addprefix $(SRCB_PATH), $(SRCB_R)}

SRCU := ${addprefix $(SRCU_PATH), $(SRCU_R)}

OBJ := $(SRC:.c=.o)
OBJB := $(SRCB:.c=.o)
OBJU := $(SRCU:.c=.o)

DEPS := $(SRC:.c=.d)
DEPSB := $(SRCB:.c=.d)
DEPSU := $(SRCU:.c=.d)

CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra
CFD := -MMD
RM	:= 	rm -f

HEADER := ${addprefix $(SRC_PATH), push_swap.h}
HEADERB := ${addprefix $(SRCB_PATH), push_swap_bonus.h}
HEADERU := ${addprefix $(SRCU_PATH), push_swap_utils.h}
LIBFT_H := ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A := ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D := ${addprefix $(LIBFT_PATH), libft.d}
LIBS_FLAGS := -I ${LIBFT_H}
LIBFT_D_CONT := $(shell cat ${LIBFT_D})

src/%.o : src/%.c ${HEADER} ${HEADERU}
	${CC} ${CFLAGS} ${CFD} -I ${HEADER} -I ${HEADERU} -I ${LIBFT_H} -c $< -o $@

src_bonus/%.o : src_bonus/%.c ${HEADERB} ${HEADERU}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERB} -I ${HEADERU} -I ${LIBFT_H} -c $< -o $@

src_utils/%.o : src_utils/%.c ${HEADERU}
	${CC} ${CFLAGS} ${CFD} -I ${HEADERU} -I ${LIBFT_H} -c $< -o $@

all : $(NAME)

bonus : $(NAMEB)
	@touch $@

-include $(DEPS)
$(NAME) : ${LIBFT_A} ${OBJ} ${OBJU}
	${CC} ${CFLAGS} -I ${HEADER} ${LIBS_FLAGS} ${OBJ} ${OBJU} ${LIBFT_A}  -o $@

-include $(DEPSB)
$(NAMEB) : ${LIBFT_A} ${OBJB} ${OBJU}
	${CC} ${CFLAGS} -I ${HEADERB} ${LIBS_FLAGS} ${OBJB} ${OBJU} ${LIBFT_A} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	make bonus -C libft

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(RM) $(OBJU)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	$(RM) $(DEPSU)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(RM) bonus
	make fclean -C libft

re: fclean all

.PHONY : clean fclean re all