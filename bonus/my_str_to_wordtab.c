/*
** my_str_to_wordtab.c for  in /home/yohan/Unix System Programmation/PSU_2016_minishell1
** 
** Made by Yohan
** Login   <yohan.le-quere@epitech.eu>
** 
** Started on  Wed Jan 18 21:57:53 2017 Yohan
** Last update Sun Mar  5 23:38:08 2017 Yohan
*/

#include <stdlib.h>
#include <ncurses.h>

int	number(int check, int word)
{
  if (check >= 1)
    return (word + 1);
  else
    return (word);
}

int	count_word(char *str, char cond)
{
  int	i;
  int	word;
  int	check;

  word = 0;
  i = 0;
  check = 0;
  if (str == 0)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] == cond)
	{
	  ++word;
	  while (str[i] == cond)
	    {
	      ++i;
	    }
	}
      if (str[i] != cond && str[i] >= 32)
	++check;
      ++i;
    }
  return (number(check, word));
}

int	nb_char(char *str, char cond, int i)
{
  int	nb;

  nb = 0;
  if (str[i] == cond)
    while (str[i] == cond)
      ++i;
  while (str[i] != cond && str[i] != '\0')
    {
      ++nb;
      ++i;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char cond)
{
  char	**tab;
  int	i;
  int	j;
  int	p;

  i = 0;
  p = 0;
  if (str == NULL)
    return (NULL);
  tab = malloc(sizeof(char *) * count_word(str, cond));
  while (str[i] != '\0')
    {
      j = 0;
      tab[p] = malloc(sizeof(char) * nb_char(str, cond, i));
      while (str[i] != cond && str[i] != '\0')
	  tab[p][j++] = str[i++];
      tab[p++][j] = '\0';
      while (str[i] == cond && str[i++] != '\0');
    }
  tab[p] = NULL;
  return (tab);
}
