/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/11/19 16:28:16 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 21:38:56 by vk               ###   ########.fr       */
=======
/*   Created: 2023/11/27 18:19:03 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/27 19:49:29 by vda-conc         ###   ########.fr       */
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
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
<<<<<<< HEAD

    if (fd <= 0)
        return (NULL);
    stash = malloc((BUFFER_SIZE + 1) * sizeof(char));
    // Parcourir stash jusqu'a l'emplacement ou l'on va plus tard ecrire.
    // Si c'est rempli ca nous permettra de copier au bon endroit dans stash lors du transfert de stash a line
    // Lire le fichier et evaluer le retour de la fonction read
    // Stocker le contenu du buffer dans stash
    // Evaluer le contenu de stash pour verifier qu'il n'y a pas de \n
    // Si il n'y a rien continuer de remplir le stash bytes apres bytes
    //      Si on voit qu'il n'y en a pas il faudra realloc de l'espace pour rajouter les choses dans stash
    // Si on trouve un \n compter le nombre de caractere a transferer dans line AVEC LE \n
    // Transferer dans line
    // Nettoyer le contenu de stash avant le \n
=======
    char *buffer;
    static char* stash;
    
    buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
    if (!buffer)
        return (NULL);
    ft_read(&stash, buffer, fd);
    ft_fill_line(line, *stash);
    ft_clean_stash();
    free(buffer);
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
    return (line);
}

int main()
{
    int fd;
<<<<<<< HEAD
    ssize_t bytes_read;
    char *buffer;

=======
    char *line;
    
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
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
