/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:54:00 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 18:17:51 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "gc_libft_part.h"
#include "gc_conversion_output.h"

static void		gc_reverse_str(char *s);
static size_t	gc_calc_base_len(unsigned long n, unsigned long base_len);
static size_t	gc_calc_len(int n);

/*	Unsigned long to base: base is a string that contains symbolic 
	alphabet for reqiured base (as example: "0123456789abcdef" for HEX).
	Works fine for length of the base that can be stored in unsigned 
	long int */
char	*gc_ulitoa_base(unsigned long n, char *base)
{
	char			*res;
	char			*buf;
	unsigned long	base_len;

	base_len = (unsigned long)gc_strlen(base);
	res = malloc(sizeof(char) * (gc_calc_base_len(n, base_len) + 1));
	if (res == NULL)
		return (NULL);
	*(res + gc_calc_base_len(n, base_len)) = '\0';
	buf = res;
	if (n == 0)
		*buf = '0';
	while (n > 0)
	{
		*buf = base[n % base_len];
		n = n / base_len;
		++buf;
	}
	gc_reverse_str(res);
	return (res);
}

static size_t	gc_calc_base_len(unsigned long n, unsigned long base_len)
{
	size_t	len;

	len = 0;
	if (n == 0)
		++len;
	while (n > 0)
	{
		n = n / base_len;
		++len;
	}
	return (len);
}

static void	gc_reverse_str(char *s)
{
	size_t	len;
	size_t	mid;
	size_t	i;
	char	buff;

	len = gc_strlen(s);
	mid = len / 2 + len % 2;
	i = 0;
	while (i < mid)
	{
		buff = *(s + i);
		*(s + i) = *(s + len - 1 - i);
		*(s + len - 1 - i) = buff;
		++i;
	}
}

char	*gc_itoa(int n)
{
	char			*res;
	char			*buf;
	unsigned int	un;

	res = (char *)malloc(sizeof(char) * (gc_calc_len(n) + 1));
	if (res == NULL)
		return (NULL);
	*(res + gc_calc_len(n)) = '\0';
	buf = res;
	un = n;
	if (n < 0)
		un = n * (-1);
	if (n == 0)
		*buf = '0';
	while (un > 0)
	{
		*buf = (char)(un % 10 + '0');
		un = un / 10;
		++buf;
	}
	if (n < 0)
		*buf = '-';
	gc_reverse_str(res);
	return (res);
}

static size_t	gc_calc_len(int n)
{
	size_t			len;
	unsigned int	un;

	len = 0;
	un = n;
	if (n < 0)
	{
		un = n * (-1);
		++len;
	}
	if (n == 0)
		++len;
	while (un > 0)
	{
		un = un / 10;
		++len;
	}
	return (len);
}
