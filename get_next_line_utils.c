/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/11/19 16:28:20 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 21:35:10 by vk               ###   ########.fr       */
=======
/*   Created: 2023/11/24 16:38:56 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/27 19:37:02 by vda-conc         ###   ########.fr       */
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
void ft_alloc_stash(char *stash, ssize_t buffer_size)
{
  size_t i;
  size_t j;
  char *new_stash;

  i = ft_strlen(stash);
  new_stash = malloc((buffer_size + i + 1) * sizeof(char));
  if (!new_stash)
    return (NULL);
  if (i > 0)
  {
    j = 0;
    while(j < i)
      new_stash[j] = stash[j++];
  }
  new_stash[j] = '\0';
=======
char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

    if (!s)
    {
        return (NULL);
    }
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
}
