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
			win_size[0] = LINES / 2	;
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

	// Creation of struct
	Win	*new_win;
	new_win = malloc(sizeof(Win));
	if (new_win == NULL)
		return;

	// Creation of windows
	WINDOW	*win;
	win = newwin(win_size[0], win_size[1], win_size[2], win_size[3]);
	WINDOW	*win_content;
	win_content = newwin(win_size[0] - 2, win_size[1] - 2, win_size[2]+1, win_size[3] + 1);

	// creation of string title
	char *win_title = strdup(title);
	if (win_title == NULL)
		return;

	// memory allocation for new pointer to Win
	if (windows->win_count == 0)
        windows->wins = malloc(sizeof(Win *));
    else
        windows->wins = realloc(windows->wins, sizeof(Win *) * (windows->win_count + 1));
    if (windows->wins == NULL)
        return;

	// assignation of newly created windows and data to struct pointers
	new_win->frame = win;
	new_win->content = win_content;
	new_win->title = win_title;
	windows->wins[windows->win_count] = new_win;
	windows->win_count++;
		
	// TODO this refreshing part belongs to a function of its own (some code below)
}