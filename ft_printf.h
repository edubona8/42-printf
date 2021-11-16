/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:56:53 by ebonamic          #+#    #+#             */
/*   Updated: 2021/11/09 11:48:24 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *pattern, ...);
int		ft_type(va_list arguments, char type);

int		ft_type_char(int chr);
int		ft_type_string(char *str);
int		ft_type_pointer(unsigned long pointer);
int		ft_type_decimal(int decimal);
int		ft_type_bases(unsigned int x, char *base);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_convert_base(size_t number, char *base);
char	*ft_uitoa(unsigned int number);

#endif
