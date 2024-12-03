/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:37:12 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 07:05:59 by paalexan         ###   ########.fr       */
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
		return (ft_handle_str(info, num_str, len, pad));
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
	printed_chars += ft_handle_pad(info, num, pad);
	if (info->flag_minus || (!info->flag_zero && pad->padding == 0))
		printed_chars += ft_handle_sign(info, num);
	return (printed_chars);
}

void	ft_calc_pad(t_parser *info, int len, int num, t_padding *pad)
{
	if (info->specifier == 's')
	{
		ft_calc_string_pad(info, len, pad);
		return ;
	}
	ft_calc_numeric_pad(info, len, num, pad);
}
