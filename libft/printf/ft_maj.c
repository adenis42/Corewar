/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:43:02 by khabbar           #+#    #+#             */
/*   Updated: 2017/03/10 09:43:11 by khabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

void	ft_maj(char **rec)
{
	int		i;

	i = -1;
	while ((*rec)[++i])
	{
		if ((*rec)[i] > 96 && (*rec)[i] < 123)
			(*rec)[i] -= 32;
	}
}
