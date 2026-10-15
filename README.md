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

# Taillon, Antoine

# Question 1 : 

Nous n'avons pas vue dans le cours la fonctionnalitée d'écrire dans un fichier avec ofstream (output fil stream).
ofstream vient de la bibliothèque fstream.

C'est moi qui a écrit ce code pour écrire dans le fichier :

    ofstream journal("../data/journal.txt", ios::app);

    auto heure = chrono::system_clock::now();
    time_t temps = chrono::system_clock::to_time_t(heure);

    journal << put_time(localtime(&temps), "%Y-%m-%d %H:%M:%S") << " - [ " << action << "] " << title << "\n";


ofstream journal : déclaration de la variable journal de type ofstream qui nous permet d'écrire dans un fichier.

("../data/journal.txt") : chemin du fichier à ouvrir

ios::app : permet d'écrire à la fin du fichier tout en gardant ce qui et déjà écrit dedans

journal << : écrit à la fin du fichier. Ce comporte comme un cout <<


# Question 2 :

J'utiliserais une base de donnée comme MongoDB pour stocker les données.
En plus MongoDB à déjà un pilote pour C++ qui est mongocxx.
Donc, au lieu de mettre toute les données et le journal dans un fichier texte, j'écrirais tout cela dans une base de données dans MongoDB.
Ceci rend les processus CRUD beaucoup plus rapide.