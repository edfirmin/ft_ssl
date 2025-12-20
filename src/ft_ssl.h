/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2025/12/18 04:41:48 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
	int p;
    int q;
    int r;
	int s;
} t_flag;

//----------UTILS----------//
void    mess_error(int k, char *c);
// int     ft_strlen(char *str);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(char *s1);
int     check_com(char *str);
void 	check_opt(char **input);
// void	*tab_free(char **tab);
// void	*ft_calloc(size_t count, size_t size);
// void	ft_bzero(void *s, size_t n);

void    md5(const __uint8_t *msg, int len, __uint8_t outp[16]);
void 	main_md5(char *src, int is_str, t_flag *flg);
void 	print_all_md5(uint8_t hash[16], char *input, t_flag flg, int is_string);
void 	handle_stdin_md5(t_flag flg);

void    sha256(const __uint8_t *msg, int len, __uint8_t outp[32]);
void 	main_sha256(char *src, int is_str, t_flag *flg);
void 	print_all_sha256(uint8_t hash[32], char *input, t_flag flg, int is_string);
void 	handle_stdin_sha256(t_flag flg);


#endif
