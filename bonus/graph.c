/*
** graph.c for  in /home/Yohan/Graphical_Prog
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Mon Nov 14 15:07:33 2016 Yohan Lequere
** Last update Sat Mar 18 16:20:51 2017 Yohan
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "graph.h"

sfRenderWindow* create_window(char* name, int width, int height)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return window;
}

sfUint8*		create_pixel(int width, int height)
{
  sfUint8*		pixel;
  int			i;

  i = 0;
  pixel = malloc(SCREEN_WIDTH * SCREEN_HEIGHT * 4 * sizeof(*pixel));
  while (i < (width * height * 4))
    {
      pixel[i] = 0;
      ++i;
    }
  return (pixel);
}

t_my_framebuffer*	my_framebuffer_create()
{
  t_my_framebuffer*	buffer;

  buffer = malloc(sizeof(buffer));
  buffer->pixels = create_pixel(SCREEN_WIDTH, SCREEN_HEIGHT);
  buffer->width = SCREEN_WIDTH;
  buffer->height = SCREEN_HEIGHT;
  return (buffer);
}

void	game_loop(sfRenderWindow *window, sfSprite *sprite,
		  t_my_framebuffer *buffer, sfTexture *texture)
{
  sfEvent		event;
  sfVector2i		screen_size;
  t_var			var;

  screen_size.x = SCREEN_WIDTH;
  screen_size.y = SCREEN_HEIGHT;
  buffer = my_framebuffer_create();
  var = parser(buffer, screen_size, var);
  sfTexture_updateFromPixels(texture, buffer->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      while (sfRenderWindow_pollEvent(window, &event))
	if (event.type == sfEvtClosed)
	  sfRenderWindow_close(window);
    }
}

int			main()
{
  sfVideoMode		mode = {WIDTH, HEIGHT, 32};
  sfRenderWindow*	window;
  t_my_framebuffer*	buffer;
  sfTexture		*texture;
  sfSprite		*sprite;

  mode = mode;
  window = create_window("Raytracer1", SCREEN_WIDTH, SCREEN_HEIGHT);
  buffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  game_loop(window, sprite, buffer, texture);
  sfRenderWindow_destroy(window);
  return (0);
}
