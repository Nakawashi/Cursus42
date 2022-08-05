# Philosopher [...%]

*Qui aurait cru que philosopher serait si mortel ?*

## Summary:
Ce projet est une introduction au threading, aux processus et sur comment travailler sur le même espace mémoire.</br>
Vous apprendrez à manipuler des threads.</br>
Vous découvrirez les mutex, les sémaphores et la mémoire partagée.</br>

*Version: 9*

## A savoir
- Des philosophes (un minimum) sont assis autour d'une table ronde au centre de laquelle se trouve un grand plat de spaghetti.
- Les philosophes sont soit en train de **manger**, de **penser** ou de **dormir**.
Lorsqu'ils mangent, ils ne peuvent pas penser ou dormir.
Lorsqu'ils dorment, ils ne peuvent pas manger ou penser.
Enfin, lorsqu'ils pensent, ils en peuvent pas manger ou dormir.
- Il y a également des fourchettes sur la table : autant que de philosophers.
- Puisque servir et manger des spaghetti à l'aide d'une seule fourchette n'est pas chose facile, un philosophe prend la fourchette sur sa gauche et celle sur sa droite, soit une fourchette dans chaque main, afin de manger.
- Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un philosophe meurt de faim.
- Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
- Les philosophes ne communiquent pas entre eux.
- Les philosophes ne peuvent pas savoir si l'un d'entre eux est sur le point de mourir.
- Inutile de préciser que les philosophes ne doivent pas mourir !

## Règles communes
Programme concernant la partie obligatoire :
- Variables globales interdites !
- Arguments :
`[number_of_philosophers]` : nb de philosophes, mais aussi nb de fourchettes </br>
`[time_to_die]` (en millisecondes) : Si un philosophe n'a pas commencé à manger `[cette valeur]` après le début de son précédent repas ou depuis le début de la simulation, il meurt. </br>
`[time_to_eat]` (en millisecones) : Le temps qu'un philosophe prend à manger. Pendant ce temps, le philosophe doit garder ses deux fourchettes. </br>
`[time_to_sleep]` (en millisecondes) : Le temps qu'un philosophe passe à dormir. </br>
`[number_of_times_each_philosopher_must_eat]` (arg optionnel) : Si tous les philosophes ont mangé au moins `[cette valeur]` de fois, la simulation prend fin. Si cet argument n'est pas spécifié, alors la simulation prend fin à la mort d'un philosophe. </br>
- Chaque philosophe se voit assigner un numéro entre 1 et `[number_of_philosophers]`
- Le philosophe numéro 1 est assis à côté du philosophe numéro `[number_of_philosophers]`. les autres suivent cette logique, ils sont donc en cercle.

Concernant les logs de votre programme :
- Tout changement d'état d'un philosophe doit être formatté comme suit :
	- `timestamp_in_ms` X has taken a fork
	- `timestamp_in_ms` X is eating
	- `timestamp_in_ms` X is sleeping
	- `timestamp_in_ms` X is thinking
	- `timestamp_in_ms` X died

(`timestamp_in_ms` = timestamp actuel en ms. X = numéro du philosophe)

- Tout message affiché ne doit pas être mélangé avec un autre message.
- Il ne doit pas y avoir plus de 10 ms entre la mort d'un philosophe et l'affichage du message annonçant sa mort.
- Encore une fois, les philosophes doivent éviter de mourir.

## Règles spécifiques
- Chaque philosophe doit être représenté par un *thread*
- Une fourchette est placée entre chaque paire de philosophes. Cela signifique que, s'il y a plusieurs philosophes, chaque philosophe a une fourchette à sa gauche et une à sa droite. S'il n'y a qu'un seul philosophe, il n'y aura donc qu'une seule fourchette à sa table.
- Afin d'empêcher les philosophes de dupliquer les fourchettes, vous devez protéger leur état en mémoire avec un **mutex** pour chacune d'entre elle.

## Usage

1. Clone the repository
2. Use command `make`
3. Run the programm ...

## Routine

## Gestion des Leaks

## Améliorations

