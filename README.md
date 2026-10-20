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

# Juteau Gaëlle

## Fonctionnalités implémenter
Pour l'Interface et Expérience Utilisateur, j'ai implémenter la numerotation automatique des ID utilisateurs, afficher le nom d'utilisateur dans l'affichage des livres et detection des doublons plus intelligente
(J'ai fait les 3 parce que j'avais mal lu les consignes plus haut)
Pour Gestion des Données, j'ai implémenter le tri des résutats par titre, auteur pour l'affichage
J'ai implémenté le journal d'activités et corriger le bug

## Question 1: C++
La notion du code que je vais expliquer est la capture dans les lambadas. Une lambada est une fonction sans nom qu'on utilise directement à l'endroit ou on en a besoin. Dans le projet, c'est dans la fonction `findBookByISBN` avec `find_if` qui parcourt les livres et retourne le premier pour lequel la lambada retourne `true`. Les crochet sont la pour qu'on y mette à l'intérieur les variables extérieur qu'on a le droit d'utiliser. Il utilise le `&` pour dire qu'il utilise l'originale au lieu d'en faire une copie.

```cpp
Book* Library::findBookByISBN(const string& isbn) {
    auto it = find_if(books.begin(), books.end(),
        [&isbn](const unique_ptr<Book>& book) {
            return book->getISBN() == isbn;
        });
    
    return (it != books.end()) ? it->get() : nullptr;
}
```

## Question 2: Options de développement possible
Pour une solution plus adaptée à la gestion de la bibliothèque,j'utiliserais une base de données comme par exemple MySQL pour stocker les donnéesdes `User` et des `Book`. Ce serait plus adapté parce que plus il y a dedonnées, plus le projet ralentit, vu qu'il charge tous les livres et lesutilisateurs en mémoire au démarrage. Avec des millions de livres, commepour la bibliothèque d'Alexandrie, ça ne fonctionnerait plus. Les fichiers`users.txt` et `books.txt` deviendraient des tables dans la base dedonnées, et on ajouterait des index sur l'ISBN, le titre et l'auteur pourque les recherches restent rapides.