# Push_swap

*Because Swap_push isn’t as natural*

## Summary:
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. </br>
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.</br>

*Version: 6*

## Authorized Operations
`sa` (swap a): Swap the first 2 elements at the top of stack a. <br>
Do nothing if there is only one or no elements.<br>
`sb` (swap b): Swap the first 2 elements at the top of stack b.<br>
Do nothing if there is only one or no elements.<br>
`ss` : sa and sb at the same time.<br>
`pa` (push a): Take the first element at the top of b and put it at the top of a.<br>
Do nothing if b is empty.<br>
`pb` (push b): Take the first element at the top of a and put it at the top of b.<br>
Do nothing if a is empty.<br>
`ra` (rotate a): Shift up all elements of stack a by 1.<br>
The first element becomes the last one.<br>
`rb` (rotate b): Shift up all elements of stack b by 1.<br>
The first element becomes the last one.<br>
`rr` : ra and rb at the same time.<br>
`rra` (reverse rotate a): Shift down all elements of stack a by 1.<br>
The last element becomes the first one.<br>
`rrb` (reverse rotate b): Shift down all elements of stack b by 1.<br>
The last element becomes the first one.<br>
`rrr` : rra and rrb at the same time.<br>

## Usage

1. Clone the repository
2. Use command `make`
3. Run the programm with arguments, either with our without double quotes :<br>
`./push swap "453 -50 78 5 42"` <br>
`./push swap 453 -50 78 5 42` <br>
Then it will print all the used operations necessary to sort it.<br>
You can use testers and visualizator from other repositories.<br>

## Routine in french

Gestion des cas d'erreurs en gardant un tableau de strings récupéré de argv.<br>
Création d'un tableau "template" qui va récupérer les valeurs d'un atoi. Ce tableau sera trié avec un quicksort pour me permettre de récupérer un pivot pour plus tard.<br>
Création d'un tableau intermédiaire qui va permettre de récupérer ces valeurs dans un nouvel emplacement mémoire, pour les copier dans chaque élément de ma liste chaînée. Ce pointeur sur int permet d'éviter de lier mon template avec la liste. Sinon lorsque je trie le tableau la liste sera aussi triée vu qu'ils pointent sur les mêmes adresses.<br>

### Trier deux éléments
Swap entre le premier élément de la liste et le second.

### Trier trois éléments
Comparer les trois valeurs et les trier manuellement avec une forêt de if/else if

### Trier cinq éléments
Jusqu'à ce que je n'aie plus que trois éléments dans ma pile a, je prends les deux valeurs les plus petites et les poussent sur b.<br>
Trier les valeurs sur a avec mon tri et pousser sur la pile a les deux valeurs qui attendaient dans la pile b.

### Trier plus d'éléments (mais doit être optimal pour 100 et 500)
Je fais des actions d'abord sur la pile a, ensuite sur la pile b. Rien de simultané (pas de `rr` ni `rrr`).<br>
Pour **100** valeurs à trier je divise la taille de la pile a en **5** (le plus opti pour moi).<br>
Pour **500** valeurs à trier je divise la taille de la pile a en **12** (le plus opti pour moi).<br>


