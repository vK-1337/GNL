/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:16 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/20 18:01:50 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    
    i = ft_strlen((stash)[index]);
    cleaned_stash = malloc((i + 1) * sizeof(char));
    j = 0;
    while(j < i)
    {
        cleaned_stash[j] = (*stash)[index];
        index++;
        j++;
    }
    cleaned_stash[j] = '\0';
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
    
    if (fd <= 0 || !fd)
        return (NULL);
    buffer = ft_read_file(fd);
    if (!buffer)
        return (NULL);
    i = ft_alloc_stash(&stash, BUFFER_SIZE); // debut bloc a transferer autre fonction si jamais trop long
    ft_load_stash(&stash, buffer, i);
    j = ft_check_stash(&stash);
    printf("J est egal a : %zu\n", j);
    printf("Stash contient : %s\n", stash);
    while (!j)
    {
        i = ft_alloc_stash(&stash, BUFFER_SIZE);
        ft_load_stash(&stash, buffer, i);
        j = ft_check_stash(&stash);
    }
    line = ft_fill_line(&stash, j);
    printf("Line contient : %s\n", line);
    ft_clean_stash(&stash, j);
    printf("Stash apres nettoyage : %s\n", stash);
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
    printf("Retour de get_next_line : %s\n" , get_next_line(fd));
    printf("Retour de get_next_line : %s\n" , get_next_line(fd));
    return (0);
}