#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

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

typedef struct Win {
	WINDOW	*frame;
	WINDOW	*content;
	char	*title;
} Win;

typedef struct Windows {
	Win		**wins;
	int		win_count;
} Windows;


extern	Windows *windows;

void	createwin(enum Win_type win_type, char *title);
void	main_loop();
void	get_keyboard_input();
void	display_windows_content();

#endif