# TP C++ : Gestion de bibliothèque

**Philippe Brutus** (2496415)

## Fonctionnalités

- **book.cpp complété** : constructeurs, getters, setters, emprunt, retour, affichage, et lecture/sauvegarde des livres dans `books.txt`.
- **Correction du bug de sauvegarde** : si on lance le programme sans `--data-dir`, il avertit au début et à la fin, et il n'essaie plus de sauvegarder dans un chemin vide.
- **Journal d'activités** : chaque action qui modifie les données (ajout, suppression, emprunt, retour, ajout d'utilisateur) est écrite dans `journal.txt`. Le fichier est créé au premier lancement et il est conservé d'une session à l'autre.
- **Interface : numérotation automatique des ID utilisateurs** : à l'ajout d'un utilisateur, le programme donne lui-même le prochain ID libre (`USR026`, `USR027`...).
- **Gestion des données : tri des livres** : l'affichage de tous les livres est trié par titre, puis par auteur si deux livres ont le même titre, avec `sort` de la STL.

## Question 1 : C++

Dans le code, `Library` garde ses livres dans des `unique_ptr` au lieu de garder les objets direct. On n'a pas vraiment vu ça en cours. En gros, c'est un pointeur intelligent qui est le seul propriétaire du livre. Quand il est détruit (livre enlevé du vector ou fin du programme), le livre est effacé de la mémoire tout seul, donc pas besoin de faire `delete` et pas de fuite de mémoire. `make_unique` sert à créer le livre et le pointeur en même temps, et `.get()` donne un pointeur normal quand on veut juste lire le livre sans le posséder, comme dans `getAllBooks()`.

```cpp
// library.h
vector<unique_ptr<Book>> books;

// library.cpp
void Library::addBook(const Book& book) {
    books.push_back(make_unique<Book>(book));
}

vector<Book*> Library::getAllBooks() {
    vector<Book*> allBooks;
    for (auto& book : books) {
        allBooks.push_back(book.get());
    }
    return allBooks;
}
```

## Question 2 : Options de développement possible

Avec des millions de livres comme à Alexandrie, la version actuelle ne marcherait plus. Le programme charge tous les livres en mémoire depuis un fichier texte et chaque recherche regarde les livres un par un, donc ce serait super lent et ça prendrait trop de mémoire. Moi j'utiliserais une base de données comme PostgreSQL, avec les livres et les utilisateurs dans des tables et des index sur l'ISBN, le titre et l'auteur. Avec les index, la base trouve un livre sans lire toute la table, et plusieurs personnes peuvent s'en servir en même temps. Pour le lien avec le C++, je prendrais libpqxx, la librairie C++ officielle de PostgreSQL : le programme envoie des requêtes SQL (ex. chercher par titre) et reçoit juste les résultats. On remplacerait `FileManager` par une classe qui parle à la base de données, et le reste du code ne changerait presque pas.

Sources :
- PostgreSQL, Indexes : https://www.postgresql.org/docs/current/indexes-intro.html
- libpqxx : https://github.com/jtv/libpqxx

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
