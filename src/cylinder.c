/*
** intersect_cyl.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Fri Feb 24 16:53:51 2017 Yohan
** Last update Sun Mar 19 15:27:19 2017 Yohan
*/

#include <SFML/Graphics.h>
#include <math.h>

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}

float	get_cyl(float a, float b, float delta)
{
  float k;
  float k2;

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

float   intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
			   float radius)
{
  sfVector3f	cyl;
  float		delta;
  float		k1;

  cyl.x = (dir_vector.x * dir_vector.x)  + (dir_vector.y * dir_vector.y);
  cyl.y = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y));
  cyl.z = (eye_pos.x * eye_pos.x)
    + (eye_pos.y * eye_pos.y) - (radius * radius);
  delta = (cyl.y * cyl.y) - (4 * cyl.x * cyl.z);
  if (delta < 0)
    return (-1);
  else if (delta == 0)
    return (k1 = (-cyl.y / (2 * cyl.x)));
  return (get_cyl(cyl.x, cyl.y, delta));
}
