# Push_Swap

Ce projet est un algorithme de tri réalisé dans le cadre du cursus de l'École 42. L'objectif est de trier une pile d'entiers, donnée en argument, en utilisant le moins d'opérations de "swap" possible, à l'aide de deux piles (stack A et stack B).

La pile A est initialisée avec les nombres fournis en argument. La pile B est initialement vide et sert d'espace de manœuvre.

## Opérations autorisées

Le tri doit être effectué en n'utilisant que les opérations suivantes :

- sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.

- sb (swap b) : Intervertit les 2 premiers éléments au sommet de la pile b.

- ss : sa et sb en même temps.

- pa (push a) : Prend le premier élément au sommet de b et le met sur a.

- pb (push b) : Prend le premier élément au sommet de a et le met sur b.

- ra (rotate a) : Décale d'une position vers le haut tous les éléments de la pile a (le premier devient le dernier).

- rb (rotate b) : Décale d'une position vers le haut tous les éléments de la pile b.

- rr : ra et rb en même temps.

- rra (reverse rotate a) : Décale d'une position vers le bas tous les éléments de la pile a (le dernier devient le premier).

- rrb (reverse rotate b) : Décale d'une position vers le bas tous les éléments de la pile b.

- rrr : rra et rrb en même temps.

## Algoritme

L'algorithme utilisé dans ce projet est conçu pour être efficace et optimisé afin de réduire le nombre d'instructions. Il est inspiré de l'algorithme "turc" (cf. https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

**Gestion des erreurs:** Le programme vérifie en amont si les arguments sont valides (uniquement des nombres, pas de doublons, pas de dépassement de la limite int).

**Tri pour 3 nombres:** Si la pile A ne contient que 3 nombres, un tri spécifique (sort_three) est appliqué pour les trier en un minimum de coups.

##### Algorithme principal (pour N > 3) :

Deux éléments sont d'abord poussés de A vers B pour initialiser la pile B.

Tant qu'il y a plus de 3 éléments dans A, le programme entre dans une boucle d'optimisation :

**Analyse des coûts:** Pour chaque élément de A, l'algorithme calcule sa "cible" (target) dans B et le "coût" en opérations (ra, rb, rr, rra, rrb, rrr) pour amener cet élément et sa cible au sommet de leurs piles respectives.

**Meilleur coup:** L'élément avec le coût le plus faible (is_good_one) est identifié.

**Exécution:** Les rotations calculées sont effectuées, et l'élément est poussé de A vers B (pb).

Une fois A réduit à 3 éléments, le sort_three est appliqué sur A.

**Retour vers A:** Les éléments sont ensuite rapatriés de B vers A. L'algorithme identifie la cible correcte dans A pour chaque élément de B et effectue les rotations nécessaires avant de "pousser" (pa).

**Finalisation:** La pile A est finalement tournée (rra) jusqu'à ce que le plus petit nombre soit au sommet, garantissant qu'elle est parfaitement triée.

## Compilation et Utilisation

Pour compiler, utilisez le ````Makefile```` fourni:

```bash
make
```

Cela générera l'exécutable ````push_swap````.

## Exécuter le programme

Le programme peut prendre les nombres en argument de deux manières:

1. En tant qu'arguments multiples:

```bash
./push_swap 2 1 3 6 5 8
```
2. En tant que chaîne de caractères unique (les nombres séparés par des espaces) :

````bash
./push_swap "2 1 3 6 5 8"
````

Le programme affichera sur la sortie standard la liste des opérations à effectuer.
