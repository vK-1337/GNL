/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vk <vk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:28:18 by vda-conc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/19 20:22:10 by vk               ###   ########.fr       */
=======
/*   Updated: 2023/11/27 18:41:15 by vda-conc         ###   ########.fr       */
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
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

<<<<<<< HEAD

#endif
=======
char	*ft_strdup(char *s);
char *get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len, int is_stash);

#endif
>>>>>>> c537f943bf6cb9c6b45ff03a28527a8f62440fdc
