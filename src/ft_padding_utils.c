/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:10:51 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:37:38 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_str(t_parser *info, char *str, int len, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!str)
	{
		if (info->precision >= 0)
			str = "";
		else
			str = "(null)";
	}
	if (info->precision >= 0 && len > info->precision)
		len = info->precision;
	ft_calc_string_pad(info, len, pad);
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(str, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}

int	ft_handle_pad(t_parser *info, int num, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_handle_sign(info, num);
	if (pad->zeros > 0)
		printed_chars += ft_print_pad(pad->zeros, '0');
	return (printed_chars);
}

int	ft_handle_sign(t_parser *info, int num)
{
	int	printed_chars;

	printed_chars = 0;
	if ((info->specifier == 'd' || info->specifier == 'i') && num < 0)
		printed_chars += ft_putchar_pf('-');
	else if (info->specifier != 'u' && info->flag_plus)
		printed_chars += ft_putchar_pf('+');
	else if (info->specifier != 'u' && info->flag_space)
		printed_chars += ft_putchar_pf(' ');
	return (printed_chars);
}

void	ft_calc_string_pad(t_parser *info, int len, t_padding *pad)
{
	if (info->precision >= 0 && len > info->precision)
		len = info->precision;
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
}

void	ft_calc_numeric_pad(t_parser *info, int len, int num, t_padding *pad)
{
	int	prefix_len;

	prefix_len = 0;
	if (info->flag_hash && num != 0)
		if (info->specifier == 'x' || info->specifier == 'X')
			prefix_len = 2;
	if (info->precision == 0 && num == 0)
		len = 0;
	if (info->specifier == 'd' || info->specifier == 'i')
	{
		if (num < 0 || info->flag_plus || info->flag_space)
			prefix_len++;
	}
	if (info->precision > len)
		pad->zeros = info->precision - len;
	else
		pad->zeros = 0;
	pad->padding = info->width - (len + pad->zeros + prefix_len);
	if (pad->padding < 0)
		pad->padding = 0;
	if (info->flag_zero && !info->flag_minus && info->precision == -1)
	{
		pad->zeros = pad->padding;
		pad->padding = 0;
	}
}
