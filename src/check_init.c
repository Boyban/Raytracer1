/*
** check_init.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Mar 15 13:10:45 2017 Yohan
** Last update Sun Mar 19 16:01:06 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"

t_var	init_pos(t_var var)
{
  var.pos.x = 0;
  var.pos.y = 0;
  var.size.x = SCREEN_WIDTH;
  var.size.y = SCREEN_HEIGHT;
  var.eye.x = EYE_X;
  var.eye.y = EYE_Y;
  var.eye.z = EYE_Z;
  return (var);
}

t_var	read_color(t_var var, char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ',');
  var.red = (float)my_get_nbr(tab[0]);
  var.green = (float)my_get_nbr(tab[1]);
  var.blue = (float)my_get_nbr(tab[2]);
  var.opacity = (float)my_get_nbr(tab[3]);
  return (var);
}

void    check_condition(t_var var, t_my_framebuffer *buffer, float k)
{
  sfVector3f	obj;
  sfVector3f	light;
  sfVector3f	light_plan;

  obj.x = var.seye.x + (var.intersection * var.dir.x);
  obj.y = var.seye.y + (var.intersection * var.dir.y);
  obj.z = var.seye.z + (var.intersection * var.dir.z);
  light = vec_light(var.dir, var.intersection, var.seye);
  light_plan = vec_light(var.dir, k, var.eye);
  var = my_new_color(var, obj, light);
  if (k > 0 && var.intersection > 0)
    {
      if (var.intersection < k)
        my_color(buffer, var.pos.x, var.pos.y, var);
      else
        my_plan(light_plan, var, buffer, k);
    }
  else if (var.intersection > 0)
    my_color(buffer, var.pos.x, var.pos.y, var);
  else if (k > 0)
    my_plan(light_plan, var, buffer, k);
  else
    my_put_pixel(buffer, var.pos.x, var.pos.y, sfBlack);
}

t_var   my_open(t_var var)
{
  int		fd;
  int		j;
  static int	i = 0;

  j = 0;
  if (i == 0)
    {
      fd = open("config.txt", O_RDONLY);
      while (get_next_line(fd, 1) != NULL)
	++j;
      var.tab = malloc(sizeof(char *) * j + 1);
      j = 0;
      fd = open("config.txt", O_RDONLY);
      while ((var.tab[j] = get_next_line(fd, 1)) != NULL)
	++j;
      var.tab[j + 1] = NULL;
      ++i;
    }
  return (var);
}

sfVector3f      my_vector(char **data, sfVector3f translations)
{
  int		x;
  int		y;
  int		z;

  x = my_get_nbr(data[0]);
  y = my_get_nbr(data[1]);
  z = my_get_nbr(data[2]);
  x = -x;
  y = y;
  z = -z;
  translations.x = (float)x;
  translations.y = (float)y;
  translations.z = (float)z;
  return (translations);
}
