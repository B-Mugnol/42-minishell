/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 00:53:02 by llopes-n          #+#    #+#             */
/*   Updated: 2022/08/09 20:17:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lst(t_list *tk_lst);

int	main(void)
{
	t_var	*env_lst;
	t_var	*var_lst;
	t_list	*input_lst;
	char	*std_in;
	char	*shell_name;

	shell_name = "luluShell>";
	env_lst = set_node();
	var_lst = set_node();
	set_exit_status(&var_lst, EXIT_SUCCESS);
	sig_setup();
	while (1)
	{
		std_in = readline(shell_name);
		if (std_in == NULL)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		add_history(std_in);
		input_lst = tokenizer(std_in);
		print_lst(input_lst);
		ft_lstclear(&input_lst, delete_parse);
		free(std_in);
	}
	rl_clear_history();
	varlst_clear(&env_lst);
	varlst_clear(&var_lst);
	return (0);
}

void	set_exit_status(t_var**var_lst, int exit_status)
{
	varlst_add_var(var_lst, varlst_new(ft_strdup("?"), ft_itoa(exit_status)));
}

void	print_lst(t_list *tk_lst)
{
	while (tk_lst)
	{
		if (tk_lst->content != NULL)
			printf("%s:[%i]\n",
				((t_parse *)(tk_lst->content))->str,
				((t_parse *)(tk_lst->content))->type);
		tk_lst = tk_lst->next;
	}
}
