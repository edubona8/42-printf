/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:12:32 by ebonamic          #+#    #+#             */
/*   Updated: 2021/11/09 23:28:26 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	if (destsize > 0)
	{
		while (src[i] != '\0' && (i < (destsize - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	if (destsize == 0)
		dest[ft_strlen(dest)] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_convert_base(size_t number, char *base)
{
	int		len;
	char	*n_base;
	size_t	base_len;
	size_t	aux;

	base_len = ft_strlen(base);
	len = 0;
	aux = number;
	if (number == 0)
		len = 1;
	while (aux > 0)
	{
		aux /= base_len;
		len++;
	}
	n_base = malloc(sizeof(char) * (len + 1));
	if (!n_base)
		return (NULL);
	n_base[len] = '\0';
	while (len-- > 0)
	{
		n_base[len] = base[number % base_len];
		number /= base_len;
	}
	return (n_base);
}

char	*ft_uitoa(unsigned int number)
{
	char			*str;
	int				len;
	unsigned int	aux;

	aux = number;
	len = 0;
	if (number == 0)
		len = 1;
	while (aux > 0)
	{
		aux /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
