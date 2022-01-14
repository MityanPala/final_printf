/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_libft_part.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoralie <gcoralie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:16:53 by gcoralie          #+#    #+#             */
/*   Updated: 2022/01/14 17:16:43 by gcoralie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_LIBFT_PART_H
# define GC_LIBFT_PART_H

# include <stddef.h>

size_t	gc_strlen(const char *s);
char	*gc_strchr(const char *s, int c);
char	*gc_strdup(const char *s);
char	*gc_strjoin(char const *s1, char const *s2);
size_t	gc_strlcpy(char *dst, const char *src, size_t size);

#endif
