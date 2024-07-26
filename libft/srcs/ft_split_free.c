/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:14:19 by lespenel          #+#    #+#             */
/*   Updated: 2023/11/28 22:58:10 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int		ft_cut(char const *s, char c, char **strs);
static int		ft_count(char const *s, char c);
static void		free_strs(char **strs);

char	**ft_split_free(char const *s, char c)
{
	char	**strs;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	strs = ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	if (ft_cut(s, c, strs) == 0)
		return (NULL);
	free((void *)s);
	return (strs);
}

static int	ft_cut(char const *s, char c, char **strs)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
		{
			strs[count] = malloc(sizeof(char) * (i + 1));
			if (!strs[count])
			{
				free_strs(strs);
				return (0);
			}
			ft_strlcpy(strs[count], s, i + 1);
			count++;
			s += i;
		}
		else
			s++;
	}
	return (1);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		if (i != 0)
		{
			s += i;
			count++;
		}
		else
			s++;
	}
	return (count);
}
