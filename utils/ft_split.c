/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeedril <tbeedril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:47:28 by tbeedril          #+#    #+#             */
/*   Updated: 2020/11/25 14:47:51 by tbeedril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}

static int	wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	words(char const *s, char c)
{
	size_t	i;
	int		ans;

	i = 0;
	ans = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ans++;
		i++;
	}
	return (ans);
}

static void	*ft_free(void **str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	int		len1;
	int		len2;
	char	**str;

	if (!s)
		return (NULL);
	len1 = words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (len1 + 1))))
		return (NULL);
	i = 0;
	while (len1-- > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		len2 = wordlen(s, c);
		if (!(str[i] = (char *)malloc((len2 + 1) * sizeof(char))))
			return (ft_free((void **)str, i));
		str[i] = ft_memcpy(str[i], s, len2);
		str[i][len2] = '\0';
		s += len2;
		i++;
	}
	str[i] = NULL;
	return (str);
}
