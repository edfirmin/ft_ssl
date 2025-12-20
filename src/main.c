/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:37:43 by edfirmin          #+#    #+#             */
/*   Updated: 2025/12/18 04:30:35 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

//./ft_ssl md5 $'ff\n'  pour tester avec le '\n' inclue dans l'input

void go_sha256 (char **av, int ac){
    t_flag flg = {0, 0, 0, 0};
    for (int i = 2; i < ac; i++) {

        if (!strcmp(av[i], "-q")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.q = 1;
            continue; //pour skip tout et refaire la boucle / pour pas hasher le "-q" en gros
        }
        if (!strcmp(av[i], "-r")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.r = 1;
            continue;//
        }
        if (!strcmp(av[i], "-p")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.p = 1;
            handle_stdin_sha256(flg);
            continue;//
        }
        if (!strcmp(av[i], "-s")) {
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.s = 1; 
            main_sha256(av[++i], 1, &flg);
            continue;//
        }
        main_sha256(av[i], 0, &flg);
    }
    if (!isatty(0) && !flg.p)
        handle_stdin_sha256(flg);
}

void go_md5 (char **av, int ac){
    t_flag flg = {0, 0, 0, 0};
    for (int i = 2; i < ac; i++) {

        if (!strcmp(av[i], "-q")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.q = 1;
            continue; //pour skip tout et refaire la boucle / pour pas hasher le "-q" en gros
        }
        if (!strcmp(av[i], "-r")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.r = 1;
            continue;//
        }
        if (!strcmp(av[i], "-p")){
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.p = 1;
            handle_stdin_md5(flg);
            continue;//
        }
        if (!strcmp(av[i], "-s")) {
            // if (++i >= ac)
            //     return mess_error(0, NULL), 1;
            flg.s = 1; 
            main_md5(av[++i], 1, &flg);
            continue;//
        }
        main_md5(av[i], 0, &flg);
    }
    if (!isatty(0) && !flg.p)
        handle_stdin_md5(flg);
}

int main(int ac, char** av){
    if (ac < 2)
        return mess_error(0, NULL), 0;
    else if (check_com(av[1]) == 2)
        return mess_error(667, av[1]), 0;
    
    check_opt(&av[2]);
    //check si les param son bon

    void (*fonc[])(char**, int) = {
        go_md5,
        go_sha256
    };
    fonc[check_com(av[1])](av, ac);
    return (1);
}

    // char **flags;

    // int i = 0;
    // i = get_flags(&flags, &av[2]);
    // // printf("i = %d\n", i);
    // int j = 0;
    // while (j < i){
    //     printf("flag = %s\n", flags[j]);
    //     j++;
    // }
    // printf ("%s\n", av[i + 2]);

    // if ((!strcmp("md5", av[1]))){
    //     while (av[i + 2])
    //     {
    //         __uint8_t result[16]; 
    //         md5((const __uint8_t*)av[i + 2], ft_strlen(av[i + 2]), result);
    //         print_md5(result, flags);
    //     }
    // }
    // else {
    //     while (av[i + 2]){
    //         __uint8_t result[32];
    //         sha256((const __uint8_t*)av[i + 2], ft_strlen(av[i + 2]), result);
    //         print_sha256(result, flags);
    //     }
    // }
    // if (i)
    //     tab_free(flags);
    
    // main_du_main();
    // print_all();

    // __uint8_t result[16];
    // md5((const __uint8_t*)av[i + 2], ft_strlen(av[i + 2]), result);
    // printf("MD5(\"%s\") = ", av[i + 2]);
    // for (int r = 0; r < 16; r++)
    //     printf("%02x", result[r]);
    // printf("\n");

    // __uint8_t result[32];
    // printf ("%s\n", av[2]);
    // sha256((const __uint8_t*)av[2], ft_strlen(av[2]), result);
    // for (int i=0; i<32; i++)
    //     printf("%02x", result[i]);
    // printf("\n");