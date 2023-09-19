/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:38 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 16:26:56 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_char(char *str, unsigned long number, int len)
{
	while (number > 0)
	{
		str[len] = 48 + (number % 10);
		number /= 10;
		len--;
	}
	return (str);
}

static int	ft_numlen(unsigned int n)
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

char	*ft_uitoa(unsigned int nbr)
{
	char			*str;
	int				len;
	unsigned long	number;

	len = ft_numlen(nbr);
	str = (char *)malloc((len + 1));
	number = nbr;
	if (!(str))
		return (NULL);
	str[len] = '\0';
	len--;
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		number *= -1;
		str[0] = '-';
	}
	str = ft_to_char(str, number, len);
	return (str);
}
