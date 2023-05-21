/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:42:53 by juzheng           #+#    #+#             */
/*   Updated: 2022/10/04 10:42:54 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int				ft_isdigit(int c);

long long int	ft_atoi(const char *str);

char			*ft_itoa(int n);
int				ft_strchr(char *str, char *cmp);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char sep);
int				ft_gnl(int fd, char **str);

size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *str, int nb);

#endif
