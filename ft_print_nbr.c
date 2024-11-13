/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:36 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/13 18:59:30 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_print_nbr(nb / 10);
	len += ft_print_char('0' + (nb % 10));
	return (len);
}
