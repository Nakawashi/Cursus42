# Découper le travail

> [ ] Le Makefile ne relink pas et fonctionne avec les règles $(NAME), all, clean, fclean et relink <br>

## Parsing de la fenêtre

> [ ] Possible de fermer la fenetre via la croix<br>
> [ ] Possible de fermer la fenetre via ESC<br>
> [ ] Fenetre fluide mais **voir ce que ca veut dire**<br>
> [ ] Afficher le nombre de mouvements ici plutôt que dans le Shell<br>


## Parsing de la carte

> [ ] Bon nombre d'arguments au lancer du programme<br>
> [ ] Extension de la carte<br>
> [ ] Au moins une sortie, un item et une position de départ<br>
> [ ] Carte rectangulaire<br>
> [ ] On est bien entouré par des murs partout<br>
> [ ] Les murs nous bloquent le passage<br>
> [ ] Check toutes les cartes proposées et accepter celles qui sont OK avec tout<br>
> [ ] La map donnée en exemple dans le PDF fonctionne<br>


## Jeu

> [ ] Déplacements via W A S D<br>
> [ ] Incrémenter de 1 pour chaque mouvement effectué<br>
> [ ] Condition de victoire Ok : avoir collecté tous les items, sortir, afficher le nombre de mouvements<br>
> [ ] Mouvement des sprites<br>

## Erreurs

> Gestion des erreurs pour chaque evenement non OK. Quitter proprement le programme, avec des signaux probablement.<br>

### Objectif :<br>

Choisir mes sprites<br>

- murs / collisions
- sol normal
- perso
- items
- sortie<br>

Afficher une image fixe<br>
Afficher les bords de la map<br>
Definir la taille de la fenetre par rapport aux nombres d'elements a afficher<br>
Gerer le Makefile<br>

-> check si on a des parametres et si on recoit le bon type de fichier.