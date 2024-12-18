/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:42:02 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/05 17:27:43 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_null_string(t_parser *info, t_padding *pad)
{
	const char	*null_str = "(null)";
	int			len;
	int			printed_chars;

	printed_chars = 0;
	if (info->precision >= 0 && info->precision < 6)
		len = 0;
	else
	{
		len = ft_strlen_pf(null_str);
		if (info->precision >= 0 && info->precision < len)
			len = info->precision;
	}
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	if (len > 0)
		printed_chars += ft_putnstr_pf(null_str, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}

int	ft_printf_strings(const char *str, t_parser *info, t_padding *pad)
{
	int	len;
	int	printed_chars;

	printed_chars = 0;
	if (!str)
		return (handle_null_string(info, pad));
	len = ft_strlen_pf(str);
	if (info->precision >= 0 && info->precision < len)
		len = info->precision;
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	if (len > 0)
		printed_chars += ft_putnstr_pf(str, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}

int	ft_printf_char(char c, t_parser *info, t_padding *pad)
{
	int	printed_chars;

	printed_chars = 0;
	if (info->width > 1)
		pad->padding = info->width - 1;
	else
		pad->padding = 0;
	if (!info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putchar_pf(c);
	if (info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}
