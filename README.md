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



# Informations
Christian Bostan
1. Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.
2. Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).
3. Créez un fichier de journal de l’application. Ce fichier est conservé au fur et à mesure des sessions (créez le fichier s’il n’existe pas à la première exécution).
# Questions
1. J’ai utilisé ofstream, qui fait partie de la bibliothèque fstream. Elle permet d’écrire des données dans un fichier texte à partir d’un programme C++. Dans mon projet, j’ai utilisé ofstream pour créer le fichier journal.txt afin de garder une trace des actions effectuées, comme l’emprunt, l’ajout ou la suppression de livres.

exemple: ofstream journalFile(journalFileName, ios::app);

Cette ligne ouvre le fichier dont le chemin est contenu dans la variable journalFileName, en utilisant la variable journalFile pour le manipuler. Le paramètre ios::app permet d’ajouter le nouveau contenu à la fin du fichier sans effacer les données déjà présentes (append).

2. J'utiliserais une base de données PostgreSQL au lieu de conserver les données dans des fichiers texte. PostgreSQL est un bon système de gestion de bases de données relationnelles pour manipuler de grandes quantités de données. De plus, il est beaucoup plus efficace pour gérer un grand nombre de livres grâce à sa capacité à stocker et à organiser de grandes quantités de données.