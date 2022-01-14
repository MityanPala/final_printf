/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_conversion_output.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:00:59 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 17:17:24 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_CONVERSION_OUTPUT_H
# define GC_CONVERSION_OUTPUT_H

int		output_char(char arg);
int		output_str(char *arg);
int		output_ptr(void *arg);
int		output_dec(int arg);
int		output_uint(unsigned int arg);
int		output_hex_lowercase(unsigned int arg);
int		output_hex_uppercase(unsigned int arg);
int		output_other(char arg);

char	*ulint_to_hex(char conversion, unsigned long num, int grid_flag);
char	*gc_ulitoa_base(unsigned long n, char *base);
char	*gc_itoa(int n);

#endif
