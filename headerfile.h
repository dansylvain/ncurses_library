#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct Windows {
	WINDOW	**wins;
	char	**titles;
	int		win_count;
} Windows;

extern	Windows *windows;

enum Win_type {
	fullsize,
	halfleft,
	halfright,
	halftop,
	halfbottom,
	topleft,
	topright,
	bottomleft,
	bottomright
};



void	createwin(enum Win_type win_type, char *title);

#endif