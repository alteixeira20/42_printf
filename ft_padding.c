/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:37:12 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/02 23:25:27 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_diu(t_parser *info)
{
	if (info->specifier == 'd' || info->specifier == 'i')
		return (1);
	if (info->specifier == 'u')
		return (1);
	return (0);
}

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
	if (!(info->precision == 0 && num_str[0] == '0'))
	{
		ft_putstr_pf(num_str);
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
	if (info->flag_minus == 0 && pad->padding > 0)
	{
		if (info->flag_zero == 1 && info->precision == -1)
		{
			ft_print_pad(pad->padding, '0');
			printed_chars += pad->padding;
		}
		else
		{
			ft_print_pad(pad->padding, ' ');
			printed_chars += pad->padding;
		}
	}
	if (ft_is_diu(info))
	{
		if (num >= 0 && info->flag_plus == 1)
			printed_chars += ft_putchar_pf('+');
		else if (num >= 0 && info->flag_space == 1)
			printed_chars += ft_putchar_pf(' ');
	}
	return (printed_chars);
}

void	ft_calc_pad(t_parser *info, int len, int num, t_padding *pad)
{
	pad->zeros = 0;
	if (info->precision > len)
		pad->zeros = info->precision - len;
	if (info->flag_hash && num != 0 && ft_is_diu(info))
		len += 2;
	if (info->precision == 0 && num == 0)
		len = 0;
	pad->padding = info->width - (len + pad->zeros);
	if ((info->flag_plus || info->flag_space) && num >= 0 && ft_is_diu(info))
		(pad->padding)--;
}
