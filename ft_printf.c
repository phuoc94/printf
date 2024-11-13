/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:02 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/13 19:27:19 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_print_nbr(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1));
	else if (c == '%')
		return (ft_print_char('%'));
	else
		return (ft_print_char(c));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		result_len;

	i = 0;
	result_len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			result_len += handle_format(str[i], &args);
		}
		else
			result_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result_len);
}
