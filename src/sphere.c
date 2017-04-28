/*
** intersect_sphere.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Feb  8 21:02:09 2017 Yohan
** Last update Sun Mar 19 14:52:41 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

float	get_my_k(float a, float b, float delta)
{
  float	k;
  float	k2;

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

float	intersect_sphere(sfVector3f eye_pos,
			 sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;

  a = (dir_vector.x * dir_vector.x) + (dir_vector.y * dir_vector.y)
    + (dir_vector.z * dir_vector.z);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y)
	   + (eye_pos.z * dir_vector.z));
  c = ((eye_pos.x * eye_pos.x) + (eye_pos.y * eye_pos.y)
       + (eye_pos.z * eye_pos.z)) - (radius * radius);
  delta = (b * b) - (4 * a * c);
  if (delta < 0)
    return (-1);
  b = -b;
  if (delta == 0)
    return (delta = (b / (2 * a)));
  return (get_my_k(a, b, delta));
}
