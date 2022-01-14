/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_parse_format_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:19:01 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 18:06:30 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_printf.h"
#include "gc_libft_part.h"

static char	*gc_set_flag_state(char *fs, char *conv);

char	*gc_parse_format_string(char *fs, char *conv, int *symbols_printed)
{
	char	*res;

	if (*fs == '\0')
	{
		*symbols_printed = 0;
		return (NULL);
	}
	res = gc_strchr(fs, '%');
	if (res == NULL)
		*symbols_printed = gc_putnstr_fd(fs, 1, gc_strlen(fs), 1);
	else
	{
		*symbols_printed = gc_putnstr_fd(fs, 1, res - fs, 1);
		++res;
		res = gc_set_flag_state(res, conv);
	}
	return (res);
}

static char	*gc_set_flag_state(char *fs, char *conv)
{
	char	*conversion_flags;

	conversion_flags = "cspdiuxX%";
	if ((*fs != '\0') && (gc_strchr(conversion_flags, *fs) != NULL))
	{
		*conv = *fs;
		++fs;
	}
	return (fs);
}
