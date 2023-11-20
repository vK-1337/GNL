/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:18 by vda-conc          #+#    #+#             */
/*   Updated: 2023/11/20 17:33:46 by vda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t ft_alloc_stash(char **stash, ssize_t buffer_size);
char *get_next_line(int fd);
ssize_t	ft_strlen(const char *str);
char *ft_read_file(int fd);
void ft_load_stash(char **stash, char* buffer, ssize_t stash_index);
ssize_t ft_check_stash(char **stash);
char *ft_fill_line(char **stash, ssize_t index);
void ft_clean_stash(char **stash, ssize_t index);

#endif