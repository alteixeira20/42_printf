/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:37:13 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/27 23:06:29 by diogomordaça    ###   ########.fr       */
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

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_pf(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_pf("(null)"));
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}
