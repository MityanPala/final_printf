/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:54:38 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 16:49:21 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *fs, ...);
char	*gc_parse_format_string(char *fs, char *conv, int *symbols_printed);
int		gc_putnstr_fd(char *s, int fd, int len, int count);

#endif
