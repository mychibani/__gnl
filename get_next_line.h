/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:35:49 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/30 13:35:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void check_leaks();
char	*get_next_line(int fd);
char	*ft_get_line(char *src);
char	*ft_gnl_join(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_is_newline(char c);
int		ft_is_line(char *str);

#endif