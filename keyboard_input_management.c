#include "headerfile.h"

/* 
	Cette fonction surveille l'entrée clavier. Les fonctions qui seront executées ici mettront à jour l'état de l'application et appeleront les fonctions liées aux différents éléments.
 */

// TODO: des fonctions de mise à jour de l'état. Comment vais-je gérer l'état de l'app?
	void	get_keyboard_input()
{
	int	ch;
	ch = getch();
	switch(ch)
	{
		case 'q':
			exit(0);
		case KEY_UP:
			mvwprintw(stdscr, LINES - 1, 0, "UP!   ");
			break;
		case KEY_DOWN:
			mvwprintw(stdscr, LINES - 1, 0, "DOWN! ");
			break;
		case KEY_LEFT:
			mvwprintw(stdscr, LINES - 1, 0, "LEFT! ");
			break;
		case KEY_RIGHT:
			mvwprintw(stdscr, LINES - 1, 0, "RIGHT!");
			break;
		case KEY_ENTER:
			mvwprintw(stdscr, LINES - 1, 0, "ENTER!");
			break;
		case '\n':
			mvwprintw(stdscr, LINES - 1, 0, "ENTER!");
			break;
	}
}