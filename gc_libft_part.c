/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_libft_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:17:29 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 17:52:37 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "gc_libft_part.h"

char	*gc_strchr(const char *s, int c)
{
	int		len;
	int		str_len;
	char	uc;

	uc = (char)c;
	str_len = gc_strlen(s);
	if (uc == '\0')
		return ((char *)(s + str_len));
	len = 0;
	while (len < str_len)
	{
		if (*(s + len) == uc)
			return ((char *)(s + len));
		++len;
	}
	return (NULL);
}

size_t	gc_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (*(s + res) != '\0')
		++res;
	return (res);
}

char	*gc_strdup(const char *s)
{
	char	*res;
	char	*buf;

	res = (char *)malloc(sizeof(char) * (gc_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	buf = res;
	while (*s != '\0')
	{
		*buf = *s;
		++buf;
		++s;
	}
	*buf = '\0';
	return (res);
}

char	*gc_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = gc_strlen(s1);
	if (s2 != NULL)
		len2 = gc_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	*(res + len1 + len2) = '\0';
	gc_strlcpy(res, s1, len1 + 1);
	gc_strlcpy(res + len1, s2, len2 + 1);
	return (res);
}

size_t	gc_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	src_len;

	src_len = gc_strlen(src);
	if (size == 0)
		return (src_len);
	res = 0;
	while (res < (size - 1))
	{
		*(dst + res) = *(src + res);
		if (*(src + res) == '\0')
			return (src_len);
		++res;
	}
	*(dst + res) = '\0';
	return (src_len);
}
