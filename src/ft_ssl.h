/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:46:59 by edfirmin          #+#    #+#             */
/*   Updated: 2025/09/30 12:58:48 by edfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//----------UTILS----------//
void    mess_error(int k, char *c);
int     check_com(char *str);
int     ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int     get_flags(char*** flag, char **input);
void	*tab_free(char **tab);


void    md5(char **sstr);
void    sha256(char **sstr);

#endif
