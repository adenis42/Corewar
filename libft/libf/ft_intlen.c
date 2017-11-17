/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:46:43 by khabbar           #+#    #+#             */
/*   Updated: 2017/03/16 17:08:58 by khabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libftprintf.h"

size_t		ft_intlen(size_t nbr)
{
	size_t	len;

	len = 1;
	while ((nbr /= 10) > 0)
		len += 1;
	return (len);
}