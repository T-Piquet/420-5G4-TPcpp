# Construire le projet

Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`

# Zachary Lewis

## Fonctionnalités choisi

1. Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.
2. Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

# Questions

## Question 1 : C++

J'ai utilisé quelques notions que nous n'avons pas vues dans le cours.  
Voici celles que je vais expliquer :

```cpp
time_t maintenant = time(nullptr);
tm* dateHeure = localtime(&maintenant);
...
put_time(dateHeure, "%Y-%m-%d %H:%M:%S")
```

### Première ligne

`time_t` : type qui représente un nombre de secondes écoulées depuis le 1er janvier 1970\
`time(nullptr)` : demande l'heure actuelle (nullptr = ne pas stocker le résultat ailleurs)

### Deuxième ligne

`tm*` : pointeur vers une structure contenant la date et l'heure\
`localetime(&maintenant)` : fonction qui transforme un `time_t` en une structure `tm`

### Troisième ligne

`put_time(...)` : fonction qui formate une structure `tm` en texte lisible\
`"%Y-%m-%d %H:%M:%S"` : format du texte désiré (année-mois-jour heure:minute:seconde)

## Question 2 : Options de développement possible

Une bibliothèque pouvant contenir des millions de livres ne devrait pas être sauvegardée localement. Pour gérer efficacement un volume aussi important, j’utiliserais une base de données relationnelle. Plusieurs solutions existent, mais j’opterais pour `MySQL`, qui est adaptée aux très grands ensembles de données et offre des mécanismes d’indexation, de requêtes optimisées et de réplication.

Pour interfacer cette base de données avec mon programme en `C++`, j’utiliserais le connecteur officiel `MySQL Connector/C++`.
Le rôle du `C++` serait alors :

- d’envoyer des requêtes `SQL` à la base de données ;

* de récupérer les résultats ;

- de transformer ces résultats en objets `C++` (ex. Livre, Auteur, etc.).

Cette solution est adaptée au futur de la bibliothèque, car :

- **Scalabilité** : la base de données peut être déployée sur plusieurs serveurs, répliquée et sauvegardée facilement.

* **Performance** : `MySQL` est optimisé pour gérer des millions d’enregistrements avec des index et des requêtes rapides.

- **Évolutivité** : on peut ajouter des champs ou modifier la structure des données sans réécrire tout le programme `C++`.

* **Interopérabilité** : d’autres applications (site web, application mobile, bornes de consultation) peuvent utiliser la même base de données ou une API qui s’appuie dessus.
