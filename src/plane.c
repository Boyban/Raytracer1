/*
** intersect_plane.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Thu Feb  9 11:36:51 2017 Yohan
** Last update Sun Mar 19 16:17:32 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "graph.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	plan;

  plan.x = 0;
  plan.y = 0;
  if (upward == 1)
    plan.z = 100;
  else
    plan.z = -100;
  return (plan);
}

void		my_plan(sfVector3f light, t_var var, t_my_framebuffer *buffer,
			float k)
{
  sfVector3f	obj;
  float		angle;

  k = k;
  obj = get_normal_plane(1);
  angle = get_light_coef(light, obj);
  var.red = R_PLANE;
  var.green = G_PLANE;
  var.blue = B_PLANE;
  var.opacity = A_PLANE;
  var = my_spot(var, angle);
  my_color(buffer, var.pos.x, var.pos.y, var);
}

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z == 0)
    return (-1);
  else if (dir_vector.z != 0)
  {
    k = -eye_pos.z / dir_vector.z;
      if (k <= 0)
	return (-1);
      else
	return (k);
  }
  return (-1);
}
