NCURSES LIBRARY

... l'occasion d'apprendre à créer une documentation pour un projet.

14/10/23:
- début du projet
- création de la fonction createwin(enum Win_type win_type, char *title)

Avec cette fonction, on crée une fenêtre aux dimensions définies par son type.
Pour l'instant, la fonction retourne (void), mais je peux lui faire retourner un code d'erreur si besoin.

La fenêtre créée est enregistrée dans la strcture définie ainsi:

typedef struct Win {
	WINDOW	*frame;
	WINDOW	*content;
	char	*title;
} Win;

typedef struct Windows {
	Win		**wins;
	int		win_count;
} Windows;

Les deux fenêtres sont gardées dans la structure Win, avec le titre, qui est malloc dans la fonction createwin().
les deux structures sont malloquées indépendamment aussi, ainsi que les pointeurs sur *Win.


la structure Windows est déclarée dans le headerfile ainsi:

extern	Windows *windows;
 

... et instanciée dans le fichir main (en dehors de la fonction!) ainsi:

Windows *windows;

********************
Prochaines étapes:
********************
- création de fonctions de libération de la mémoire
- création de fonctions d'affichage de contenu selon le type (lists, txt, tabs)
- gestion de l'état de l'application et des attributs
- fonctions de modification de l'état par utilisation du clavier
