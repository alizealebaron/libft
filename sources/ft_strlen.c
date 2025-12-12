/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:47:09 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/17 11:23:32 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	somme;

	somme = 0;
	while (s[somme])
		somme++;
	return (somme);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char string[] = "CanardCoin";

// 	printf("ft_strlen(%s) = %ld\n", string, ft_strlen(string));
// 	printf("   strlen(%s) = %ld"  , string,    strlen(string));

// 	return (-1);
// }