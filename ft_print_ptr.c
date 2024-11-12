/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:51 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/12 23:25:06 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned long n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += print_hex(n / 16);
	len += write(1, &hex[n % 16], 1);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int len;
	len = 0;

	len += write(1, "0x", 2);
	len += print_hex((unsigned long)ptr);
	return (len);
}