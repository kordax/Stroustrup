// Test01.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define maxline 1000
#define eof -1

char line[maxline];
char save[maxline];
int max;

int getline()
{
	int c, i;
	extern char line [];
	for (i = 0; i < maxline - 1 && (c = getchar()) != eof && c != '\n'; i++)
		line[i] = c;
	i++;
	line[i] = '\0';
	return(i);
}

void copy()
{
	extern char line [];
	extern char save [];
	int i = 0;
	while ((save[i] = line[i]) != '\0')
		i++;
}

int main()
{
	int len;
	extern int max;
	extern char save [];
	max = 0;
	printf("Enter some strings >\n");
	while ((len = getline()) > 1)
	{
		if (len > max)
		{
			max = len;
			copy();
		}
	}
	if (max > 0)
		printf("Max string = %s\n", save);
	_getch();
	return(0);
}