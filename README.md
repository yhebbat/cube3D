                            UN JEU 3D AVEC LE LANGUAGE “C”
Le sujet
    Ce projet est inspiré du jeu Wolfenstein 3D. Mondialement connu, Wolfenstein 3D est considéré comme le premier FPS (c'est à dire un jeu de tire à la première personne) jamais développé.
		• L'objectif est de faire une vue dynamique (qui s'adapte au cours du temps selon les mouvements du joueur)
		• et subjective (on voit du point de vue des yeux du personnage)
		• au sein d’un labyrinthe ayant une représentation graphique 3D "réalistique", dans lequel on doit trouver son chemin.
Ce projet permet d'explorer la technique du ray-casting. (Le lancer de rayons est une technique de rendu capable de créer une perspective tridimensionnelle à partir d'une carte bidimensionnelle).

La 1ere etape a faire : c’est de parsing “avec le quelle on prend toute les information pour bien commencer”:
	le concepte est simple:
		- lire depuis un fichier précis grâce a get_next_line, qui copie ligne par ligne dans un variable et ensuite on peux sauvegarder les infos utiles dans des variables.
		-traiter les erreurs qui peuvent poser des problèmes au programme.
		-pour plus de détails chercher sur le codes.
		-toute explication demander seras dans le code dans le fichiers suivant :
			pars.c
 
La 2eme etape est de bien comprendre les fonctions de la minilibx :
	mlx_loop_hook() ;
	mlx_loop() ;
	mlx_new_window() ;
	mlx_new_image() ;
	mlx_destroy_image() ;
	mlx_hook() ;
	vous trouverais toute les explications ici:https://qst0.github.io/ft_libgfx/man_mlx.html	.
La 3eme chose est d’ouvrir une fenêtre et une image  et dessiner des carres, des ligne et des cercles .
	ft_utils.c
La 4eme étape dessiner la MINIMAP pour apprendre a utiliser la Minilibx.

La 5eme étape savoir récupérer les keys faire bouger le joueur dans la minimap.

La 6eme étape est le Raycasting les explication serons dans les photos suivant.

La 7eme étape est dessiner les murs .

La 8eme étape et d’ajouter les textures.

