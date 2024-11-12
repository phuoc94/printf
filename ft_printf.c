/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:02 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/12 15:06:39 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(div);
	}
	ft_putchar('0' + mod);
}

int ft_printf(const char *str, ...)
{

	int i;
	va_list	args;
	i = 0;


	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if(str[i] == 'c')
				ft_putchar(va_arg(args, int));
			else if(str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(args, int));

		}else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);

	return (0);
}
int main()
{
    int result = ft_printf("H%s, worl%c.\n", "ello", 'd');

	(void)result;
	return (0);
}
