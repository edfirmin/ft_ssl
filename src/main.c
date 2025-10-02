/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:37:43 by edfirmin          #+#    #+#             */
/*   Updated: 2025/09/30 13:06:32 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int main(int ac, char** av){
    if (ac < 2){
        mess_error(0, NULL);
		return (0);
	}
    else if (check_com(av[1]) == 2){
        mess_error(667, av[1]);
        return (0);
    }
    // printf ("c'est good");
    void (*fonc[])(char **) = {
        md5,
        sha256
    };
    char **flags;

    int i = get_flags(&flags, &av[2]);
    printf("i = %d\n", i);
    int j = 0;
    while (j < i){
        printf("flag = %s\n", flags[j]);
        j++;
    }
    // tab_free(flags);
    printf("la suite: %s\n", av[i + 2]);
    fonc[0] (&av[i + 2]);
    return (1);
}
