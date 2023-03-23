/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gobarbos <gobarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:54:45 by gobarbos          #+#    #+#             */
/*   Updated: 2022/11/29 14:52:34 by gobarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_join(char *buff, char *temp_buff)
{
	char	*temp;

	temp = ft_strjoin(buff, temp_buff);
	free(buff);
	return (temp);
}

char	*read_file(int fd, char *buff)
{
	char	*temp_buff;
	int		byte;

	if (!buff)
		buff = ft_calloc(1, 1);
	temp_buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, temp_buff, BUFFER_SIZE);
		if (byte == -1 || (byte == 0 && temp_buff == NULL))
		{
			free(buff);
			free(temp_buff);
			return (NULL);
		}
		temp_buff[byte] = 0;
		buff = ft_free_join(buff, temp_buff);
		if (ft_strchr(buff, 10))
			break ;
	}
	free(temp_buff);
	return (buff);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*new_buff(char *buff)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new_buf = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		new_buf[j++] = buff[i++];
	free(buff);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	buff = new_buff(buff);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	if (argc > 1)
		printf("%s\n", get_next_line(fd));
}*/
