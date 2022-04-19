> Grafikart : https://www.youtube.com/watch?v=2VV9FAQWHdw

# Global

<cible>: <dependences>
	<commande>

Si on ecrit juste "make", la première commande sera lancée.

L'arobase avant le echo @echo va silent le texte non désiré (teste avec et sans tu verras)

# .PHONY

Signifie "faux" / "fake"<br>
On y inscrit les cibles qui ne sont pas de vrai fichiers, nos commandes custom, inventées. Ce sont des commandes qui sont lancees en permanence.

# Variables spéciales

$@ = nom de la cible
$< = première dépendence
$^ = liste des dépendences
$? = liste des dépendences plus récentes que la cible
$* = nom du fichier, sans son extension

# Vers la librairie
-lft
-lmlx
Pour trouver le nom, enlever le mot "lib" du .a et ecrire la suite.<br>
Exemple : libftprintf sera -lftprintf

%.o : %.c = toutes les cibles en .o seront créées avec toutes les dependences en .c


