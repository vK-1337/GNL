/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:19:03 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/27 19:49:29 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check_stash(char *str)
{
    ssize_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}
int ft_read(char **stash, char *buffer, int fd)
{
    int bytes_read;
    int is_line;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    if (!*stash)
        *stash = ft_strdup(buffer);
    else 
        *stash = ft_strjoin(*stash, buffer);
    if (bytes_read == 0)
        return (0);
    is_line_i = ft_check_stash(*stash);
    while (is_line_i == -1 && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        *stash = ft_strjoin(*stash, buffer);
        is_line_i = ft_check_stash(*stash);
    }
    return (is_line);
}

ft_fill_line(char *line, char **stash)
{
    ssize_t
}

char *get_next_line(fd)
{
    char *line;
    char *buffer;
    static char* stash;
    
    buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
    if (!buffer)
        return (NULL);
    ft_read(&stash, buffer, fd);
    ft_fill_line(line, *stash);
    ft_clean_stash();
    free(buffer);
    return (line);
}

int main()
{
    int fd;
    char *line;
    
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur dans l'ouverture du fichier");
        return (1);
    }
    printf("APPEL NUMERO 1\n");
    line = get_next_line(fd);
    printf("Retour numero 1: |%s|\n\n", line);
    printf("APPEL NUMERO 2\n");
    line = get_next_line(fd);
    printf("Retour numero 2: |%s|\n\n", line);
    printf("APPEL NUMERO 3\n");
    line = get_next_line(fd);
    printf("Retour numero 3: |%s|\n\n", line);
    free(line);
    return (0);
}