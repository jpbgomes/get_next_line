/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:10 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/29 19:20:28 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char g_last[BUFFER_SIZE + 1];
static ssize_t bytes_read;
static t_list *stash;
static int i;
static int j;

char *get_next_line(int fd)
{
  i = 0;
  j = 0;
  bytes_read = -1;
  while (bytes_read == -1 || bytes_read > 0)
  {
    bytes_read = read(fd, g_last, BUFFER_SIZE);
    if (bytes_read == -1)
      return (NULL);
    else
    {
      g_last[bytes_read] = '\0';
      printf("BT = %ld\nLast Content = %s\n\n", bytes_read, g_last);
      
      if (bytes_read > 0)
      {
        char *content_copy = malloc(bytes_read + 1);
        if (!content_copy)
          return (NULL);
        ft_strlcpy(content_copy, g_last, bytes_read + 1);

        if(stash == NULL)
        {
          printf("NEW NODE\n");
          stash = ft_lstnew(content_copy);
        }
        else
        {
          printf("NEW NODE TO BACK\n");
          t_list	*new_node = ft_lstnew(content_copy);
          ft_lstadd_back(&stash, new_node);
        }
        
        printf("CT = %d\n", ft_contains(g_last, '\n'));
        i += ft_strlen(g_last);
        j += 1;
        if (ft_contains(g_last, '\n') > 0)
          return (cres_lst(stash, i, j));
      }
    }
  }
    
  return (NULL);
}