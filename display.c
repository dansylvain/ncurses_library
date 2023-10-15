#include "headerfile.h"

void	display_windows_content()
{
	int	i;

	i = 0;
	while (i < windows->win_count)
	{
		box(windows->wins[i]->frame, 0, 0);
		mvwprintw(windows->wins[i]->frame, 0, 0, ". %s ", windows->wins[i]->title);
		// TODO: funcs d'affichage des données selon types de données (lists, tabs, txt...)
		wrefresh(windows->wins[i]->frame);
		i++;
	}
}