/*
** my_strcmp.c for  in /home/yohan/fonction_tetris
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Thu Feb 23 22:17:27 2017 Yohan
** Last update Mon Mar 13 17:59:31 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "graph.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_strcmp(char *str, char *cmp)
{
  int	i;

  i = 0;
  if (str == NULL || cmp == NULL)
    return (-1);
  else if (my_strlen(str) !=  my_strlen(cmp))
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] != cmp[i])
	return (-1);
      ++i;
    }
  return (1);
}
