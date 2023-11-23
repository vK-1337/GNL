/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:16 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/23 17:39:47 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_copy_and_free(char *buffer, ssize_t bytes_read)
{
    char *copy;
    ssize_t i;
    
    copy = malloc((bytes_read + 1) * sizeof(char));
    if (!copy)
        return (NULL);
    i = 0;
    while (i < bytes_read)
    {
        copy[i] = buffer[i];
        i++;
    }
    free(buffer);
    return (copy);
}

char *ft_fill_line(char **stash, ssize_t index)
{
    ssize_t i;
    char *line;
    
    line = malloc((index + 1) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while(i < index)
    {
        line[i] = (*stash)[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

void ft_clean_stash(char **stash, ssize_t index)
{
    ssize_t i;
    ssize_t j;
    char *cleaned_stash;
    
    i = 0;
    while ((*stash)[i + index])
        i++;
    cleaned_stash = malloc((i) * sizeof(char));
    if (!cleaned_stash)
        return;
    j = 0;
    while(j < i)
    {
        cleaned_stash[j] = (*stash)[index + 1];
        index++;
        j++;
    }
    free(*stash);
    *stash = cleaned_stash;
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    ssize_t i;
    ssize_t j;
    char *buffer;
    
    line = (NULL);
    if (fd <= 0 || read(fd, line, 0) == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = ft_read_file(fd);
    if (!buffer)
        return (NULL);
    i = ft_alloc_stash(&stash, buffer);
    ft_load_stash(&stash, buffer, i);
    j = ft_check_stash(&stash, buffer);
    while (!j)
    {
        buffer = ft_read_file(fd);
        i = ft_alloc_stash(&stash, buffer);
        ft_load_stash(&stash, buffer, i);
        j = ft_check_stash(&stash, buffer);
    }
    free(buffer);
    if ( j == -1 )
        j = 1;
    line = ft_fill_line(&stash, j);
    ft_clean_stash(&stash, j);
    return (line);
}

int main()
{
    int fd;
    
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur dans l'ouverture du fichier");
        return (1);
    }
    printf("PASSAGE NUMERO 1 DE GNL :\n");
    printf("Retour de get_next_line : %s FIN DE RETOUR\n" , get_next_line(fd));
    printf("PASSAGE NUMERO 2 DE GNL :\n");
    printf("Retour de get_next_line : %s FIN DE RETOUR\n" , get_next_line(fd));
    printf("PASSAGE NUMERO 3 DE GNL :\n");
    printf("Retour de get_next_line : %s FIN DE RETOUR\n" , get_next_line(fd));
    printf("PASSAGE NUMERO 4 DE GNL :\n");
    printf("Retour de get_next_line : %s FIN DE RETOUR\n" , get_next_line(fd));
    close(fd);
    return (0);
}