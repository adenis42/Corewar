/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 11:55:29 by nolivier          #+#    #+#             */
/*   Updated: 2017/09/25 10:31:41 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_print_fork(t_process *process, t_settings *sets, int val)
{
	if (!(((sets->options & VERBOSITY) && (sets->options & OPERATIONS))))
		return ;
	if (val & 0x8000)
		val = -(val ^ 0xffff) - 1;
	ft_printf("P%5d | fork %d (%d)\n", process->num, val,
	process->proc_counter + (val % IDX_MOD));
}

int			ft_fork(t_settings *sets, t_process *process, t_process **begin)
{
	unsigned char	*index;
	unsigned int	counter;
	unsigned int	i;

	if (++process->cycle_count < (g_op_tab + 11)->cycles)
		return (1);
	counter = 0;
	i = 0xffffffff;
	while (++i < 2)
		counter |= (sets->memory[(process->proc_counter + 1 + i) % MEM_SIZE]
		<< ((1 - i) * 8));
	index = (!(counter & 0x8000)) ? (sets->memory + ((process->proc_counter +
	(counter % IDX_MOD)) % MEM_SIZE)) : (sets->memory + ((process->proc_counter
	- (((counter ^ 0xffff) + 1)) % IDX_MOD)) % MEM_SIZE);
	ft_print_fork(process, sets, counter);
	ft_print_pc_move(process, sets, 3);
	ft_graph_process(process, sets);
	process->cycle_count = 0;
	if (!ft_create_process(begin, process, index, sets))
		return (0);
	process->proc_counter = (process->proc_counter + 3) % MEM_SIZE;
	return (1);
}
