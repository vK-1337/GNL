/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:18 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/27 22:35:50 by vk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strdup(char *s);
int ft_check_stash(char *str);
char *get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char  *ft_fill_line(char **stash, ssize_t index);
void ft_clean_stash(char **stash, ssize_t index);
int ft_read(char **stash, char *buffer, int fd);


#endif
