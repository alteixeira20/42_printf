/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:37:13 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/02 21:33:35 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(const char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen_pf(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_pf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnstr_pf(const char *str, int n)
{
	int	i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

char	*ft_strjoin_pf(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc((ft_strlen_pf(s1) + ft_strlen_pf(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
