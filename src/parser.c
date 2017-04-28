/*
** parser.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Mon Mar 13 17:05:27 2017 Yohan
** Last update Mon Mar 27 07:58:17 2017 Yohan
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"

# define OBJ	"SPHERE|CYLINDER|CONE"

t_var			draw_cyl(char *str, t_my_framebuffer *buffer, t_var var)
{
  sfVector3f		eye;
  static char		**know = NULL;
  static char		**data = NULL;
  sfVector3f		translations;

  eye.x = EYE_X;
  eye.y = EYE_Y;
  eye.z = EYE_Z;
  know = my_str_to_wordtab(str, '|');
  data = my_str_to_wordtab(know[0], ',');
  translations = my_vector(data, translations);
  eye = translate(eye, translations);
  var.dir = calc_dir_vector(500, var.size, var.pos);
  var.intersection = intersect_cylinder(eye, var.dir,
					(float)my_get_nbr(know[3]));
  var = read_color(var, know[2]);
  var.cheat = 1;
  var = check_shad(var, eye, 2, my_get_nbr(know[3]));
  buffer = buffer;
  free_tab(data);
  var.seye = eye;
  return (var);
}

t_var			draw_sph(char *str, t_my_framebuffer *buffer, t_var var)
{
  sfVector3f		eye;
  static char		**know = NULL;
  static char		**data = NULL;
  sfVector3f		translations;

  eye.x = EYE_X;
  eye.y = EYE_Y;
  eye.z = EYE_Z;
  know = my_str_to_wordtab(str, '|');
  data = my_str_to_wordtab(know[0], ',');
  translations = my_vector(data, translations);
  eye = translate(eye, translations);
  var.dir = calc_dir_vector(500, var.size, var.pos);
  var.intersection = intersect_sphere(eye, var.dir,
				      (float)my_get_nbr(know[3]));
  var = read_color(var, know[2]);
  var.cheat = 0;
  var = check_shad(var, eye, 1, my_get_nbr(know[3]));
  buffer = buffer;
  var.seye = eye;
  free_tab(data);
  return (var);
}

void		draw_pix(t_var var, t_my_framebuffer *buffer)
{
  sfVector3f	eye;
  float		k;

  eye.x = EYE_X;
  eye.y = EYE_Y;
  eye.z = EYE_Z;
  var.dir = calc_dir_vector(500, var.size, var.pos);
  k = intersect_plane(eye, var.dir);
  if (var.intersection == 42)
    my_put_pixel(buffer, var.pos.x, var.pos.y, sfBlack);
  else
    check_condition(var, buffer, k);
}

t_var		my_var(t_var var, t_var (**pointer)(), char **obj,
		       t_my_framebuffer *buffer)
{
  int		j;
  char		**line;
  int		i;
  int		val;
  t_color	color;

  j = -1;
  color.var2 = -1;
  while (var.tab[++j] != NULL)
    {
      i = 0;
      line = my_str_to_wordtab(var.tab[j], '=');
      while (my_strcmp(line[0], obj[i]) == -1 && obj[i] != '\0')
	++i;
      if (obj[i] != '\0')
	var = pointer[i](line[1], buffer, var);
      if (var.intersection == 42)
	val = 42;
      if ((color.var2 > var.intersection || color.var2 == -1)
	  && var.intersection > 0)
	color = take_color(var, color);
    }
  free_tab(line);
  var = done_color(var, color, val);
  return (var);
}

t_var			parser(t_my_framebuffer *buffer, sfVector2i screen_size,
			       t_var var)
{
  t_var			(*pointer[3])();
  static char		**obj = NULL;

  var = my_open(var);
  var = init_pos(var);
  if (obj == NULL)
    obj  = my_str_to_wordtab(OBJ, '|');
  var.cheat = -1;
  pointer[0] = &draw_sph;
  pointer[1] = &draw_cyl;
  pointer[2] = &draw_cone;
  while (var.pos.x != screen_size.x)
    {
      var.pos.y = 0;
      while (var.pos.y != screen_size.y)
	{
	  var.intersection = -1;
	  var = my_var(var, pointer, obj, buffer);
	  draw_pix(var, buffer);
	  ++var.pos.y;
	}
      ++var.pos.x;
    }
  return (var);
}
