/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_numbers_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:42:53 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 18:21:31 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	int		len;
	char	*dest;

	if (n == INT_MIN)
		return (ft_strdup_pf("2147483648"));
	if (n < 0)
		n = -n;
	len = ft_num_len(n);
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

char	*ft_utoa_pf(unsigned long n)
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
