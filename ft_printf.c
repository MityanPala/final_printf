/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:54:40 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 18:04:51 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"
#include "gc_libft_part.h"
#include "gc_conversion_output.h"

static int	output_argument(va_list *aptr, char *conv);

int	ft_printf(const char *fs, ...)
{
	va_list	aptr;
	int		print_len;
	int		total_len;
	char	*fs_ptr;
	char	conv;

	va_start(aptr, fs);
	fs_ptr = (char *)fs;
	total_len = 0;
	while (fs_ptr != NULL)
	{
		conv = 0;
		fs_ptr = gc_parse_format_string(fs_ptr, &conv, &print_len);
		total_len += print_len;
		print_len = output_argument(&aptr, &conv);
		if (print_len == -1)
			return (total_len);
		total_len += print_len;
	}
	va_end(aptr);
	return (total_len);
}

static int	output_argument(va_list *aptr, char *conv)
{
	int	res;

	res = -1;
	if (*conv == (char) 'c')
		res = output_char((char)(va_arg(*aptr, int)));
	if (*conv == (char) 's')
		res = output_str(va_arg(*aptr, char *));
	if (*conv == (char) 'p')
		res = output_ptr(va_arg(*aptr, void *));
	if ((*conv == (char) 'd') || (*conv == (char) 'i'))
		res = output_dec(va_arg(*aptr, int));
	if (*conv == (char) 'u')
		res = output_uint(va_arg(*aptr, unsigned int));
	if (*conv == (char) 'x')
		res = output_hex_lowercase(va_arg(*aptr, unsigned int));
	if (*conv == (char) 'X')
		res = output_hex_uppercase(va_arg(*aptr, unsigned int));
	if (*conv == (char) '%' || *conv == (char) '\0'
		|| (gc_strchr("cspdiuxX", (int)(*conv)) == NULL))
		res = output_other(*conv);
	return (res);
}

/*	Output 'len' symbols from string 's' to 'fd' 'count' times */
int	gc_putnstr_fd(char *s, int fd, int len, int count)
{
	int	i;

	i = 0;
	if (count < 0)
		count = 0;
	while (i < count)
	{
		write(fd, (void *)s, len);
		++i;
	}
	return (len * i);
}
