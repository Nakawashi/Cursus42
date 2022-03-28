# Découper le travail

> x Le Makefile ne relink pas et fonctionne avec les règles $(NAME), all, clean, fclean et relink <br>

## Parsing de la fenêtre

> x Possible de fermer la fenetre via la croix<br>
> x Possible de fermer la fenetre via ESC<br>
> x Fenetre fluide mais **voir ce que ca veut dire**<br>
> x Afficher le nombre de mouvements ici plutôt que dans le Shell<br>


## Parsing de la carte

> x Au moins une sortie, un item et une position de départ<br>
> x Extension de la carte<br>
> x Carte rectangulaire<br>
> x On est bien entouré par des murs partout<br>
> x Les murs nous bloquent le passage<br>
> x Check toutes les cartes proposées et accepter celles qui sont OK avec tout<br>
> x La map donnée en exemple dans le PDF fonctionne<br>


## Jeu

> x Déplacements via W A S D<br>
> x Incrémenter de 1 pour chaque mouvement effectué<br>
> x Avoir collecté tous les items, sortir, afficher le nombre de mouvements<br>
> x Mouvement des sprites<br>

## Erreurs

> Gestion des erreurs pour chaque evenement non OK. Quitter proprement le programme, avec des signaux probablement.<br>

Objectif :<br>
Choisir mes sprites<br>
- murs / collisions
- sol normal
- perso
- items
- sortie
Afficher ce qui est fixe d'abord. Une image, puis tout le mur autour.<br>
Definir ce qui seront les murs, les items, la sortie<br>
Definir la taille de la fenetre par rapport aux nombres d'elements a afficher<br>