/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:20 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/23 17:27:58 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
	 return (i);
	while (str[i] && str[i + 1] && str[i + 2] && str[i + 3])
		i += 4;
	while (str[i])
		i++;
	return (i);
}

char *ft_read_file(int fd)
{
	ssize_t bytes_read;
	char *buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (bytes_read < BUFFER_SIZE)
		buffer = ft_copy_and_free(buffer, bytes_read);
	buffer[bytes_read] = '\0';
	return (buffer);
}

void ft_load_stash(char **stash, char* buffer, ssize_t stash_index)
{
	ssize_t i;
	ssize_t j;
	
	if (!buffer)
		return;
	i = 0;
	j = stash_index;
	while (buffer[i] != '\0')
		(*stash)[j++] = buffer[i++];
	(*stash)[j] = '\0';
}

ssize_t ft_check_stash(char **stash, char *buffer)
{
	ssize_t i;
	ssize_t buffer_len;
	ssize_t stash_len;
	
	buffer_len = ft_strlen(buffer);
	i = 0;
	while ((*stash)[i] != '\0')
	{
		if ((*stash)[i] == '\n' && i == 0)
			return (-1);
		if ((*stash)[i] == '\n')
			return (i);
		i++;
	}
	if ( buffer_len < BUFFER_SIZE )
	{
		stash_len = ft_strlen(*stash);
		return (buffer_len + stash_len);
	}
	free(buffer);
	return (0);
}

ssize_t ft_alloc_stash(char **stash, char* buffer)
{
  ssize_t i;
  ssize_t j;
  char *new_stash;

  i = ft_strlen(*stash);
  j = ft_strlen(buffer);
  new_stash = malloc((j + i + 1) * sizeof(char));
  if (!new_stash)
	return (-1);
  j = 0;
  if (i > 0)
  {
   	while ((*stash)[j] != '\0') 
	{
        new_stash[j] = (*stash)[j];
        j++;
    }
  }
  if (i == 0 && ft_strlen(buffer) == 0)
  	new_stash[BUFFER_SIZE] = '\0';
  else	
  	new_stash[j] = '\0';
  free(*stash);
  *stash = new_stash;
  return (i);
}
