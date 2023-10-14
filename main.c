#include "headerfile.h"

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


	return(0);
}