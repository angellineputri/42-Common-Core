/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfasius <dfasius@student.42.sg>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 07:42:25 by dfasius           #+#    #+#             */
/*   Updated: 2024/12/16 07:42:26 by dfasius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_my_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	if (argc > 1 || !argv)
		return (1);
	mini = (t_mini){0};
	init_mini(&mini, &envp);
	rl_catch_signals = 0;
	while (1)
	{
		g_my_signal = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		new_line(&envp, &mini);
	}
	return (0);
}
