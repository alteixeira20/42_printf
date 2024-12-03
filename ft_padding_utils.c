/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:10:51 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 19:11:18 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_str(t_parser *info, char *num_str, int len, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!num_str)
		num_str = "(null)";
	if (info->precision == 0)
		return (ft_print_pad(pad->padding, ' '));
	if (info->precision >= 0 && len > info->precision)
		len = info->precision;
	if (!info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(num_str, len);
	if (info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}

int	ft_handle_pad(t_parser *info, int num, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!info->flag_minus && pad->padding > 0)
	{
		if (info->flag_zero && info->precision == -1)
		{
			// Print the sign before zero-padding
			printed_chars += ft_handle_sign(info, num);
			printed_chars += ft_print_pad(pad->zeros, '0');
		}
		else
		{
			printed_chars += ft_print_pad(pad->padding, ' ');
			// Print the sign after padding if no zero-padding
			printed_chars += ft_handle_sign(info, num);
		}
	}
	else
	{
		// Print the sign directly for left-aligned or no padding
		printed_chars += ft_handle_sign(info, num);
	}
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
	if (info->precision == 0)
		len = 0;
	else if (info->precision >= 0 && len > info->precision)
		len = info->precision;
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
}

void ft_calc_numeric_pad(t_parser *info, int len, int num, t_padding *pad)
{
    int prefix_len = 0;

    // Prefix length for hash flag or signs
    if (info->flag_hash && num != 0 && (info->specifier == 'x' || info->specifier == 'X'))
        prefix_len = 2; // Add "0x" or "0X"

    // Adjust length for empty number representation when precision is `.0`
    if (info->precision == 0 && num == 0)
        len = 0;

    if (info->specifier != 'u' && (num < 0 || info->flag_plus || info->flag_space))
        prefix_len++; // Space for "-", "+" or " "

    // Zero padding logic
    if (info->precision > len)
        pad->zeros = info->precision - len;
    else if (info->flag_zero && !info->flag_minus && info->precision == -1)
        pad->zeros = info->width - (len + prefix_len);
    else
        pad->zeros = 0;

    // Space padding logic
    pad->padding = info->width - (len + pad->zeros + prefix_len);
    if (pad->padding < 0)
        pad->padding = 0;
}
