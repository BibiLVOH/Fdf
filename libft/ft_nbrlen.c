/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:50:17 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/13 15:53:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int i)
{
	int		taille;

	taille = 0;
	if (i < 0)
	{
		taille = 1;
		i = -i;
	}
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		taille++;
	}
	return (taille);
}
