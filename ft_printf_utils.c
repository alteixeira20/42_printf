/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:42:53 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/26 20:43:50 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_unnum_len(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_pf(int n)
{
	int		sign;
	int		len;
	char	*dest;

	len = ft_num_len(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}

char	*ft_utoa_pf(unsigned int n)
{
	char			*dest;
	unsigned int	len;

	len = ft_unnum_len(n);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = '0' + (n % 10);
		n /= 10;
	}
	return (dest);
}
