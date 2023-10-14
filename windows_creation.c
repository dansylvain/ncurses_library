#include "headerfile.h"

/* 
	The values defined in get_win_size depend on the value of enum win_type.
	More window types can be added by adding cases and enum values.

	The windows created have a frame (with func box). The content window that is returned is smaller, so that the frame is not erased by the content.
 */

int	*get_win_size(enum Win_type win_type)
{
	int *win_size = malloc(sizeof(int) * 4);
	if (!win_size)
		return(NULL);
	switch (win_type)
	{

		case fullsize:
			win_size[0] = LINES - 1;
			win_size[1] = COLS;
			win_size[2] = 0;
			win_size[3] = 0;
			break;
		case halfleft:
			win_size[0] = LINES - 1;
			win_size[1] = COLS / 2;
			win_size[2] = 0;
			win_size[3] = 0;
			break;
		case halfright:
			win_size[0] = LINES - 1;
			win_size[1] = COLS / 2;
			win_size[2] = 0;
			win_size[3] = COLS / 2;
			break;
		case halftop:
			win_size[0] = LINES / 2;
			win_size[1] = COLS;
			win_size[2] = 0;
			win_size[3] = 0;
			break;
		case halfbottom:
			win_size[0] = LINES / 2;
			win_size[1] = COLS;
			win_size[2] = LINES / 2;
			win_size[3] = 0;
			break;
		case topleft:
			win_size[0] = LINES / 2;
			win_size[1] = COLS / 2;
			win_size[2] = 0;
			win_size[3] = 0;
			break;
		case topright:
			win_size[0] = LINES / 2;
			win_size[1] = COLS / 2;
			win_size[2] = 0;
			win_size[3] = COLS / 2;
			break;
		case bottomleft:
			win_size[0] = LINES / 2;
			win_size[1] = COLS / 2;
			win_size[2] = LINES / 2;
			win_size[3] = 0;
			break;
		case bottomright:
			win_size[0] = LINES / 2;
			win_size[1] = COLS / 2;
			win_size[2] = LINES / 2;
			win_size[3] = COLS / 2;
			break;
	}
	return (win_size);
}

void	createwin(enum Win_type win_type, char *title)
{
	int	*win_size = get_win_size(win_type); //depending on win type spcified

	// Cration of windows
	WINDOW	*win;
	win = newwin(win_size[0], win_size[1], win_size[2], win_size[3]);
	WINDOW	*win_content;
	win_content = newwin(win_size[0] - 2, win_size[1] - 2, win_size[2] + 1, win_size[3] + 1);

	// memo allocation for the pointers (not handled by newwin in this case!)
	if (windows->win_count == 0)
	{
        windows->wins = malloc(sizeof(WINDOW *));
		windows->titles = malloc(sizeof(WINDOW *));
	}
	else
	{
        windows->wins = realloc(windows->wins, sizeof(WINDOW *) * (windows->win_count + 1));
        windows->titles = realloc(windows->titles, sizeof(WINDOW *)*(windows->win_count+1));
	}
	if (windows->wins == NULL || windows->titles == NULL)
		return;
		
	
	// add new window to + changing data of struct Window
	windows->wins[windows->win_count] = win_content;
	windows->titles[windows->win_count] = strdup(title)	;
	windows->win_count++;

	// TODO this refreshing part belongs to a function of its own (some code below)
	box(win, 0, 0);
	if (title)
		wprintw(win, ". %s ", windows->titles[windows->win_count - 1]);
	wrefresh(win);
	wrefresh(win_content);
}