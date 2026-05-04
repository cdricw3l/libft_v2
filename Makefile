CC			:=cc
AR			:=ar -rcs
GFLAGS		:=-Wall -Wextra -Werror -g
NAME		:=libft.a
ASSERT_NAME	:= myLibftTester/assert_test
SRCS		:=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

SRCS_ASSERT := ${filter-out myLibftTester/draft.c, ${wildcard myLibftTester/*.c}}

OBJETS_SRCS		:=	${SRCS:.c=.o}
OBJETS_ASSERT	:=	${SRCS_ASSERT:.c=.o} ${OBJETS_SRCS}

%.o:%.c
	${CC} -c  ${GFLAGS} $^ -o $@

${NAME}:	${OBJETS_SRCS}
	${AR} ${NAME} ${OBJETS_SRCS}

as: ${OBJETS_ASSERT}
	${CC} ${GFLAGS} -lbsd ${OBJETS_ASSERT} -o ${ASSERT_NAME}
ifeq (${shell uname} , Darwin)
	${shell export MallocStackLogging=1}
	leaks -list  --atExit --  ./${ASSERT_NAME}
else
	valgrind --leak-check=full --show-leak-kinds=all -s ./${ASSERT_NAME}
endif

clean:
	rm -f ${OBJETS_SRCS} ${OBJETS_ASSERT}
	rm -rf test*

fclean: clean
	rm -f ${NAME} ${ASSERT_NAME} draft

re: fclean ${NAME}

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}


draft:
	gcc myLibftTester/draft.c -L. -lft -lbsd -o draft

t: draft
	./draft

.PHONY: draft
