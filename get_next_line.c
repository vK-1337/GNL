/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:19:03 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/27 23:13:01 by vk               ###   ########.fr       */
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
    int is_line_i;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    if (!*stash)
        *stash = ft_strdup(buffer);
    else
        *stash = ft_strjoin(*stash, buffer);
    if (bytes_read == 0)
	{
		free(buffer);
		if (!*stash)
			return (0);
		else
			return (ft_strlen(*stash));
	}
    is_line_i = ft_check_stash(*stash);
    while (is_line_i == -1 && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if ( bytes_read > 0)
        {
          buffer[bytes_read] = '\0';
          *stash = ft_strjoin(*stash, buffer);
          is_line_i = ft_check_stash(*stash);
        }
    }
    return (is_line_i);
}

void ft_clean_stash(char **stash, ssize_t index)
{
	ssize_t i;
	ssize_t limit;
	char* new_stash;

	limit = 0;
	while ((*stash)[limit + index])
		limit++;
	new_stash = malloc((limit + 1) * sizeof(char));
	if (!new_stash)
		return;
	i = 0;
	while (i < limit)
	{
		new_stash[i] = (*stash)[i + index + 1];
		i++;
	}
	free(*stash);
	new_stash[i] = '\0';
	*stash = new_stash;
	return;
}

char *ft_fill_line(char **stash, ssize_t index)
{
	ssize_t i;
	char *line;

	line = malloc(((index + 1) + 1) * sizeof (char));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= index)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}


char *get_next_line(int fd)
{
	char *line;
    char *buffer;
    static char* stash;
    int line_index;

	line = NULL;
	if (fd <= 0 || read(fd, line, 0) == -1)
		return (NULL);
  buffer = malloc((BUFFER_SIZE + 1) * sizeof (char));
  if (!buffer)
      return (NULL);
  line_index = ft_read(&stash, buffer, fd);
	if (line_index == 0)
		return (NULL);
  if (line_index == -1)
    line_index = (ft_strlen(stash));
	line = ft_fill_line(&stash, line_index);
  ft_clean_stash(&stash, line_index);
  free(buffer);
  return (line);
}

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("./test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Erreur dans l'ouverture du fichier");
//         return (1);
//     }
//     printf("APPEL NUMERO 1\n");
//     line = get_next_line(fd);
//     printf("Retour numero 1: |%s|\n\n", line);
//     printf("APPEL NUMERO 2\n");
//     line = get_next_line(fd);
//     printf("Retour numero 2: |%s|\n\n", line);
//     printf("APPEL NUMERO 3\n");
//     line = get_next_line(fd);
//     printf("Retour numero 3: |%s|\n\n", line);
//     free(line);
//     return (0);
// }
