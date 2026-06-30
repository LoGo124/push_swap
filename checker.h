/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:00:00 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/30 18:02:40 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif

// push_swap
// ft_stack.c
void	ft_stack_fill(t_data *data, char **v);
int		ft_check_stack(t_stack_node *node);

// GNL
char	*get_next_line(int fd);

// gnl_utils
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);

#endif
