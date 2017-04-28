/*
** calc_dir_vector.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Feb  8 20:47:51 2017 Yohan
** Last update Sun Mar 19 16:27:27 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	coord;

  coord.x = dist_to_plane;
  coord.y = (screen_size.x / 2) - screen_pos.x;
  coord.z = (screen_size.y / 2) - screen_pos.y;
  return (coord);
}
