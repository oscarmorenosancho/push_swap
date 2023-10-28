# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:34:11 by omoreno-          #+#    #+#              #
#    Updated: 2023/10/28 23:14:06 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAMEB := checker

SRCM_R:= push_swap.c

SRCB_R:= push_swap_bonus.c

SRCU_R:= ft_check_duplicated.c\
	ft_check_n_get_argument.c\
	ft_take_arguments.c\
	ft_log_error_exit.c\
	ft_new_stack_el.c\
	ft_dllstfindfirstinrange.c\
	ft_dllstfindfirstinsertloc.c\
	ft_stack_head_order_n_bit.c\
	ft_putstackcmd_fd.c\
	ft_check_stack_ordered.c\
	stack_class.c\
	stack_class2.c\
	ft_getstackcmd.c\
	push_swap_data_class.c\
	push_swap_data_class2.c\
	push_swap_data_class3.c\
	ft_fill_stack_with_arg.c\
	ft_read_n_play_cmd_list_fd.c\
	ft_find_best_move.c\
	ft_find_best_move2.c\
	ft_move_chunck_to_s.c\
	ft_move_chunks_to_s.c\
	ft_sort_anal.c\
	ft_to_do_when_sorted.c\
	ft_sort_2.c\
	ft_sort_3_a.c\
	ft_sort_4_5_a.c\
	ft_ins_into_4.c\
	fr_sort_gt_5.c\
	fr_is_convinient_cmd_in_both.c\
	ft_sum_pow2.c

SRCM_PATH		:= src/
SRCB_PATH		:= src_bonus/
SRCU_PATH		:= src_utils/
LIBFT_PATH		:= libft/
BUILD_PATH		:= .build/

SRCM_F			:= $(addprefix $(SRCM_PATH), $(SRCM_R))
SRCB_F			:= $(addprefix $(SRCB_PATH), $(SRCB_R))
SRCU_F			:= $(addprefix $(SRCU_PATH), $(SRCU_R))

SRCM_BP			:= $(addprefix $(BUILD_PATH),$(SRCM_PATH))
SRCB_BP			:= $(addprefix $(BUILD_PATH),$(SRCB_PATH))
SRCU_BP			:= $(addprefix $(BUILD_PATH),$(SRCU_PATH))

SRCM_FP			:= $(addprefix $(SRCM_PATH), $(SRCM_F))
SRCB_FP			:= $(addprefix $(SRCB_PATH), $(SRCB_F))
SRCU_FP			:= $(addprefix $(SRCU_PATH), $(SRCU_F))

SRCM			:= ${addprefix $(SRCM_PATH), $(SRCM_R)}
SRCB			:= ${addprefix $(SRCB_PATH), $(SRCB_R)}
SRCU			:= ${addprefix $(SRCU_PATH), $(SRCU_R)}

OBJM			:= $(addprefix $(BUILD_PATH),$(SRCM_F:.c=.o))
OBJB			:= $(addprefix $(BUILD_PATH),$(SRCB_F:.c=.o))
OBJU			:= $(addprefix $(BUILD_PATH),$(SRCU_F:.c=.o))

DEPSM			:= $(addprefix $(BUILD_PATH),$(SRCM_F:.c=.d))
DEPSB			:= $(addprefix $(BUILD_PATH),$(SRCB_F:.c=.d))
DEPSU			:= $(addprefix $(BUILD_PATH),$(SRCU_F:.c=.d))

CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -g
CFD := -MMD
RM	:= 	rm -Rf

HEADERM := ${addprefix $(SRCM_PATH), push_swap.h}
HEADERB := ${addprefix $(SRCB_PATH), push_swap_bonus.h}
HEADERU := ${addprefix $(SRCU_PATH), push_swap_utils.h}
LIBFT_H := ${addprefix $(LIBFT_PATH), libft.h}
LIBFT_A := ${addprefix $(LIBFT_PATH), libft.a}
LIBFT_D := ${addprefix $(LIBFT_PATH), libft.d}
LIBS_FLAGS := -I ${LIBFT_H}
LIBFT_D_CONT := $(shell cat ${LIBFT_D})

folder_create = $(shell mkdir -p $(1))

.SECONDEXPANSION:

${BUILD_PATH}%.o : %.c ${HEADERM} Makefile | $$(call folder_create,$$(dir $$@))
	${CC} ${CFLAGS} ${CFD} -I ${SRCM_PATH} -I ${SRCB_PATH} -I ${SRCU_PATH}\
		-I $(LIBFT_PATH) -I . -c $< -o $@

all : $(NAME)

$(BUILD_PATH):
	mkdir -p -m 777 $@

bonus : $(NAMEB)
	@touch $@

-include $(DEPS)
$(NAME) : ${LIBFT_A} ${OBJM} ${OBJU} Makefile
	${CC} ${CFLAGS} -I ${HEADERM} ${LIBS_FLAGS} ${OBJM} ${OBJU} ${LIBFT_A}  -o $@

-include $(DEPSB)
$(NAMEB) : ${LIBFT_A} ${OBJB} ${OBJU} Makefile
	${CC} ${CFLAGS} -I ${HEADERB} ${LIBS_FLAGS} ${OBJB} ${OBJU} ${LIBFT_A} -o $@

${LIBFT_A} : ${LIBFT_D_CONT}
	make -C libft

clean :
	@echo "Cleaning push_swap"
	$(RM) ${BUILD_PATH}
	$(RM) $(OBJM)
	$(RM) $(OBJB)
	$(RM) $(OBJU)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	$(RM) $(DEPSU)
	make clean -C libft

fclean : clean
	@echo "Full cleaning of push_swap"
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(RM) bonus
	make fclean -C libft

re: fclean all

.PHONY : clean fclean re all