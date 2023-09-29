/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:52:00 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/29 12:16:09 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_char(char *str, long number, int len)
{
	while (number > 0)
	{
		str[len] = 48 + (number % 10);
		number /= 10;
		len--;
	}
	return (str);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_n;
	long	number;

	len_n = ft_numlen(n);
	str = (char *)malloc((len_n + 1));
	number = n;
	if (!(str))
		return (NULL);
	str[len_n] = '\0';
	len_n--;
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		number *= -1;
		str[0] = '-';
	}
	str = ft_to_char(str, number, len_n);
	return (str);
}
