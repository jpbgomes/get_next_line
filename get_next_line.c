/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:10 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:00 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char g_last[BUFFER_SIZE + 1];
static t_list *stash;

char *get_next_line(int fd)
{
  if (stash)
  {
    printf("STASH NOT EMPTY\n");
    t_list *tmp;
    int i = 0;
    int j = 0;

    tmp = stash;
    while(tmp)
    {
      printf("Stash Content = %s\n\n", (char *)tmp->content);
      if (ft_contains((char *)tmp->content, '\n') >= 0)
      {
        printf("Founded Content = %d\n\n", ft_contains((char *)tmp->content, '\n'));
        i += ft_contains((char *)tmp->content, '\n');
        return (cres_lst(stash, i, j));
      }
      else
        i += ft_strlen((char *)tmp->content);
    
      tmp = tmp->next;
      if (tmp && tmp->content)
        j += 1;
    }

    printf("Res Length = %d/%d\n\n", i, j);
  }
  else
    printf("STASH EMPTY\n");

  ssize_t bytes_read = read(fd, g_last, BUFFER_SIZE);
  if (bytes_read == -1)
    printf("Error reading file\n");
  else
  {
    g_last[bytes_read] = '\0';
    printf("Last Content = %s\n\n", g_last);

    //printf("Last = %s\n\n", g_last);

    if(stash == NULL)
    {

      // if (ft_contains(g_last, '\n') >= 0)
      //   return (cres_str(g_last, ft_contains(g_last, '\n')));
      // else
      printf("NEW NODE\n");
      stash = ft_lstnew(g_last);
    }
    else
    {
      printf("NEW NODE TO BACK\n");
      t_list	*new_node = ft_lstnew(g_last);
      ft_lstadd_back(&stash, new_node);
    }
  }
  
  return (NULL);
}