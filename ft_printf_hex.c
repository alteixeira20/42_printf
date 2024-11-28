/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:15:21 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/28 03:00:33 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *ptr)
{
	char	*hex_str;
	char	*output;
	int		printed_chars;

	if (ptr == NULL)
	{
		output = "(nil)";
		return (ft_putstr_pf(output));
	}
	hex_str = ft_itoa_base_pf((unsigned long)ptr, 16, 0);
	if (!hex_str)
		return (-1);
	output = ft_strjoin_pf("0x", hex_str);
	free(hex_str);
	if (!output)
		return (-1);
	printed_chars = ft_putstr_pf(output);
	free(output);
	return (printed_chars);
}

int	ft_printf_x(unsigned int num, t_parser *info, t_padding *pad)
{
	char	*hex_str;
	int		len;
	int		printed_chars;

	hex_str = ft_itoa_base_pf(num, 16, (info->specifier == 'X'));
	if (!hex_str)
		return (-1);
	len = ft_strlen_pf(hex_str);
	ft_calc_pad(info, len, 0, pad);
	printed_chars = ft_handle_sign_and_pad(info, 0, pad);
	ft_print_pad(pad->zeros, '0');
	printed_chars += pad->zeros + ft_putstr_pf(hex_str);
	if (info->flag_minus && pad->padding > 0)
	{
		ft_print_pad(pad->padding, ' ');
		printed_chars += pad->padding;
	}
	free(hex_str);
	return (printed_chars);
}
