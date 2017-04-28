/*
** make_shad.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Fri Mar 17 17:41:35 2017 Yohan
** Last update Sat Mar 18 16:39:18 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"

# define OBJ    "SPHERE|CYLINDER|CONE"

sfVector3f	my_point(float k, sfVector3f eye, sfVector3f dir)
{
  sfVector3f	point;

  point.x = eye.x + (k * dir.x);
  point.y = eye.y + (k * dir.y);
  point.z = eye.z + (k * dir.z);
  return (point);
}

float		my_plan_shad(int cond, sfVector3f light, sfVector3f point,
			     int radius)
{
  float		c;

  if (cond == 1)
    c = intersect_sphere(point, light, (float)radius);
  else if (cond == 2)
    c = intersect_cylinder(point, light, (float)radius);
  else if (cond == 3)
    c = intersect_cone(point, light, (float)radius);
  return (c);
}

t_var		check_shad(t_var var, sfVector3f eye, int cond, int radius)
{
  float		k;
  float		c;
  sfVector3f	point;
  sfVector3f	light;

  var.radius = radius;
  k = intersect_plane(var.eye, var.dir);
  if (k != -1)
    {
      point = my_point(k, eye, var.dir);
      light = vec_light(var.dir, k, eye);
      var.obj = my_str_to_wordtab(OBJ, '|');
      c = my_plan_shad(cond, light, point, radius);
      if ((c > 0 && c < 1) && var.intersection < 0)
	{
	  var.intersection = 42;
	  return (var);
	}
    }
  return (var);
}
