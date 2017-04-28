/*
** rotate.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1/src
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Thu Mar  9 17:17:53 2017 Yohan
** Last update Wed Mar 15 16:33:02 2017 Yohan
*/

#include <SFML/Graphics.h>
#include <math.h>

sfVector3f	rotate_x(sfVector3f angles, float angle)
{
  float	rotate;

  rotate = angles.y;
  angles.y = angles.y * cosf(angle) + angles.z * -sinf(angle);
  angles.z = rotate * sinf(angle) + angles.z * cosf(angle);
  return (angles);
}

sfVector3f	rotate_y(sfVector3f angles, float angle)
{
  float	rotate;

  rotate = angles.x;
  angles.x = angles.x * cosf(angle) + angles.z * sinf(angle);
  angles.z = rotate * -sinf(angle) + angles.z * cosf(angle);
  return (angles);
}

sfVector3f	rotate_z(sfVector3f angles, float angle)
{
  float	rotate;

  rotate = angles.x;
  angles.x = angles.x * cosf(angle) + angles.y * -sinf(angle);
  angles.y = rotate * sinf(angle) + angles.y * cosf(angle);
  return (angles);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_x(to_rotate, angles.x * M_PI / 180);
  to_rotate = rotate_y(to_rotate, angles.y * M_PI / 180);
  to_rotate = rotate_z(to_rotate, angles.z * M_PI / 180);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_z(to_rotate, angles.z * M_PI / 180);
  to_rotate = rotate_y(to_rotate, angles.y * M_PI / 180);
  to_rotate = rotate_x(to_rotate, angles.x * M_PI / 180);
  return (to_rotate);
}
