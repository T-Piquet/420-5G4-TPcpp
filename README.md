# Author: Viken M. (202379344)

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

# Veille technologique

## Question 1

> Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours. Montrez ici l’exemple sorti du code du projet.

```c++
void FileManager::log(const std::string& message) {
	ofstream logFile(dataDir + "/logs.txt", ios::app);
	if (logFile.is_open()) {
		time_t now = time(nullptr);
		tm* localTime = localtime(&now);

		logFile << put_time(localTime, "%Y-%m-%d %H:%M:%S") << " - " << message << endl;

		logFile.close();
	}
}
```

Cette partie aborde deux concepts que nous n'avons pas vus en cours. :a manipulation des fichiers et la gestion du temps. Je vais me concentrer sur l'aspect du `time` dans mes explications.

`time` fait partie de la library `<ctime>`. L'appel `time(nullptr)` renvoie l'heure actuelle sous forme d'objet `time_t`. En utilisant un pointeur nul, on obtient le temps écoulé en secondes depuis l'epoch Unix (le 1er janvier 1970).

`localtime` convertit l'objet `time_t` en une structure `tm`.

Pour afficher la date et l'heure, j'utilise la fonction `put_time`. Elle accepte des spécificateurs de format particuliers pour contrôler l'affichage.

## Question 2

> Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Quelle solution technologique utiliseriez vous ? Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.

Actuellement, les livres et les utilisateurs sont stockés dans des fichiers texte. À chaque lancement, le programme charge tout le fichier en mémoire et à chaque sauvegarde il réécrit le fichier en entier. Avec des millions de livres, ce processus serait très lent.

J'utiliserais plutôt SQLite.

Pour l'utiliser en C++, j'utiliserais la bibliothèque de SQLite (`sqlite3.h`). Je remplacerais la classe `FileManager` par un gestionnaire `DatabaseManager` utilisant une approche fonctionnelle, capable d'exécuter des requêtes SQL au lieu de lire et d'écrire des fichiers texte. Les opérations de recherche et de tri par titre seraient effectuées directement par la base de données plutôt que par `std::sort`.

## Fonctionnalités choisis

### Interface et Expérience Utilisateur
> Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.

### Gestion des Données
> Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).
