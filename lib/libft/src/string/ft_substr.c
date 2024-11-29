/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:15:58 by Basile19          #+#    #+#             */
/*   Updated: 2024/11/29 12:03:10 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*result;

	if (!s)
		return (0);
	i = 0;
	n = ft_strlen(s);
	if (start > n)
		return (ft_strdup(""));
	if (n < len)
		len = n;
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
