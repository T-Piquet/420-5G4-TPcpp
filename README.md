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

# Alexander Saint-Jean
DA: 202397719

## Les fonctionnalités que j'ai implémenter

1- Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres.

2- Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

## Questions

### Question 1: C++

``` cpp
void FileManager::sauvgarderEvenementJournal(const string &evenement, const string &description)
{
    filesystem::path path = filesystem::path(booksFileName).parent_path() / "journal.txt";

    ofstream file(path, ios::app);

    if (file.is_open())
    {
        time_t presentTime = time(nullptr);
        tm *dateTime = localtime(&presentTime);

        file << put_time(dateTime, "%Y-%m-%d %H:%M:%S") << " - [" << evenement << "] " << description << "\n";
    }
    else
    {
        cout << "Erreur, l'écriture dans le journal à échouer : " << path << "\n";
    }
}
```

### Explications

Une notion qu'on n'a pas vue en classe l'écriture dans un fihier.
Elle consiste à faire un log pour chacune de nos actions.

- `parent_path()` : récupère le répertoire parent du fichier des livres
- `ofstream file(...)` : écrit dans le fichier de journalisation
- `ios::app` : ajoute les nouveaux événement à la fin du fichier sans écraser les données déjà écrites dans le fichier `journal.txt`
- `if (file.is_open())` : vérifie si le fichier a été ouvert
- `time_t` : représente le temps utilisé par le programme pour obtenir la date et l'heure actuelles
- `time(nullptr)` : récupére l'heure actuelle et le `nullptr` signifie qu'aucune adresse mémoire n'est fournie pour recevoir le résultat de la fonction
- `tm*` : c'est un pointeur qui contient l'adresse d'une structure avec les informations de la date et de l'heure
- `localtime(&tempsActuel)` : fonction qui convertit la valeur du temps en date et heure locales, puis retourne un pointeur vers une structure `tm`
- `put_time(...)` : fonction qui formate les informations de date et d'heure en texte
- `"%Y-%m-%d %H:%M:%S"` : format de la date et de l'heure (année-mois-jour heure:minute:seconde)

### Exemple de sorties du code du projet

```text
2026-10-18 01:25:33 - [SUPPRESSION LIVRE] Alex|Jean|9781111111111|0|
2026-10-18 01:25:39 - [SAUVGARDE] Sauvgarde des données dans la librairie
```
## Question 2: Options de développement possible
Pour gérer une bibliothèque qui pourrait un jour gérer des milliers de livres, j'utiliserais une base de données SQL, comme PostgreSQL. Contrairement à c++, SQL permet de stocker les livres et les utilisateurs sous forme d'objet dans des tables claire et organisées. C'est plus facile et plus rapide que de rechercher un livre avec des requêtes SQL et les indexs. SQL permet aussi de relier les livres aux utilisateurs et facilité la gestion des emprunts. Pour intégrer cette technologie à mon programme C++, j'utiliserais une bibliothèque comme libpqxx, qui permet à C++ de communiquer avec PostgreSQL. Le programme pourrait alors envoyer des requêtes SQL pour ajouter, supprimer, rechercher des livres, au lieu de lire et d'écrire directement dans des fichiers texte.