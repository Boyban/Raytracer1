/*
** my_light.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Fri Mar 17 23:14:01 2017 Yohan
** Last update Sun Mar 19 16:28:01 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"

t_var	my_spot(t_var var, float angle)
{
  var.red = var.red * angle;
  var.green = var.green * angle;
  var.blue = var.blue * angle;
  return (var);
}

t_var	my_new_color(t_var var, sfVector3f obj, sfVector3f light)
{
  float	angle;

  if (var.cheat == 0)
    obj = get_normal_sphere(obj);
  else if (var.cheat == 1)
    obj = get_normal_cylinder(obj);
  else
    obj = get_normal_cone(obj, (float)var.cte);
  angle = get_light_coef(light, obj);
  if (angle > 0 && angle < 1)
    var = my_spot(var, angle);
  else
    {
      var.red = 0;
      var.green = 0;
      var.blue = 0;
    }
  return (var);
}
