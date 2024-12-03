/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:42:02 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 06:25:47 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_precision(t_parser *info)
{
	const char	*null_str;
	char		*truncated;

	null_str = "(null)";
	if (info->precision == 0)
		return (ft_strdup_pf(""));
	if (info->precision > 0)
	{
		truncated = ft_strdup_pf(null_str);
		if (!truncated)
			return (NULL);
		if (info->precision < ft_strlen_pf(null_str))
			truncated[info->precision] = '\0';
		return (truncated);
	}
	return (ft_strdup_pf(null_str));
}

static int	handle_width_and_alignment(t_parser *info, t_padding *pad)
{
	char	*truncated;
	int		len;
	int		printed_chars;

	printed_chars = 0;
	truncated = handle_precision(info);
	if (!truncated)
		return (0);
	len = ft_strlen_pf(truncated);
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
	if (!info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(truncated, ft_strlen_pf(truncated));
	if (info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	free(truncated);
	return (printed_chars);
}

int	ft_printf_strings(const char *str, t_parser *info, t_padding *pad)
{
	int		len;
	int		printed_chars;

	if (!str)
		return (handle_width_and_alignment(info, pad));
	printed_chars = 0;
	if (info->precision >= 0)
	{
		if (info->precision < ft_strlen_pf(str))
			len = info->precision;
		else
			len = ft_strlen_pf(str);
	}
	else
		len = ft_strlen_pf(str);
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
	if (!info->flag_minus && pad->padding > 0)
		printed_chars += ft_print_pad(pad->padding, ' ');
	if (len > 0)
		printed_chars += ft_putnstr_pf(str, len);
	if (info->flag_minus && pad->padding > 0)
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
