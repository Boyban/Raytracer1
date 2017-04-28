/*
** my_color.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Mar 15 13:45:27 2017 Yohan
** Last update Sat Mar 18 17:00:12 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "graph.h"

t_color	take_color(t_var var, t_color color)
{
  color.red = var.red;
  color.blue = var.blue;
  color.green = var.green;
  color.opacity = var.opacity;
  color.var2 = var.intersection;
  color.cheat = var.cheat;
  color.seye = var.seye;
  color.cte = var.cte;
  return (color);
}

t_var	done_color(t_var var, t_color color, int val)
{
  var.red = color.red;
  var.green = color.green;
  var.blue = color.blue;
  var.opacity = color.opacity;
  var.intersection = color.var2;
  var.cheat = color.cheat;
  var.seye = color.seye;
  var.cte = color.cte;
  if (val == 42 && var.intersection < 0)
    var.intersection = 42;
  return (var);
}

void	my_color(t_my_framebuffer* buffer, int x, int y, t_var var)
{
  if (x < 0 || y < 0);
  else
    {
      buffer->pixels[(SCREEN_WIDTH * y + x) * 4] = var.red;
      buffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = var.green;
      buffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = var.blue;
      buffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = var.opacity;
    }
}
