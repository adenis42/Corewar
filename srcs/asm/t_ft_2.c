/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ft_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:34:29 by adenis            #+#    #+#             */
/*   Updated: 2017/10/10 16:37:10 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	ft_name(t_output *pop)
{
	pop->name = ft_strsub(pop->name, ft_strchr(pop->name, '"') - pop->name + 1,
		ft_strrchr(pop->name, '"') - ft_strchr(pop->name, '"') - 1);
	return ;
}

void	ft_ncom(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 1;
	pop->val = 0;
}

void	ft_indir(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 2;
	pop->val = ft_atoi(pop->name);
}

void	ft_inst(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 1;
	if (g_op_tab[whichop(pop->name)].coding_param)
		pop->size++;
	pop->val = whichop(pop->name) + 1;
	if (pop->size > 1)
		pop->val = pop->val << 8 | ft_opc(pop);
}

void	ft_reg(t_output *pop)
{
	if (!pop->name)
		return ;
	pop->size = 1;
	pop->val = ft_atoi(&(pop->name)[1]);
}