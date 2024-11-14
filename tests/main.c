/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:41 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/14 17:56:56 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int	main(void)
{
	int res1;
	int res2;

	res1 = ft_printf("Character: %c\n", 'A');
	res2 = printf("Character: %c\n", 'A');
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("String: %s\n", "Hello, ft_printf!");
	res2 = printf("String: %s\n", "Hello, ft_printf!");
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Pointer: %p\n", &res1);
	res2 = printf("Pointer: %p\n", &res1);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Decimal: %d\n", 12345);
	res2 = printf("Decimal: %d\n", 12345);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Integer: %i\n", -6789);
	res2 = printf("Integer: %i\n", -6789);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Unsigned: %u\n", 4294967295U);
	res2 = printf("Unsigned: %u\n", 4294967295U);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex (lowercase): %x\n", 255);
	res2 = printf("Hex (lowercase): %x\n", 255);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex (uppercase): %X\n", 255);
	res2 = printf("Hex (uppercase): %X\n", 255);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Percent sign: %%\n");
	res2 = printf("Percent sign: %%\n");
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Multiple: %c %s %d %u %x %X %%\n", 'B', "Test", 42, 42U,
			42, 42);
	res2 = printf("Multiple: %c %s %d %u %x %X %%\n", 'B', "Test", 42, 42U, 42,
			42);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Mix: %s %p %i %X %c\n", "Mix", &res1, -123, 255, 'Z');
	res2 = printf("Mix: %s %p %i %X %c\n", "Mix", &res1, -123, 255, 'Z');
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Complex: %d %s %p %u %x %X %c %%\n", 123, "Complex",
			&res2, 123U, 123, 123, 'C');
	res2 = printf("Complex: %d %s %p %u %x %X %c %%\n", 123, "Complex", &res2,
			123U, 123, 123, 'C');
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Empty string: %s\n", "");
	res2 = printf("Empty string: %s\n", "");
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Null pointer: %p\n", NULL);
	res2 = printf("Null pointer: %p\n", NULL);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Large number: %d\n", 2147483647);
	res2 = printf("Large number: %d\n", 2147483647);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Negative large number: %d\n", -2147483648);
	res2 = printf("Negative large number: %ld\n", -2147483648);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Zero: %d\n", 0);
	res2 = printf("Zero: %d\n", 0);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Unsigned zero: %u\n", 0U);
	res2 = printf("Unsigned zero: %u\n", 0U);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex zero: %x\n", 0);
	res2 = printf("Hex zero: %x\n", 0);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex uppercase zero: %X\n", 0);
	res2 = printf("Hex uppercase zero: %X\n", 0);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Unsigned zero: %u\n", 0U);
	res2 = printf("Unsigned zero: %u\n", 0U);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex zero: %x\n", 0);
	res2 = printf("Hex zero: %x\n", 0);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex uppercase zero: %X\n", 0);
	res2 = printf("Hex uppercase zero: %X\n", 0);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Unsigned max: %u\n", UINT_MAX);
	res2 = printf("Unsigned max: %u\n", UINT_MAX);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex max: %x\n", UINT_MAX);
	res2 = printf("Hex max: %x\n", UINT_MAX);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Hex uppercase max: %X\n", UINT_MAX);
	res2 = printf("Hex uppercase max: %X\n", UINT_MAX);
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	res1 = ft_printf("Pointer 0: %p\n", 0);
	res2 = printf("Pointer 0: (nil)\n");
	printf(res1 == res2 ? GREEN "OK\n\n" RESET : RED "KO\n\n" RESET);

	return (0);
}
