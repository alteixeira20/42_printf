/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:15:21 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 06:38:40 by paalexan         ###   ########.fr       */
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
		return (ft_putnstr_pf(output, ft_strlen_pf(output)));
	}
	hex_str = ft_itoa_base_pf((unsigned long)ptr, 16, 0);
	if (!hex_str)
		return (-1);
	output = ft_strjoin_pf("0x", hex_str);
	free(hex_str);
	if (!output)
		return (-1);
	printed_chars = ft_putnstr_pf(output, ft_strlen_pf(output));
	free(output);
	return (printed_chars);
}

int	ft_printf_x(unsigned int num, t_parser *info, t_padding *pad)
{
	char	*hex_str;
	int		len;
	int		printed_chars;

	printed_chars = 0;
	hex_str = ft_itoa_base_pf(num, 16, (info->specifier == 'X'));
	if (!hex_str)
		return (-1);
	len = ft_strlen_pf(hex_str);
	ft_calc_pad(info, len, num, pad);
	if (info->precision == 0 && num == 0)
	{
		free(hex_str);
		return (ft_print_pad(pad->padding, ' '));
	}
	if (!info->flag_minus && pad->padding > 0)
		if (!(info->flag_zero && info->precision == -1))
			printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_handle_hash(num, info);
	printed_chars += ft_print_pad(pad->zeros, '0');
	printed_chars += ft_putnstr_pf(hex_str, ft_strlen_pf(hex_str));
	if (info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	free(hex_str);
	return (printed_chars);
}
