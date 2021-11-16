/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:45:53 by ebonamic          #+#    #+#             */
/*   Updated: 2021/11/10 21:14:51 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *pattern, ...)
{
	va_list	arguments;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(arguments, pattern);
	while (pattern[i] != '\0')
	{
		if (pattern[i] == '%')
		{
			i++;
			len = len + ft_type(arguments, pattern[i]);
		}
		else
			len = len + write(1, &pattern[i], 1);
		i++;
	}
	va_end(arguments);
	return (len);
}

int	ft_type(va_list arguments, char type)
{
	if (type == 'c')
		return (ft_type_char(va_arg(arguments, int)));
	else if (type == 's')
		return (ft_type_string(va_arg(arguments, char *)));
	else if (type == 'p')
		return (ft_type_pointer(va_arg(arguments, unsigned long)));
	else if (type == 'd' || type == 'i')
		return (ft_type_decimal(va_arg(arguments, int)));
	else if (type == 'u')
		return (ft_type_bases(va_arg(arguments, unsigned int), "0123456789"));
	else if (type == 'x')
		return (ft_type_bases(va_arg(arguments, \
		unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_type_bases(va_arg(arguments, \
		unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
