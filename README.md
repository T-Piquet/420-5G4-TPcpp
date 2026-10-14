# TP1 — Gestion de bibliothèque

**Nom :** Noncent  
**Prénom :** Marvens

## Fonctionnalités implémentées

### 1. Tri des livres
J'ai ajouté l'option 14 qui permet d'afficher les livres triés par titre ou par auteur. J'ai utilisé `std::sort` pour effectuer le tri.

### 2. Génération automatique des ID
J'ai ajouté l'option 15 qui permet de créer un utilisateur avec un identifiant généré automatiquement. Le programme recherche le plus grand ID existant et génère le suivant pour éviter les doublons.

### 3. Journal d'activités
J'ai créé les fichiers `journal.h` et `journal.cpp` pour enregistrer les activités de la bibliothèque dans `journal.txt`. Le journal conserve la date, l'heure et les informations concernant les ajouts, suppressions, emprunts et retours de livres.

## Veille technologique

### Question 1 — C++

Une notion que nous avons peu vue en cours est l'utilisation des **fonctions lambda avec `std::sort`**. Une fonction lambda est une fonction anonyme que l'on peut écrire directement dans une instruction. Dans mon projet, je l'utilise pour comparer les titres ou les auteurs des livres afin de les trier. Cela permet d'éviter de créer une fonction de comparaison séparée et rend le code plus simple.

Voici un exemple tiré de mon code dans `library.cpp` :

```cpp
sort(sortedBooks.begin(), sortedBooks.end(),
    [](Book* a, Book* b) {
        return a->getTitle() < b->getTitle();
    });
```

Dans cet exemple, `std::sort` parcourt le vecteur `sortedBooks` et utilise la fonction lambda pour comparer deux livres. La méthode `getTitle()` récupère leur titre et l'opérateur `<` détermine leur ordre alphabétique. Le même principe est utilisé pour trier les livres par auteur.

### Question 2 — Options de développement possibles

Pour une bibliothèque comme celle d'Alexandrie qui pourrait contenir des millions de livres, je proposerais d'utiliser une base de données PostgreSQL plutôt que des fichiers texte. Cela permettrait de gérer une grande quantité de livres et d'effectuer des recherches plus rapidement grâce aux index. 
