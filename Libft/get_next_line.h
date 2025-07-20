/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:13:59 by gita              #+#    #+#             */
/*   Updated: 2025/07/20 20:02:17 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 68
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*keep_joining(char *result, char *findnl);
char	*line_extract_n_update_buf(char *str);
ssize_t	keep_reading(char *findingnl, int fd);

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char	*s, unsigned char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *str, unsigned int start, size_t len);

#endif