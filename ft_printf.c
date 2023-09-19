/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:28 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 17:15:48 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_check(va_list list, const char str_index)
{
	size_t	length;

	length = 0;
	if (str_index == 'c')
		length += ft_printchar(va_arg(list, int));
	else if (str_index == 's')
		length += ft_printstr(va_arg(list, char *));
	else if (str_index == 'd' || str_index == 'i')
		length += ft_printnbr(va_arg(list, int));
	else if (str_index == 'p')
		length += ft_print_ptr(va_arg(list, unsigned long long));
	else if (str_index == 'u')
		length += ft_print_uint(va_arg(list, unsigned int));
	else if (str_index == 'x' || str_index == 'X')
		length += ft_print_hex(str_index, va_arg(list, unsigned int));
	else if (str_index == '%')
		length += ft_printchar('%');
	return ((int)length);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	length;
	size_t	index;

	va_start(list, str);
	length = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
			length += format_check(list, str[index++ + 1]);
		else
			length += ft_printchar(str[index]);
		index++;
	}
	va_end(list);
	return ((int)length);
}

// int	main(void)
// {
// 	char	a = 'a';
// 	char	b = 'b';
// 	char	*str = "cde";
// 	unsigned int	u_nbr = 2077918407;
// 	size_t	printf_nbr;
// 	size_t	ft_printf_nbr;

// 	ft_printf_nbr = ft_printf("%c %c %s %% %d\nptr = %p\n", a, b, str, 42, str);
// 	printf_nbr = printf("%c %c %s %% %d\nptr = %p\n", a, b, str, 42, str);

// 	printf("unsigned int %u\n", u_nbr);
// 	ft_printf("ft unsint %u\n", u_nbr);

// 	printf("%zu\n", ft_printf_nbr);
// 	printf("%zu\n", printf_nbr);

// 	printf("%++i\n",-42);

// 	return (0);
// }