/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:49 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/19 17:48:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int n, int base)
{
	char	*res;
	int		len;
	char	buf[17];

	res = NULL;
	ft_strcpy(buf, "0123456789ABCDEF");
	len = ft_nbrlen_base(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		res[len - 1] = buf[ft_abs(n % base)];
		n = n / base;
		len--;
	}
	return (res);
}
