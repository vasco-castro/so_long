/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:50 by vsoares-          #+#    #+#             */
/*   Updated: 2026/05/02 22:13:21 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	exit_so_long(char *error)
{
	ft_dprintf(2, RED "Error\n%s\n" RESET, error);
	free_game();
	exit(EXIT_FAILURE);
}

void	exit_successfully(char *sucess)
{
	ft_printf(BIGREEN "%s\n" RESET, sucess);
	free_game();
	exit(EXIT_SUCCESS);
}
