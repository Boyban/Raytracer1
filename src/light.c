/*
** light.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Sun Mar 19 14:54:01 2017 Yohan
** Last update Sun Mar 19 16:27:40 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	n;
  float	n2;
  float	angle;

  n = sqrt((powf(normal_vector.x, 2) + powf(normal_vector.y, 2)
	    + powf(normal_vector.z, 2)));
  n2 = sqrt((powf(light_vector.x, 2)) + (powf(light_vector.y, 2))
	    + (powf(light_vector.z, 2)));
  normal_vector.x = normal_vector.x / n;
  normal_vector.y = normal_vector.y / n;
  normal_vector.z = normal_vector.z / n;
  light_vector.x = light_vector.x / n2;
  light_vector.y = light_vector.y / n2;
  light_vector.z = light_vector.z / n2;
  angle = (normal_vector.x * light_vector.x)
    + (normal_vector.y * light_vector.y) + (normal_vector.z * light_vector.z);
  return (angle);
}
