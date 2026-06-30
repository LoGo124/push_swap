/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:11:23 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/06/30 15:42:20 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*extract_nline(char *readed)
{
	char	*nstr;
	int		i;
	int		j;

	nstr = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!nstr)
		return (NULL);
	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (!readed[i])
	{
		free(nstr);
		free(readed);
		return (NULL);
	}
	j = -1;
	while (readed[i + ++j + 1])
		nstr[j] = readed[i + j + 1];
	nstr[j] = 0;
	free(readed);
	return (nstr);
}

char	*extract_line(char *readed)
{
	char	*line;

	if (!readed || !*readed)
		return (NULL);
	line = ft_strdup(readed);
	if (ft_strchr(readed, '\n'))
		line[(int)(ft_strchr(readed, '\n') - readed) + 1] = 0;
	else
		line[ft_strlen(line)] = 0;
	return (line);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*read_eol(int fd, char *readed)
{
	char	*buffer;
	int		rd_bytes;

	if (!readed)
		readed = malloc(BUFFER_SIZE + 1 * sizeof(char));
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	rd_bytes = 1;
	while (rd_bytes > 0 && !ft_strchr(readed, '\n'))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(readed);
			readed = NULL;
		}
		else if (rd_bytes > 0)
		{
			buffer[rd_bytes] = 0;
			readed = join_and_free(readed, buffer);
		}
	}
	free(buffer);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*saved[4096];
	char		*line;
	char		*readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	if (!saved[fd])
		saved[fd] = ft_strdup("");
	readed = ft_strdup(saved[fd]);
	free(saved[fd]);
	readed = read_eol(fd, readed);
	if (!readed)
		return (NULL);
	line = extract_line(readed);
	saved[fd] = extract_nline(readed);
	if (!saved[fd])
		free(saved[fd]);
	return (line);
}
