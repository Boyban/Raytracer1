/*
** my_put_pixel.c for  in /home/Yohan/Graphical_Prog
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Sun Dec 11 14:16:19 2016 Yohan Lequere
** Last update Thu Mar 16 19:53:14 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "graph.h"

void            my_put_pixel(t_my_framebuffer* framebuffer,
			     int x, int y, sfColor color)
{
  if (x < 0 || y < 0);
  else
    {
      framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4] = color.r;
      framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(SCREEN_WIDTH * y + x) * 4 + 3] = color.a;
    }
}
