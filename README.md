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

Mathéo Lacerte
202430191

## Question 1 : C++

Une notion que nous avons peu vue en cours est l’utilisation de `filesystem` pour gérer les fichiers et les dossiers. 
Dans mon projet, cette bibliothèque sert à construire les chemins vers les fichiers contenant les livres et les utilisateurs.

Voici un exemple tiré de `main.cpp` :

```cpp
booksFile = (filesystem::path(dataDir) / "books.txt").string();
usersFile = (filesystem::path(dataDir) / "users.txt").string();
```

La variable `dataDir` contient le chemin du dossier de données choisi au lancement du programme. `filesystem::path(dataDir)` crée un objet qui représente ce chemin. 
L’opérateur `/` ajoute ensuite le nom du fichier au chemin du dossier. Ici, il ne fait pas une division : il sert à assembler un chemin. 
Par exemple, si le dossier est `data`, le programme construit le chemin vers `data/books.txt`. Finalement, `.string()` transforme le chemin en chaîne de caractères pour le conserver dans la variable.

Cette méthode est pratique parce que la bibliothèque gère les séparateurs de chemins selon le système d’exploitation. 
Le programme utilise aussi `filesystem::is_directory(dataDir)` pour vérifier que le chemin correspond bien à un dossier avant de continuer.

#### Question 2 : Options de développement possible

Pour une bibliothèque qui pourrait contenir des millions de livres, je choisirais une base de données PostgreSQL pour remplacer les fichiers texte. 
Je créerais des tables pour les livres, les exemplaires, les utilisateurs et les emprunts. 
Séparer les livres de leurs exemplaires permettrait de gérer plusieurs copies du même livre.

Dans le programme actuel, les données sont chargées en mémoire et les recherches parcourent les livres. Avec PostgreSQL, faire les recherches directement dans la base de données avec des requêtes SQL. 
avec index, par exemple sur l’ISBN, pour retrouver rapidement un livre. Le programme récupérerait seulement les résultats nécessaires, avec un affichage par pages, au lieu de charger des millions de livres.

Pour cette solution en C++, j’utiliserais la bibliothèque `libpq`. Elle permet au programme de se connecter à PostgreSQL, d’envoyer des requêtes SQL et de récupérer les résultats. 
Par exemple, l’ajout d’un livre ferait une requête `INSERT`, et une recherche ferait une requête `SELECT`.
