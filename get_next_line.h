/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:34 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/30 16:31:51 by jpedro-b         ###   ########.fr       */
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
  size_t	ft_strlcpy(char *dst, const char *src, size_t size);
  void  ft_strfill(char *res, char *content, int start);
  char  *cres_lst(t_list **lst);
#endif

#ifndef BUFFER_SIZE
  #define BUFFER_SIZE 42
#endif