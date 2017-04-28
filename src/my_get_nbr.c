/*
** my_get_nbr.c for  in /home/yohan/Unix System Programmation/PSU_2016_navy_bootstrap
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Jan 30 12:24:51 2017 Yohan
** Last update Tue Mar 14 16:24:47 2017 Yohan
*/

#include "graph.h"

int	my_get_nbr(char *str)
{
  int	val;
  int	count;
  int	sous;
  int	j;

  j = my_strlen(str) - 1;
  val = 0;
  count = 1;
  sous = 0;
  while (str[j] >= 48 && str[j] <= 57 && j >= 0)
    {
      val = val + ((str[j] - 48) * count);
      count = count * 10;
      j = j - 1;
    }
  while (str[j] == '-')
    {
      sous = sous + 1;
      j = j - 1;
    }
  if (sous % 2 == 1)
    val = val * -1;
  return (val);
}
