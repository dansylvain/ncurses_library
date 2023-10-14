NCURSES LIBRARY

... l'occasion d'apprendre à créer une documentation pour un projet.

14/10/23:
- début du projet
- création de la fonction createwin(enum Win_type win_type, char *title)

Avec cette fonction, on crée une fenêtre aux dimensions définies par son type.
Pour l'instant, la fonction retourne (void), mais je peux lui faire retourner un code d'erreur si besoin.

La fenêtre créée est enregistrée dans la strcture définie ainsi:

typedef struct Windows {
	WINDOW	**wins;
	char	**titles;
	int		win_count;
} Windows;


... déclarée dans l haderfile ainsi:

extern	Windows *windows;
 

... et instancié dans le fichir main (en dehors de la fonction!) ainsi:

Windows *windows;
