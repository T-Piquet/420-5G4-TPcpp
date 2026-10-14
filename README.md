# Gestion de bibliothèque — TP C++

**Nom :** William Meunier  
**DA :** 2361359

# Table des matières

- [Construire le projet](#construire-le-projet)
- [Répertoire data](#répertoire-data)
- [Fonctionnalités ajoutées](#fonctionnalités-ajoutées)
  - [Interface et expérience utilisateur](#interface-et-expérience-utilisateur)
  - [Gestion des données](#gestion-des-données)
  - [Journal d’activités](#journal-dactivités)
  - [Correction de la sauvegarde](#correction-de-la-sauvegarde)
- [Question 1 — Une notion utilisée en C++](#question-1--une-notion-utilisée-en-c)
- [Question 2 — Une solution adaptée à une grande bibliothèque](#question-2--une-solution-adaptée-à-une-grande-bibliothèque)



# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet :
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`

## Fonctionnalités ajoutées


### Interface et expérience utilisateur

Le nom de l’emprunteur est affiché à la place de son identifiant dans les listes de livres et les résultats de recherche.


### Gestion des données

Les livres sont triés à l’aide de la fonction `sort` de la STL :

- **Recherche par titre :** tri par titre.
- **Recherche par auteur :** tri par auteur, puis par titre lorsque les auteurs sont identiques.
- **Liste complète et livres disponibles :** tri par titre.


### Journal d’activités

Le fichier `journal.txt` enregistre les activités de l’application avec leur date et leur heure. Il est créé s’il n’existe pas, et les nouvelles entrées sont ajoutées à la fin pour conserver l’historique entre les sessions.

Les actions enregistrées sont :

- L’ajout d’un livre.
- La suppression d’un livre.
- L’emprunt d’un livre.
- Le retour d’un livre.


Exemple de journal:

```
2026-10-14 20:32:44 - [AJOUT LIVRE] testjournal|auteur|132575|1|
2026-10-14 20:33:29 - [EMPRUNT LIVRE] Britannicus|Jean Racine|9782070380824|0|USR015
2026-10-14 20:33:44 - [RETOUR LIVRE] Britannicus|Jean Racine|9782070380824|1|
2026-10-14 20:35:22 - [AJOUT LIVRE] beautitre|beaunom|9871|1|
2026-10-14 20:38:22 - [SUPPRESSION LIVRE] beautitre|beaunom|9871|1|
2026-10-14 20:52:50 - [AJOUT LIVRE] drthhtyfd|srth|135512|1|
```


### Correction de la sauvegarde

Si les chemins des fichiers de données sont vides, le programme ne tente pas de sauvegarder. Il affiche un message explicite indiquant qu’un répertoire doit être fourni avec l’option `--data-dir`.



### Question 1 — Une notion utilisée en C++

La classe `stringstream`, fournie par la bibliothèque `<sstream>`, permet de lire une chaîne de caractère comme un flux de données. Je l'utilise pour lire les lignes et les séparer avec `|`. Ensuite, je les mets dans un vector, ce qui me permet de récupérer les éléments de ce dernier pour remplir les attributs du livre.

Extrait de `book.cpp` :

```cpp
vector<string> champs;
stringstream ss(line);
string champ;

// Découper la ligne au niveau des |
while (getline(ss, champ, '|')) {
    champs.push_back(champ);
}

// Ajouter le dernier champ vide si la ligne se termine par |
if (!line.empty() && line.back() == '|') {
    champs.push_back("");
}
```


### Question 2 — Une solution adaptée à une grande bibliothèque

Je proposerais de remplacer les fichiers texte par une base de données relationnelle comme MySQL. Cela permettrait de conserver un grand nombre de données et que ce soit plus simple à maintenir en ordre. Le programme peut rester en C++ et communiquer avec MySql via un connecteur pour exécuter des requêtes  SQL.