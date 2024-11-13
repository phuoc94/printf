/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:36 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/13 18:13:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_print_char('-');
		len += ft_print_char('2');
		len += ft_print_nbr(147483648);
		return (len);
	}
	if (nb < 0)
	{
		len += ft_print_char('-');
		nb = -nb;
		len += ft_print_nbr(nb);
		return (len);
	}
	if (nb >= 10)
	{
		len += ft_print_nbr(nb / 10);
	}
	len += ft_print_char('0' + (nb % 10));
	return (len);
}
