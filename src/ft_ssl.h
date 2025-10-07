/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2025/10/07 15:07:40 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//----------UTILS----------//
void    mess_error(int k, char *c);
int     check_com(char *str);
int     ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int     get_flags(char*** flag, char **input);
void	*tab_free(char **tab);
void	*ft_calloc(size_t count, size_t size);
// void	ft_bzero(void *s, size_t n);


void md5(const uint8_t *msg, int len, uint8_t digest[16]);

void    sha256(char **sstr);

#endif
