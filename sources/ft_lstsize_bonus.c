/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:25:41 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/24 16:11:27 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		som;
	t_list	*tmp;

	tmp = lst;
	som = 0;
	while (tmp)
	{
		som++;
		tmp = tmp->next;
	}
	return (som);
}
