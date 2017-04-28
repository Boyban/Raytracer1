/*
** graph.h for  in /home/Yohan/Graphical_Prog
** 
** Made by Yohan Lequere
** Login   <Yohan@epitech.net>
** 
** Started on  Mon Nov 14 16:45:05 2016 Yohan Lequere
** Last update Fri Apr 28 21:32:30 2017 Yohan
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include <math.h>

# define SCREEN_WIDTH 840
# define SCREEN_HEIGHT 640
# define WIDTH 840
# define HEIGHT 640
# define EYE_X	-500
# define EYE_Y	0
# define EYE_Z	100
# define R_PLANE 241
# define G_PLANE 255
# define B_PLANE 133
# define A_PLANE 60

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_float
{
  float			k;
  float			k2;
}			t_float;

typedef struct		s_color
{
  float			red;
  float			green;
  float			blue;
  float			opacity;
  float			var2;
  int			cheat;
  sfVector3f		seye;
  int			cte;
  int			shad;
  int			radius;
}			t_color;

typedef	struct		s_var
{
  char			**tab;
  sfVector3f		eye;
  sfVector2i		pos;
  sfVector2i		size;
  sfVector3f		dir;
  sfVector3f		seye;
  float			red;
  float			green;
  float			blue;
  float			opacity;
  float			intersection;
  int			cheat;
  char			**obj;
  char			**line;
  int			i;
  int			j;
  int			radius;
  int			cte;
  int			shad;
}			t_var;

t_my_framebuffer*	my_framebuffer_create();
t_var		parser(t_my_framebuffer *buffer, sfVector2i screen_size, t_var);
t_var		draw_sph(char*, t_my_framebuffer*, t_var);
sfVector3f      translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f      rotate_x(sfVector3f angles, float angle);
sfVector3f      rotate_y(sfVector3f angles, float angle);
sfVector3f      rotate_z(sfVector3f angles, float angle);
sfVector3f      rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f      rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
void            my_put_pixel(t_my_framebuffer* framebuffer, int x,
			     int y, sfColor color);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
sfVector3f      calc_dir_vector(float, sfVector2i, sfVector2i);
float           intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
				 float radius);
float           intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius);
float           intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius);
char		*get_next_line(const int, int);
int		my_strlen(char *);
int		my_strcmp(char *, char *);
char		**my_str_to_wordtab(char *, char);
int		my_get_nbr(char *);
sfVector3f      vec_light(sfVector3f dir, float k, sfVector3f screen_eye);
sfVector3f      my_vector(char **data, sfVector3f translations);
void		check_condition(t_var, t_my_framebuffer*, float);
t_var		init_pos(t_var);
void		my_color(t_my_framebuffer* buffer, int x, int y, t_var var);
t_var		my_open(t_var);
t_var		read_color(t_var, char*);
t_var		done_color(t_var var, t_color color, int);
t_color		take_color(t_var var, t_color color);
t_var		check_shad(t_var var, sfVector3f, int, int);
t_var		my_new_color(t_var, sfVector3f, sfVector3f);
sfVector3f	get_normal_sphere(sfVector3f);
sfVector3f	get_normal_cylinder(sfVector3f);
sfVector3f	get_normal_plan(int);
sfVector3f	get_normal_cone(sfVector3f, float);
void		free_tab(char**);
void		my_plan(sfVector3f, t_var, t_my_framebuffer*, float);
t_var		draw_cone(char*, t_my_framebuffer*, t_var);
float		get_light_coef(sfVector3f, sfVector3f);
t_var		my_spot(t_var, float);

#endif /* !GRAPH_H */
