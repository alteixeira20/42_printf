/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/26 21:02:53 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parser_flags(const char **form, t_parser *info)
{
	while (**form == '-' || **form == '+' || **form == '0' || **form == ' ')
	{
		if (**form == '-')
			info->flag_minus = 1;
		if (**form == '+')
			info->flag_plus = 1;
		if (**form == '0')
			info->flag_zero = 1;
		if (**form == ' ')
			info->flag_space = 1;
		(*form)++;
	}
}

static void	ft_parser_width(const char **format, t_parser *info)
{
	while (**format >= '0' && **format <= '9')
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	ft_parser_precision(const char **format, t_parser *info)
{
	if (**format == '.')
	{
		info->precision = 0;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			info->precision = info->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
}

static int	ft_parser_specifier(const char **format, t_parser *info)
{
	if (**format == 'd' || **format == 'i' || **format == 'u')
	{
		info->specifier = **format;
		(*format)++;
		return (1);
	}
	else
		return (0);
}

int	ft_parser_numbers(const char **format, t_parser *info)
{
	(*format)++;
	ft_parser_flags(format, info);
	ft_parser_width(format, info);
	ft_parser_precision(format, info);
	return (ft_parser_specifier(format, info));
}
