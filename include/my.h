/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_H_
#define MY_H_

int my_strcmp(char const *s1, char const *s2);
char *convert_int_str(int nb);
char *my_revstr(char *str);
int my_strlen(char *str);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_put_nberror(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_memset(char *str, char c, int size);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *str1, char *str2);
void my_puterror(char *str);

#endif /* MY_H_ */
