/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:26:54 by edfirmin          #+#    #+#             */
/*   Updated: 2025/10/07 14:36:54 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_bzero(void *s, size_t n){
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size){
	void	*mem;

	if (count == 0 || size == 0)
	{
		mem = malloc(0);
		return (mem);
	}
	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}

int ft_strlen(char *str){
    int i = 0;

    while (str[i]){
        i++;
    }
    return i;
}

char	*ft_strjoin(char *s1, char *s2){
	char	*str;
	int		i = 0;
	int		j = 0;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (str)
	{
		while (s1[j]){
			str[i++] = s1[j++];
		}
		j = 0;
		while (s2[j]){
			str[i++] = s2[j++];
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1){
	int		i = 0;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == 0)
		return (0);
	while (s1[i]){
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

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

int check_flag(char* str){
    char* flags[] = {
        "p",
        "q",
        "r",
        "s"
    };
    for (int i = 0; flags[i]; i++){
        if (!strcmp(str, flags[i]))
            return 1;
        continue;
    }
    return 0;
}

int get_flags(char*** flag, char **input){
    int i = 0;
    int j = 0;

    while (input[i]){
        if(input[i][0] == '-' && check_flag(&input[i][1]))
            j++;
        else
            break;
        i++;
    }
    if (!j)
        return 0;
    *flag = (char **)malloc((j + 1) * sizeof(char *));
    (*flag)[j] = NULL;
    i = 0;
    while (i < j){
        (*flag)[i] = ft_strdup(input[i]);
        i++;
    }
    return j;
}

void	*tab_free(char **tab){
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
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