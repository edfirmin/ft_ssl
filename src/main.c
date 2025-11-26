/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:37:43 by edfirmin          #+#    #+#             */
/*   Updated: 2025/11/26 10:46:10 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

//./ft_ssl md5 $'ff\n'  pour tester avec le '\n' inclue dans l'input

int main(int ac, char** av){
    if (ac < 2){
        mess_error(0, NULL);
		return (0);
	}
    else if (check_com(av[1]) == 2){
        mess_error(667, av[1]);
        return (0);
    }
    // void (*fonc[])(char **) = {
    //     md5,
    //     sha256
    // };
    char **flags;

    int i = get_flags(&flags, &av[2]);
    printf("i = %d\n", i);
    int j = 0;
    while (j < i){
        printf("flag = %s\n", flags[j]);
        j++;
    }
    // tab_free(flags);

    // __uint8_t result[16];
    // md5((const __uint8_t*)av[i + 2], ft_strlen(av[i + 2]), result);
    // printf("MD5(\"%s\") = ", av[i + 2]);
    // for (int r = 0; r < 16; r++)
    //     printf("%02x", result[r]);
    // printf("\n");

    __uint8_t result[32];
    sha256((const __uint8_t*)av[i + 2], ft_strlen(av[i + 2]), result);

    return (1);
}
