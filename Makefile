SRCFILES	= ft_printf.c gc_conversion_output_1.c gc_conversion_output_2.c gc_libft_part.c gc_parse_format_string.c gc_ulitoa_base.c

OBJFILES	= $(SRCFILES:.c=.o)

DEPFILES	= $(SRCFILES:.c=.d)

LN			= libftprintf.a

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -MMD

%.o:	%.c
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

${LN}:	${OBJFILES}
		ar rcu ${LN} ${OBJFILES}

all:	${LN}

-include $(DEPFILES)

clean:	
		${RM} ${OBJFILES} ${DEPFILES}

fclean:	clean
		${RM} ${LN}

re:		fclean all

.PHONY:	all clean fclean re