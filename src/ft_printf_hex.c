/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:15:21 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:39:54 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_null_pointer(t_parser *info, t_padding *pad)
{
	char	*output;
	int		len;
	int		printed_chars;

	output = "(nil)";
	len = ft_strlen_pf(output);
	printed_chars = 0;
	ft_calc_string_pad(info, len, pad);
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(output, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}

int	ft_printf_p(void *ptr, t_parser *info, t_padding *pad)
{
	char	*hex_str;
	char	*output;
	int		len;
	int		printed_chars;

	printed_chars = 0;
	if (ptr == NULL)
		return (handle_null_pointer(info, pad));
	hex_str = ft_itoa_base_pf((unsigned long)ptr, 16, 0);
	if (!hex_str)
		return (-1);
	output = ft_strjoin_pf("0x", hex_str);
	free(hex_str);
	if (!output)
		return (-1);
	len = ft_strlen_pf(output);
	ft_calc_string_pad(info, len, pad);
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(output, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
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
	ft_calc_numeric_pad(info, len, num, pad);
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
	printed_chars += ft_putnstr_pf(hex_str, len);
	if (info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	free(hex_str);
	return (printed_chars);
}
