/*
** translate.c for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Thu Mar  9 16:58:56 2017 Yohan
** Last update Thu Mar  9 18:10:08 2017 Yohan
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	new;

  new.x = to_translate.x + translations.x;
  new.y = to_translate.y + translations.y;
  new.z = to_translate.z + translations.z;
  return (new);
}
