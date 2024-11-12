/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:02 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/12 23:33:57 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	int result_len;

	i = 0;
	result_len = 0;

	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == 'c')
				result_len += ft_print_char(va_arg(args, int));
			else if (str[i] == 's')
				result_len += ft_print_str(va_arg(args, char *));
			else if (str[i] == 'p')
				result_len += ft_print_ptr(va_arg(args, void *));
		}
		else
			result_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result_len);
}