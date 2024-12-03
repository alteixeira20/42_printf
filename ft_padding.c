/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:37:12 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 06:35:36 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad(int len, char c)
{
	int	counter;

	counter = 0;
	while (len > 0)
	{
		ft_putchar_pf(c);
		len--;
		counter++;
	}
	return (counter);
}

int	ft_handle_nb(t_parser *info, char *num_str, int len, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (info->specifier == 's')
	{
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
	if (!(info->precision == 0 && num_str[0] == '0'))
	{
		ft_putnstr_pf(num_str, ft_strlen_pf(num_str));
		printed_chars += len;
	}
	if (info->flag_minus && pad->padding > 0)
	{
		ft_print_pad(pad->padding, ' ');
		printed_chars += pad->padding;
	}
	return (printed_chars);
}

int	ft_handle_sign_and_pad(t_parser *info, int num, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (!info->flag_minus && pad->padding > 0)
	{
		if (info->flag_zero && info->precision == -1)
		{
			if ((info->specifier == 'd' || info->specifier == 'i') && num < 0)
			{
				printed_chars += ft_putchar_pf('-');
				num = -num;
			}
			else if (info->specifier != 'u' && info->flag_plus)
				printed_chars += ft_putchar_pf('+');
			else if (info->specifier != 'u' && info->flag_space)
				printed_chars += ft_putchar_pf(' ');
			printed_chars += ft_print_pad(pad->zeros, '0');
		}
		else
		{
			printed_chars += ft_print_pad(pad->padding, ' ');
			if ((info->specifier == 'd' || info->specifier == 'i') && num < 0)
			{
				printed_chars += ft_putchar_pf('-');
				num = -num;
			}
			else if (info->specifier != 'u' && info->flag_plus)
				printed_chars += ft_putchar_pf('+');
			else if (info->specifier != 'u' && info->flag_space)
				printed_chars += ft_putchar_pf(' ');
		}
	}
	if (info->flag_minus || (!info->flag_zero && pad->padding == 0))
	{
		if ((info->specifier == 'd' || info->specifier == 'i') && num < 0)
		{
			printed_chars += ft_putchar_pf('-');
			num = -num;
		}
		else if (info->specifier != 'u' && info->flag_plus)
			printed_chars += ft_putchar_pf('+');
		else if (info->specifier != 'u' && info->flag_space)
			printed_chars += ft_putchar_pf(' ');
	}
	return (printed_chars);
}

void	ft_calc_pad(t_parser *info, int len, int num, t_padding *pad)
{
	int	prefix_len;

	pad->zeros = 0;
	if (info->specifier == 's')
	{
		if (info->precision == 0)
			len = 0;
		else if (info->precision >= 0 && len > info->precision)
			len = info->precision;
		pad->padding = info->width - len;
		if (pad->padding < 0)
			pad->padding = 0;
		return ;
	}
	prefix_len = 0;
	if (info->specifier == 'x' || info->specifier == 'X')
	{
		if (info->flag_hash && num != 0)
			prefix_len = 2;
	}
	if (info->precision > len)
		pad->zeros = info->precision - len;
	else if (info->flag_zero && !info->flag_minus && info->precision == -1)
		pad->zeros = info->width - len;
	if (num < 0 || info->flag_plus || info->flag_space)
		prefix_len++;
	pad->padding = info->width - (len + pad->zeros + prefix_len);
	if (pad->padding < 0)
		pad->padding = 0;
}
