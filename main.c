#include "headerfile.h"

Windows *windows;

void finish() {
    endwin();
}

int	main(void)
{
	if (atexit(finish) != 0)
	{
        perror("atexit");
        exit(EXIT_FAILURE);
    }

	initscr();
	refresh();



	windows = malloc(sizeof(Windows));
	if (windows == NULL)
		return(1);
	windows->wins = NULL;
	windows->win_count = 0;	
	windows->titles = NULL;
	
	
	createwin(topleft, "one");
	createwin(topright, "two");
	createwin(bottomleft, "tthreenia");
	createwin(bottomright, "4");
	// createwin_corner_topright();
	// createwin_corner_bottomright();
	// createwin_corner_topleft();
	// createwin_corner_bottomleft();
	// createwin_half_top();
	// createwin_half_bottom();
	// createwin_half_right();
	// createwin_half_left();

	int	ch;
	ch = getch();



	return(0);
}