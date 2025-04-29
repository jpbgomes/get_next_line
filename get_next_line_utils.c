/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:37 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/29 17:55:55 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (! new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	ft_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char  *cres_str(const char *s, int pos)
{
  char  *res;
  int i;

  i = 0;
  res = malloc((pos + 2) * sizeof(char));
  if (!res)
    return (NULL);
  else
  {
    while (i < pos)
    {
      res[i] = s[i];
      i++;
    }
    res[i + 1] = '\n';
    res[i + 2] = '\0';
  }

  return (res);
}

char  *cres_lst(const t_list *lst, int i, int j)
{
  printf("Lst C = %s\nI = %d\nJ = %d\n", (char *)lst->content, i, j);
  return ("TESTE");
}