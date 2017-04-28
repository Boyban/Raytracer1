/*
** free_tab.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Sat Mar 18 02:28:45 2017 Yohan
** Last update Sat Mar 18 12:24:07 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  while (i != 0)
    {
      free(tab[i]);
      --i;
    }
}
