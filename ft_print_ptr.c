/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:51 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/13 16:16:34 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned long n, int uppercase)
{
	const char	*hex;
	int		len;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += print_hex((n / 16), uppercase);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int len;
	len = 0;

	len += write(1, "0x", 2);
	len += print_hex((unsigned long)ptr, 0);
	return (len);
}