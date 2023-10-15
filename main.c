#include "headerfile.h"

Windows *windows;

void finish() {
    endwin();
}

void	init_windows_struct()
{
	windows = malloc(sizeof(Windows));
	if (windows == NULL)
		return;
	windows->wins = NULL;
	windows->win_count = 0;	
}

void	init_ncurses_settings()
{
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	curs_set(0);
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
}

int		main(void)
{
	if (atexit(finish) != 0)
	{
        perror("atexit");
        exit(EXIT_FAILURE);
    }

	// TODO: une fonction de paramètrage des settings? Quels settings adopter quand/où?
	init_ncurses_settings();
	init_windows_struct();

	createwin(topright, "two");
	createwin(bottomright, "4");
	createwin(bottomleft, "tthreenia");
	createwin(topleft, "one");
	// createwin_corner_topright();
	// createwin_corner_bottomright();
	// createwin_corner_topleft();
	// createwin_corner_bottomleft();
	// createwin_half_top();
	// createwin_half_bottom();
	// createwin_half_right();
	// createwin_half_left();

	main_loop();

	return(0);
}