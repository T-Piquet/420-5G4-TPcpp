# Travail Practique

**Nguyen, Thien Kim**

# Fonctionnalités choisis

## Interface et Expérience Utilisateur

- Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.

## Gestion des Données

- Tri des résultats par titre, auteur pour l'affichage (utilisation de la fonction de tri de la STL).

# Questions
## Question1 : C++

La librairie filesystem a été introduit dans C++17. Cette librarie est utilisée pour manipuler les chemins et les fichiers. Elle contient plusieurs classes comme **filesystem::path**; **filesystem::is_directory**; **filesystem_copy_file**, qui se retrouve dans les fichiers <ins>main.cpp</ins> et <ins>filemanager.cpp</ins>.

Dans filemanager.pp :

```
// Create backup
void FileManager::createBackup() {
    if (fileExists(booksFileName)) {
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }
    
    if (fileExists(usersFileName)) {
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }
    
    cout << "Fichiers de sauvegarde créés.\n";
}
```
## Question2 : Options de développement possible

Une solution plus adaptée pour la gestion de bibliothèque pourra être l'utilité d'une base de donnée, comme MySQL, pour stocker facilement les données comme les livres et les utilisateurs. Cette base de donnée simplieras l'ajout et la suppression d'un livre dans la bibliothèque. COmment interfacer MySQL avec C++ : 

1. MySQL a une librairie de connector avec C++, alors on devra l'installer **MySQL COnnector/C++ Library**
2. Dans le fichier, on doit inclure : 
```
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
```
pour prendre le données besoin pour établir une connection.

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