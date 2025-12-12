/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:42:59 by alebaron          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:57 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     char str[] = "Lorem ipsum The leader at Cyllage Gym in Rock Pokémon.";
// 	printf("------------ Fonction libc ------------\n");
//     printf("\nBefore bzero(): %s\n\n", str);
//     bzero(str + 11, 6);
//     printf("After bzero(): %s\n\n", str);
// 	printf("------------ Fonction a moi ------------\n");
// 	char str1[] = "Lorem ipsum The leader at Cyllage Gym in Rock Pokémon.";
// 	printf("\nBefore bzero(): %s\n\n", str1);
//     ft_bzero(str1 + 11, 6);
//     printf("After bzero(): %s\n\n", str1);

//     return 0;
// }