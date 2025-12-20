/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edilson <edilson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:26:54 by edfirmin          #+#    #+#             */
/*   Updated: 2025/12/18 04:57:53 by edilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int file_open;

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
        "-p",
        "-q",
        "-r",
        "-s",
		NULL
    };
    for (int i = 0; flags[i]; i++){
        if (!strcmp(str, flags[i]))
            return 1;
        continue;
    }
    return 0;
}

void check_opt(char **input){
    int i = 0;
    int j = 0;

	// printf("buggggg 1\n");
    while (input[i]){
        if(input[i][0] == '-' && !check_flag(input[i])){
			// printf("buggggg 2 %s\n", input[i]);
			j = 667;
        	break;
		}
		i++;
    }
	if (j != 0){
		printf("Error : invalide options; valide options:\n-p\n-q\n-r\n-s\n");
		exit(1);
	}
}

int check_com(char *str){
    char* comms[] = {
        "md5",
        "sha256",
		NULL
    };
    for (int i = 0; i < 2; i++){
        if (!strcmp(str, comms[i]))
            return(i);
        continue;
    }
    return (2);
}




//----------------------------------------MD5---------------------------------------//
void main_md5(char *src, int is_str, t_flag *flg) {

    uint8_t hash[16];
    struct stat status;

    if (!is_str && stat(src, &status) == 0 && S_ISREG(status.st_mode)) {

        int fd = open(src, O_RDONLY);
        if (fd < 0)
			return;

        uint8_t *data = calloc(status.st_size, 1);
        if (!data) {
			close(fd);
			return; 
		}
        read(fd, data, status.st_size);
        close(fd);

        md5(data, status.st_size, hash);
		flg->s = 1;
        print_all_md5(hash, src, *flg, 0);
        free(data);

        return;
    }
	// else if (!is_str && (stat(src, &status) != 0 || !S_ISREG(status.st_mode))){
	// 	printf("Error: %s: can not be open\n", src);
	// 	return;
	// }
    md5((uint8_t *)src, strlen(src), hash);
    print_all_md5(hash, src, *flg, 1);
}

void print_md5(uint8_t hash[16]) {
    for (int i = 0; i < 16; i++)
        printf("%02x", hash[i]);
}

void print_all_md5(uint8_t hash[16], char *input, t_flag flg, int is_string){

    if (flg.q) {
        print_md5(hash);
        printf("\n");
        return;
    }
    if (flg.r) {
        print_md5(hash);
        printf(" %s\n", input);
        return;
    }
	if (flg.s){
		printf("MD5 (");
		if (is_string) printf("\"");
		printf("%s", input);
		if (is_string) printf("\"");
		printf(") = ");
		print_md5(hash);
		printf("\n");
		return;
	}
	printf("(");
    if (is_string) printf("\"");
    printf("%s", input);
    if (is_string) printf("\"");
    printf(") = ");
    print_md5(hash);
    printf("\n");
}

void handle_stdin_md5(t_flag flg) {

    uint8_t buf[4096];
    uint8_t *data = NULL;
    size_t total = 0;
    size_t n;
    uint8_t hash[16];
	// printf("lalalalande\n");m
	
	if (isatty(0))
        printf("ft_ssl: reading from stdin, press Ctrl+D to finish the input)\n");
    while ((n = read(0, buf, sizeof(buf))) > 0) {
        // write(1, buf, n);
        uint8_t *tmp = malloc(total + n);
        if (data) {
            memcpy(tmp, data, total);
            free(data);
        }
        memcpy(tmp + total, buf, n);
        data = tmp;
        total += n;
    }
	// if (n == -1){
	// 	printf("lalalalande\n");
	// 	return;
	// }
    md5(data, total, hash);

    // if (!flg.q)
    //     printf("\n");
	if (flg.p)
    	print_all_md5(hash, (char *)data, flg, 1);
	else
		print_all_md5(hash, "stdin", flg, 0);
    free(data);
}




//----------------------------------------SHA256----------------------------------------//
void main_sha256(char *src, int is_str, t_flag *flg) {

    uint8_t hash[32];
    struct stat status;

    if (!is_str && stat(src, &status) == 0 && S_ISREG(status.st_mode)) {

        int fd = open(src, O_RDONLY);
        if (fd < 0)
			return;

        uint8_t *data = calloc(status.st_size, 1);
        if (!data) {
			close(fd);
			return; 
		}
        read(fd, data, status.st_size);
        close(fd);

        sha256(data, status.st_size, hash);
		flg->s = 1;
        print_all_sha256(hash, src, *flg, 0);
        free(data);

        return;
    }
	// else if (!is_str && (stat(src, &status) != 0 || !S_ISREG(status.st_mode))){
	// 	printf("Error: %s: can not be open\n", src);
	// 	return;
	// }
    sha256((uint8_t *)src, strlen(src), hash);
    print_all_sha256(hash, src, *flg, 1);
}

void print_sha256(uint8_t hash[32]) {
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);
}

void print_all_sha256(uint8_t hash[32], char *input, t_flag flg, int is_string){

    if (flg.q) {
        print_sha256(hash);
        printf("\n");
        return;
    }
    if (flg.r) {
        print_sha256(hash);
        printf(" %s\n", input);
        return;
    }
	if (flg.s){
		printf("SHA256 (");
		if (is_string) printf("\"");
		printf("%s", input);
		if (is_string) printf("\"");
		printf(") = ");
		print_sha256(hash);
		printf("\n");
		return;
	}
	printf("(");
    if (is_string) printf("\"");
    printf("%s", input);
    if (is_string) printf("\"");
    printf(") = ");
    print_sha256(hash);
    printf("\n");
}

void handle_stdin_sha256(t_flag flg) {

    uint8_t buf[4096];
    uint8_t *data = NULL;
    size_t total = 0;
    size_t n;
    uint8_t hash[32];
	// printf("lalalalande\n");m
	
	if (isatty(0))
        printf("ft_ssl: reading from stdin, press Ctrl+D to finish the input)\n");
    while ((n = read(0, buf, sizeof(buf))) > 0) {
        // write(1, buf, n);
        uint8_t *tmp = malloc(total + n);
        if (data) {
            memcpy(tmp, data, total);
            free(data);
        }
        memcpy(tmp + total, buf, n);
        data = tmp;
        total += n;
    }
	// if (n == -1){
	// 	printf("lalalalande\n");
	// 	return;
	// }
    sha256(data, total, hash);

    // if (!flg.q)
    //     printf("\n");
	if (flg.p)
    	print_all_sha256(hash, (char *)data, flg, 1);
	else
		print_all_sha256(hash, "stdin", flg, 0);
    free(data);
}

// void	*tab_free(char **tab){
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (NULL);
// } 

// void	ft_bzero(void *s, size_t n){
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		((char *)s)[i] = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size){
// 	void	*mem;

// 	if (count == 0 || size == 0)
// 	{
// 		mem = malloc(0);
// 		return (mem);
// 	}
// 	mem = malloc(count * size);
// 	if (!mem)
// 		return (0);
// 	ft_bzero(mem, count * size);
// 	return (mem);
// }

// int ft_strlen(char *str){
//     int i = 0;

//     while (str[i]){
//         i++;
//     }
//     return i;
// }

// char	*ft_strjoin(char *s1, char *s2){
// 	char	*str;
// 	int		i = 0;
// 	int		j = 0;

// 	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!str)
// 		return (0);
// 	if (str)
// 	{
// 		while (s1[j]){
// 			str[i++] = s1[j++];
// 		}
// 		j = 0;
// 		while (s2[j]){
// 			str[i++] = s2[j++];
// 		}
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strdup(char *s1){
// 	int		i = 0;
// 	char	*dup;

// 	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (dup == 0)
// 		return (0);
// 	while (s1[i]){
// 		dup[i] = s1[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }
