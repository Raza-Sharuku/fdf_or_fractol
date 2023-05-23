/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:07:26 by sraza             #+#    #+#             */
/*   Updated: 2023/05/23 15:53:44 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*ここではあらゆるMallocをしてNullじゃない場合の値を返す*/

void	*ft_free_three(char ***str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_free_fdf(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

void	*ft_free_fdf(char **result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

char	**two_malloc(char ***str2, int len, int i)
{
	char	**str;

	errno = 0;
	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (errno != 0)
	{
		str2[i] = NULL;
		ft_free_three(str2);
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
	return (str);
}

char	***three_malloc(t_array *a)
{
	char	***str2;

	errno = 0;
	str2 = (char ***)malloc(sizeof(char **) * (a->y_len + 1));
	if (errno != 0)
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
	return (str2);
}
