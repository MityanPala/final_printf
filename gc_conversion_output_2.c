/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_conversion_output_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:38 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 20:26:59 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "gc_libft_part.h"
#include "gc_conversion_output.h"

/*	Output for conversion specifier % and if no other valid specifier found */
int	output_other(char arg)
{
	int		res;
	char	*str;

	if (arg == '\0')
		return (0);
	res = 0;
	str = gc_strdup("_");
	if (arg == '%')
	{
		str[0] = '%';
		res = gc_putnstr_fd(str, 1, 1, 1);
	}
	if (res == 0)
		return (-1);
	free(str);
	return (res);
}

int	output_ptr(void *arg)
{
	int		res;
	char	*str;

	if (arg == NULL)
		str = gc_strdup("0x0");
	else
	{
		str = ulint_to_hex('x', (unsigned long)arg, 1);
	}
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	if (res == 0)
		return (-1);
	free(str);
	return (res);
}

int	output_uint(unsigned int arg)
{
	int		res;
	char	*str;

	str = gc_ulitoa_base((unsigned long)arg, "0123456789");
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	free(str);
	if (res == 0)
		return (-1);
	return (res);
}

int	output_hex_lowercase(unsigned int arg)
{
	int		res;
	char	*str;

	str = ulint_to_hex('x', (unsigned long)arg, 0);
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	if (res == 0)
		return (-1);
	free(str);
	return (res);
}

int	output_hex_uppercase(unsigned int arg)
{
	int		res;
	char	*str;

	str = ulint_to_hex('X', (unsigned long)arg, 0);
	res = gc_putnstr_fd(str, 1, gc_strlen(str), 1);
	if (res == 0)
		return (-1);
	free(str);
	return (res);
}
