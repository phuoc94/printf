/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:27:36 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/14 17:48:12 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long nb)
{
	int	len;
	int	result;

	result = 0;
	len = 0;
	if (nb < 0)
	{
		result = ft_print_char('-');
		if (result == -1)
			return (result);
		len += result;
		nb = -nb;
	}
	if (nb >= 10)
	{
		result = ft_print_nbr(nb / 10);
		if (result == -1)
			return (result);
		len += result;
	}
	result = ft_print_char('0' + (nb % 10));
	if (result == -1)
		return (result);
	len += result;
	return (len);
}
