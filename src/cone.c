/*
** intersect_cone.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Mar 15 17:53:45 2017 Yohan
** Last update Sun Mar 19 15:15:37 2017 Yohan
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "graph.h"

t_var                   draw_cone(char *str, t_my_framebuffer *buffer,
				  t_var var)
{
  sfVector3f            eye;
  static char           **know = NULL;
  static char           **data = NULL;
  sfVector3f            translations;

  eye.x = EYE_X;
  eye.y = EYE_Y;
  eye.z = EYE_Z;
  know = my_str_to_wordtab(str, '|');
  data = my_str_to_wordtab(know[0], ',');
  translations = my_vector(data, translations);
  eye = translate(eye, translations);
  var.dir = calc_dir_vector(500, var.size, var.pos);
  var.intersection = intersect_cone(eye, var.dir,
                                      (float)my_get_nbr(know[3]));
  var = read_color(var, know[2]);
  var.cheat = 2;
  var.cte = my_get_nbr(know[3]);
  var = check_shad(var, eye, 3, my_get_nbr(know[3]));
  buffer = buffer;
  var.seye = eye;
  return (var);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  semiangle = (semiangle * M_PI) / 180;
  intersection_point.z = intersection_point.z * tanf(-semiangle);
  return (intersection_point);
}

float	my_coeff(float a, float b, float delta)
{
  float	k;
  float	k2;

  b = -b;
  k = ((b + sqrt(delta)) / (2 * a));
  k2 = ((b - sqrt(delta)) / (2 * a));
  if (k > 0 && k2 > 0)
    {
      if (k > k2)
	return (k2);
      else
	return (k);
    }
  else if (k > 0)
    return (k);
  else if (k2 > 0)
    return (k2);
  return (-1);
}

float	intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
		       float semiangle)
{
  float	angle;
  float	delta;
  float	a;
  float	b;
  float	c;
  float	tang;

  angle = (semiangle * M_PI) / 180;
  tang = powf(tanf(angle), 2);
  a = powf(dir_vector.x, 2) + powf(dir_vector.y, 2)
    - (powf(dir_vector.z, 2) * tang);
  b = (2 * eye_pos.x * dir_vector.x) + (2 * eye_pos.y * dir_vector.y)
    - ((2 * eye_pos.z * dir_vector.z) * tang);
  c = powf(eye_pos.x, 2) + powf(eye_pos.y, 2) - (powf(eye_pos.z, 2) * tang);
  delta = (b * b) - (4 * a * c);
  if (delta == 0)
    return (delta = (-b) / (2 * a));
  else if (delta < 0)
    return (-1);
  delta = my_coeff(a, b, delta);
  return (delta);
}
