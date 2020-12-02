/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:21:48 by tbeedril          #+#    #+#             */
/*   Updated: 2020/12/02 18:18:19 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_new_1quo(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	wordlen = 0;
	*res += 1;
	*new += 1;
	while (**new && **new != '\'')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (**new)
		*new += 1;
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_new_word(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;

	*res += 1;
	wordlen = 0;
	while (**new && **new != ' ' && **new != ';' && **new != '\''
	&& **new != '\"' && **new != '$' && **new != '>'
	&& **new != '<' && **new != '|')
	{
		(*new)++;
		wordlen++;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	ft_lstadd_back(tmp, ft_lstnew(str, 0));
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_new_2quo(char **new, t_list **tmp, int *res)
{
	char	*str;
	int		wordlen;
	char	*tmp_str;

	*res += 1;
	*new += 1;
	wordlen = 0;
	while (**new && **new != '\"')
	{
		*new += 1;
		wordlen += 1;
	}
	tmp_str = ft_strndup(*new - wordlen, wordlen);
	str = ft_some_dol(tmp_str);
	free(tmp_str);
	ft_lstadd_back(tmp, ft_lstnew(str, 2));
	if (++*new)
		*res += words_get(new, tmp);
}

void	ft_do_space(char **new, t_list **tmp, int *res)
{
	while (**new && **new == ' ' && **new != ';' && **new != '\''
	&& **new != '\"' && **new != '$' && **new != '>'
	&& **new != '<' && **new != '|')
		*new += 1;
	if (*new)
		*res += words_get(new, tmp);
}

void	ft_sign_dollar(char **new, t_list **tmp, int *res)
{
	char	*str;
	char	*fin;
	int		wordlen;

	*res += 1;
	*new += 1;
	wordlen = 1;
	while (*new && **new && **new != ' ' && **new != ';' && **new != '\''
	&& **new != '\"' && **new != '$' && **new != '>'
	&& **new != '<' && **new != '|')
	{
		*new += 1;
		wordlen += 1;
	}
	str = ft_strndup(*new - wordlen, wordlen);
	if (str[1] == '?')
		fin = ft_itoa(code);
	else
		fin = ft_strdup(ft_get_tiktok(str + 1));
	free(str);
	ft_lstadd_back(tmp, ft_lstnew(fin, 1));
	if (**new)
		*res += words_get((++new), tmp);
}