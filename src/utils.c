/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:26:54 by edfirmin          #+#    #+#             */
/*   Updated: 2025/09/24 12:35:28 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void mess_error(int k, char *c){
    if (c){
        printf("ft_ssl: Error: '%s' is an invalid command.\n\n", c);
        k = 1;
    }
    char* mess[] = {
        "usage: ft_ssl command [flags] [file/string]",
        "Commands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s",
        ""
    };
    printf("%s\n", mess[k]);
}

int check_com(char *str){
    char* comms[] = {
        "md5",
        "sha256"
    };
    for (int i = 0; i < 2; i++){
        if (!strcmp(str, comms[i]))
            return(i);
        continue;
    }
    return (2);
}