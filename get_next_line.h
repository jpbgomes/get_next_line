/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:34 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/29 17:54:57 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H
  #include <fcntl.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <stdio.h>

  typedef struct s_list
  {
    void			*content;
    struct s_list	*next;
  }	t_list;

  char *get_next_line(int fd);
  t_list	*ft_lstnew(void *content);
  void	ft_lstadd_back(t_list **lst, t_list *new);
  int	ft_contains(char *set, char c);
  size_t	ft_strlen(const char *s);
  char  *cres_str(const char *s, int pos);
  char  *cres_lst(const t_list *lst, int i, int j);
#endif

#ifndef BUFFER_SIZE
  #define BUFFER_SIZE 42
#endif