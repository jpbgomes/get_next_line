/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:10 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/30 17:11:38 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char g_last[BUFFER_SIZE + 1];
static ssize_t bytes_read;
static t_list *stash;

char *get_next_line(int fd)
{
	char	*content;
	t_list	*tmp;
  
  if (stash)
	{
    // printf("Stash = %p\n", stash);
		tmp = stash;
		while (tmp)
		{
			content = (char *)tmp->content;
      // printf("OLD CONTENT = %s\n", content);
      if (ft_contains(content, '\n') > 0)
      {
        return (cres_lst(&stash));
      }

			tmp = tmp->next;
		}
	}
  
  bytes_read = -1;
  while (bytes_read == -1 || bytes_read > 0)
  {
    bytes_read = read(fd, g_last, BUFFER_SIZE);
    if (bytes_read == -1)
      return (NULL);
    else
    {
      g_last[bytes_read] = '\0';
      // printf("BT = %ld\nLast Content = %s\n", bytes_read, g_last);
      
      if (bytes_read > 0)
      {
        char *content_copy = malloc(bytes_read + 1);
        if (!content_copy)
          return (NULL);
        ft_strlcpy(content_copy, g_last, bytes_read + 1);

        if(stash == NULL)
        {
          // printf("NEW NODE\n\n");
          stash = ft_lstnew(content_copy);
        }
        else
        {
          // printf("NEW NODE TO BACK\n\n");
          t_list	*new_node = ft_lstnew(content_copy);
          ft_lstadd_back(&stash, new_node);
        }
        
        if (ft_contains(g_last, '\n') > 0)
          return (cres_lst(&stash));
      }
    }
  }
    
  return (NULL);
}