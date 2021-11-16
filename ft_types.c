/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:11:10 by ebonamic          #+#    #+#             */
/*   Updated: 2021/11/05 23:59:00 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_char(int chr)
{
	return (write(1, &chr, sizeof(char)));
}

int	ft_type_string(char *str)
{
	if (!str)
		str = "(null)";
	return (write(1, str, ft_strlen(str) * sizeof(char)));
}

int	ft_type_pointer(unsigned long pointer)
{
	char	*str;
	char	*aux;
	int		len;

	str = ft_convert_base(pointer, "0123456789abcdef");
	aux = str;
	str = ft_strjoin("0x", aux);
	free(aux);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	ft_type_decimal(int decimal)
{
	char	*str;
	char	sign;
	int		len;

	sign = 0;
	len = 0;
	if (decimal < 0)
	{
		str = ft_uitoa(-(long)decimal);
		sign = 1;
	}
	else
		str = ft_uitoa(decimal);
	if (sign == 1)
		len = write(1, "-", sizeof(char));
	len += write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	ft_type_bases(unsigned int x, char *base)
{
	char	*str;
	int		len;

	str = ft_convert_base(x, base);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}
