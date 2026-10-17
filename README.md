# Nom du contributeur
Marisa Yu, Groupe 1


# Fonctionnalités choisies d'implémenter
Interface et Expérience Utilisateur :
    - Numérotation automatique des ID utilisateurs

Gestion des Données :
    - Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).


# Question 1 : C++
```
for (size_t i = 0; i < users.size(); i++) {
        int userIdCurrent = stoi(users[i]->getUserId());

        if (userIdCurrent > plusGrandId) {
            plusGrandId = userIdCurrent;
        }
}
```
Dans le cours, nous n'avons pas vu ``size_t``. Il est utilisé pour compter la taille d'un vecteur à la place de ``ìnt``,
car il représente seulement des nombres positifs, comparativement au ``int``qui représente des nombres positifs et négatifs.
Lorsque j'ai utilisé ``ìnt``, cela m'a donné un erreur lorsque j'utilisais ``.size()``.


# Question 2 : Options de développement possible
Une autre option de développement serait de programmer avec le langage de programmation PHP. Le PHP produit des sites Web dynamques. Il peut facilement relier une base de données tel que MySQL, qui peut également conserver une grande masse de données. On peut utiliser le C++ pour sa STL, qui inclut les algorithmes de tri, de recherches, et autres. Ces derniers qui facilitent le développement et qui sont très pratiques pour structurer les différentes types de données d'un système de gestion de bibliothèque.



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