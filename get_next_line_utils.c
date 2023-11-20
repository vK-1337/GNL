/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:20 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/20 16:38:30 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t ft_check_stash(char **stash)
{
	ssize_t i;

	i = 0;
	while ((*stash)[i])
	{
		if ((*stash)[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
ssize_t	ft_strlen(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
	 return(0);
	while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
		i += 4;
	while (str[i])
		i++;
	return (i);
}

ssize_t ft_alloc_stash(char **stash, ssize_t buffer_size)
{
  ssize_t i;
  ssize_t j;
  char *new_stash;

  i = ft_strlen(*stash);
  new_stash = malloc((buffer_size + i + 1) * sizeof(char));
  if (!new_stash)
	return (-1);
  j = 0;
  if (i > 0)
  {
   	while ((*stash)[j] != '\0') 
	{
        new_stash[j] = (*stash)[j + 1];
        j++;
    }
  }
  new_stash[j] = '\0';
  free(*stash);
  *stash = new_stash;
  return (i);
}

char *ft_read_file(int fd)
{
	ssize_t bytes_read;
	char *buffer;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

void ft_load_stash(char **stash, char* buffer, ssize_t stash_index)
{
	ssize_t i;
	ssize_t j;

	i = 0;
	j = stash_index;
	while (buffer[i])
	{
		(*stash)[j] = buffer[i];
		i++;
		j++;
	}
}