#include "headerfile.h"

void	main_loop()
{

	while(42)
	{
		refresh();
		display_windows_content();
		get_keyboard_input();	
	}
}