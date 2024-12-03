/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:28:35 by paalexan          #+#    #+#             */
/*   Updated: 2024/12/03 06:00:11 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parser_flags(const char **f, t_parser *info)
{
	while (**f == '-' || **f == '+' || **f == '0' || **f == ' ' || **f == '#')
	{
		if (**f == '-')
			info->flag_minus = 1;
		if (**f == '+')
			info->flag_plus = 1;
		if (**f == '0')
			info->flag_zero = 1;
		if (**f == ' ')
			info->flag_space = 1;
		if (**f == '#')
			info->flag_hash = 1;
		(*f)++;
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
	else if (**format == '%' || **format == 'c' || **format == 's')
	{
		info->specifier = **format;
		(*format)++;
		return (1);
	}
	else if (**format == 'p' || **format == 'x' || **format == 'X')
	{
		info->specifier = **format;
		(*format)++;
		return (1);
	}
	else
		return (0);
}

int	ft_parser(const char **format, t_parser *info)
{
	(*format)++;
	ft_parser_flags(format, info);
	ft_parser_width(format, info);
	ft_parser_precision(format, info);
	if (!ft_parser_specifier(format, info))
		return (0);
	if (info->specifier == 'u')
	{
		info->flag_plus = 0;
		info->flag_space = 0;
	}
	if (info->specifier == 'x' || info->specifier == 'X')
	{
		info->flag_plus = 0;
		info->flag_space = 0;
	}
	return (1);
}
