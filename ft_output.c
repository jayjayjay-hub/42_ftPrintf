/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:24:18 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/05 16:35:33 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	size_t	index;

	index = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	else
	{
		while (str[index])
			write(1, &str[index++], 1);
		return ((int)ft_strlen(str));
	}
}

int	ft_printnbr(int nbr)
{
	int		len_nbr;
	char	*num;

	num = ft_itoa(nbr);
	len_nbr = ft_printstr(num);
	free(num);
	return (len_nbr);
}
