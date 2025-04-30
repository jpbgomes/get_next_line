/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:20:37 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/30 16:29:54 by jpedro-b         ###   ########.fr       */
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

int	ft_calculatelen(t_list *lst)
{
	int	len;
	int	i;
	char	*content;
	t_list	*tmp;

	len = 0;
	i = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			content = (char *)tmp->content;

			i = 0;
			while (content[i] != '\0')
			{
				if (content[i] == '\n')
				{
					len += i;
					return (len);
				}
				else
					i++;
			}
			len += i;
			tmp = tmp->next;
		}
	}
	return (len);
}

char  *cres_lst(t_list *lst)
{
	char	*res;
	t_list	*tmp;
	int	total_len;
	int lst_nbr;
	int c;
	int i;
	char	*content;

	total_len = ft_calculatelen(lst);
	printf("Total Len Res = %d\n", total_len);

	c = 0;
	lst_nbr = 0;
	if (lst)
	{
		res = malloc(total_len * sizeof(char));
		if (!res)
			return (NULL);

		tmp = lst;
		while (tmp)
		{
			i = 0;
			content = (char *)tmp->content;
			printf("Content = %s\n", content);

			while (content[i] && c < total_len)
			{
				// printf("C = %d | I = %d | N = %c\n", c, i, content[i]);
				
				res[c] = content[i];
				i++;
				c++;
			}

			if (ft_contains(content, '\n') > 0 && ft_contains(content, '\n') < (int)ft_strlen(content) - 1)
			{
				printf("NOT END New Line = %d | TL - %ld\n", ft_contains(content, '\n'), ft_strlen(content));
				// content += ((int)ft_strlen(content) - ft_contains(content, '\n')); 
				tmp->content += 1 + ft_contains(content, '\n');
				// printf("Content2 = %s\n", content);
			}
			else if (ft_contains(content, '\n') > 0 && ft_contains(content, '\n') == (int)ft_strlen(content) - 1)
			{
				printf("END New Line = %d | TL - %ld\n", ft_contains(content, '\n'), ft_strlen(content));
			}

			tmp = tmp->next;
			lst_nbr++;
		}
	}

	res[c] = '\n';

  return (res);
}