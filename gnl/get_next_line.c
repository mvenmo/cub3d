/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenmo <mvenmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:54:18 by botilia           #+#    #+#             */
/*   Updated: 2022/07/15 09:54:49 by mvenmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *stat_str)
{
	char		*bufer;
	int			readed_chars;
	char		*tmp;

	readed_chars = 1;
	bufer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!stat_str)
		stat_str = ft_calloc(1, 1);
	while (!ft_strchr(stat_str, '\n') && readed_chars != 0)
	{
		readed_chars = read(fd, bufer, BUFFER_SIZE);
		if (readed_chars == -1)
		{
			free(bufer);
			free(stat_str);
			return (NULL);
		}
		bufer[readed_chars] = '\0';
		tmp = stat_str;
		stat_str = ft_strjoin(stat_str, bufer);
		free(tmp);
	}
	free(bufer);
	return (stat_str);
}

char	*get_line(char *stat_str)
{
	char	*nstr;
	int		i;

	i = 0;
	if (stat_str[i] == '\0')
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	nstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!nstr)
		return (NULL);
	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
	{
		nstr[i] = stat_str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*wow_next_line(char *stat_str)
{
	size_t	i;
	char	*next_line;
	size_t	a;

	if (!stat_str)
		return (NULL);
	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	if (stat_str[i] == '\0')
	{
		free(stat_str);
		return (NULL);
	}
	a = i;
	next_line = (char *)malloc(sizeof(char) * ((ft_strlen(stat_str)) - i + 1));
	if (!next_line)
		return (NULL);
	i = 0;
	while (stat_str[a])
		next_line[i++] = stat_str[++a];
	next_line[i] = '\0';
	free(stat_str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stat_str;
	char		*nst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_str = read_file(fd, stat_str);
	if (!stat_str)
		return (NULL);
	nst = get_line(stat_str);
	stat_str = wow_next_line(stat_str);
	return (nst);
}
