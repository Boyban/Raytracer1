/*
** get_next_line.c for  in /home/yohan/Get_next_line
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Feb 22 11:33:07 2017 Yohan
** Last update Fri Mar 17 23:41:17 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "graph.h"

char    *my_strcat(char *str, char *buffer, int str_size)
{
  char  *tmp;
  int   i;

  i = 0;
  tmp = malloc(sizeof(char) * str_size + 2);
  while (i != str_size)
    {
      tmp[i] = str[i];
      ++i;
    }
  tmp[i] = buffer[0];
  i = i + 1;
  tmp[i] = '\0';
  return (tmp);
}

char	*get_next_line(const int fd, int i)
{
  char		*str;
  char		buffer[1];
  int		size;
  int		str_size;

  i = i;
  str = malloc(sizeof(char) * 1);
  str[0] = '\0';
  str_size = 0;
  while (1)
    {
      size = read(fd, buffer, 1);
      if (size == 0 && str[0] == '\0')
	return (NULL);
      buffer[size] = '\0';
      if (buffer[0] == '\n')
	return (str);
      str = my_strcat(str, buffer, str_size);
      ++str_size;
    }
}
