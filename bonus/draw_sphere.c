/*
** draw_sphere.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Feb  8 21:35:49 2017 Yohan
** Last update Sun Mar 19 00:10:14 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "graph.h"

sfVector3f	vec_light(sfVector3f dir, float k, sfVector3f screen_eye)
{
  sfVector3f	obj;
  sfVector3f	light;
  sfVector3f	sun;

  sun.x = -200;
  sun.y = 200;
  sun.z = 200;
  obj.x = screen_eye.x + (k * dir.x);
  obj.y = screen_eye.y + (k * dir.y);
  obj.z = screen_eye.z + (k * dir.z);
  light.x = sun.x - obj.x;
  light.y = sun.y - obj.y;
  light.z = sun.z - obj.z;
  return (light);
}
