/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:20 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/19 21:35:10 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}
