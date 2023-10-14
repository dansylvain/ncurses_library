#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct Contact {
	char	name[21];
	char	email[31];
	char	stone_skipping_record[10];
	char	favourite_pokemon[15];
    struct 	Contact *next;
	struct 	Contact *previous;
	
} Contact;

extern	Contact	*head;
extern	Contact	*tail;

// Prototypes here

#endif