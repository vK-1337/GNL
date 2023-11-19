/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:16 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 17:55:25 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    ssize_t bytes_read;
    char *line;
    
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
    // Return line
    return (line);
}

int main()
{
    int fd;
    ssize_t bytes_read;
    char *buffer;
    
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur dans l'ouverture du fichier");
        return (1);
    }
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    buffer[10] = '\0';
    if (!buffer)
    {
        printf("Erreur pour allouer le buffer");
        return (1);
    }
    bytes_read = read(fd, buffer, 15);
    while (bytes_read)
    {
        printf("%zu", bytes_read);
        printf("%s", buffer);
        bytes_read = read(fd, buffer, 15);
    }
    if (bytes_read == -1)
    {
        printf("Erreur dans la lecture du fichier");
        close(fd);
        return (1);
    }
    return (0);
}