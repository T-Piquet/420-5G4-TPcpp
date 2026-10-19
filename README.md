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


# VEILLE TECHNOLOGIQUE

Nom et prénom: Alizada, Kaywan

Pour Interface et Expérience Utilisateur: numérotation automatique des ID utilisateurs.

Pour Gestion des Données: Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

Question 1 : C++

Reponse 1:
ofstream est une fonctionnalité qui provient de la bibliothèque <fstream>. Elle existe pour écrire des données dans des fichiers et si les fichiers n'existent pas, il les crées automatiquement. Par contre, ofstream de base va effacer tout le contenu d'un fichier par les données que toi tu lui donne, alors il a besoin de "ios::app" qui lui s'assure qu'a la place que ofstream remplace tes données, elle fait juste ajouter tes données à la fin du fichier. 

Cette ligne crée une variable qui connait le chemin du fichier et qui est pret a ajouter des choses dans le fichier:
ofstream file(journalsFileName, ios::app);

Cette ligne ajoute les élément dans le fichier:
file << heure << "-" << " [" << action << "] " << info << "\n";


Question 2 : Options de développement possible

Reponse 2:
Une solution adaptée pour la gestion de bibliothèque pourrait être que à la place d'utiliser des fichiers .txt dans notre dossier ".data", on pourrait plutot utiliser mysqlworkbench pour faire des tableaux("books", "journal", "users"). Je me dis que sa sera plus simple de conserver des données avec sql dans 3 tableaux différents qui explique la relation entre les tableau plutôt que d'avoir 3 fichiers différents où on a de la misère à trouver comments les éléments se rapproche.
