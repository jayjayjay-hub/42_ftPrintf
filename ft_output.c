/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:24:18 by jtakahas          #+#    #+#             */
/*   Updated: 2023/09/28 17:58:44 by jtakahas         ###   ########.fr       */
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
		write(1, &*str, ft_strlen(str));
		return ((int)ft_strlen(str));
	}
}

int	ft_printnbr(int nbr)
{
	char	*str_nbr;
	int		len;

	str_nbr = ft_itoa(nbr);
	len = ft_printstr(str_nbr);
	free(str_nbr);
	return (len);
}
