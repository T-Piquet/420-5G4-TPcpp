# William Luis Roux

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

## Fonctionnalités choisies

1. Numerotation automatique des ID utilisateurs
2. Tri des resultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

# Questions

## Question 1 : C++

J'ai utilisé une fonctionnalité que nous n'avons pas vue dans le cours: Journalisation

```cpp
void FileManager::logAction(const string& action, const string& details) {
    ofstream logFile("data/journal.txt", ios::app);

    if (!logFile.is_open()) {
        cout << "Erreur : Impossible d'ouvrir/créer le fichier de journalisation.\n";
        return;
    } else {
        time_t now = time(0);
        tm* dateHeure = localtime(&now);

        logFile << put_time(dateHeure, "%Y-%m-%d %H:%M:%S") << " - [" << action << "] " << details << "\n";
    }
    logFile.close();
}
```

### Explication

- `ofstream logFile(...)` : Permet de créer le fichier de journalisation a l'endroit désiré
- `if (!logFile.is_open())` : Vérifie que le stream est ouvert. S'il ne l'est pas, on annule la journalisation.

- `time_t` : type qui représente le nombre de secondes écoulées depuis le 1er janvier 1970
- `time(0)` : demande l'heure actuelle. 0 signifie qu'on passe un pointeur nul à la fonction time()
- `tm*` : pointeur vers une structure contenant la date et l'heure
- `localtime(&now)` : fonction qui transforme un temps `time_t` en date/heure locale et renvoie un pointeur `tm`.
- `put_time(...)` : fonction qui formate une structure `tm` en texte lisible
- `"%Y-%m-%d %H:%M:%S"` : format du texte désiré (année-mois-jour heure:minute:seconde)
- `logFile.close();` : Ferme le stream afin de libérer les ressources système (le fichier)

### Exemple de sorties

```text
2026-10-23 10:23:57 - [EMPRUNT] Les Misérables|Victor Hugo|9782253096337|0|Marie Dubois
2026-10-23 01:35:23 - [AJOUT LIVRE] L'assomoir|Victor Hugo|9782253090275|1|
```

## Question 2 : Options de développement possible

Pour la gestion de la bibliothèque, des fichiers .txt font l'affaire pour sauvegarder les données pour une utilisation locale. Cependant, si on désire l'utiliser réellement avec plusieurs utilisateurs et une grande quantité de livres, il serait alors nécessaire d'utiliser une base de données comme MySQL ou MongoDB. MongoDB étant une base de données non relationnelle (NoSQL), elle ne marcherait pas très bien avec une librairie qui possède beaucoup de relations entre ses tables (livres, utilisateurs, emprunts, etc.). J'utiliserais donc MySQL pour ce programme.

Pour interfacer MySQL avec le C++, j'utiliserais le connecteur officiel `MySQL Connector/C++` en l'installant avec sudo apt install, puis en utilisant cette connection dans le code avec des #include.