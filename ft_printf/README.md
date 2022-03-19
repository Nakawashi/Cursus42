# Rewrite a light version of printf
Vous devez implémenter les conversions suivantes :
- %c Affiche un seul caractère.
- %s Affiche une chaîne de caractères (telle que définie par la convention C).
- %p L’argument de pointeur void -  doit être affiché en hexadécimal.
- %d Affiche un nombre décimal (base 10).
- %i Affiche un entier en base 10.
- %u Affiche un nombre décimal non signé (base 10).
- %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
- %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
- %% Affiche un signe pourcentage.

## How to compile
```
make (to generate the programm libftprintf.a)
gcc main.c libftprintf.a (will generate ./a.out)
./a.out (run to see main.c results)
```
then compare printf and my ft_printf