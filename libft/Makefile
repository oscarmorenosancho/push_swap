# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:10:43 by omoreno-          #+#    #+#              #
#    Updated: 2023/10/28 21:44:56 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_memchr.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c

SRCB := ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c

SRCGNL := get_next_line_utils.c\
		get_next_line.c

SRCX := ft_copy_pos.c\
	ft_linelen.c\
	ft_lstdeletewhere.c\
	ft_lstreverse.c\
	ft_every_in_line.c\
	ft_log_error.c\
	ft_lstevery.c\
	ft_lstrreduce.c\
	ft_findfirst_with_pos.c\
	ft_lstdeletenode.c\
	ft_lstfindfirst.c\
	ft_strreduce.c\
	ft_str_merge.c\
	ft_str_join_char.c

SRCU := ft_sort_int_tab.c\
	ft_clone_int_tab.c\
	ft_tabiteri.c\
	ft_find_first_int.c\
	ft_max_min.c

SRCDLL := ft_dllstnew.c\
	ft_dllstadd_front.c\
	ft_dllstsize.c\
	ft_dllstlast.c\
	ft_dllstadd_back.c\
	ft_dllstdelone.c\
	ft_dllstclear.c\
	ft_dllstiter.c\
	ft_dllstiterrev.c\
	ft_dllstmap.c\
	ft_dllst_extract.c\
	ft_dllst_push.c\
	ft_dllst_revrotate.c\
	ft_dllst_rotate.c\
	ft_dllst_swap.c\
	ft_dllstfindfirstnode.c\
	ft_dllstfindfirstnoderev.c\
	ft_dllst_reduce.c

LIBFT_PATH		:= libft/
MAND_PATH		:= src/
BONUS_PATH		:= src_bonus/
GNL_PATH		:= get_next_line/
X_PATH			:= src_extra/
DLL_PATH		:= src_dl_list/
UTILS_PATH		:= src_utils/
BUILD_PATH		:= .build/

SRCM_F			:= $(addprefix $(MAND_PATH), $(SRC))
SRCB_F			:= $(addprefix $(BONUS_PATH), $(SRCB))
SRCGNL_F		:= $(addprefix $(GNL_PATH), $(SRCGNL))
SRCX_F			:= $(addprefix $(X_PATH), $(SRCX))
SRCDLL_F		:= $(addprefix $(DLL_PATH), $(SRCDLL))
SRCU_F			:= $(addprefix $(UTILS_PATH), $(SRCU))

SRC_FP			:= $(addprefix $(LIBFT_PATH), $(SRC_F))
SRCB_FP			:= $(addprefix $(LIBFT_PATH), $(SRCB_F))
SRCGNL_FP		:= $(addprefix $(LIBFT_PATH), $(SRCGNL_F))
SRCX_FP			:= $(addprefix $(LIBFT_PATH), $(SRCX_F))
SRCDLL_FP		:= $(addprefix $(LIBFT_PATH), $(SRCDLL_F))
SRCU_FP			:= $(addprefix $(LIBFT_PATH), $(SRCU_F))

OBJM			:= $(addprefix $(BUILD_PATH),$(SRCM_F:.c=.o))
OBJB			:= $(addprefix $(BUILD_PATH),$(SRCB_F:.c=.o))
OBJGNL			:= $(addprefix $(BUILD_PATH),$(SRCGNL_F:.c=.o))
OBJX			:= $(addprefix $(BUILD_PATH),$(SRCX_F:.c=.o))
OBJDLL			:= $(addprefix $(BUILD_PATH),$(SRCDLL_F:.c=.o))
OBJU			:= $(addprefix $(BUILD_PATH),$(SRCU_F:.c=.o))

DEPS			:= $(addprefix $(BUILD_PATH),$(SRCM_F:.c=.d))
DEPSB			:= $(addprefix $(BUILD_PATH),$(SRCB_F:.c=.d))
DEPSGNL			:= $(addprefix $(BUILD_PATH),$(SRCGNL_F:.c=.d))
DEPSX			:= $(addprefix $(BUILD_PATH),$(SRCX_F:.c=.d))
DEPSDLL			:= $(addprefix $(BUILD_PATH),$(SRCDLL_F:.c=.d))
DEPSU			:= $(addprefix $(BUILD_PATH),$(SRCU_F:.c=.d))

CC				:= 	@gcc
CFLAGS			:= -Wall -Werror -Wextra -MMD -g
RM				:= 	@rm -Rf
LIBC			:= 	@ar -rcs
HEADER			:= libft.h 
MAND_H			:= $(addprefix $(MAND_PATH), libft_mand.h)
BONUS_H			:= $(addprefix $(BONUS_PATH), libft_bonus.h)
GNL_H			:= $(addprefix $(GNL_PATH), get_next_line.h)
X_H				:= $(addprefix $(X_PATH), libft_extra.h)
DLL_H			:= $(addprefix $(DLL_PATH), dl_list.h)
UTILS_H			:= $(addprefix $(UTILS_PATH), utils.h)
MAND_HP			:= $(addprefix $(LIBFT_PATH), $(MAND_H))
BONUS_HP		:= $(addprefix $(LIBFT_PATH), $(BONUS_H))
GNL_HP			:= $(addprefix $(LIBFT_PATH), $(GNL_H))
X_HP			:= $(addprefix $(LIBFT_PATH), $(X_H))
DLL_HP			:= $(addprefix $(LIBFT_PATH), $(DLL_H))
UTILS_HP		:= $(addprefix $(LIBFT_PATH), $(UTILS_H))
HEADER_FP		:= $(addprefix $(LIBFT_PATH), $(HEADER))
ALL_HEADERS		:= ${MAND_H} ${BONUS_H} ${GNL_H} ${X_H} ${DLL_H} ${UTILS_H} $(HEADER)
ALL_HEADERS_FP	:= $(addprefix $(LIBFT_PATH), $(ALL_HEADERS)) 

folder_create = $(shell mkdir -p $(1))

.SECONDEXPANSION:

$(BUILD_PATH)%.o: %.c ${HEADER} | $$(call folder_create,$$(dir $$@))
	@echo "Compiling " $@ " ..."
	${CC} ${CFLAGS} -I ${LIBFT_PATH} -I ${MAND_PATH} -I ${BONUS_PATH} \
		-I ${GNL_PATH} -I ${X_PATH} -I ${DLL_PATH} -I ${UTILS_PATH} \
			-c $< -o $@

all : $(NAME)

$(BUILD_PATH):
	mkdir -p -m 777 $@

-include $(DEPMS) $(DEPSB) $(DEPSDLL) $(DEPSGNL) $(DEPSDLL) $(DEPSX) $(DEPSU)
$(NAME) : $(OBJM) $(OBJB) $(OBJGNL) $(OBJX) $(OBJDLL) $(OBJU) ${ALL_HEADERS}
	@echo "Linking " $@ " ..."
	$(LIBC) $(NAME) $(OBJM) $(OBJB) $(OBJX) $(OBJGNL) $(OBJDLL) $(OBJU)
	@echo $(SRC_FP) $(SRCB_FP) $(SRCGNL_FP) $(SRCX_FP) $(SRCDLL_FP) $(SRCU_FP)\
		${ALL_HEADERS_FP} > $(NAME:.a=.d)

clean :
	@echo "Cleaning libft"
	$(RM) ${BUILD_PATH}

fclean : clean
	@echo "Full cleaning of libft"
	$(RM) $(NAME)
	$(RM) *.d

re: fclean all

.PHONY : clean fclean re all
