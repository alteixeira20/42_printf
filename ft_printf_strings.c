/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:42:02 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/02 21:35:58 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strings(const char *str, t_parser *info, t_padding *pad)
{
	int	len;
	int	printed_chars;

	printed_chars = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen_pf(str);
	if (info->precision >= 0 && info->precision < len)
		len = info->precision;
	pad->padding = info->width - len;
	if (pad->padding < 0)
		pad->padding = 0;
	if (!info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	printed_chars += ft_putnstr_pf(str, len);
	if (info->flag_minus)
		printed_chars += ft_print_pad(pad->padding, ' ');
	return (printed_chars);
}
