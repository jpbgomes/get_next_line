/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:37 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/29 19:29:48 by jpedro-b         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int						src_l;
	unsigned long			i;

	src_l = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_l);
}

void  ft_strfill(char *res, char *content, int start)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(content))
	{
		// printf("L = %c|Pos I = %ld\n",  content[i], i);
		res[start + i] = content[i];
		i++;
	}
}

char  *cres_lst(t_list *lst, int i, int j)
{
	char	*res;
	t_list	*tmp;
	int	c;

	printf("I = %d\nJ = %d\n", i, j);

	if (lst)
	{
		res = malloc(i * sizeof(char));
		if (!res)
			return (NULL);

		c = 0;
		tmp = lst;
		while (tmp)
		{
			ft_strfill(res, (char *)tmp->content, c);
			c += ft_strlen(tmp->content);
			printf("Content = %s\n", (char *)tmp->content);
			tmp = tmp->next;
		}
	}
  return (res);
}