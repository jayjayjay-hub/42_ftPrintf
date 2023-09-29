/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:38 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/29 12:14:01 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_to_char(char *str, unsigned long number, int len)
{
	while (number > 0)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	return (str);
}

static int	ft_nbrlen(unsigned int n)
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
	int				len_nbr;
	unsigned long	number;

	len_nbr = ft_nbrlen(nbr);
	str = (char *)malloc((len_nbr + 1));
	number = nbr;
	if (!(str))
		return (NULL);
	str[len_nbr] = '\0';
	len_nbr--;
	if (number == 0)
		str[0] = '0';
	str = ft_to_char(str, number, len_nbr);
	return (str);
}
