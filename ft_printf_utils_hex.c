/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:16:05 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 03:42:55 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_templen(unsigned long num, int base, int len)
{
	unsigned long	temp;

	temp = num / base;
	while (temp > 0)
	{
		temp /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_pf(unsigned long num, int base, int uppercase)
{
	int		len;
	char	*dest;
	char	*digits;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = 1;
	len = ft_templen(num, base, len);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = digits[num % base];
		num /= base;
	}
	return (dest);
}

char	*ft_ptr_to_hex(void *ptr)
{
	char	*hex;
	char	*result;

	hex = ft_itoa_base_pf((unsigned long)ptr, 16, 0);
	if (!hex)
		return (NULL);
	result = ft_strjoin_pf("0x", hex);
	free(hex);
	return (result);
}