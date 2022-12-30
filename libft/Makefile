# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:10:43 by omoreno-          #+#    #+#              #
#    Updated: 2022/12/30 14:10:13 by omoreno-         ###   ########.fr        #
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
	ft_find_first_int.c

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
	ft_dllstfindfirst.c\
	ft_dllstfindfirstrev.c\
	ft_dllstfindfirstnode.c\
	ft_dllstfindfirstnoderev.c

LIBFT_PATH := libft/
SRC_PATH := src/
BONUS_PATH := src_bonus/
GNL_PATH := get_next_line/
X_PATH := src_extra/
DLL_PATH := src_dl_list/
UTILS_PATH := src_utils/

SRC_F := $(addprefix $(SRC_PATH), $(SRC))
SRCB_F := $(addprefix $(BONUS_PATH), $(SRCB))
SRCGNL_F := $(addprefix $(GNL_PATH), $(SRCGNL))
SRCX_F := $(addprefix $(X_PATH), $(SRCX))
SRCDLL_F := $(addprefix $(DLL_PATH), $(SRCDLL))
SRCU_F := $(addprefix $(UTILS_PATH), $(SRCU))

SRC_FP := $(addprefix $(LIBFT_PATH), $(SRC_F))
SRCB_FP := $(addprefix $(LIBFT_PATH), $(SRCB_F))
SRCGNL_FP := $(addprefix $(LIBFT_PATH), $(SRCGNL_F))
SRCX_FP := $(addprefix $(LIBFT_PATH), $(SRCX_F))
SRCDLL_FP := $(addprefix $(LIBFT_PATH), $(SRCDLL_F))
SRCU_FP := $(addprefix $(LIBFT_PATH), $(SRCU_F))

OBJ := $(SRC_F:.c=.o)
OBJB := $(SRCB_F:.c=.o)
OBJGNL := $(SRCGNL_F:.c=.o)
OBJX := $(SRCX_F:.c=.o)
OBJDLL := $(SRCDLL_F:.c=.o)
OBJU := $(SRCU_F:.c=.o)

DEPS := $(SRC_F:.c=.d)
DEPSB := $(SRCB_F:.c=.d)
DEPSGNL := $(SRCGNL_F:.c=.d)
DEPSX := $(SRCX_F:.c=.d)
DEPSDLL := $(SRCDLL_F:.c=.d)
DEPSU := $(SRCU_F:.c=.d)

CC	:= 	gcc
CFLAGS := -Wall -Werror -Wextra -MMD
RM	:= 	rm -f
LIBC	:= 	ar -rcs
HEADER := libft.h 
MAND_H := $(addprefix $(SRC_PATH), libft_mand.h)
BONUS_H := $(addprefix $(BONUS_PATH), libft_bonus.h)
GNL_H := $(addprefix $(GNL_PATH), get_next_line.h)
X_H := $(addprefix $(X_PATH), libft_extra.h)
DLL_H := $(addprefix $(DLL_PATH), dl_list.h)
UTILS_H := $(addprefix $(UTILS_PATH), utils.h)
MAND_HP := $(addprefix $(LIBFT_PATH), $(MAND_H))
BONUS_HP := $(addprefix $(LIBFT_PATH), $(BONUS_H))
GNL_HP := $(addprefix $(LIBFT_PATH), $(GNL_H))
X_HP := $(addprefix $(LIBFT_PATH), $(X_H))
DLL_HP := $(addprefix $(LIBFT_PATH), $(DLL_H))
UTILS_HP := $(addprefix $(LIBFT_PATH), $(UTILS_H))
HEADER_FP := $(addprefix $(LIBFT_PATH), $(HEADER)) 

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

all : $(NAME)

-include $(DEPS)
$(NAME) : $(OBJ) $(HEADER) $(MAND_H)
	$(LIBC) $(NAME) $(OBJ)
	@echo $(SRC_FP) $(HEADER_FP) $(MAND_HP) > $(NAME:.a=.d)

-include $(DEPSB)
bonus: $(OBJ) $(OBJB) $(OBJGNL) $(OBJX) $(OBJDLL) $(OBJU) $(HEADER) $(MAND_H) $(GNL_H) $(X_H) $(BONUS_H) $(DLL_H) $(UTILS_H)
	$(LIBC) $(NAME) $(OBJ) $(OBJB) $(OBJX) $(OBJGNL) $(OBJDLL) $(OBJU)
	@echo $(SRC_FP) $(SRCB_FP) $(SRCGNL_FP) $(SRCX_FP) $(SRCDLL_FP) $(SRCU_FP)\
		$(HEADER_FP) $(MAND_HP) $(BONUS_HP) $(GNL_HP) $(X_HP) $(DLL_HP) > $(NAME:.a=.d)
	@touch $@

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJB)
	$(RM) $(OBJGNL)
	$(RM) $(OBJX)
	$(RM) $(OBJDLL)
	$(RM) $(OBJU)
	$(RM) $(DEPS)
	$(RM) $(DEPSB)
	$(RM) $(DEPSGNL)
	$(RM) $(DEPSX)
	$(RM) $(DEPSDLL)
	$(RM) $(DEPSU)

fclean : clean
	$(RM) $(NAME)
	$(RM) bonus
	$(RM) *.d

re: fclean all

.PHONY : clean fclean re all
