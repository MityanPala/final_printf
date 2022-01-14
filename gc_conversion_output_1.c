/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_conversion_output_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:35 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 18:16:05 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "gc_libft_part.h"
#include "gc_conversion_output.h"

/*	Returns string (that must be freed after function call) that contains
	unsigned int converted to hex. Conversion must be 'x' or 'X' and if
	grid_flag flag is set to 1, it prepends "0x" и "0X" depening on
	conversion symbol */
char	*ulint_to_hex(char conversion, unsigned long num, int grid_flag)
{
	char	*res;
	char	*buff;

	if (num == 0)
		return (gc_strdup("0"));
	if (conversion == 'x')
	{
		buff = gc_ulitoa_base(num, "0123456789abcdef");
		if (grid_flag != 1)
			return (buff);
		res = gc_strjoin("0x", buff);
		free(buff);
	}
	if (conversion == 'X')
	{
		buff = gc_ulitoa_base(num, "0123456789ABCDEF");
		if (grid_flag != 1)
			return (buff);
		res = gc_strjoin("0X", buff);
		free(buff);
	}
	return (res);
}

int	output_char(char arg)
{
	int		res;
	char	*str;

	str = gc_strdup("_");
	str[0] = arg;
	res = gc_putnstr_fd(str, 1, 1, 1);
	free(str);
	if (res == 0)
		return (-1);
	return (res);
}

int	output_str(char *arg)
{
	int		res;
	char	*str;

	str = arg;
	if (arg == NULL)
		str = "(null)";
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	return (res);
}

int	output_dec(int arg)
{
	int		res;
	char	*str;

	str = gc_itoa(arg);
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	free(str);
	if (res == 0)
		return (-1);
	return (res);
}
